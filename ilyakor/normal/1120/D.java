import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        int[] cost;
        ArrayList<Integer>[] g;
        long[][] d;
        boolean[] ans;
        boolean[][] visited;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            cost = new int[n];
            for (int i = 0; i < n; ++i)
                cost[i] = in.nextInt();
            g = new ArrayList[n];
            for (int i = 0; i < n; ++i)
                g[i] = new ArrayList<>();
            for (int i = 0; i < n - 1; ++i) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                g[x].add(y);
                g[y].add(x);
            }
            d = new long[2][n];
            for (int i = 0; i < d.length; ++i)
                Arrays.fill(d[i], -1);
            long res1 = dfs(0, 0, -1);

            ans = new boolean[n];
            visited = new boolean[2][n];
            restore(0, 0, -1);
            int res2 = 0;
            for (int i = 0; i < n; ++i) if (ans[i]) ++res2;

            out.printLine(res1 + " " + res2);
            for (int i = 0; i < n; ++i)
                if (ans[i])
                    out.print((i + 1) + " ");
            out.printLine();
        }

        private long dfs(int x, int c, int p) {
            if (d[c][x] != -1)
                return d[c][x];
            if (p != -1 && g[x].size() == 1) {
                d[c][x] = c == 0 ? cost[x] : 0;
                return d[c][x];
            }
            long notTake = 0, worst = 0;
            for (int y : g[x])
                if (y != p) {
                    long val = dfs(y, 0, x);
                    notTake += val;
                    long oval = dfs(y, 1, x);
                    if (val - oval > worst)
                        worst = val - oval;
                }
            long take = cost[x];
            take += notTake - worst;
            if (c == 1) notTake -= worst;
            d[c][x] = Math.min(take, notTake);
            return d[c][x];
        }

        private void restore(int x, int c, int p) {
            if (visited[c][x]) return;
            visited[c][x] = true;
            if (p != -1 && g[x].size() == 1) {
                if (c == 0) ans[x] = true;
                return;
            }
            long notTake = 0, worst = 0, wind = -1;
            for (int y : g[x])
                if (y != p) {
                    long val = d[0][y];
                    notTake += val;
                    long oval = d[1][y];
                    long delta = val - oval;
                    if (delta > worst) {
                        worst = delta;
                        wind = y;
                    } else if (delta == worst) {
                        wind = -2;
                    }
                }
            long take = cost[x];
            take += notTake - worst;
            if (c == 1) notTake -= worst;
            if (take <= notTake) {
                ans[x] = true;
            }
            for (int y : g[x])
                if (y != p) {
                    long val = d[0][y];
                    long oval = d[1][y];
                    long delta = val - oval;
                    if (delta != worst)
                        restore(y, 0, x);
                    else {
                        if (c == 1 || take <= notTake) {
                            restore(y, 1, x);
                            if (wind == -2 || (notTake <= take && c == 0))
                                restore(y, 0, x);
                        } else {
                            restore(y, 0, x);
                        }
                    }
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