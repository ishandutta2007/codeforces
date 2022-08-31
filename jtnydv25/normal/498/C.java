import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.AbstractCollection;
import java.util.stream.Stream;
import java.util.StringTokenizer;
import java.util.Map;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public static Map<Long, Integer> factorize(long n) {
            Map<Long, Integer> factors = new LinkedHashMap<>();
            for (long d = 2; n > 1; ) {
                int power = 0;
                while (n % d == 0) {
                    ++power;
                    n /= d;
                }
                if (power > 0) {
                    factors.put(d, power);
                }
                ++d;
                if (d * d > n) {
                    d = n;
                }
            }
            return factors;
        }

        public static int maxMatching(List<Integer>[] graph) {
            int n = graph.length;
            int[] match = new int[n];
            Arrays.fill(match, -1);
            int[] p = new int[n];
            for (int i = 0; i < n; ++i) {
                if (match[i] == -1) {
                    int v = findPath(graph, match, p, i);
                    while (v != -1) {
                        int pv = p[v];
                        int ppv = match[pv];
                        match[v] = pv;
                        match[pv] = v;
                        v = ppv;
                    }
                }
            }
            return (int) Arrays.stream(match).filter(x -> x != -1).count() / 2;
        }

        static int findPath(List<Integer>[] graph, int[] match, int[] p, int root) {
            Arrays.fill(p, -1);
            int n = graph.length;
            int[] base = IntStream.range(0, n).toArray();

            boolean[] used = new boolean[n];
            int[] q = new int[n];
            int qt = 0;
            used[root] = true;
            q[qt++] = root;
            for (int qh = 0; qh < qt; qh++) {
                int u = q[qh];
                for (int v : graph[u]) {
                    if (base[u] == base[v] || match[u] == v) continue;
                    if (v == root || match[v] != -1 && p[match[v]] != -1) {
                        int curbase = lca(match, base, p, u, v);
                        boolean[] blossom = new boolean[n];
                        markPath(match, base, blossom, p, u, curbase, v);
                        markPath(match, base, blossom, p, v, curbase, u);
                        for (int i = 0; i < n; ++i)
                            if (blossom[base[i]]) {
                                base[i] = curbase;
                                if (!used[i]) {
                                    used[i] = true;
                                    q[qt++] = i;
                                }
                            }
                    } else if (p[v] == -1) {
                        p[v] = u;
                        if (match[v] == -1)
                            return v;
                        v = match[v];
                        used[v] = true;
                        q[qt++] = v;
                    }
                }
            }
            return -1;
        }

        static void markPath(int[] match, int[] base, boolean[] blossom, int[] p, int u, int curbase, int child) {
            for (; base[u] != curbase; u = p[match[u]]) {
                blossom[base[u]] = blossom[base[match[u]]] = true;
                p[u] = child;
                child = match[u];
            }
        }

        static int lca(int[] match, int[] base, int[] p, int a, int b) {
            boolean[] used = new boolean[match.length];
            while (true) {
                a = base[a];
                used[a] = true;
                if (match[a] == -1) break;
                a = p[match[a]];
            }
            while (true) {
                b = base[b];
                if (used[b]) return b;
                b = p[match[b]];
            }
        }

        public void solve(int testNumber, InputReader2 in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            HashSet<Long> primes = new HashSet<>();
            List<HashSet<Integer>> good = new ArrayList<>();
            for (int i = 0; i <= n; i++) good.add(new HashSet<Integer>());
            int[] a = new int[n + 1];
            HashMap[] facta = new HashMap[n + 1];
            for (int i = 1; i <= n; i++) {
                a[i] = in.nextInt();
                facta[i] = (HashMap) factorize((long) a[i]);
                primes.addAll(facta[i].keySet());
            }
            for (int i = 1; i <= m; i++) {
                int p = in.nextInt(), q = in.nextInt();
                good.get(p).add(q);
                good.get(q).add(p);
            }
            int ans = 0;
            for (Long p : primes) {
                List<Integer> arr = new ArrayList<>();
                for (int i = 1; i <= n; i++) {
                    int k = (int) facta[i].getOrDefault(p, 0);
                    for (int j = 0; j < k; j++) arr.add(i);
                }
                int size = arr.size();
                List<Integer>[] graph = Stream.generate(ArrayList::new).limit(size).toArray(List[]::new);
                for (int i = 0; i < size; i++)
                    for (int j = i + 1; j < size; j++)
                        if (good.get(arr.get(i)).contains(arr.get(j))) {
                            graph[i].add(j);
                            graph[j].add(i);
                        }
                ans += maxMatching(graph);
            }
            out.println(ans);
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

        public void println(long i) {
            writer.println(i);
        }

    }
}