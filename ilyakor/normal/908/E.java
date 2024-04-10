import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        static final int mod = 1000 * 1000 * 1000 + 7;
        static int[] f = new int[10000];
        static int[] rf = new int[10000];

        static {
            f[0] = 1;
            rf[0] = 1;
            for (int i = 1; i < f.length; ++i) {
                f[i] = (int) ((f[i - 1] * (long) i) % mod);
                rf[i] = IntegerUtils.pow(f[i], mod - 2, mod);
            }
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int m = in.nextInt();
            int n = in.nextInt();
            long[] a = new long[m];
            for (int i = 0; i < n; ++i) {
                long x = (1L << (long) i);
                char[] s = in.nextToken().toCharArray();
                for (int j = 0; j < m; ++j)
                    if (s[j] == '1')
                        a[j] |= x;
            }

            int[] comp = new int[m];
            HashMap<Long, Integer> pos = new HashMap<>();
            for (int i = 0; i < m; ++i) {
                if (!pos.containsKey(a[i])) {
                    pos.put(a[i], i);
                }
                comp[pos.get(a[i])] += 1;
            }

            int[] d = new int[m + 1];
            d[0] = 1;
            d[1] = 1;
            for (int i = 2; i <= m; ++i) {
                long cur = 0;
                for (int j = 1; j <= i; ++j) {
                    long val = d[i - j];
                    val *= C(i - 1, j - 1);
                    cur += val;
                    cur %= mod;
                }
                d[i] = (int) cur;
            }
            long res = 1;
            for (int x : comp)
                if (x > 0) {
                    res *= d[x];
                    res %= mod;
                }
            out.printLine(res);
        }

        private long C(int n, int k) {
            if (k < 0 || k > n) return 0;
            long res = f[n];
            res *= rf[k];
            res %= mod;
            res *= rf[n - k];
            res %= mod;
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

        public String nextToken() {
            int c = readSkipSpace();
            StringBuilder sb = new StringBuilder();
            while (!isSpace(c)) {
                sb.append((char) c);
                c = read();
            }
            return sb.toString();
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

    static class IntegerUtils {
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
            return (int) (res % mod);
        }

    }
}