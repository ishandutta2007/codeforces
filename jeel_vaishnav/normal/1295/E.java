import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        EPermutationSeparation solver = new EPermutationSeparation();
        solver.solve(1, in, out);
        out.close();
    }

    static class EPermutationSeparation {
        long[] segTree;
        long[] lazy;

        void handleLazy(int low, int high, int pos) {
            segTree[pos] += lazy[pos];
            if (low != high) {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }

        void updateSegTree(int low, int high, int pos, int l, int r, long val) {
            handleLazy(low, high, pos);

            if (low > r || high < l)
                return;

            if (low >= l && high <= r) {
                lazy[pos] += val;
                handleLazy(low, high, pos);
                return;
            }

            int mid = (low + high) >> 1;
            updateSegTree(low, mid, 2 * pos + 1, l, r, val);
            updateSegTree(mid + 1, high, 2 * pos + 2, l, r, val);
            segTree[pos] = Math.min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
        }

        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();

            int p[] = new int[n];
            int ind[] = new int[n];
            for (int i = 0; i < n; ++i) {
                p[i] = sc.nextInt() - 1;
                ind[p[i]] = i;
            }

            long a[] = new long[n];
            for (int i = 0; i < n; ++i)
                a[i] = sc.nextLong();

            segTree = new long[4 * (n - 1)];
            lazy = new long[4 * (n - 1)];

            for (int i = n - 1; i >= 1; --i) {
                updateSegTree(0, n - 2, 0, 0, i - 1, a[i]);
            }

            long ans = segTree[0];
            for (int i = n - 1; i >= 0; --i) {
                int curInd = ind[i];
                updateSegTree(0, n - 2, 0, 0, curInd - 1, -a[curInd]);
                updateSegTree(0, n - 2, 0, curInd, n - 2, a[curInd]);

                ans = Math.min(ans, segTree[0]);
            }

            out.print(ans);
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

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;

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