import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
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

    static class TaskC {
        public static final long inf = Long.MAX_VALUE / 4;
        int n;
        int m;
        int d;
        int N;
        int M;
        int RN;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            d = IntegerUtils.gcd(n, m);
            N = n / d;
            M = m / d;
            RN = BigInteger.valueOf(N).modInverse(BigInteger.valueOf(M)).intValue();
            RN = (RN % M + M) % M;
            int q = in.nextInt();
            for (int it = 0; it < q; ++it) {
                int x = in.nextInt();
                int y = in.nextInt();
                long res = inf;
                res = Math.min(res, calc(x, y));
                res = Math.min(res, calc(2 * n - x, y));
                res = Math.min(res, calc(x, 2 * m - y));
                res = Math.min(res, calc(2 * n - x, 2 * m - y));
                if (res == inf) res = -1;
                out.printLine(res);
            }
        }

        private long calc(int x, int y) {
            int delta = y - x;
            if (Math.abs(delta) % (2 * d) != 0) return inf;
            delta /= 2 * d;
            long val = ((long) delta) * (long) RN;
            val %= M;
            val += M;
            val %= M;
            val = val * (2 * n) + x;
            Assert.assertTrue(val % (2 * n) == x);
            Assert.assertTrue(val % (2 * m) == y);
            return val;
        }

    }

    static class InputReader {
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

    static class OutputWriter {
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

    static class Assert {
        public static void assertTrue(boolean flag) {
//        if (!flag)
//        while (true);
            if (!flag)
                throw new AssertionError();
        }

    }

    static class IntegerUtils {
        public static int gcd(int x, int y) {
            if (y == 0) return x;
            return gcd(y, x % y);
        }

    }
}