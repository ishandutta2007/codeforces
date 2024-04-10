import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Van Hanh Pham (skyvn97)
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
        private static final int N = 3;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            long res = Others.longINF * 5;
            long cnt[] = IOUtils.readLongArray(in, N, 0);

            for (int i = 0; i < N; i++)
                for (int j = i; j < N; j++) {
                    boolean ok = true;
                    long sum = 0;
                    for (int k = 0; k < N; k++) {
                        if (cnt[k] > 0 && (k < i || k > j)) ok = false;
                        if (cnt[k] > 1) ok = false;
                        if (i <= k && k <= j && cnt[k] == 0) sum++;
                    }
                    if (!ok) continue;
                    res = Math.min(res, sum);
                }

            for (int first = 0; first <= N; first++)
                for (int last = 0; last <= N; last++) {
                    long firstMask = (BitUtils.MASK(N) - 1) ^ (BitUtils.MASK(N - first) - 1);
                    long lastMask = BitUtils.MASK(last) - 1;
                    for (int eatFirst = 0; eatFirst < BitUtils.MASK(N); eatFirst++)
                        for (int eatLast = 0; eatLast < BitUtils.MASK(N); eatLast++) {
                            if (!BitUtils.subMask(eatFirst, firstMask)) continue;
                            if (!BitUtils.subMask(eatLast, lastMask)) continue;
                            long numDays = 0;
                            long sum = 0;
                            boolean ok = true;
                            for (int i = 0; i < N; i++) {
                                long real = cnt[i];
                                if (BitUtils.BIT(eatFirst, i)) real--;
                                if (BitUtils.BIT(eatLast, i)) real--;
                                if (real < 0) ok = false;
                                numDays = Math.max(numDays, real);
                                sum += real;
                            }
                            if (!ok) continue;
                            res = Math.min(res, 3 * numDays - sum
                                    + BitUtils.countBitOne(firstMask ^ eatFirst)
                                    + BitUtils.countBitOne(lastMask ^ eatLast));
                        }
                }
            out.println(res);
        }

    }

    static class IOUtils {
        public static long[] readLongArray(InputReader in, int size, int start) {
            long[] res = new long[start + size];
            for (int i = start; i < start + size; i++)
                res[i] = in.nextLong();
            return res;
        }

    }

    static class Others {
        public static final long longINF = (long) 1e18 + 7;

    }

    static class BitUtils {
        public static long MASK(int x) {
            return 1L << x;
        }

        public static boolean BIT(long mask, int pos) {
            return ((mask >> pos) & 1) == 1;
        }

        public static int countBitOne(long mask) {
            int res = 0;
            while (mask > 0) {
                if ((mask & 1) == 1) res++;
                mask >>= 1;
            }
            return res;
        }

        public static boolean subMask(long small, long big) {
            return ((big & small) == small);
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
}