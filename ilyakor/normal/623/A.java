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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        int n;
        boolean[][] a;
        int[] u;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            a = new boolean[n][n];
            for (int i = 0; i < n; ++i)
                a[i][i] = true;
            int m = in.nextInt();
            for (int i = 0; i < m; ++i) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                a[x][y] = true;
                a[y][x] = true;
            }
            u = new int[n];
            int[] res = new int[n];
            Arrays.fill(res, -1);
            for (int i = 0; i < n; ++i) {
                if (u[i] != 0) continue;
                int deg = 0;
                for (int j = 0; j < n; ++j)
                    if (!a[i][j]) ++deg;
                if (deg == 0) {
                    res[i] = 1;
                    continue;
                }
                dfs(i, +1);
            }
            for (int i = 0; i < n; ++i)
                if (res[i] == -1)
                    res[i] = u[i] == 1 ? 0 : 2;
            boolean ok = true;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j) {
                    if (a[i][j]) {
                        if (Math.abs(res[i] - res[j]) > 1)
                            ok = false;
                    } else {
                        if (Math.abs(res[i] - res[j]) <= 1)
                            ok = false;
                    }
                }
            if (ok) {
                out.printLine("Yes");
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < n; ++i) {
                    if (res[i] == 0) sb.append('a');
                    else if (res[i] == 1) sb.append('b');
                    else sb.append('c');
                }
                out.printLine(sb.toString());
            } else {
                out.printLine("No");
            }
        }

        private void dfs(int x, int val) {
            u[x] = val;
            for (int i = 0; i < n; ++i)
                if (!a[x][i]) {
                    if (u[i] != 0) continue;
                    dfs(i, -val);
                }
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
}