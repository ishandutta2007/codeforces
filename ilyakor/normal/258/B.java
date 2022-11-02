import java.io.IOException;
import java.io.OutputStreamWriter;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {

    static final long mod = 1000000007;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int m = in.nextInt();
        long[] inv = new long[100];
        for (int i = 1; i < inv.length; ++i) {
            inv[i] = IntegerUtlis.pow((long)i, mod - 2, mod);
        }

        long[] pw8 = new long[20];
        pw8[0] = 1;
        for (int i = 1; i < pw8.length; ++i)
            pw8[i] = pw8[i - 1] * 8L;

        long[] d = new long[100];
        String ms = Integer.toString(m);
        int pcnt = 0;
        for (int i = 0; i <= ms.length(); ++i) {
            if (i == ms.length()) {
                ++d[pcnt];
                continue;
            }
            int nd = ms.charAt(i) - '0';
            for (int j = 0; j < nd; ++j) {
                int cur = pcnt;
                if (j == 4 || j == 7) ++cur;
                long tmp = 1, den = 1;
                for (int t = 0; t <= ms.length() - i - 1; ++t) {
                    d[cur + t] += pw8[ms.length() - i - 1 - t] * tmp / den;
                    tmp *= (long) ms.length() - i - 1 - t;
                    tmp *= 2L;
                    den *= (long)(t + 1);
                }
            }
            if (nd == 4 || nd == 7) ++pcnt;
        }
        --d[0];

//        long[] dd = new long[100];
//        for (int i = 1; i <= m; ++i) {
//            int x = i;
//            int cur = 0;
//            while (x > 0) {
//                if (x % 10 == 4 || x % 10 == 7) ++cur;
//                x /= 10;
//            }
//            ++dd[cur];
//        }
//        for (int i = 0; i < 20; ++i)
//            Assert.assertTrue(d[i] == dd[i]);

        long res = 0;
        for (int i = 1; i <= 9; ++i)
            for (int i1 = 0; i1 < i; ++i1)
                for (int i2 = 0; i1 + i2 < i; ++i2)
                    for (int i3 = 0; i1 + i2  + i3 < i; ++i3)
                        for (int i4 = 0; i1 + i2 + i3 + i4 < i; ++i4)
                            for (int i5 = 0; i1 + i2 + i3 + i4 + i5 < i; ++i5)
                                for (int i6 = 0; i1 + i2 + i3 + i4 + i5 + i6 < i; ++i6) {
                                    int[] cnts = new int[10];
                                    ++cnts[i1];
                                    ++cnts[i2];
                                    ++cnts[i3];
                                    ++cnts[i4];
                                    ++cnts[i5];
                                    ++cnts[i6];
                                    long cur = d[i] % mod;
                                    for (int t = 0; t <= 9; ++t) {
                                        long s = d[t];
                                        if (s < cnts[t]) {
                                            cur = 0;
                                            continue;
                                        }
                                        for (int j = 0; j < cnts[t]; ++j) {
                                            cur *= (long) (s - j);
                                            cur %= mod;
                                            //cur *= inv[j + 1];
                                            //cur %= mod;
                                        }
                                    }
                                    res += cur;
                                    res %= mod;
                                }
        out.printLine(res % mod);
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

    public static long pow(long x, long y, long mod) {
        x %= mod;
        long res = 1;
        while (y > 0) {
            if (y % 2 == 1) {
                --y;
                res = BigInteger.valueOf(res).multiply(BigInteger.valueOf(x)).mod(BigInteger.valueOf(mod)).longValue();
            } else {
                y /= 2;
                x = BigInteger.valueOf(x).multiply(BigInteger.valueOf(x)).mod(BigInteger.valueOf(mod)).longValue();
            }
        }
        return res % mod;
    }

    }