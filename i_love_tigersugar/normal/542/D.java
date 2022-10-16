import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.TreeMap;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.Map.Entry;
import java.io.BufferedReader;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        private long x;
        private ArrayList<Map.Entry<Long, ArrayList<Long>>> prime;
        private ArrayList<Long> divisors;
        private long[][] dp;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            x = in.nextLong();

            divisors = NumberTheory.getDivisors(x);
            TreeMap<Long, ArrayList<Long>> potential =
                    new TreeMap<Long, ArrayList<Long>>();
            for (long div : divisors) {
                TaskD.Pair pw = primeMul(div - 1);
                if (pw.fi < 0) continue;
                if (!potential.containsKey(pw.fi))
                    potential.put(pw.fi, new ArrayList<Long>());
                potential.get(pw.fi).add(div);
            }

            prime = new ArrayList<Map.Entry<Long, ArrayList<Long>>>();
            for (Map.Entry<Long, ArrayList<Long>> entry : potential.entrySet())
                prime.add(entry);

            dp = new long[divisors.size()][prime.size() + 1];
            dp[0][0] = 1;
            for (int curPrime = 0; curPrime < prime.size(); curPrime++)
                for (int curDiv = 0; curDiv < divisors.size(); curDiv++)
                    if (dp[curDiv][curPrime] > 0) {
                        dp[curDiv][curPrime + 1] += dp[curDiv][curPrime];
                        for (long mul : prime.get(curPrime).getValue()) {
                            long newDivVal = Others.bigProduct(divisors.get(curDiv), mul);
                            if (x % newDivVal != 0) continue;
                            int newDiv = findElememt(divisors, newDivVal);
                            if (newDiv >= 0) dp[newDiv][curPrime + 1] += dp[curDiv][curPrime];
                        }
                    }
            out.println(dp[divisors.size() - 1][prime.size()]);
        }

        private TaskD.Pair primeMul(long x) {
            TreeMap<Long, Integer> fact = NumberTheory.getPrimeFactors(x);
            if (fact.size() != 1) return new TaskD.Pair(-1, -1);
            long prime = fact.firstKey();
            return new TaskD.Pair(prime, fact.get(prime));
        }

        private int findElememt(ArrayList<Long> list, long key) {
            int L = 0;
            int R = list.size() - 1;
            while (L <= R) {
                if (R - L <= 2) {
                    for (int i = L; i <= R; i++) if (list.get(i) == key) return i;
                    return -1;
                }
                int M = (L + R) / 2;
                if (list.get(M) == key) return (M);
                if (list.get(M) > key) R = M - 1;
                if (list.get(M) < key) L = M + 1;
            }
            return -1;
        }

        static class Pair {
            long fi;
            int se;

            public Pair(long fi, int se) {
                this.fi = fi;
                this.se = se;
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

        public long nextLong() {
            return Long.parseLong(nextString());
        }

    }

    static class NumberTheory {
        public static TreeMap<Long, Integer> getPrimeFactors(long x) {
            TreeMap<Long, Integer> res = new TreeMap<Long, Integer>();
            for (int i = 2; (long) i * i <= x; i++)
                if (x % i == 0) {
                    int mul = 0;
                    while (x % i == 0) {
                        mul++;
                        x /= i;
                    }
                    res.put((long) i, mul);
                }
            if (x > 1) res.put(x, 1);
            return res;
        }

        public static ArrayList<Long> getDivisors(long x) {
            ArrayList<Long> res = new ArrayList<Long>();
            for (int i = 1; (long) i * i <= x; i++)
                if (x % i == 0) {
                    res.add((long) i);
                    if (x / i != i) res.add(x / i);
                }
            Collections.sort(res);
            return res;
        }

    }

    static class Others {
        public static final long longINF = (long) 1e18 + 7;

        public static long bigProduct(long a, long b) {
            if (a == 0 || b == 0) return (0);
            int sign = 1;
            if (a < 0) return (-bigProduct(-a, b));
            if (b < 0) return (-bigProduct(a, -b));
            return (longINF / a < b ? longINF : a * b);
        }

    }
}