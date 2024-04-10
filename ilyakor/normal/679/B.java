import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
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
        static final int maxn = 218 * 1000;
        long[] a;
        long[] d;
        long[] D;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            a = new long[maxn];
            for (int i = 0; i < maxn; ++i)
                a[i] = (long) i * (long) i * (long) i;
            d = new long[maxn];
            D = new long[maxn];
            Arrays.fill(d, -1);
            Arrays.fill(D, -1);
            d[0] = 0;
            D[0] = 0;
            for (int i = 1; i < maxn; ++i) {
                f(i);
            }
            long x = in.nextLong();
            long res = 0, r1 = g(x);
            long r2 = 0;
            while (x > 0) {
                int ind = getPos(x);
                long cur = (long) ind * (long) ind * (long) ind;
                if (g(x - cur) + 1 + r2 == r1) {
                    ++r2;
                    res += cur;
                    x -= cur;
                } else {
                    x = cur - 1;
                }
            }
            out.printLine(r1 + " " + res);
        }

        long f(int n) {
            if (D[n] != -1) return D[n];
            long res = D[n - 1];
            long val = n, t = n - 1;
            val = val * val * val;
            --val;
            val -= t * t * t;
            if (val >= 0) {
                res = Math.max(res, 1 + g(val));
            }
            D[n] = res;
            return res;
        }

        long g(long n) {
            if (n < maxn) {
                if (d[(int) n] != -1) return d[(int) n];
            }
            int pos = getPos(n);
            long res = f(pos);
            res = Math.max(res, 1 + g(n - (long) pos * (long) pos * (long) pos));
            if (n < maxn) {
                d[(int) n] = res;
            }
            return res;
        }

        private int getPos(long n) {
            int l = 0, r = maxn - 1;
            while (r - l > 1) {
                int t = (l + r) / 2;
                long cur = (long) t * (long) t * (long) t;
                if (cur <= n) {
                    l = t;
                } else {
                    r = t;
                }
            }
            return l;
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

        public long nextLong() {
            long sgn = 1;
            int c = readSkipSpace();
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res = res * 10L + (long) (c - '0');
                c = read();
            } while (!isSpace(c));
            res *= sgn;
            return res;
        }

    }
}