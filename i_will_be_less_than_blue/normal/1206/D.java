import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.util.Set;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Queue;
import java.util.LinkedList;
import java.io.InputStream;

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
            long[] a = in.la(n);
            solve(n, a, out);
        }

        private void solve(int n, long[] a, PrintWriter out) {
            List<List<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < 61; i++) {
                adj.add(new ArrayList<>());
                for (int j = 0; j < n; j++) {
                    if ((a[j] & (1L << i)) != 0) {
                        adj.get(i).add(j);
                    }
                }
            }
            for (List<Integer> integers : adj) {
                if (integers.size() >= 3) {
                    out.println(3);
                    return;
                }
            }
            ShortestCycle g = new ShortestCycle(n);
            for (List<Integer> integers : adj) {
                if (integers.size() == 2) {
                    g.addEdgeUndirected(integers.get(0), integers.get(1));
                }
            }
            for (int i = 0; i < n; i++) {
                g.getSmallestCycleLength(i);
            }
            out.println(g.shortestCycle == Cons.max ? -1 : g.shortestCycle);
        }

    }

    static class Graph {
        public List<List<Integer>> graph;
        private final int size;

        Graph(int size) {
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

        public long[] la(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) a[i] = l();
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

        public long l() {
            long num = 0;
            int b;
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

    static class ShortestCycle extends Graph {
        private Set<Integer> S;
        private Queue<Integer> R;
        private int[] parent;
        private int[] dis;
        public int shortestCycle;

        public ShortestCycle(int size) {
            super(size);
            this.S = new HashSet<>();
            this.R = new LinkedList<>();
            this.parent = new int[size];
            this.dis = new int[size];
            this.shortestCycle = Cons.max;
        }

        public void getSmallestCycleLength(int source) {
            if (graph.get(source).size() == 0) return;
            clearEverything();
            parent[source] = -1;
            dis[source] = 0;
            R.add(source);
            int girth = Cons.max;
            while (!R.isEmpty()) {
                int current = R.poll();
                S.add(current);
                for (Integer nei : graph.get(current)) {
                    if (nei != parent[current]) {
                        if (!S.contains(nei)) {
                            parent[nei] = current;
                            dis[nei] = dis[current] + 1;
                            R.add(nei);
                        } else {
                            girth = Math.min(girth, dis[nei] + dis[current] + 1);
                        }
                    }
                }
            }
            this.shortestCycle = Math.min(this.shortestCycle, girth);
        }

        private void clearEverything() {
            this.S.clear();
            this.R.clear();
            Arrays.fill(this.parent, -2);
            Arrays.fill(this.dis, 0);
        }

    }

    static class Cons {
        public static int max = (int) 3e5 + 10;

    }
}