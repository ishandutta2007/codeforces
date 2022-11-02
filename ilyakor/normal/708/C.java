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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        int[][] g;
        int[] par;
        int[] subtreeSize;
        int[] best;
        int n;
        int[] up;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            int[][] edges = new int[n - 1][2];
            int[] deg = new int[n];
            for (int i = 0; i < n - 1; ++i) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                edges[i][0] = x;
                edges[i][1] = y;
                ++deg[x];
                ++deg[y];
            }
            g = new int[n][];
            for (int i = 0; i < n; ++i) {
                g[i] = new int[deg[i]];
            }
            Arrays.fill(deg, 0);
            for (int i = 0; i < n - 1; ++i) {
                int x = edges[i][0];
                int y = edges[i][1];
                g[x][deg[x]++] = y;
                g[y][deg[y]++] = x;
            }

            par = new int[n];
            subtreeSize = new int[n];
            best = new int[n];
            dfs(0, -1);
            up = new int[n];
            dfs1(0, -1, 0);
            for (int i = 0; i < n; ++i) {
                boolean ok = ((n - subtreeSize[i]) - up[i]) * 2 <= n;
                for (int x : g[i]) {
                    if (x == par[i]) continue;
                    int s = subtreeSize[x];
                    if (2 * s <= n) continue;
                    int bk = best[x];
                    if (2 * (s - bk) <= n) continue;
                    ok = false;
                    break;
                }
                out.print(ok ? 1 : 0);
                out.print(" ");
            }
            out.printLine();
        }

        private void dfs1(int x, int p, int val) {
            up[x] = val;
            int[] kids = new int[2];
            for (int y : g[x])
                if (y != p)
                    update(kids, best[y]);
            int own = n - subtreeSize[x];
            if (own * 2 <= n) update(kids, own);
            for (int y : g[x]) {
                if (y == p) continue;
                int v = kids[0];
                if (v == best[y]) v = kids[1];
                dfs1(y, x, Math.max(val, v));
            }
        }

        private void dfs(int x, int p) {
            par[x] = p;
            subtreeSize[x] = 1;
            for (int y : g[x]) {
                if (y == p) continue;
                dfs(y, x);
                best[x] = Math.max(best[x], best[y]);
                subtreeSize[x] += subtreeSize[y];
            }
            if (subtreeSize[x] * 2 <= n)
                best[x] = Math.max(best[x], subtreeSize[x]);
        }

        private void update(int[] kid, int s) {
            if (s > kid[0]) {
                kid[1] = kid[0];
                kid[0] = s;
            } else if (s > kid[1]) {
                kid[1] = s;
            }
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