import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.math.BigDecimal;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.math.MathContext;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
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
    public static final int inf = 1000 * 1000 * 1000;
    public static final int mod = 1000 * 1000 * 1000 + 7;
    public static final int maxn = 218 * 1000;

    static long[] f;
    static long[] rf;
    static long[] p2;

    static {
        f = new long[maxn];
        rf = new long[maxn];
        p2 = new long[maxn];
        f[0] = 1;
        rf[0] = 1;
        p2[0] = 1;
        for (int i = 1; i < maxn; ++i) {
            f[i] = (f[i - 1] * (long)i) % mod;
            rf[i] = IntegerUtlis.pow(f[i], mod - 2, mod);
            p2[i] = (p2[i - 1] * 2L) % mod;
        }
    }

    static long C(int n, int k) {
        if (k < 0 || k > n) return 0;
        long res = f[n] * rf[k];
        res %= mod;
        res *= rf[n - k];
        return res % mod;
    }

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        int state = 0, prev = inf, pi = -1;
        int[] pos = new int[n + 1];
        int[] status = new int[n + 1];
        Arrays.fill(pos, -1);
        int count = 0;
        int head = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) continue;
            ++count;
            pos[a[i]] = i;
            if (state == 0) {
                if (a[i] < prev) {
                    prev = a[i];
                } else {
                    // a[i] > prev
                    state = 1;
                    prev = a[i];
                    head = pi;
                }
            } else {
                if (a[i] < prev) {
                    out.printLine(0);
                    return;
                } else {
                    prev = a[i];
                }
            }
            pi = i;
            status[a[i]] = state;
        }
        if (head == -1) head = pi;
        if (count == 0) {
            out.printLine(p2[n - 1]);
            return;
        }
        if (count == 1) {
            int ind = -1;
            for (int i = 0; i < n; ++i)
                if (a[i] != 0) ind = i;
            if (a[ind] == 1) {
                long res = C(n - 1, ind);
                out.printLine(res);
                return;
            }
            long le = C(n - a[ind], ind) * p2[a[ind] - 2];
            le %= mod;
            long ri = C(n - a[ind], n - ind - 1) * p2[a[ind] - 2];
            ri %= mod;
            long res = (le + ri) % mod;
            out.printLine(res);
            return;
        }
        long Res = 0;
        for (status[a[head]] = 0; status[a[head]] < 2; ++status[a[head]]) {
            try {
                long res = 1;
                int l = -1, r = -1;
                for (int i = 1; i <= n; ++i) {
                    if (pos[i] == -1) continue;
                    int cl, cr;
                    if (status[i] == 0) {
                        cl = pos[i];
                        cr = pos[i] + i - 1;
                    } else {
                        cr = pos[i];
                        cl = pos[i] - i + 1;
                    }
                    if (cl < 0 || cr >= n || cr < cl) {
//                        out.printLine(0);
//                        return;
                        throw new RuntimeException();
                    }
                    if (l == -1) {
                        if (cr > cl) res *= p2[cr - cl - 1];
                        res %= mod;
                    } else {
                        if (cl > l || cr < r) {
//                            out.printLine(0);
//                            return;
                            throw new RuntimeException();
                        }
                        int k = cr - r;
                        if (status[i] == 1) --k;
                        res *= C((cr - cl) - (r - l) - 1, k);
                        res %= mod;
                    }
                    l = cl;
                    r = cr;
                }
                if (l == -1) {
                    Assert.assertTrue(false);
                    res *= p2[n - 1];
                    res %= mod;
                } else {
                    res *= C(n - 1 - (r - l), n - r - 1);
                }
                Res += res;
            } catch (Throwable e) {

            }
            if (a[head] == 1) break;
        }
        Res %= mod;
        out.printLine(Res);

    }
}

class IntegerUtlis {

    public static int pow(long x, long y, int mod) {
        x %= mod;
        long res = 1;
        while (y > 0) {
            if (y % 2 == 1) {
                --y;
                res = (res * x) % mod;
            } else {
                y /= 2;
                x = (x * x) % mod;
            }
        }
        return (int)(res % mod);
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

class Assert {

    public static void assertTrue(boolean flag) {
        if (!flag)
            throw new AssertionError();
    }

    }