import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Queue;
import java.util.LinkedList;
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
        TaskC2 solver = new TaskC2();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC2 {
        private ArrayList<Integer>[] adj;
        private int[] high;
        private int n;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            in.nextInt();
            high = new int[n + 1];
            adj = new ArrayList[n + 1];
            for (int i = 1; i <= n; i++) adj[i] = new ArrayList<Integer>();
            for (int i = 0; i < n - 1; i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                adj[u].add(v);
                adj[v].add(u);
            }
            int u = bfs(1);
            u = bfs(u);
            out.println(high[u]);
        }

        private int bfs(int s) {
            Arrays.fill(high, -1);
            Queue<Integer> q = new LinkedList<Integer>();
            high[s] = 0;
            q.add(s);
            int lastNode = s;
            while (!q.isEmpty()) {
                int u = q.remove();
                lastNode = u;
                for (int v : adj[u])
                    if (high[v] < 0) {
                        high[v] = high[u] + 1;
                        q.add(v);
                    }
            }
            return lastNode;
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