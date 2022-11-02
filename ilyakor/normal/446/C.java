import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
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
    static final int mod = 1000 * 1000 * 1000 + 9;
    static final int maxn = 312 * 1000;
    static final int BUBEN = 500;

    long[] f;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        f = new long[maxn + 10];
        {
            long f1 = 0, f2 = 1;
            f[0] = 0;
            f[1] = 1;
            for (int i = 2; i < maxn; ++i) {
                long _f = (f1 + f2) % mod;
                f1 = f2;
                f2 = _f;
                f[i] = _f;
            }
        }

        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = in.nextInt();
        int[] as = getSums(n, a);

        int[] lefts = new int[BUBEN];
        int[] rights = new int[BUBEN];
        int[] deltas = new int[n + 10];
        int[] _a = new int[n + 10];
        int cnt = 0;
        for (int it = 0; it < m; ++it) {
            int ty = in.nextInt();
            int l = in.nextInt() - 1;
            int r = in.nextInt() - 1;
            if (ty == 1) {
                if (cnt + 1 >= BUBEN) {
                    Arrays.fill(deltas, 0);
                    for (int i = 0; i < cnt; ++i) {
                        deltas[lefts[i]] += 1;
                        deltas[lefts[i]] %= mod;
                        deltas[rights[i] + 1] -= f[rights[i] - lefts[i] + 2];
                        deltas[rights[i] + 2] -= f[rights[i] - lefts[i] + 1];
                        deltas[rights[i] + 1] = (deltas[rights[i] + 1] % mod + mod) % mod;
                        deltas[rights[i] + 2] = (deltas[rights[i] + 2] % mod + mod) % mod;
                    }
                    for (int i = 0; i < n; ++i) {
                        _a[i] = deltas[i];
                        if (i - 1 >= 0) {
                            _a[i] += _a[i - 1];
                            _a[i] %= mod;
                        }
                        if (i - 2 >= 0) {
                            _a[i] += _a[i - 2];
                            _a[i] %= mod;
                        }
                        a[i] += _a[i];
                        a[i] %= mod;
                    }
                    as = getSums(n, a);
                    cnt = 0;
                }
                lefts[cnt] = l;
                rights[cnt] = r;
                ++cnt;
            } else {
                int res = as[l] - as[r + 1];
                res = (res % mod + mod) % mod;
                for (int i = 0; i < cnt; ++i) {
                    if (rights[i] < l || lefts[i] > r) continue;
                    int U = Math.min(rights[i], r) - lefts[i] + 1;
                    int D = Math.max(lefts[i], l) - lefts[i];
                    res += f[U + 2];
                    res -= f[D + 2];
                    res = (res % mod + mod) % mod;
                }
                out.printLine(res);
            }
        }

    }

    private int[] getSums(int n, int[] a) {
        int[] as = new int[n + 1];
        as[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            as[i] = (as[i + 1] + a[i]) % mod;
        }
        return as;
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