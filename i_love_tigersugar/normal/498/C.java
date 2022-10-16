import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.util.Set;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.TreeMap;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author @VanHanhPham_skyvn97
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        private int[] val;
        private TreeMap<Integer, Integer>[] primeFactors;
        private int n;
        private boolean[][] isGood;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            int numPair = in.nextInt();
            val = IOUtils.readIntArray(in, n, 1);
            isGood = new boolean[n + 1][n + 1];
            for (int i = 0; i < numPair; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                isGood[x][y] = isGood[y][x] = true;
            }
            primeFactors = new TreeMap[n + 1];
            for (int i = 1; i <= n; i++) primeFactors[i] = NumberTheory.getPrimeFactors(val[i]);
            ArrayList<Integer> allFactors = new ArrayList<Integer>();
            for (int i = 1; i <= n; i++) {
                Set<Integer> set = primeFactors[i].keySet();
                for (int x : set) allFactors.add(x);
            }
            allFactors = ArrayUtils.uniqueElements(allFactors);
            int res = 0;
            for (int factor : allFactors) res += maxStep(factor);
            out.println(res);
        }

        private int maxStep(int factor) {
            DinicFlow df = new DinicFlow(n + 2);
            int src = n + 1;
            int snk = n + 2;
            for (int i = 1; i <= n; i++)
                if (primeFactors[i].containsKey(factor)) {
                    if (i % 2 == 0) df.addEdge(src, i, primeFactors[i].get(factor), 0);
                    if (i % 2 == 1) df.addEdge(i, snk, primeFactors[i].get(factor), 0);
                }
            for (int i = 1; i <= n; i++)
                if (i % 2 == 0)
                    for (int j = 1; j <= n; j++)
                        if (j % 2 == 1 && isGood[i][j])
                            df.addEdge(i, j, Others.intINF, 0);
            return df.maxFlow(src, snk);
        }

    }

    static class NumberTheory {
        public static TreeMap<Integer, Integer> getPrimeFactors(int x) {
            TreeMap<Integer, Integer> res = new TreeMap<Integer, Integer>();
            for (int i = 2; (long) i * i <= x; i++)
                if (x % i == 0) {
                    int mul = 0;
                    while (x % i == 0) {
                        mul++;
                        x /= i;
                    }
                    res.put(i, mul);
                }
            if (x > 1) res.put(x, 1);
            return res;
        }

    }

    static class IOUtils {
        public static int[] readIntArray(InputReader in, int size, int start) {
            int[] res = new int[start + size];
            for (int i = start; i < start + size; i++)
                res[i] = in.nextInt();
            return res;
        }

    }

    static class ArrayUtils {
        public static ArrayList<Integer> uniqueElements(ArrayList<Integer> arr) {
            ArrayList<Integer> tmp = new ArrayList<Integer>();
            for (int x : arr) tmp.add(x);
            Collections.sort(tmp);
            ArrayList<Integer> res = new ArrayList<Integer>();
            for (int x : tmp) if (res.isEmpty() || res.get(res.size() - 1) != x) res.add(x);
            return res;
        }

    }

    static class DinicFlow {
        private int[] dist;
        private int[] head;
        private int[] work;
        private ArrayList<Integer> point;
        private ArrayList<Integer> capa;
        private ArrayList<Integer> flow;
        private ArrayList<Integer> next;
        private int m;
        private int n;

        public DinicFlow(int n) {
            this.n = n;
            this.m = 0;
            dist = new int[n + 1];
            head = new int[n + 1];
            work = new int[n + 1];
            Arrays.fill(head, -1);
            point = new ArrayList<Integer>();
            capa = new ArrayList<Integer>();
            flow = new ArrayList<Integer>();
            next = new ArrayList<Integer>();
        }

        public int addEdge(int u, int v, int c1, int c2) {
            int res = m;
            point.add(v);
            capa.add(c1);
            flow.add(0);
            next.add(head[u]);
            head[u] = m++;
            point.add(u);
            capa.add(c2);
            flow.add(0);
            next.add(head[v]);
            head[v] = m++;
            return res;
        }

        public int maxFlow(int s, int t) {
            int totFlow = 0;
            while (bfs(s, t)) {
                for (int i = 1; i <= n; i++) work[i] = head[i];
                while (true) {
                    int d = dfs(s, t, Others.intINF);
                    if (d <= 0) break;
                    totFlow += d;
                }
            }
            return totFlow;
        }

        private boolean bfs(int s, int t) {
            Queue<Integer> q = new LinkedList<Integer>();
            Arrays.fill(dist, -1);
            dist[s] = 0;
            q.add(s);
            while (!q.isEmpty()) {
                int u = q.remove();
                for (int i = head[u]; i >= 0; i = next.get(i))
                    if (flow.get(i) < capa.get(i) && dist[point.get(i)] < 0) {
                        dist[point.get(i)] = dist[u] + 1;
                        q.add(point.get(i));
                    }
            }
            return dist[t] > 0;
        }

        private int dfs(int s, int t, int f) {
            if (s == t) return f;
            for (; work[s] >= 0; work[s] = next.get(work[s])) {
                int i = work[s];
                if (flow.get(i) < capa.get(i) && dist[point.get(i)] == dist[s] + 1) {
                    int d = dfs(point.get(i), t, Math.min(f, capa.get(i) - flow.get(i)));
                    if (d > 0) {
                        flow.set(i, flow.get(i) + d);
                        flow.set(i ^ 1, flow.get(i ^ 1) - d);
                        return d;
                    }
                }
            }
            return 0;
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String nextString() {
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
            return Integer.parseInt(nextString());
        }

    }

    static class Others {
        public static final int intINF = (int) 1e9 + 7;

    }
}