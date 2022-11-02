import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.math.BigDecimal;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.MathContext;
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
    static final int mod = 1000 * 1000 * 1000 + 7;

    static long[] f, rf;

    static {
        f = new long[20000];
        rf = new long[20000];
        f[0] = 1;
        rf[0] = 1;
        for (int i = 1; i < f.length; ++i) {
            f[i] = (f[i - 1] * (long) i) % mod;
            rf[i] = IntegerUtils.pow(f[i], mod - 2, mod);
        }
    }

    long C(int n, int k) {
        if (k < 0 || k > n) return 0;
        long res = f[n];
        res *= rf[k];
        res %= mod;
        res *= rf[n - k];
        res %= mod;
        return res;
    }

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        long[] d = new long[n + 1];
        long[] nd = new long[n + 1];
        d[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                long mult = C(i - 1, j - 1);
                if (j == 1) mult = (mult * 2L) % mod;
                d[i] = (d[i] + mult * d[i - j]) % mod;
            }
        }
        nd[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                long mult = C(i - 1, j - 1);
                nd[i] = (nd[i] + mult * nd[i - j]) % mod;
            }
        }
        long res = d[n] - nd[n];
        res %= mod;
        res += mod;
        res %= mod;
        out.printLine(res);
    }
}

class IntegerUtils {

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