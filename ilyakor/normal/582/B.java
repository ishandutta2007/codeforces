import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    static final int inf = 1000 * 1000 * 1000 + 10;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int t = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        int[][] d = new int[n][n];
        for (int i = 0; i < n; ++i) {
            int[] nd = new int[2 * n];
            Arrays.fill(nd, -inf);
            nd[i] = 0;
            for (int j = i; j < 2 * n; ++j) {
                if (nd[j] < 0) continue;
                for (int k = j + 1; k < 2 * n; ++k)
                    if (a[k % n] >= a[j % n])
                        nd[k] = Math.max(nd[k], nd[j] + 1);
            }
            for (int j = 0; j < n; ++j)
                d[i][j] = nd[j + n];
        }
        int[][] r = new int[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(r[i], -inf);
            r[i][i] = 1;
            for (int j = i; j < n; ++j) {
                if (r[i][j] < 0) continue;
                for (int k = j + 1; k < n; ++k)
                    if (a[k] >= a[j])
                        r[i][k] = Math.max(r[i][k], r[i][j] + 1);
            }
        }
        --t;
        while (t > 0) {
            if (t % 2 == 1) {
                r = mult(r, d);
                --t;
            } else {
                d = mult(d, d);
                t /= 2;
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                res = Math.max(res, r[i][j]);
        out.printLine(res);
    }

    private int[][] mult(int[][] a, int[][] b) {
        int n = a.length;
        int[][] res = new int[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                res[i][j] = -inf;
                for (int k = 0; k < n; ++k) {
                    if (a[i][k] < 0 || b[k][j] < 0) continue;
                    int val = a[i][k] + b[k][j];
                    if (val > res[i][j])
                        res[i][j] = val;
                }
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