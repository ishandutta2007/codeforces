import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskE {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        long seed = 42;
        int n = in.nextInt();
        seed += n; seed *= 57;
        int len = in.nextInt();
        seed += len; seed *= 57;
        int h = in.nextInt();
        seed += h; seed *= 57;
        int[] b = new int[len];
        for (int i = 0; i < len; ++i) {
            b[i] = h - in.nextInt();
            seed += b[i]; seed *= 57;
        }

        Random random = new Random(seed);
        for (int i = 0; i < len; ++i) {
            int j = random.nextInt(len);
            if (i != j) {
                int t = b[i];
                b[i] = b[j];
                b[j] = t;
            }
        }
        Arrays.sort(b);

        int n2 = 1;
        while (n2 <= 2 * len + 10) n2 *= 2;
        SegmentTreeFastIntervalAddMax tree = new SegmentTreeFastIntervalAddMax(n2);
        for (int i = 0; i < len; ++i) {
            tree.set(i + 1, len - i);
        }

        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }

        for (int i = 0; i < len; ++i) {
            inc(tree, b, a[i], -1);
        }
        int res = 0;
        if (tree.queryMax(1, len) <= 0)
            ++res;
        for (int i = 0; i + len < n; ++i) {
            inc(tree, b, a[i], +1);
            inc(tree, b, a[i + len], -1);
            if (tree.queryMax(1, len) <= 0)
                ++res;
        }
        out.printLine(res);
    }

    private void inc(SegmentTreeFastIntervalAddMax tree, int[] b, int x, int delta) {
        int l = 0, r = b.length;
        while (r - l > 1) {
            int t = (r + l) / 2;
            if (b[t] > x)
                r = t;
            else
                l = t;
        }
        int ind = b[l] > x ? l : r;
        if (ind > 0) tree.modifyAdd(1, ind, delta);
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

    public void set(int i, int v) {
        modifyAdd(i, i, -queryMax(i, i) + v);
    }

    }