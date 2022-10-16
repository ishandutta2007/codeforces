import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Random;
import java.util.Collections;
import java.io.InputStream;
import java.util.ArrayList;

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
        EgorInputReader in = new EgorInputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        private static final int MOD = (int) 1e9 + 7;
        private static final int MAX = 200200;
        private static final int LOG = 25;
        private long[] frac;
        private long[] finv;
        private TaskE.Cell[] cells;
        private int n;
        private int x;
        private int y;
        private int s;
        private long[] numGoodWays;
        private long[][] numBadWays;
        private long[][] numWays;

        public void solve(int testNumber, EgorInputReader in, PrintWriter out) {
            x = in.nextInt();
            y = in.nextInt();
            n = in.nextInt() + 1;
            s = in.nextInt();
            cells = new TaskE.Cell[n];
            cells[0] = new TaskE.Cell(1, 1);
            for (int i = 1; i < n; i++) cells[i] = new TaskE.Cell(in);
            ArrayUtils.sortArray(cells);

            frac = NumberTheory.getFraction(MAX, MOD);
            finv = NumberTheory.getFractionInverse(frac, MOD);

            TaskE.Cell finish = new TaskE.Cell(x, y);

            numWays = new long[n][n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    numWays[i][j] = countWays(cells[i], cells[j]);

            numGoodWays = new long[n];
            for (int i = n - 1; i >= 0; i--) {
                numGoodWays[i] = countWays(cells[i], finish);
                for (int j = i + 1; j < n; j++)
                    numGoodWays[i] = (numGoodWays[i] - numWays[i][j] * numGoodWays[j] % MOD + MOD) % MOD;
            }

            numBadWays = new long[n][LOG + 1];
            for (int i = n - 1; i >= 0; i--) {
                numBadWays[i][0] = numGoodWays[i];
                for (int j = 1; j <= LOG; j++) {
                    numBadWays[i][j] = countWays(cells[i], finish);
                    for (int k = i + 1; k < n; k++)
                        numBadWays[i][j] = (numBadWays[i][j] - numWays[i][k] * numBadWays[k][j] % MOD + MOD) % MOD;
                    for (int k = 0; k < j; k++) {
                        numBadWays[i][j] -= numBadWays[i][k];
                        if (numBadWays[i][j] < 0) numBadWays[i][j] += MOD;
                    }
                }
            }

            long allWays = countWays(cells[0], finish);
            long res = allWays;

            for (int i = 0; i <= LOG; i++) {
                long tmp = numBadWays[0][i];
                res = (res + (s - 1) * tmp) % MOD;
                s = (s + 1) / 2;
            }
            out.println(res * NumberTheory.inverse(allWays, MOD) % MOD);
        }

        private long comb(int n, int k) {
            if (k > n) return 0;
            return frac[n] * finv[k] % MOD * finv[n - k] % MOD;
        }

        private long countWays(TaskE.Cell a, TaskE.Cell b) {
            if (a.x > b.x || a.y > b.y) return 0;
            return comb(b.x - a.x + b.y - a.y, b.x - a.x);
        }

        static class Cell implements Comparable<TaskE.Cell> {
            public int x;
            public int y;

            public Cell(EgorInputReader in) {
                x = in.nextInt();
                y = in.nextInt();
            }

            public Cell(int x, int y) {
                this.x = x;
                this.y = y;
            }

            public Cell(Random rnd, int m, int n) {
                this.x = (int) Others.randLong(rnd, 1, m);
                this.y = (int) Others.randLong(rnd, 1, n);
                if (x < 1 || x > m) throw new RuntimeException();
                if (y < 1 || y > n) throw new RuntimeException();
            }

            public int compareTo(TaskE.Cell c) {
                return x == c.x ? y - c.y : x - c.x;
            }

        }

    }

    static class NumberTheory {
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

        public static long[] getFraction(int lim, int MOD) {
            long[] frac = new long[lim + 1];
            frac[0] = 1;
            for (int i = 1; i <= lim; i++) frac[i] = frac[i - 1] * i % MOD;
            return frac;
        }

        public static long[] getFractionInverse(long[] frac, int MOD) {
            long[] finv = new long[frac.length];
            for (int i = 0; i < frac.length; i++) finv[i] = inverse(frac[i], MOD);
            return finv;
        }

    }

    static class Others {
        public static long randLong(Random rnd, long l, long r) {
            if (l > r) throw new RuntimeException();
            long tmp = rnd.nextLong() % (r - l + 1);
            return (tmp + r - l + 1) % (r - l + 1) + l;
        }

    }

    static class EgorInputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private EgorInputReader.SpaceCharFilter filter;

        public EgorInputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class ArrayUtils {
        public static <Type extends Comparable<? super Type>> void sortArray(Type[] types) {
            ArrayList<Type> arr = new ArrayList<Type>();
            for (Type t : types) arr.add(t);
            Collections.sort(arr);
            for (int i = 0; i < types.length; i++)
                types[i] = arr.get(i);
        }

    }
}