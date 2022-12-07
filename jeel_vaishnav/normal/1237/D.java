import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.TreeMap;
import java.util.InputMismatchException;
import java.io.IOException;
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
        DBalancedPlaylist solver = new DBalancedPlaylist();
        solver.solve(1, in, out);
        out.close();
    }

    static class DBalancedPlaylist {
        int[] segTree;

        int querySegTree(int low, int high, int pos, int l, int r) {
            if (low > r || high < l)
                return -1;
            if (low >= l && high <= r)
                return segTree[pos];

            int mid = (low + high) >> 1;
            int val1 = querySegTree(low, mid, 2 * pos + 1, l, r);
            int val2 = querySegTree(mid + 1, high, 2 * pos + 2, l, r);
            return Math.max(val1, val2);
        }

        void updateSegTree(int low, int high, int pos, int ind, int val) {
            if (low > ind || high < ind)
                return;

            if (low == high) {
                segTree[pos] = Math.max(segTree[pos], val);
                return;
            }

            int mid = (low + high) >> 1;
            updateSegTree(low, mid, 2 * pos + 1, ind, val);
            updateSegTree(mid + 1, high, 2 * pos + 2, ind, val);
            segTree[pos] = Math.max(segTree[2 * pos + 1], segTree[2 * pos + 2]);
        }

        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();

            TreeMap<Integer, Integer> map = new TreeMap<>();

            int a[] = new int[3 * n];
            for (int i = 0; i < n; ++i) {
                a[i] = sc.nextInt();
                a[n + i] = a[i];
                a[2 * n + i] = a[i];
                map.put(a[i], 1);
            }

            int ptr = 0;
            for (int i : map.keySet())
                map.put(i, ptr++);

            segTree = new int[4 * ptr];
            Arrays.fill(segTree, -1);
            int suffix[] = new int[3 * n];
            Arrays.fill(suffix, Integer.MAX_VALUE);
            for (int i = 0; i < 3 * n; ++i) {
                int reqV = 2 * a[i] + 1;
                if (map.higherKey(reqV - 1) != null) {
                    int sind = map.get(map.higherKey(reqV - 1));
                    int cans = querySegTree(0, ptr - 1, 0, sind, ptr - 1);
                    if (cans != -1)
                        suffix[cans] = Math.min(suffix[cans], i);
                }
                updateSegTree(0, ptr - 1, 0, map.get(a[i]), i);
            }

            for (int i = 3 * n - 2; i >= 0; --i)
                suffix[i] = Math.min(suffix[i + 1], suffix[i]);

            for (int i = 0; i < n; ++i) {
                if (suffix[i] == Integer.MAX_VALUE)
                    out.print("-1 ");
                else
                    out.print((suffix[i] - i) + " ");
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