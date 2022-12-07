import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.AbstractCollection;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Jeel Vaishnav
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        FCheapRobot solver = new FCheapRobot();
        solver.solve(1, in, out);
        out.close();
    }

    static class FCheapRobot {
        int[] par;
        HashSet<Integer>[] query;
        long[] ans;
        long cans;

        int findSet(int i) {
            if (par[i] == i)
                return i;
            par[i] = findSet(par[i]);
            return par[i];
        }

        void union(int i, int j) {
            i = findSet(i);
            j = findSet(j);

            if (i == j)
                return;

            if (query[i].size() < query[j].size()) {
                int temp = i;
                i = j;
                j = temp;
            }

            par[j] = i;
            for (int k : query[j]) {
                if (query[i].contains(k)) {
                    query[i].remove(k);
                    ans[k] = cans;
                } else
                    query[i].add(k);
            }
        }

        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int k = sc.nextInt();
            int q = sc.nextInt();

            Edge e[] = new Edge[m];
            ArrayList<Integer> adj[] = new ArrayList[n];
            for (int i = 0; i < n; ++i)
                adj[i] = new ArrayList<>();
            for (int i = 0; i < m; ++i) {
                e[i] = new Edge(sc.nextInt() - 1, sc.nextInt() - 1, sc.nextLong());
                adj[e[i].u].add(i);
                adj[e[i].v].add(i);
            }

            long minCost[] = new long[n];
            Arrays.fill(minCost, Long.MAX_VALUE);
            int vis[] = new int[n];
            PriorityQueue<Pair> queue = new PriorityQueue<>(new Comparator<Pair>() {

                public int compare(Pair o1, Pair o2) {
                    if (o1.cost < o2.cost)
                        return -1;
                    if (o1.cost > o2.cost)
                        return 1;
                    return 0;
                }
            });
            for (int i = 0; i < k; ++i) {
                queue.add(new Pair(i, 0));
                minCost[i] = 0;
            }
            while (!queue.isEmpty()) {
                Pair curP = queue.poll();
                int ind = curP.ind;
                long cost = curP.cost;

                if (vis[ind] == 1)
                    continue;
                vis[ind] = 1;

                for (int edgeInd : adj[ind]) {
                    Edge curE = e[edgeInd];

                    int j = curE.findAnother(ind);
                    long curCost = cost + curE.w;
                    if (curCost < minCost[j]) {
                        minCost[j] = curCost;
                        queue.add(new Pair(j, curCost));
                    }
                }
            }

            for (int i = 0; i < m; ++i) {
                e[i].cost = minCost[e[i].u] + minCost[e[i].v] + e[i].w;
            }
            Arrays.sort(e, new Comparator<Edge>() {

                public int compare(Edge o1, Edge o2) {
                    if (o1.cost < o2.cost)
                        return -1;
                    if (o1.cost > o2.cost)
                        return 1;
                    return 0;
                }
            });

            query = new HashSet[n];
            for (int i = 0; i < n; ++i)
                query[i] = new HashSet<>();
            for (int i = 0; i < q; ++i) {
                int u = sc.nextInt() - 1;
                int v = sc.nextInt() - 1;
                query[u].add(i);
                query[v].add(i);
            }

            par = new int[n];
            for (int i = 0; i < n; ++i)
                par[i] = i;

            ans = new long[q];
            for (int i = 0; i < m; ++i) {
//            out.println((e[i].u + 1) + " " + (e[i].v + 1) + " " + e[i].w + " " + minCost[e[i].u] + " " + minCost[e[i].v] + " " + e[i].cost);
                cans = e[i].cost;
                union(e[i].u, e[i].v);
            }

            for (int i = 0; i < q; ++i)
                out.print(ans[i] + " ");
        }

        class Pair {
            int ind;
            long cost;

            Pair(int a, long b) {
                ind = a;
                cost = b;
            }

        }

        class Edge {
            int u;
            int v;
            long w;
            long cost;

            Edge(int a, int b, long c) {
                u = a;
                v = b;
                w = c;
            }

            int findAnother(int ind) {
                if (ind == u)
                    return v;
                return u;
            }

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();

            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }

                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();

            while (isSpaceChar(c))
                c = read();

            int sgn = 1;

            if (c == '-') {
                sgn = -1;
                c = read();
            }

            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));

            return res * sgn;
        }

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;

            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}