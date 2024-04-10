import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Set;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.HashSet;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
}

class TaskC {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        Set<Integer> ps = new HashSet<>();
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
            int x = a[i];
            for (int j = 2; j * j <= x; ++j) {
                if (x % j != 0) continue;
                ps.add(j);
                while (x % j == 0) x /= j;
            }
            if (x > 1) ps.add(x);
        }

        ArrayList<ii> edges = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            edges.add(new ii(in.nextInt() - 1, in.nextInt() - 1));
        }

        int res = 0;
        for (int p : ps) {
            MaxFlowDinic g = new MaxFlowDinic();
            g.init(n + 2);
            int S = n, T = n + 1;
            for (ii e : edges) {
                if (e.first % 2 == 0)
                    g.addEdge(e.first, e.second, 100000);
                else
                    g.addEdge(e.second, e.first, 100000);
            }
            for (int i = 0; i < n; ++i) {
                int x = a[i];
                int c = 0;
                while (x % p == 0) {
                    ++c;
                    x /= p;
                }
                if (c == 0) continue;
                if (i % 2 == 0) {
                    g.addEdge(S, i, c);
                } else {
                    g.addEdge(i, T, c);
                }
            }
            res += g.maxFlow(S, T);
        }
        out.printLine(res);
    }
}

class InputReader {
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

class OutputWriter {
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

class ii implements Comparable<ii> {
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

}

class MaxFlowDinic {

    static public class Edge {
        int s, t, rev, cap, f;

        public Edge(int s, int t, int rev, int cap) {
            this.s = s;
            this.t = t;
            this.rev = rev;
            this.cap = cap;
        }
    }

    public ArrayList<Edge>[] graph;
    int src, dest;
    int[] ptr, Q, dist;

    public void init(int nodes) {
        graph = new ArrayList[nodes];
        for (int i = 0; i < nodes; i++)
            graph[i] = new ArrayList<Edge>();
        ptr = new int[nodes];
        Q = new int[nodes];
        dist = new int[nodes];
    }

    public void addEdge(int s, int t, int cap) {
        graph[s].add(new Edge(s, t, graph[t].size(), cap));
        graph[t].add(new Edge(t, s, graph[s].size() - 1, 0));
    }

    boolean dinic_bfs() {
        Arrays.fill(dist, -1);
        dist[src] = 0;
        int sizeQ = 0;
        Q[sizeQ++] = src;
        for (int i = 0; i < sizeQ; i++) {
            int u = Q[i];
            for (Edge e : graph[u]) {
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
            Edge e = graph[u].get(ptr[u]);
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

}