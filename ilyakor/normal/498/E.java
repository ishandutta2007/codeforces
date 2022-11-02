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
 * @author ilyakor
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
    static final long mod = 1000 * 1000 * 1000 + 7;

    Matrix a;
    int N;
    boolean[] hor;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int[] w = new int[7];
        for (int i = 0; i < 7; ++i)
            w[i] = in.nextInt();
        long[] v = new long[1 << 7];
        v[0] = 1;
        for (int ind = 0; ind < 7; ++ind) {
            N = ind + 1;
            int pcnt = 1 << (ind + 1);

            a = new Matrix(pcnt);
            for (int p1 = 0; p1 < pcnt; ++p1) {
                hor = new boolean[ind + 1];
                gen(p1, 0, 0);
            }

            a = a.pow(w[ind], mod);
            {
                long[] nv = new long[1 << 7];
                for (int i = 0; i < pcnt / 2; ++i)
                    nv[i * 2 + 1] = v[i];
                v = nv;
            }
            {
                long[] nv = new long[1 << 7];
                for (int i = 0; i < pcnt; ++i)
                    for (int j = 0; j < pcnt; ++j)
                        nv[i] = (nv[i] + a.a[i][j] * v[j]) % mod;
                v = nv;
            }
        }
        out.printLine(v[(1 << 7) - 1]);
    }

    boolean hor(int ind) {
        if (ind < 0 || ind >= N) return true;
        return this.hor[ind];
    }

    boolean vert(int ind, int left, int right) {
        if ((left >> ind) % 2 == 0) return false;
        if ((right >> ind) % 2 == 0) return false;
        return true;
    }

    private void gen(int left, int right, int pos) {
        if (pos >= N) {
            a.a[left][right] += 1;
            return;
        }
        for (int h = 0; h < 2; ++h)
            for (int v = 0; v < 2; ++v) {
                if (h == 0 && pos == N - 1) continue;

                this.hor[pos] = (h == 1);
                boolean bad = true;
                if (!vert(pos, left, right + (v << pos))) bad = false;
                if (!hor(pos - 1)) bad = false;
                if (!hor(pos)) bad = false;

                if (!bad) {
                    gen(left, right + (v << pos), pos + 1);
                }
            }
    }
}

class Matrix {
    public long[][] a;

    public Matrix(int n) {
        a = new long[n][n];
    }

    public static Matrix uni(int n) {
        Matrix res = new Matrix(n);
        for (int i = 0; i < n; ++i)
            res.a[i][i] = 1;
        return res;
    }

    public Matrix multiply(Matrix b, long mod) {
        Matrix res = new Matrix(a.length);
        for (int i = 0; i < a.length; ++i)
            for (int j = 0; j < a.length; ++j)
                for (int k = 0; k < a.length; ++k) {
                    res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % mod;
                }
        return res;
    }

    public Matrix pow(long y, long mod) {
        Matrix res = Matrix.uni(a.length);
        Matrix x = this;
        while (y > 0) {
            if (y % 2L == 0) {
                x = x.multiply(x, mod);
                y /= 2L;
            } else {
                res = res.multiply(x, mod);
                --y;
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