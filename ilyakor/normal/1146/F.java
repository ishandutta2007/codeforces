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
import java.util.ArrayList;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        static final int mod = 998244353;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] p = new int[n];
            ArrayList<Integer>[] g = new ArrayList[n];
            for (int i = 0; i < n; ++i)
                g[i] = new ArrayList<>();
            for (int i = 1; i < n; ++i) {
                p[i] = in.nextInt() - 1;
                g[p[i]].add(i);
            }
            int[][] d = new int[2][n];
            long[] f = new long[2];
            for (int x = n - 1; x >= 0; --x) {
                if (g[x].isEmpty()) {
                    d[0][x] = 1;
                    d[1][x] = 1;
                    continue;
                }
                if (g[x].size() == 1) {
                    int y = g[x].get(0);
                    d[0][x] = d[0][y];
                    d[1][x] = d[1][y];
                    continue;
                }
                Arrays.fill(f, 0);
                f[0] = 1;
                long prod = 1;
                for (int y : g[x]) {
                    long c = d[0][y], s = d[1][y];
                    prod = (prod * (c + s)) % mod;
                    for (int i = f.length - 1; i >= 0; --i) {
                        f[i] = (c * f[i] + s * (i > 0 ? f[i - 1] : 0)) % mod;
                    }
                }
                d[0][x] = (int) ((prod - f[1] + mod) % mod);
                d[1][x] = (int) (prod - f[0] + mod) % mod;
            }
            out.printLine(d[0][0]);
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
}