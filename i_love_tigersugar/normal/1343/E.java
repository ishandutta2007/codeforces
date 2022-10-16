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
 * @author Van Hanh Pham <skyvn97> <vanhanh.pham@gmail.com>
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskE {
        private ArrayList<Integer>[] adj;
        int numNode;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            numNode = in.nextInt();
            int numEdge = in.nextInt();
            int start = in.nextInt();
            int mid = in.nextInt();
            int end = in.nextInt();

            int[] weights = IOUtils.readIntArray(in, numEdge, 1);
            Arrays.sort(weights, 1, numEdge + 1);
            long[] sumWeight = new long[numEdge + 1];
            sumWeight[0] = 0;
            for (int i = 1; i <= numEdge; i++) sumWeight[i] = sumWeight[i - 1] + weights[i];

            adj = new ArrayList[numNode + 1];
            for (int i = 1; i <= numNode; i++) adj[i] = new ArrayList<Integer>();
            for (int i = 0; i < numEdge; i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                adj[u].add(v);
                adj[v].add(u);
            }

            int[] distStart = bfs(start);
            int[] distMid = bfs(mid);
            int[] distEnd = bfs(end);

            long result = Others.LONG_INFINITY;
            for (int i = 1; i <= numNode; i++) {
                int once = distStart[i] + distEnd[i];
                int twice = distMid[i];
                if (once + twice > numEdge) continue;
                result = Math.min(result, sumWeight[once + twice] + sumWeight[twice]);
            }
            out.println(result);
        }

        private int[] bfs(int start) {
            int[] dist = new int[numNode + 1];
            Arrays.fill(dist, -1);

            Queue<Integer> queue = new LinkedList<Integer>();
            dist[start] = 0;
            queue.add(start);

            while (!queue.isEmpty()) {
                int u = queue.remove();
                for (int v : adj[u])
                    if (dist[v] < 0) {
                        dist[v] = dist[u] + 1;
                        queue.add(v);
                    }
            }

            return dist;
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

        public String next() {
            return nextString();
        }

        public int nextInt() {
            return Integer.parseInt(nextString());
        }

    }

    static class Others {
        public static final long LONG_INFINITY = (long) 1e18 + 7;

    }

    static class IOUtils {
        public static int[] readIntArray(InputReader in, int size, int start) {
            int[] res = new int[start + size];
            for (int i = start; i < start + size; i++)
                res[i] = in.nextInt();
            return res;
        }

    }
}