import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.math.BigInteger;
import java.io.IOException;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        static final long mod = 1000 * 1000 * 1000 + 7;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int p = in.nextInt();
            int k = in.nextInt();
            if (k == 0) {
                long res = IntegerUtils.pow(p, p - 1, mod);
                out.printLine(res);
                return;
            }
            if (k == 1) {
                long res = IntegerUtils.pow(p, p, mod);
                out.printLine(res);
                return;
            }
            int cnt = 0;
            long cur = 1;
            do {
                ++cnt;
                cur = (cur * (long) k) % p;
            } while (cur != 1);
            Assert.assertTrue((p - 1) % cnt == 0);
            long r = (p - 1) / cnt;
            long res = IntegerUtils.pow(p, r, mod);
            out.printLine(res);
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

    static class Assert {
        public static void assertTrue(boolean flag) {
//        if (!flag)
//        while (true);
            if (!flag)
                throw new AssertionError();
        }

    }

    static class IntegerUtils {
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
}