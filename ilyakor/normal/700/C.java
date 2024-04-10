import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Random;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
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
        int n;
        int[] par;
        int[] bl;
        int[] comp;
        int[] size;
        int[] u;
        int cu;
        int s;
        int t;
        ArrayList<TaskC.Edge>[] g;
        int bi;
        int bv;
        boolean[] used;
        int[] tin;
        int[] fup;
        int timer;
        int REM;
        int[] va;
        int[] vb;
        int vas;
        int vbs;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            par = new int[n];
            bl = new int[n];
            comp = new int[n];
            size = new int[n];
            u = new int[n];
            va = new int[n + 10];
            vb = new int[n + 10];
            g = new ArrayList[n];
            for (int i = 0; i < n; ++i)
                g[i] = new ArrayList<>();
            tin = new int[n];
            fup = new int[n];

            int m = in.nextInt();
            s = in.nextInt() - 1;
            t = in.nextInt() - 1;
            DisjointSets dsu = new DisjointSets(n);
            ArrayList<TaskC.Edge> edges = new ArrayList<>();
            ArrayList<Integer> candidates = new ArrayList<>();
            init();
            Random random = new Random(0xdead);
            for (int it = 0; it < m; ++it) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                int w = in.nextInt();
//            int x = random.nextInt(n);
//            int y = random.nextInt(n);
//            int w = random.nextInt(1000 * 1000 * 1000);
                TaskC.Edge e = new TaskC.Edge(x, y, w, it);
                TaskC.Edge ee = new TaskC.Edge(y, x, w, it);
                edges.add(e);
                g[x].add(e);
                g[y].add(ee);
            }
            Collections.shuffle(edges);
            for (int i = 0; i < m; ++i) {
                TaskC.Edge e = edges.get(i);
                dsu.unite(e.x, e.y);

                if (add_edge(e.x, e.y)) {
                    candidates.add(i);
                }

            }
            if (dsu.root(s) != dsu.root(t)) {
                out.printLine(0);
                out.printLine(0);
                return;
            }

            long res = Integer.MAX_VALUE;
            ArrayList<Integer> rv = new ArrayList<>();
            for (int ind : candidates) {
                long cur = edges.get(ind).w;
                cur += (long) calc(edges, edges.get(ind).ind);
                if (cur < res) {
                    res = cur;
                    rv.clear();
                    rv.add(edges.get(ind).ind);
                    if (bi != -1)
                        rv.add(bi);
                }
            }
            if (res == Integer.MAX_VALUE) res = -1;
            out.printLine(res);
            if (res == -1) return;
            out.printLine(rv.size());
            for (int x : rv)
                out.print((x + 1) + " ");
            out.printLine();
        }

        private int calc(ArrayList<TaskC.Edge> edges, int rem) {
            REM = rem;
            bi = -1;
            used = new boolean[n];
            bv = Integer.MAX_VALUE;
            timer = 0;
            if (!dfs(s, -1))
                return 0;
            return bv;
//        init();
//        for (int i = 0; i < edges.size(); i++) {
//            Edge e = edges.get(i);
//            if (e.ind == rem) continue;
//            add_edge(e.x, e.y);
//        }
//        if (get(s) == get(t))
//            return Integer.MAX_VALUE;
//        if (get_comp(s) != get_comp(t))
//            return 0;
//
//        int lca = merge_path(s, t);
//        ArrayList<Integer> path = new ArrayList<>();
//        for (int i = 0; i < vas; i++) {
//            int x = va[i];
//            if (x == lca) break;
//            path.add(x);
//        }
//        ArrayList<Integer> path2 = new ArrayList<>();
//        for (int i = 0; i < vbs; i++) {
//            int x = vb[i];
//            path2.add(x);
//            if (x == lca) break;
//        }
//        Collections.reverse(path2);
//        path.addAll(path2);
//        int res = Integer.MAX_VALUE;
//        for (int i = 1; i < path.size(); i++) {
//            int x = path.get(i - 1);
//            int y = path.get(i);
//            int val = minEdge(x, y, rem);
//            if (val < res) {
//                res = val;
//                bi = mimimi;
//            }
//        }
//        return res;
        }

        private boolean dfs(int v, int p) {
            used[v] = true;
            tin[v] = timer;
            fup[v] = timer;
            ++timer;
            boolean res = false;
            if (v == t) res = true;
            for (TaskC.Edge e : g[v]) {
                int to = e.y;
                if (e.ind == p) continue;
                if (e.ind == REM) continue;
                if (used[to])
                    fup[v] = Math.min(fup[v], tin[to]);
                else {
                    boolean ist = dfs(to, e.ind);
                    if (ist) res = true;
                    fup[v] = Math.min(fup[v], fup[to]);
                    if (fup[to] > tin[v] && ist) {
                        if (e.w < bv) {
                            bv = e.w;
                            bi = e.ind;
                        }
                    }
                }
            }
            return res;
        }

        void init() {
            for (int i = 0; i < n; ++i) {
                bl[i] = comp[i] = i;
                size[i] = 1;
                par[i] = -1;
            }
        }

        int get(int v) {
            if (v == -1) return -1;
            if (bl[v] == v) return v;
            bl[v] = get(bl[v]);
            return bl[v];
        }

        int get_comp(int v) {
            v = get(v);
            if (comp[v] == v) return v;
            comp[v] = get_comp(comp[v]);
            return comp[v];
        }

        void make_root(int v) {
            v = get(v);
            int root = v,
                    child = -1;
            while (v != -1) {
                int p = get(par[v]);
                par[v] = child;
                comp[v] = root;
                child = v;
                v = p;
            }
            size[root] = size[child];
        }

        int merge_path(int a, int b) {
            ++cu;

            vas = 0;
            vbs = 0;
            int lca = -1;
            for (; ; ) {
                if (a != -1) {
                    a = get(a);
                    va[vas++] = a;

                    if (u[a] == cu) {
                        lca = a;
                        break;
                    }
                    u[a] = cu;

                    a = par[a];
                }

                if (b != -1) {
                    b = get(b);
                    vb[vbs++] = b;

                    if (u[b] == cu) {
                        lca = b;
                        break;
                    }
                    u[b] = cu;

                    b = par[b];
                }
            }

            for (int i = 0; i < vas; i++) {
                int x = va[i];
                bl[x] = lca;
                if (x == lca) break;
            }
            for (int i = 0; i < vbs; i++) {
                int x = vb[i];
                bl[x] = lca;
                if (x == lca) break;
            }
            return lca;
        }

        boolean add_edge(int a, int b) {
            a = get(a);
            b = get(b);
            if (a == b) return false;

            int ca = get_comp(a),
                    cb = get_comp(b);
            if (ca != cb) {
                if (size[ca] > size[cb]) {
                    int t = a;
                    a = b;
                    b = t;
                    t = ca;
                    ca = cb;
                    cb = t;
                }
                make_root(a);
                par[a] = comp[a] = b;
                size[cb] += size[a];
            } else
                merge_path(a, b);
            return true;
        }

        static class Edge {
            int x;
            int y;
            int w;
            int ind;

            public Edge(int x, int y, int w, int ind) {
                this.x = x;
                this.y = y;
                this.w = w;
                this.ind = ind;
            }

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