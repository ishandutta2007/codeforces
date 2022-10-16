import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Queue;
import java.io.BufferedReader;
import java.util.LinkedList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Van Hanh Pham (skyvn97)
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
        private int n;
        private int m;
        private ArrayList<TaskE.Edge> edges;
        private Queue<Integer> curNodes;
        private Queue<Integer>[] curEdges;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            m = in.nextInt();
            edges = new ArrayList<TaskE.Edge>();
            for (int i = 0; i < m; i++) edges.add(new TaskE.Edge(in));

            int[] degree = new int[n + 1];
            for (TaskE.Edge e : edges) {
                degree[e.u]++;
                degree[e.v]++;
            }
            ArrayList<Integer> oddNodes = new ArrayList<Integer>();
            for (int i = 1; i <= n; i++) if (degree[i] % 2 != 0) oddNodes.add(i);
            if (oddNodes.size() % 2 != 0) throw new RuntimeException();
            for (int i = 0; i < oddNodes.size() / 2; i++) {
                int u = oddNodes.get(2 * i);
                int v = oddNodes.get(2 * i + 1);
                edges.add(new TaskE.Edge(u, v, true));
            }

            curNodes = new LinkedList<Integer>();
            curEdges = new LinkedList[n + 1];
            for (int i = 1; i <= n; i++) curEdges[i] = new LinkedList<Integer>();
            for (int i = 0; i < edges.size(); i++) {
                int u = edges.get(i).u;
                int v = edges.get(i).v;
                curEdges[u].add(i);
                curEdges[v].add(i);
            }
            for (int i = 1; i <= n; i++) curNodes.add(i);

            while (true) {
                int s = getNode();
                if (s < 0) break;
                buildCycle(s);
            }

            out.println(n - oddNodes.size());
            for (TaskE.Edge e : edges) e.printEdge(out);
        }

        private int getNode() {
            while (!curNodes.isEmpty()) {
                int u = curNodes.element();
                if (getEdge(u) < 0) curNodes.poll();
                else return u;
            }
            return -1;
        }

        private int getEdge(int u) {
            while (!curEdges[u].isEmpty()) {
                int id = curEdges[u].element();
                if (edges.get(id).used) curEdges[u].poll();
                else return id;
            }
            return -1;
        }

        private void buildCycle(int s) {
            int u = s;
            while (true) {
                int id = getEdge(u);
                if (id < 0) throw new RuntimeException();
                edges.get(id).used = true;
                edges.get(id).setDir(u);
                u = edges.get(id).other(u);
                if (u == s) return;
            }
        }

        static class Edge {
            public static final int FORWARD = 0;
            public static final int BACKWARD = 1;
            int u;
            int v;
            int dir;
            boolean fake;
            boolean used;

            public Edge(InputReader in) {
                u = in.nextInt();
                v = in.nextInt();
                fake = false;
                used = false;
                dir = -1;
            }

            public Edge(int u, int v, boolean fake) {
                this.u = u;
                this.v = v;
                this.fake = fake;
                used = false;
                dir = -1;
            }

            public int other(int x) {
                if (u != x && v != x) throw new UnknownError();
                return u ^ v ^ x;
            }

            public void setDir(int from) {
                if (from != u && from != v) throw new UnknownError();
                dir = from == u ? FORWARD : BACKWARD;
            }

            void printEdge(PrintWriter out) {
                if (dir != FORWARD && dir != BACKWARD) throw new UnknownError();
                if (fake) return;
                if (dir == FORWARD) out.printf("%d %d\n", u, v);
                else out.printf("%d %d\n", v, u);
            }

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
}