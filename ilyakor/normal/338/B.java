import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.OutputStream;
import java.io.PrintWriter;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    static final int inf = 1000 * 1000 * 100;

    ArrayList<Integer>[] g;
    boolean[] marked;
    int[] d;
    int[] dd;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        g = new ArrayList[n];
        marked = new boolean[n];
        for (int i = 0; i < n; ++i)
            g[i] = new ArrayList<Integer>();
        d = new int[n];
        Arrays.fill(d, -inf);
        int m = in.nextInt();
        int diam = in.nextInt();
        for (int i = 0; i < m; ++i) {
            int x = in.nextInt() - 1;
            d[x] = 0;
            marked[x] = true;
        }
        for (int i = 0; i < n - 1; ++i) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            g[x].add(y);
            g[y].add(x);
        }
        dfs1(0, -1);
        dd = new int[n];
        Arrays.fill(dd, -inf);
        dfs2(0, -1, -inf);
        int res = 0;
        for (int i = 0; i < n; ++i)
            if (dd[i] <= diam)
                ++res;
        out.printLine(res);
    }

    private void dfs1(int x, int parent) {
        for (int y : g[x]) if (y != parent) {
            dfs1(y, x);
            if (d[y] != -inf && d[x] < d[y] + 1)
                d[x] = d[y] + 1;
        }
    }

    private void dfs2(int x, int parent, int val) {
        if (val != -inf) ++val;
        if (marked[x]) {
            val = Math.max(val, 0);
        }
        dd[x] = Math.max(d[x], val);
        int m1 = -inf, m2 = -inf, i1 = -1, i2 = -1;
        for (int y : g[x]) if (y != parent) {
            if (d[y] + 1> m1) {
                m2 = m1;
                i2 = i1;
                m1 = d[y] + 1;
                i1 = y;
            } else if (d[y] + 1> m2) {
                m2 = d[y] + 1;
                i2 = y;
            }
        }
        for (int y : g[x]) if (y != parent) {
            dfs2(y, x, Math.max(val, y == i1 ? m2 : m1));
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