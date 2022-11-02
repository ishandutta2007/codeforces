import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Stack;
import java.util.ArrayList;
import java.util.List;
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
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        static final int mod = 1000 * 1000 * 1000 + 7;
        ArrayList<TaskG.Edge>[] g;
        boolean[] u;
        ArrayList<Integer> curV;
        int[] ind;
        ArrayList<Integer>[] tree;
        ArrayList<Long>[] tv;
        long[][] up;
        int[][] upV;
        LCA lca;
        int[][][] d;
        long[][] dv;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            g = new ArrayList[n];
            for (int i = 0; i < n; ++i)
                g[i] = new ArrayList<>();
            for (int i = 0; i < m; ++i) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                long val = in.nextLong();
                g[x].add(new TaskG.Edge(x, y, val));
                g[y].add(new TaskG.Edge(y, x, val));
            }

            long[] p2 = new long[63];
            p2[0] = 1;
            for (int i = 1; i < p2.length; ++i)
                p2[i] = (p2[i - 1] * 2L) % mod;

            d = new int[2][n][62];
            dv = new long[n][62];


            u = new boolean[n];
            ind = new int[n];
            long res = 0;
            for (int root = 0; root < n; ++root) {
                if (u[root]) continue;
                curV = new ArrayList<>();
                dfs(root);
                DisjointSets dsu = new DisjointSets(curV.size());
                tree = new ArrayList[curV.size()];
                tv = new ArrayList[curV.size()];
                for (int i = 0; i < curV.size(); ++i) {
                    tree[i] = new ArrayList<>();
                    tv[i] = new ArrayList<>();
                }
                for (int x : curV)
                    for (TaskG.Edge e : g[x]) {
                        int y = e.to;
                        if (dsu.root(ind[x]) == dsu.root(ind[y])) continue;
                        dsu.unite(ind[x], ind[y]);
                        tree[ind[x]].add(ind[y]);
                        tv[ind[x]].add(e.val);
                        tree[ind[y]].add(ind[x]);
                        tv[ind[y]].add(e.val);
                    }
                lca = new LCA(tree, 0);

                up = new long[20][curV.size()];
                upV = new int[20][curV.size()];
                for (int x : curV) {
                    upV[0][ind[x]] = ind[x];
                    for (TaskG.Edge e : g[x]) {
                        int y = e.to;
                        if (ind[y] == lca.parent[ind[x]]) {
                            up[0][ind[x]] = e.val;
                            upV[0][ind[x]] = ind[y];
                        }
                    }
                }
                for (int i = 1; i < up.length; ++i)
                    for (int j = 0; j < up[i].length; ++j) {
                        int y = upV[i - 1][j];
                        long yv = up[i - 1][j];
                        upV[i][j] = upV[i - 1][y];
                        up[i][j] = yv ^ up[i - 1][y];
                    }

                ArrayList<Long> gauss_ = new ArrayList<>();
                for (int x : curV)
                    for (TaskG.Edge e : g[x]) {
                        int y = e.to;
                        long v = getXor(ind[x], ind[y]);
                        v ^= e.val;
                        if (v != 0)
                            gauss_.add(v);
                    }
                long[] gauss = new long[gauss_.size()];
                for (int i = 0; i < gauss.length; ++i)
                    gauss[i] = gauss_.get(i);

                boolean[] nz = new boolean[62];
                int[] basis = new int[62];
                Arrays.fill(basis, -1);
                int dim = 0;
                for (int col = 0; col <= 61; ++col) {
                    long mask = 1L << (long) col;
                    boolean has1 = false;
                    int ind = -1;
                    for (int row = 0; row < gauss.length; ++row) {
                        if ((gauss[row] & mask) == 0L) continue;
                        has1 = true;
                        if (row >= dim) {
                            ind = row;
                            break;
                        }
                    }
                    nz[col] = has1;
                    if (ind == -1) continue;
                    basis[col] = dim;
                    long tmp = gauss[dim];
                    gauss[dim] = gauss[ind];
                    gauss[ind] = tmp;
                    for (int row = 0; row < gauss.length; ++row) {
                        if (row == dim) continue;
                        if ((gauss[row] & mask) == 0L) continue;
                        gauss[row] ^= gauss[dim];
                    }
                    ++dim;
                }

                oddDfs(0);
                for (int i = 0; i <= 61; ++i) {
                    {
                        long cur = dv[0][i];
                        if (nz[i]) {
                            long val = p2[dim - 1] * p2[i];
                            val %= mod;
                            res += val * cur;
                            res %= mod;
                        } else {
                            long val = p2[dim] * p2[i];
                            val %= mod;
                            res += val * cur;
                            res %= mod;
                        }
                    }
                    {
                        long cur = dv[0][i];
                        cur = ((long) curV.size() * (long) (curV.size() - 1)) / 2L - cur;
                        if (nz[i]) {
                            long val = p2[dim - 1] * p2[i];
                            val %= mod;
                            res += val * cur;
                            res %= mod;
                        }
                    }
                }

//            for (int x : curV) for (int y : curV) {
//                if (x >= y) continue; // Count pairs only once.
//                long val = getXor(ind[x], ind[y]);
//                for (int i = 0; i <= 61; ++i) {
//                    long mask = 1L << (long) i;
//                    if ((val & mask) != 0L) {
//                        if (nz[i]) {
//                            res += p2[dim - 1] * p2[i];
//                            res %= mod;
//                        } else {
//                            res += p2[dim] * p2[i];
//                            res %= mod;
//                        }
//                    } else {
//                        if (nz[i]) {
//                            res += p2[dim - 1] * p2[i];
//                            res %= mod;
//                        }
//                    }
//                }
//            }
            }

            out.printLine(res);
        }

        private long getXor(int x, int y) {
            int r = lca.lca(x, y);
            return getRootXor(r, x) ^ getRootXor(r, y);
        }

        private long getRootXor(int r, int x) {
            long res = 0;
            for (int i = up.length - 1; i >= 0; --i) {
                int y = upV[i][x];
                if (lca.depth[y] < lca.depth[r]) continue;
                res ^= up[i][x];
                x = y;
            }
            return res;
        }

        void oddDfs(int x) {
            Arrays.fill(d[0][x], 0);
            Arrays.fill(d[1][x], 0);
            Arrays.fill(dv[x], 0);
            for (int i = 0; i <= 61; ++i)
                d[0][x][i] = 1;
            ArrayList<Integer> neigh = tree[x];
            for (int ind = 0; ind < neigh.size(); ++ind) {
                int y = neigh.get(ind);
                if (y != lca.parent[x]) {
                    long v = tv[x].get(ind);
                    oddDfs(y);
                    for (int i = 0; i <= 61; ++i) {
                        dv[x][i] += dv[y][i];
                        long mask = 1L << (long) i;
                        if ((v & mask) == 0L) {
                            dv[x][i] += (long) d[0][x][i] * (long) d[1][y][i];
                            dv[x][i] += (long) d[1][x][i] * (long) d[0][y][i];
                            d[0][x][i] += d[0][y][i];
                            d[1][x][i] += d[1][y][i];
                        } else {
                            dv[x][i] += (long) d[0][x][i] * (long) d[0][y][i];
                            dv[x][i] += (long) d[1][x][i] * (long) d[1][y][i];
                            d[0][x][i] += d[1][y][i];
                            d[1][x][i] += d[0][y][i];
                        }
                        dv[x][i] %= mod;
                    }
                }
            }
        }

        private void dfs(int x) {
            ind[x] = curV.size();
            curV.add(x);
            u[x] = true;
            for (TaskG.Edge e : g[x]) {
                int y = e.to;
                if (!u[y])
                    dfs(y);
            }
        }

        static class Edge {
            int from;
            int to;
            long val;

            public Edge(int from, int to, long val) {
                this.from = from;
                this.to = to;
                this.val = val;
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

        public long nextLong() {
            long sgn = 1;
            int c = readSkipSpace();
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res = res * 10L + (long) (c - '0');
                c = read();
            } while (!isSpace(c));
            res *= sgn;
            return res;
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

    static class LCA {
        public int[] depth;
        public int[] parent;
        int[] dfs_order;
        int cnt;
        int[] first;
        int[] minPos;
        int n;

        void dfs(List<Integer>[] tree, int u, int d) {
            Stack<Integer> st = new Stack<Integer>();
            depth[u] = d;
            int[] it = new int[tree.length];
            st.push(u);
            while (!st.empty()) {
                u = st.peek();
                d = depth[u];
                dfs_order[cnt++] = u;
                while (true) {
                    if (it[u] >= tree[u].size()) {
                        st.pop();
                        break;
                    }
                    int v = tree[u].get(it[u]);
                    ++it[u];
                    if (depth[v] == -1) {
                        depth[v] = d + 1;
                        parent[v] = u;
                        st.push(v);
                        break;
                    }
                }
            }
        }

        void buildTree(int node, int left, int right) {
            if (left == right) {
                minPos[node] = dfs_order[left];
                return;
            }
            int mid = (left + right) >> 1;
            int n0 = node * 2;
            int n1 = node * 2 + 1;
            buildTree(n0, left, mid);
            buildTree(n1, mid + 1, right);
            minPos[node] = depth[minPos[n0]] < depth[minPos[n1]] ? minPos[n0] : minPos[n1];
        }

        public LCA(List<Integer>[] tree, int root) {
            int nodes = tree.length;
            depth = new int[nodes];
            parent = new int[nodes];
            parent[root] = root;
            Arrays.fill(depth, -1);

            n = 2 * nodes - 1;
            dfs_order = new int[n];
            cnt = 0;
            dfs(tree, root, 0);

            minPos = new int[4 * n];
            buildTree(1, 0, n - 1);

            first = new int[nodes];
            Arrays.fill(first, -1);
            for (int i = 0; i < dfs_order.length; i++) {
                int v = dfs_order[i];
                if (first[v] == -1)
                    first[v] = i;
            }
        }

        public int lca(int a, int b) {
            return minPos(1, 0, n - 1, Math.min(first[a], first[b]), Math.max(first[a], first[b]));
        }

        int minPos(int node, int left, int right, int a, int b) {
            if (left > b || right < a)
                return -1;
            if (left >= a && right <= b)
                return minPos[node];
            int mid = (left + right) >> 1;
            int p1 = minPos(node * 2, left, mid, a, b);
            int p2 = minPos(node * 2 + 1, mid + 1, right, a, b);
            if (p1 == -1)
                return p2;
            if (p2 == -1)
                return p1;
            return depth[p1] < depth[p2] ? p1 : p2;
        }

    }
}