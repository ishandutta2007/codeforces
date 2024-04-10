import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        boolean[] u;
        int[] q;
        int l;
        int r;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int m = in.nextInt();
            int a = in.nextInt();
            int b = in.nextInt();
            int up = 2 * (a + b) + 6;
            int n = up;
            //n = Math.max(n, 100000);
            int[] d = new int[n];
            u = new boolean[n];
            q = new int[n + 10];
            u[0] = true;
            int cur = 1;
            d[0] = cur;
            for (int t = 1; t < n; ++t) {
                if (t >= a && u[t - a]) {
                    u[t] = true;
                    ++cur;
                    l = 0;
                    r = 0;
                    q[l++] = t;
                    while (l > r) {
                        int x = q[r++];
                        if (x + a <= t && !u[x + a]) {
                            ++cur;
                            u[x + a] = true;
                            q[l++] = x + a;
                        }
                        if (x - b >= 0 && !u[x - b]) {
                            ++cur;
                            u[x - b] = true;
                            q[l++] = x - b;
                        }
                    }
                }
                d[t] = cur;
            }

            long res = 0;
            n = up;
            for (int i = 0; i <= m && i < n; ++i)
                res += d[i];
            int g = IntegerUtils.gcd(a, b);
            for (int i = 0; i < g; ++i) {
                int from = (n - i + g - 1) / g;
                int to = (m - i) / g;
                if (to >= from) {
                    res += aritm(d[(from - 1) * g + i] + 1, to - from + 1);
                }
            }
            out.printLine(res);
        }

        private long aritm(int a0, int cnt) {
            long res = a0 * (long) cnt + (cnt * (long) (cnt - 1)) / 2L;
            return res;
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

    static class IntegerUtils {
        public static int gcd(int x, int y) {
            if (y == 0) return x;
            return gcd(y, x % y);
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
}