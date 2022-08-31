import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.PriorityQueue;
import java.util.AbstractQueue;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.AbstractCollection;
import java.util.stream.Stream;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author jtnydv25
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        G solver = new G();
        solver.solve(1, in, out);
        out.close();
    }

    static class G {
        public static void addEdge(List<G.Edge>[] graph, int s, int t, int cap, int cost) {
            graph[s].add(new G.Edge(t, cap, cost, graph[t].size()));
            graph[t].add(new G.Edge(s, 0, -cost, graph[s].size() - 1));
        }

        static void bellmanFord(List<G.Edge>[] graph, int s, int[] dist) {
            int n = graph.length;
            Arrays.fill(dist, Integer.MAX_VALUE);
            dist[s] = 0;
            boolean[] inqueue = new boolean[n];
            int[] q = new int[n];
            int qt = 0;
            q[qt++] = s;
            for (int qh = 0; (qh - qt) % n != 0; qh++) {
                int u = q[qh % n];
                inqueue[u] = false;
                for (int i = 0; i < graph[u].size(); i++) {
                    G.Edge e = graph[u].get(i);
                    if (e.cap <= e.f)
                        continue;
                    int v = e.to;
                    int ndist = dist[u] + e.cost;
                    if (dist[v] > ndist) {
                        dist[v] = ndist;
                        if (!inqueue[v]) {
                            inqueue[v] = true;
                            q[qt++ % n] = v;
                        }
                    }
                }
            }
        }

        public static int[] minCostFlow(List<G.Edge>[] graph, int s, int t, int maxf) {
            int n = graph.length;
            int[] prio = new int[n];
            int[] curflow = new int[n];
            int[] prevedge = new int[n];
            int[] prevnode = new int[n];
            int[] pot = new int[n];

            bellmanFord(graph, s, pot); // bellmanFord invocation can be skipped if edges costs are non-negative
            int flow = 0;
            int flowCost = 0;
            while (flow < maxf) {
                PriorityQueue<Long> q = new PriorityQueue<>();
                q.add((long) s);
                Arrays.fill(prio, Integer.MAX_VALUE);
                prio[s] = 0;
                boolean[] finished = new boolean[n];
                curflow[s] = Integer.MAX_VALUE;
                while (!finished[t] && !q.isEmpty()) {
                    long cur = q.remove();
                    int u = (int) (cur & 0xFFFF_FFFFL);
                    int priou = (int) (cur >>> 32);
                    if (priou != prio[u])
                        continue;
                    finished[u] = true;
                    for (int i = 0; i < graph[u].size(); i++) {
                        G.Edge e = graph[u].get(i);
                        if (e.f >= e.cap)
                            continue;
                        int v = e.to;
                        int nprio = prio[u] + e.cost + pot[u] - pot[v];
                        if (prio[v] > nprio) {
                            prio[v] = nprio;
                            q.add(((long) nprio << 32) + v);
                            prevnode[v] = u;
                            prevedge[v] = i;
                            curflow[v] = Math.min(curflow[u], e.cap - e.f);
                        }
                    }
                }
                if (prio[t] == Integer.MAX_VALUE)
                    break;
                for (int i = 0; i < n; i++)
                    if (finished[i])
                        pot[i] += prio[i] - prio[t];
                int df = Math.min(curflow[t], maxf - flow);
                flow += df;
                for (int v = t; v != s; v = prevnode[v]) {
                    G.Edge e = graph[prevnode[v]].get(prevedge[v]);
                    e.f += df;
                    graph[v].get(e.rev).f -= df;
                    flowCost += df * e.cost;
                }
            }
            return new int[]{flow, flowCost};
        }

        int dummy(int s, int n) {
            return n + 1 + s;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            int[] a = new int[n + 2];
            for (int i = 2; i <= n + 1; i++) a[i] = in.nextInt();
            List<G.Edge>[] graph = Stream.generate(ArrayList::new).limit(2 * n + 10).toArray(List[]::new);
            int s = 0, t = n + 2;
            addEdge(graph, 0, 1, 4, 0);
            for (int i = 2; i <= n + 1; i++) {
                addEdge(graph, 1, dummy(i, n), 1, -1);
                addEdge(graph, dummy(i, n), i, 1, 0);
                int cnt0 = 0, cnt1 = 0, cnt2 = 0;
                for (int j = i + 1; j <= n + 1; j++) {
                    if (cnt0 < 3 && (a[j] - a[i]) % 7 == 0) {
                        addEdge(graph, i, dummy(j, n), 1, -1);
                        cnt0++;
                    }
                    if (cnt1 < 3 && a[j] == a[i] - 1) {
                        addEdge(graph, i, dummy(j, n), 1, -1);
                        cnt1++;
                    }
                    if (cnt2 < 3 && a[j] == a[i] + 1) {
                        addEdge(graph, i, dummy(j, n), 1, -1);
                        cnt2++;
                    }
                }
                addEdge(graph, i, n + 2, 1, 0);
            }
            out.println(-minCostFlow(graph, s, t, Integer.MAX_VALUE)[1]);
        }

        static class Edge {
            int to;
            int f;
            int cap;
            int cost;
            int rev;

            Edge(int to, int cap, int cost, int rev) {
                this.to = to;
                this.cap = cap;
                this.cost = cost;
                this.rev = rev;
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

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public int nextInt() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            int res = 0;

            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }

            throw new InputMismatchException();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }
}