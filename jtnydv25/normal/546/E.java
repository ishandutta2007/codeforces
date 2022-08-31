import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
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
        InputReader2 in = new InputReader2(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public static void addEdge(List<TaskE.Edge>[] graph, int s, int t, int cap) {
            graph[s].add(new TaskE.Edge(s, t, graph[t].size(), cap));
            graph[t].add(new TaskE.Edge(t, s, graph[s].size() - 1, 0));
        }

        public static int maxFlow(List<TaskE.Edge>[] graph, int s, int t) {
            int flow = 0;
            int[] q = new int[graph.length];
            while (true) {
                int qt = 0;
                q[qt++] = s;
                TaskE.Edge[] pred = new TaskE.Edge[graph.length];
                for (int qh = 0; qh < qt && pred[t] == null; qh++) {
                    int cur = q[qh];
                    for (TaskE.Edge e : graph[cur]) {
                        if (pred[e.t] == null && e.cap > e.f) {
                            pred[e.t] = e;
                            q[qt++] = e.t;
                        }
                    }
                }
                if (pred[t] == null)
                    break;
                int df = Integer.MAX_VALUE;
                for (int u = t; u != s; u = pred[u].s)
                    df = Math.min(df, pred[u].cap - pred[u].f);
                for (int u = t; u != s; u = pred[u].s) {
                    pred[u].f += df;
                    graph[pred[u].t].get(pred[u].rev).f -= df;
                }
                flow += df;
            }
            return flow;
        }

        public void solve(int testNumber, InputReader2 in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            int[] a = new int[n + 1];
            int[] b = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                a[i] = in.nextInt();
            }
            for (int i = 1; i <= n; i++) {
                b[i] = in.nextInt();
                b[i] -= a[i];
            }
            List<Integer>[] graph = Stream.generate(ArrayList::new).limit(n + 1).toArray(List[]::new);
            for (int i = 1; i <= m; i++) {
                int p = in.nextInt(), q = in.nextInt();
                graph[p].add(q);
                graph[q].add(p);
            }
            List<TaskE.Edge>[] graph2 = Stream.generate(ArrayList::new).limit(2 * n + 3).toArray(List[]::new);
            int totalsupply = 0, totaldemand = 0;
            for (int i = 1; i <= n; i++) {
                if (b[i] < 0) {
                    //supply node
                    addEdge(graph2, 0, i, -b[i]);
                    totalsupply -= b[i];
                } else {
                    // demand node
                    addEdge(graph2, i, 2 * n + 1, b[i]);
                    totaldemand += b[i];
                }
            }
            for (int i = 1; i <= n; i++) {
                addEdge(graph2, i, i + n, a[i]);
                for (int j : graph[i]) {
                    addEdge(graph2, i + n, j, a[i]);
                }
            }
            int flow = maxFlow(graph2, 0, 2 * n + 1);
            if (flow != totaldemand || totalsupply != totaldemand) {
                out.print("NO");
            } else {
                out.println("YES");
                for (int i = 1; i <= n; i++) {
                    int total = 0;
                    int[] ans = new int[n + 1];
                    for (TaskE.Edge e : graph2[i + n]) {
                        ans[e.t] = e.f;
                        if (e.t != i) total += e.f;
                    }
                    ans[i] = a[i] - total;
                    for (int j = 1; j <= n; j++) out.print(ans[j] + " ");
                    out.println("");
                }
            }

        }

        static class Edge {
            int s;
            int t;
            int rev;
            int cap;
            int f;

            public Edge(int s, int t, int rev, int cap) {
                this.s = s;
                this.t = t;
                this.rev = rev;
                this.cap = cap;
            }

        }

    }

    static class InputReader2 {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader2(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
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

        public void println(String s) {
            writer.println(s);
        }

        public void print(String i) {
            writer.print(i);
        }

    }
}