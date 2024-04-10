import java.io.OutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {
    static final long inf = (long)(1E17);
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = in.nextInt();
        int[] b = new int[n];
        for (int i = 0; i < n; ++i)
            b[i] = in.nextInt();
        long[][][] d = new long[n + 1][3 * n][3 * n];
        for (int i = 0; i < d.length; ++i)
            for (int j = 0; j < d[i].length; ++j)
                for (int k = 0; k < d[i][j].length; ++k)
                    d[i][j][k] = inf;
        for (int i = 0; i < 3 * n; ++i)
            d[0][i][i] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < d[i].length; ++j)
                for (int k = 0; k < d[i][j].length; ++k)
                    if (d[i][j][k] != inf) {
                        if (k > 0) {
                            d[i + 1][j][k - 1] = Math.min(d[i + 1][j][k - 1], d[i][j][k] + b[i]);
                        }
                        if (k < 3 * n - 1) {
                            d[i + 1][j][k + 1] = Math.min(d[i + 1][j][k + 1], d[i][j][k] + a[i]);
                        }
                    }
        long[][] g = new long[3 * n][3 * n];
        for (int i = 0; i < 3  * n; ++i)
            for (int j = 0; j < 3 * n; ++j)
                g[i][j] = d[n][i][j];
        int y = m;
        long[][] opt = new long[3 * n][3 * n];
        for (int i = 0; i < 3  * n; ++i)
            for (int j = 0; j < 3 * n; ++j)
                opt[i][j] = i == j ? 0 : inf;
        while (y > 0) {
            if (y % 2 == 1) {
                --y;
                opt = mult(opt, g);
            } else {
                y /= 2;
                g = mult(g, g);
            }
        }
        out.printLine(opt[0][0]);
    }

    private long[][] mult(long[][] g1, long[][] g2) {
        long[][] res = new long[g1.length][g1[0].length];
        int n = g1.length;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                res[i][j] = inf;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k) {
                    long val = g1[i][k] + g2[k][j];
                    if (res[i][j] > val)
                        res[i][j] = val;
                }
        return res;
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