import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Jeel Vaishnav
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        EAntennaCoverage solver = new EAntennaCoverage();
        solver.solve(1, in, out);
        out.close();
    }

    static class EAntennaCoverage {
        int[] segTree;

        int querySegTree(int low, int high, int pos, int l, int r) {
            if (low > r || high < l)
                return Integer.MAX_VALUE;
            if (low >= l && high <= r)
                return segTree[pos];
            int mid = (low + high) >> 1;
            int val1 = querySegTree(low, mid, 2 * pos + 1, l, r);
            int val2 = querySegTree(mid + 1, high, 2 * pos + 2, l, r);
            return Math.min(val1, val2);
        }

        void updateSegTree(int low, int high, int pos, int ind, int val) {
            if (low > ind || high < ind)
                return;
            if (low == high) {
                segTree[pos] = val;
                return;
            }
            int mid = (low + high) >> 1;
            updateSegTree(low, mid, 2 * pos + 1, ind, val);
            updateSegTree(mid + 1, high, 2 * pos + 2, ind, val);
            segTree[pos] = Math.min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
        }

        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();
            int m = sc.nextInt();

            Pair p[] = new Pair[n];
            for (int i = 0; i < n; ++i)
                p[i] = new Pair(sc.nextInt(), sc.nextInt());

            Arrays.sort(p, new Comparator<Pair>() {

                public int compare(Pair o1, Pair o2) {
                    if (o1.ind < o2.ind)
                        return -1;
                    if (o1.ind > o2.ind)
                        return 1;
                    return 0;
                }
            });

            int dp[] = new int[2 * m];
            segTree = new int[4 * 2 * m];
            int ans = Integer.MAX_VALUE;
            Arrays.fill(segTree, Integer.MAX_VALUE);
            for (int i = 0; i < 2 * m; ++i) {
                dp[i] = Integer.MAX_VALUE;

                for (int j = 0; j < n; ++j) {
                    if (p[j].ind <= i) {
                        int reqDist = i - p[j].ind;
                        int cost = Math.max(0, reqDist - p[j].scope);
                        int lastInd = p[j].ind - reqDist - 1;
                        if (lastInd < 0) {
                            dp[i] = Math.min(dp[i], cost);
                        } else {
                            int val = querySegTree(0, 2 * m - 1, 0, lastInd, i - 1);
                            if (val != Integer.MAX_VALUE)
                                dp[i] = Math.min(dp[i], val + cost);
                        }
                    }
                }

                updateSegTree(0, 2 * m - 1, 0, i, dp[i]);
                if (i >= m - 1)
                    ans = Math.min(ans, dp[i]);
            }

            out.print(ans);
        }

        class Pair {
            int ind;
            int scope;

            Pair(int a, int b) {
                ind = a - 1;
                scope = b;
            }

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();

            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }

                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();

            while (isSpaceChar(c))
                c = read();

            int sgn = 1;

            if (c == '-') {
                sgn = -1;
                c = read();
            }

            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));

            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}