import java.io.IOException;
import java.io.OutputStreamWriter;
import java.math.BigDecimal;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.OutputStream;
import java.math.MathContext;
import java.io.PrintWriter;
import java.util.Random;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {
    static final int mod = 1000000007;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        int seed = 0xdead;
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
            seed = seed * 57 + a[i];
        }
        Random random = new Random(seed);
        for (int i = 0; i < n; ++i) {
            int j = random.nextInt(n);
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
        Arrays.sort(a);
        int M = a[a.length - 1];
        int[] b = new int[M + 10];
        long res = 0;
        for (int LCM = 1; LCM <= M; ++LCM) {
            int cnt = 0;
            for (int i = 1; i * i <= LCM; ++i) if (LCM % i == 0) {
                b[cnt++] = i;
                if (i * i != LCM)
                    b[cnt++] = LCM / i;
            }
            Arrays.sort(b, 0, cnt);
            int prev = -1;
            long cur = 1;
            b[cnt] = M + 1;
            for (int i = 1; i <= cnt; ++i) {
                int t = search(a, b[i]);
                if (i < cnt)
                    cur *= IntegerUtlis.pow((long)i, (long)(t - prev), mod);
                else {
                    if (t == prev) {
                        cur = 0;
                        break;
                    }
                    long val = IntegerUtlis.pow((long) i, (long) (t - prev), mod);
                    val -= IntegerUtlis.pow((long) (i - 1), (long) (t - prev), mod);
                    val %= mod;
                    val += mod;
                    val %= mod;
                    cur *= val;
                }
                cur %= mod;
                prev = t;
            }
            res += cur;
            res %= mod;
        }
        out.printLine(res % mod);
    }

    private int search(int[] a, int x) {
        int l = -1, r = a.length;
        while (l + 1 < r) {
            int t = (l + r) / 2;
            if (a[t] < x) l = t;
            else r = t;
        }
        return l;
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