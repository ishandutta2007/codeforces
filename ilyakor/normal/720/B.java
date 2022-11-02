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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        ArrayList<TaskB.Edge>[] g;
        TaskB.Edge[] st;
        int[] used;
        DisjointSets comps;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            g = new ArrayList[n];
            for (int i = 0; i < n; ++i)
                g[i] = new ArrayList<>();
            int m = in.nextInt();
            int[] cols = new int[m];
            for (int i = 0; i < m; ++i) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                int c = in.nextInt() - 1;
                g[x].add(new TaskB.Edge(i, y, c));
                g[y].add(new TaskB.Edge(i, x, c));
                cols[i] = c;
            }

            used = new int[n];
            comps = new DisjointSets(m);
            st = new TaskB.Edge[n + 1];
            dfs(0, -1, 0);


            int[] colCnt = new int[m];
            for (int i = 0; i < m; ++i) {
                ++colCnt[cols[i]];
            }

            boolean[] cyc = new boolean[m];
            for (int i = 0; i < m; ++i) {
                if (comps.root(i) != i)
                    cyc[comps.root(i)] = true;
            }

            MaxFlowDinic g = new MaxFlowDinic();
            //MinCostFlow g = new MinCostFlow();
            g.init(2 * m + 2);
            int S = 2 * m, T = 2 * m + 1;
            int need = 0;
            for (int i = 0; i < m; ++i) {
                if (!cyc[i]) continue;
                g.addEdge(S, i, 1);
                ++need;
            }

            for (int i = 0; i < m; ++i) {
                if (colCnt[i] == 0) continue;
                //g.addEdge(i + m, T, 1, 1);
                if (colCnt[i] > 1) {
                    g.addEdge(i + m, T, colCnt[i] - 1);
                }
            }
            for (int i = 0; i < m; ++i) {
                int r = comps.root(i);
                if (!cyc[r]) continue;
                g.addEdge(r, m + cols[i], 1);
            }

            //long cost = g.minCostFlow(S, T)[1];
            // long res = -cost;
            int res = g.maxFlow(S, T) - need;
            for (int i = 0; i < m; ++i)
                if (colCnt[i] > 0) ++res;
            out.printLine(res);


//        ArrayList<Integer>[] a = new ArrayList[2 * m];
//        for (int i = 0; i < a.length; ++i)
//            a[i] = new ArrayList<>();
//        ArrayList<ii> sc = new ArrayList<>();
//        for (int i = 0; i < m; ++i) {
//            if (colCnt[i] > 0)
//                sc.add(new ii(colCnt[i], i));
//        }
//        Collections.sort(sc);
//        Collections.reverse(sc);
//        int[] colMap = new int[m];
//        for (int i = 0; i < sc.size(); ++i)
//            colMap[sc.get(i).second] = i;
//
//        for (int i = 0; i < m; ++i) {
//            int r = comps.root(i);
//            if (!cyc[r]) continue;
//            a[colMap[cols[i]]].add(r);
//        }
//        int[] rmatching = new int[m];
//        MaxMatching1.maxMatching(a, rmatching);
//        int[] matching = new int[m];
//        Arrays.fill(matching, -1);
//        for (int i = 0; i < m; ++i) {
//            if (rmatching[i] != -1)
//                matching[rmatching[i]] = i;
//        }
//        int res = 0;
//        for (int i = 0; i < m; ++i) {
//            if (colCnt[i] == 0) continue;
//            if (colCnt[i] == 1 && matching[colMap[i]] != -1) continue;
//            ++res;
//        }
//        out.printLine(res);
        }

        void dfs(int v, int p, int depth) {
            used[v] = 1;
            for (TaskB.Edge e : g[v]) {
                int to = e.to;
                if (to == p) continue;
                if (used[to] == 2) continue;
                if (used[to] == 1) {
                    for (int i = depth - 1; i >= 0; --i) {
                        if (st[i].to == to) break;
                        comps.unite(e.ind, st[i].ind);
                    }
                } else {
                    st[depth] = e;
                    dfs(to, v, depth + 1);
                }
            }
            used[v] = 2;
        }

        static class Edge {
            int ind;
            int to;
            int c;

            public Edge(int ind, int to, int c) {
                this.ind = ind;
                this.to = to;
                this.c = c;
            }

        }

    }

    static class MaxFlowDinic {
        public ArrayList<MaxFlowDinic.Edge>[] graph;
        int src;
        int dest;
        int[] ptr;
        int[] Q;
        int[] dist;

        public void init(int nodes) {
            graph = new ArrayList[nodes];
            for (int i = 0; i < nodes; i++)
                graph[i] = new ArrayList<MaxFlowDinic.Edge>();
            ptr = new int[nodes];
            Q = new int[nodes];
            dist = new int[nodes];
        }

        public void addEdge(int s, int t, int cap) {
            graph[s].add(new MaxFlowDinic.Edge(s, t, graph[t].size(), cap));
            graph[t].add(new MaxFlowDinic.Edge(t, s, graph[s].size() - 1, 0));
        }

        boolean dinic_bfs() {
            Arrays.fill(dist, -1);
            dist[src] = 0;
            int sizeQ = 0;
            Q[sizeQ++] = src;
            for (int i = 0; i < sizeQ; i++) {
                int u = Q[i];
                for (MaxFlowDinic.Edge e : graph[u]) {
                    if (dist[e.t] < 0 && e.f < e.cap) {
                        dist[e.t] = dist[u] + 1;
                        Q[sizeQ++] = e.t;
                    }
                }
            }
            return dist[dest] >= 0;
        }

        int dinic_dfs(int u, int f) {
            if (u == dest)
                return f;
            for (; ptr[u] < graph[u].size(); ++ptr[u]) {
                MaxFlowDinic.Edge e = graph[u].get(ptr[u]);
                if (dist[e.t] == dist[u] + 1 && e.f < e.cap) {
                    int df = dinic_dfs(e.t, Math.min(f, e.cap - e.f));
                    if (df > 0) {
                        e.f += df;
                        graph[e.t].get(e.rev).f -= df;
                        return df;
                    }
                }
            }
            return 0;
        }

        public int maxFlow(int src, int dest) {
            this.src = src;
            this.dest = dest;
            int flow = 0;
            while (dinic_bfs()) {
                Arrays.fill(ptr, 0);
                while (true) {
                    int df = dinic_dfs(src, Integer.MAX_VALUE);
                    if (df == 0)
                        break;
                    flow += df;
                }
            }
            return flow;
        }

        static public class Edge {
            public int s;
            public int t;
            public int rev;
            public int cap;
            public int f;

            public Edge(int s, int t, int rev, int cap) {
                this.s = s;
                this.t = t;
                this.rev = rev;
                this.cap = cap;
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

    static class DisjointSets {
        int[] p;
        int[] rank;

        public DisjointSets(int size) {
            p = new int[size];
            for (int i = 0; i < size; i++) {
                p[i] = i;
            }
            rank = new int[size];
        }

        public DisjointSets(int[] p, int[] rank) {
            this.p = p;
            this.rank = rank;
        }

        public int root(int x) {
            while (x != p[x])
                x = p[x];
            return x;
        }

        public void unite(int a, int b) {
            a = root(a);
            b = root(b);
            if (a == b)
                return;
            if (rank[a] < rank[b]) {
                p[a] = b;
            } else {
                p[b] = a;
                if (rank[a] == rank[b])
                    ++rank[a];
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
}