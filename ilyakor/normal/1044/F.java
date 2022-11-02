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
import java.util.HashSet;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        int n;
        ArrayList<Integer>[] g;
        int[] tin;
        int[] tout;
        int T;
        LCA lca;
        SegmentTreeAddZeroCount tree;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            int q = in.nextInt();

            g = new ArrayList[n];
            for (int i = 0; i < n; ++i)
                g[i] = new ArrayList<>();
            for (int i = 0; i < n - 1; ++i) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                g[x].add(y);
                g[y].add(x);
            }
            tin = new int[n];
            tout = new int[n];
            T = 0;

            int R = 0;

            dfs(R, -1);

            lca = new LCA(g, R);
            tree = new SegmentTreeAddZeroCount(n);

            HashSet<ii> edges = new HashSet<>();
            for (int it = 0; it < q; ++it) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                if (x > y) {
                    int t = x;
                    x = y;
                    y = t;
                }
                ii edge = new ii(x, y);
                int delta = edges.contains(edge) ? -1 : 1;

                update(x, y, delta);
                int res = tree.zeroCount(0, n - 1);
                out.printLine(res);

                if (edges.contains(edge))
                    edges.remove(edge);
                else
                    edges.add(edge);
            }
        }

        private void update(int x, int y, int delta) {
            int r = lca.lca(x, y);
            if (r == y) {
                int t = x;
                x = y;
                y = t;
            }
            if (r != x) {
                tree.add(0, n - 1, 10);
                tree.add(0, n - 1, delta);
                tree.add(tin[x], tout[x], -delta);
                tree.add(tin[y], tout[y], -delta);
                tree.add(0, n - 1, -10);
                return;
            }
            int down = 0, up = g[x].size();
            while (up - down > 1) {
                int t = (up + down) / 2;
                int ti = t;
                if (g[x].get(ti) == lca.parent[x]) {
                    if (ti == g[x].size() - 1) {
                        up = t;
                        continue;
                    } else {
                        ++ti;
                    }
                }
                if (tin[g[x].get(ti)] > tin[y])
                    up = t;
                else
                    down = t;
            }
            down += 2;
            if (down > g[x].size() - 1) down = g[x].size() - 1;
            while (g[x].get(down) == lca.parent[x] || tin[g[x].get(down)] > tin[y])
                --down;
            int v = g[x].get(down);
            Assert.assertTrue(tin[y] >= tin[v] && tout[y] <= tout[v]);

            tree.add(0, n - 1, 10);
            tree.add(tin[v], tout[v], delta);
            tree.add(tin[y], tout[y], -delta);
            tree.add(0, n - 1, -10);
        }

        private void dfs(int x, int p) {
            tin[x] = T++;
            for (int y : g[x])
                if (y != p) dfs(y, x);
            tout[x] = T - 1;
        }

    }

    static class Assert {
        public static void assertTrue(boolean flag) {
//        if (!flag)
//        while (true);
            if (!flag)
                throw new AssertionError();
        }

    }

    static class SegmentTreeAddZeroCount {
        int[] delta;
        int[] minCnt;
        int[] min;
        int n;

        public SegmentTreeAddZeroCount(int n) {
            this.n = n;
            delta = new int[4 * n];
            minCnt = new int[4 * n];
            min = new int[4 * n];
            buildTree(1, 0, n - 1);
        }

        void buildTree(int node, int left, int right) {
            minCnt[node] = right - left + 1;
            if (left < right) {
                int mid = (left + right) >> 1;
                buildTree(node * 2, left, mid);
                buildTree(node * 2 + 1, mid + 1, right);
            }
        }

        public void add(int a, int b, int value) {
            add(a, b, value, 1, 0, n - 1);
        }

        void add(int a, int b, int value, int node, int left, int right) {
            if (left > b || right < a) {
                return;
            }
            if (left >= a && right <= b) {
                delta[node] += value;
                return;
            }
            int mid = (left + right) >> 1;
            int n0 = node * 2;
            int n1 = node * 2 + 1;
            add(a, b, value, n0, left, mid);
            add(a, b, value, n1, mid + 1, right);

            min[node] = Math.min(min[n0] + delta[n0], min[n1] + delta[n1]);
            minCnt[node] = (min[node] == min[n0] + delta[n0] ? minCnt[n0] : 0) + (min[node] == min[n1] + delta[n1] ? minCnt[n1] : 0);
        }

        public int zeroCount(int a, int b) {
            return zeroCount(a, b, 0, 1, 0, n - 1);
        }

        int zeroCount(int a, int b, int sumAdd, int node, int left, int right) {
            sumAdd += delta[node];
            if (left >= a && right <= b) return min[node] + sumAdd == 0 ? minCnt[node] : 0;
            int mid = (left + right) >> 1;
            int res = 0;
            if (a <= mid)
                res += zeroCount(a, b, sumAdd, node * 2, left, mid);
            if (b > mid)
                res += zeroCount(a, b, sumAdd, node * 2 + 1, mid + 1, right);
            return res;
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

    static class ii implements Comparable<ii> {
        public int first;
        public int second;

        public ii() {
        }

        public ii(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            ii ii = (ii) o;

            if (first != ii.first) return false;
            if (second != ii.second) return false;

            return true;
        }

        public int hashCode() {
            int result = first;
            result = 31 * result + second;
            return result;
        }

        public int compareTo(ii o) {
            if (first != o.first) {
                return first < o.first ? -1 : 1;
            }
            if (second != o.second) {
                return second < o.second ? -1 : 1;
            }
            return 0;
        }


        public String toString() {
            return "{" +
                    "first=" + first +
                    ", second=" + second +
                    '}';
        }

    }
}