import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author ilyakor
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD {

    public static final int MAXL = 400 * 1000;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        ArrayList<Guy> guys = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            guys.add(new Guy(in.nextInt(), in.nextInt(), in.nextInt(), i));
        }
        Collections.shuffle(guys);
        Collections.sort(guys);
        int h = 1;
        while (h < MAXL) h *= 2;
        SegmentTreeFastIntervalAddMax tree = new SegmentTreeFastIntervalAddMax(h);
        int res = 0;
        int ri = 0;
        ArrayList<Integer>[] open = new ArrayList[MAXL];
        for (int i = 0; i < MAXL; ++i)
            open[i] = new ArrayList<>();
        int prev = 0;
        for (int i = 0; i < n; ++i) {
            int L = guys.get(i).l;
            while (prev < L) {
                for (int R : open[prev]) {
                    tree.modifyAdd(prev, R, -1);
                }
                ++prev;
            }
            tree.modifyAdd(guys.get(i).v, guys.get(i).r, +1);
            open[guys.get(i).v].add(guys.get(i).r);
            int cur = tree.queryMax(guys.get(i).l, MAXL - 1);
            if (res < cur) {
                res = cur;
                ri = i;
            }
        }

        out.printLine(res);
        int[] d = new int[MAXL];
        for (int i = 0; i <= ri; ++i) {
            if (guys.get(i).v >= guys.get(ri).l) {
                ++d[guys.get(i).v];
                --d[guys.get(i).r + 1];
            }
        }
        ArrayList<Integer> rlist = new ArrayList<>();
        int cx = guys.get(ri).l;
        int cur = d[cx];
        while (cur < res) {
            ++cx;
            cur += d[cx];
        }
        Assert.assertTrue(cur == res);
        for (Guy guy : guys) {
            if (guy.l <= guys.get(ri).l && guy.r >= cx && guy.v <= cx && guy.v >= guys.get(ri).l)
                rlist.add(guy.index);
        }
        Assert.assertTrue(rlist.size() == res);
        Collections.sort(rlist);
        for (int x : rlist) {
            out.print((x + 1) + " ");
        }
        out.printLine();
    }

    static class Guy implements Comparable<Guy> {
        int l, v, r, index;

        Guy(int l, int v, int r, int index) {
            this.l = l;
            this.v = v;
            this.r = r;
            this.index = index;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Guy guy = (Guy) o;

            if (l != guy.l) return false;
            if (r != guy.r) return false;
            if (v != guy.v) return false;

            return true;
        }

        public int hashCode() {
            int result = l;
            result = 31 * result + v;
            result = 31 * result + r;
            return result;
        }


        public int compareTo(Guy o) {
            return Integer.compare(l, o.l);
        }
    }
}

class InputReader {
    private InputStream stream;
    private byte[] buffer = new byte[10000];
    private int cur;
    private int count;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public static boolean isSpace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public int read() {
        if (count == -1) {
            throw new InputMismatchException();
        }
        try {
            if (cur >= count) {
                cur = 0;
                count = stream.read(buffer);
                if (count <= 0)
                    return -1;
            }
        } catch (IOException e) {
            throw new InputMismatchException();
        }
        return buffer[cur++];
    }

    public int readSkipSpace() {
        int c;
        do {
            c = read();
        } while (isSpace(c));
        return c;
    }

    public int nextInt() {
        int sgn = 1;
        int c = readSkipSpace();
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res = res * 10 + c - '0';
            c = read();
        } while (!isSpace(c));
        res *= sgn;
        return res;
    }

    }

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0) {
                writer.print(' ');
            }
            writer.print(objects[i]);
        }
    }

    public void printLine(Object... objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

    }

class SegmentTreeFastIntervalAddMax {
    final int n;
    final int[] t;
    final int[] m;
    final boolean[] h;
    final int[] q;

    public SegmentTreeFastIntervalAddMax(int n) {
        this.n = n;
        t = new int[2 * n];
        m = new int[2 * n];
        h = new boolean[2 * n];
        q = new int[2 * n];
        for (int i = n; i < 2 * n; i++)
            q[i] = 1;
        for (int i = 2 * n - 1; i > 1; i -= 2)
            q[i >> 1] = q[i] + q[i ^ 1];
    }

    void modifierHelper(int i, int p) {
        t[i] += p;
        m[i] += p;
        h[i] = true;
    }

    void pop(int i) {
        if (h[i >> 1]) {
            t[i >> 1] = Math.max(t[i], t[i ^ 1]) + m[i >> 1];
        } else {
            t[i >> 1] = Math.max(t[i], t[i ^ 1]);
        }
    }

    void popUp(int i) {
        for (; i > 1; i >>= 1)
            pop(i);
    }

    void push(int i) {
        if (h[i >> 1]) {
            modifierHelper(i, m[i >> 1]);
            modifierHelper(i ^ 1, m[i >> 1]);
            h[i >> 1] = false;
            m[i >> 1] = 0;
        }
    }

    void pushDown(int i) {
        int k;
        for (k = 0; (i >> k) > 0; k++)
            ;
        for (k -= 2; k >= 0; k--)
            push(i >> k);
    }

    public void modifyAdd(int a, int b, int v) {
        a += n;
        b += n;
        pushDown(a);
        pushDown(b);
        int ta = a;
        int tb = b;

        for (; a <= b; a = (a + 1) >> 1, b = (b - 1) >> 1) {
            if ((a & 1) != 0)
                modifierHelper(a, v);
            if ((b & 1) == 0)
                modifierHelper(b, v);
        }

        popUp(ta);
        popUp(tb);
    }

    public int queryMax(int a, int b) {
        a += n;
        b += n;
        pushDown(a);
        pushDown(b);

        int res = 0;
        for (; a <= b; a = (a + 1) >> 1, b = (b - 1) >> 1) {
            if ((a & 1) != 0)
                res = Math.max(res, t[a]);
            if ((b & 1) == 0)
                res = Math.max(res, t[b]);
        }
        return res;
    }

    }

class Assert {

    public static void assertTrue(boolean flag) {
        if (!flag)
            throw new AssertionError();
    }

    }