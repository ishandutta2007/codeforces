import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        char[] s = in.nextToken().toCharArray();
        //char[] s = new char[1000 * 1000];
//        for (int i = 0; i < s.length; ++i)
//            s[i] = i % 2 == 0 ? '(' : ')';
        int n = s.length;
        int[] st = new int[n + 1];
        int sts = 0;
        int[] wh = new int[n];
        Arrays.fill(wh, -1);
        int h = 1;
        while (h <= n + 5) h *= 2;
        int[] treeInt = new int[h];
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st[sts++] = i;
            } else {
                if (sts > 0) {
                    wh[st[sts - 1]] = i;
                    --sts;
                    treeInt[i + 1] += 1;
                }
            }
        }
        //System.err.println("Nyah");
        FenwickTree tree = new FenwickTree(treeInt);
        //System.err.println("Kawai");
        int m = in.nextInt();
//        int m = 100 * 1000;
        ArrayList<ii>[] q = new ArrayList[n];
        for (int i = 0; i < n; ++i)
            q[i] = new ArrayList<>();
        //System.err.println("Sugoi");
        for (int i = 0; i < m; ++i) {
            int l = in.nextInt() - 1;
            int r = in.nextInt() - 1;
//            int l = i;
//            int r = m - 1;
            q[l].add(new ii(r, i));
        }
        //System.err.println("Blah");
        int[] res = new int[m];
        for (int i = 0; i < n; ++i) {
            for (ii query : q[i]) {
                res[query.second] = tree.sum(query.first + 1) * 2;
            }
            if (wh[i] != -1)
                tree.add(wh[i] + 1, -1);
        }
        for (int i = 0; i < m; ++i)
            out.printLine(res[i]);
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

    public String nextToken() {
        int c = readSkipSpace();
        StringBuilder sb = new StringBuilder();
        while (!isSpace(c)) {
            sb.append((char) c);
            c = read();
        }
        return sb.toString();
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

class FenwickTree {
    int[] t;
    int n;

    public FenwickTree(int n) {
        this.n = n;
        t = new int[n];
    }

    public FenwickTree(int[] a) {
        n = a.length;
        t = new int[n];
        for (int i = 0; i < n; i++) {
            t[i] += a[i];
            int j = i | i + 1;
            if (j < n)
                t[j] += t[i];
        }
    }

    public void add(int i, int value) {
        for (; i < n; i += (i + 1) & -(i + 1))
            t[i] += value;
    }

    // sum[0,i]
    public int sum(int i) {
        int res = 0;
        for (; i >= 0; i -= (i + 1) & -(i + 1))
            res += t[i];
        return res;
    }

    }

class ii implements Comparable<ii> {
    public int first;
    public int second;

    public ii() {
    }

    public ii(int first, int second) {
        this.first = first;
        this.second = second;
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        ii ii = (ii) o;

        if (first != ii.first) return false;
        if (second != ii.second) return false;

        return true;
    }

    public int hashCode() {
        int result = first;
        result = 31 * result + second;
        return result;
    }

    public int compareTo(ii o) {
        if (first != o.first) {
            return first < o.first ? -1 : 1;
        }
        if (second != o.second) {
            return second < o.second ? -1 : 1;
        }
        return 0;
    }

    }