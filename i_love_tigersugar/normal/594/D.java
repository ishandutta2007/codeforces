import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeMap;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        private static final int MAX = 1000100;
        private static final int MOD = (int) 1e9 + 7;
        InputReader in;
        PrintWriter out;
        public static Comparator<TaskD.Query> compLeft = new Comparator<TaskD.Query>() {
            public int compare(TaskD.Query x, TaskD.Query y) {
                return y.left - x.left;
            }
        };
        TaskD.Query[] queries;
        TreeMap<Integer, Integer>[] primeFactors;
        int[] val;
        int[] lastPos;
        long[] prod;
        long[] prodInv;
        long[] inv;
        int n;
        int q;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            init(in);
            prepare();
            process(out);
        }

        private void init(InputReader in) {
            n = in.nextInt();
            val = IOUtils.readIntArray(in, n, 1);
            q = in.nextInt();
            queries = new TaskD.Query[q];
            for (int i = 0; i < q; i++) queries[i] = new TaskD.Query(in, i);
        }

        private void prepare() {
            int[] primeDiv = NumberTheory.getPrimeDiv(MAX);
            primeFactors = new TreeMap[n + 1];
            for (int i = 1; i <= n; i++) primeFactors[i] = NumberTheory.getPrimeFactorsFast(val[i], primeDiv);

            Arrays.sort(queries, compLeft);

            lastPos = new int[MAX];
            Arrays.fill(lastPos, n + 1);

            inv = new long[MAX + 1];
            for (int i = 1; i <= MAX; i++) inv[i] = NumberTheory.inverse(i, MOD);

            prod = new long[n + 1];
            prodInv = new long[n + 1];
            prod[0] = prodInv[0] = 1;
            for (int i = 1; i <= n; i++) prod[i] = prod[i - 1] * val[i] % MOD;
            for (int i = 1; i <= n; i++) prodInv[i] = NumberTheory.inverse((int) prod[i], MOD);
        }

        private void process(PrintWriter out) {
            TaskD.SegmentTree myit = new TaskD.SegmentTree(n);
            int id = n + 1;
            for (TaskD.Query query : queries) {
                while (id > query.left) {
                    id--;
                    for (int prime : primeFactors[id].keySet()) {
                        myit.update(id, lastPos[prime] - 1, prime - 1);
                        myit.update(id, lastPos[prime] - 1, inv[prime]);
                        lastPos[prime] = id;
                    }
                }
                long segProd = prod[query.right] * prodInv[query.left - 1] % MOD;
                query.answer = segProd * myit.get(query.right) % MOD;
            }
            Arrays.sort(queries);
            for (TaskD.Query query : queries) out.println(query.answer);
        }

        static class Query implements Comparable<TaskD.Query> {
            int left;
            int right;
            int id;
            long answer;

            public Query(InputReader in, int id) {
                left = in.nextInt();
                right = in.nextInt();
                this.id = id;
                answer = 0;
            }

            public int compareTo(TaskD.Query q) {
                return id - q.id;
            }

        }

        static class SegmentTree {
            long[] lazy;
            int n;

            public SegmentTree(int n) {
                this.n = n;
                lazy = new long[4 * n + 7];
                Arrays.fill(lazy, 1);
            }

            private void update(int i, int l, int r, int u, int v, long c) {
                if (l > v || r < u || l > r || v < u) return;
                if (u <= l && r <= v) {
                    lazy[i] = lazy[i] * c % MOD;
                    return;
                }
                int m = (l + r) / 2;
                update(2 * i, l, m, u, v, c);
                update(2 * i + 1, m + 1, r, u, v, c);
            }

            public void update(int u, int v, long c) {
                update(1, 1, n, u, v, c);
            }

            public long get(int x) {
                int i = 1;
                int l = 1;
                int r = n;
                long res = 1;
                while (true) {
                    res = res * lazy[i] % MOD;
                    if (l == r) return res;
                    int m = (l + r) / 2;
                    if (x > m) {
                        i = 2 * i + 1;
                        l = m + 1;
                    } else {
                        i = 2 * i;
                        r = m;
                    }
                }
            }

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

    static class NumberTheory {
        public static TreeMap<Integer, Integer> getPrimeFactorsFast(int x, int[] primeDiv) {
            TreeMap<Integer, Integer> res = new TreeMap<Integer, Integer>();
            while (x > 1) {
                int prime = primeDiv[x];
                int mul = 0;
                while (x % prime == 0) {
                    mul++;
                    x /= prime;
                }
                res.put(prime, mul);
            }
            return res;
        }

        public static int[] getPrimeDiv(int maxValue) {
            int[] primeDiv = new int[maxValue + 1];
            Arrays.fill(primeDiv, -1);
            for (int i = 2; i <= maxValue; i++)
                if (primeDiv[i] < 0)
                    for (int j = i; j <= maxValue; j += i) primeDiv[j] = i;
            return primeDiv;
        }

        public static long inverse(long x, long mod) {
            long res = 1;
            long mul = x;
            long k = mod - 2;
            while (k > 0) {
                if (k % 2 == 1) res = res * mul % mod;
                mul = mul * mul % mod;
                k >>= 1;
            }
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
}