import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author @VanHanhPham_skyvn97
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC3 solver = new TaskC3();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC3 {
        private static final int LOG = 18;
        int[][] par;
        int[] high;
        int n;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            par = new int[n + 1][LOG + 1];
            high = new int[n + 1];
            high[0] = -1;
            int bestX = 1;
            int bestY = 1;
            for (int i = 2; i <= n; i++) {
                int par = in.nextInt();
                createNode(i, par);
                int oldX = bestX;
                int oldY = bestY;
                if (dis(oldX, i) > dis(bestX, bestY)) {
                    bestX = oldX;
                    bestY = i;
                }
                if (dis(oldY, i) > dis(bestX, bestY)) {
                    bestX = oldY;
                    bestY = i;
                }
                out.print(dis(bestX, bestY) + " ");
            }
            out.println();
        }

        private void createNode(int child, int node) {
            high[child] = high[node] + 1;
            par[child][0] = node;
            for (int j = 1; j <= LOG; j++)
                par[child][j] = par[par[child][j - 1]][j - 1];
        }

        private int dis(int u, int v) {
            return high[u] + high[v] - 2 * high[LCA(u, v)];
        }

        private int LCA(int u, int v) {
            if (high[u] < high[v]) return (LCA(v, u));
            for (int i = LOG; i >= 0; i--) {
                if (high[par[u][i]] >= high[v]) {
                    u = par[u][i];
                }
            }
            if (u == v) return (u);
            for (int i = LOG; i >= 0; i--) {
                if (par[u][i] != par[v][i]) {
                    u = par[u][i];
                    v = par[v][i];
                }
            }
            return par[u][0];
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String nextString() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

    }
}