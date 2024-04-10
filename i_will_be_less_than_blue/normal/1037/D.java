import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.List;
import java.util.Collection;
import java.util.Set;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Queue;
import java.util.LinkedList;
import java.io.InputStream;
import java.util.ArrayList;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.i();
            TaskD.MyGraph g = new TaskD.MyGraph(n + 1);
            for (int i = 0; i < n - 1; i++) {
                int s = in.i();
                int t = in.i();
                g.addEdgeUndirected(s, t);
            }
            int[] path = in.ia(n);
            boolean isCorrect = g.doBfs(path);
            if (isCorrect) {
                out.println("Yes");
            } else {
                out.println("No");
            }
        }

        static class MyGraph extends Graph {
            MyGraph(int s) {
                super(s);
            }

            private boolean doBfs(int[] a) {
                Queue<Integer> q = new LinkedList<>();
                boolean[] vis = new boolean[size + 1];
                q.add(1);
                int ind = 1;
                while (!q.isEmpty()) {
                    int u = q.poll();
                    vis[u] = true;
                    Set<Integer> n = new HashSet<>();
                    for (int e : graph.get(u)) {
                        if (!vis[e]) n.add(e);
                    }
                    for (int i = 0; i < n.size(); i++) {
                        if (!n.contains(a[ind + i])) return false;
                        q.add(a[ind + i]);
                    }
                    ind += n.size();
                }
                return true;
            }

        }

    }

    static class InputReader {
        private InputStream is;
        private byte[] inbuf = new byte[1024];
        private int lenbuf = 0;
        private int ptrbuf = 0;

        public InputReader(InputStream is) {
            this.is = is;
        }

        private int readByte() {
            if (lenbuf == -1) throw new InputMismatchException();
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = is.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) return -1;
            }
            return inbuf[ptrbuf++];
        }

        public int[] ia(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = i();
            return a;
        }

        public int i() {
            int num = 0, b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

    }

    static class Graph {
        public List<List<Integer>> graph;
        public final int size;

        public Graph(int size) {
            this.size = size;
            this.graph = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                this.graph.add(new ArrayList<>());
            }
        }

        public void addEdgeUndirected(int from, int to) {
            this.graph.get(from).add(to);
            this.graph.get(to).add(from);
        }

    }
}