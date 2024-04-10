import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.TreeMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Comparator;
import java.util.TreeSet;
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
        C2HeidiAndTheTuringTestMedium solver = new C2HeidiAndTheTuringTestMedium();
        solver.solve(1, in, out);
        out.close();
    }

    static class C2HeidiAndTheTuringTestMedium {
        int[] segTree;
        int[] lazy;

        void handleLazy(int low, int high, int pos) {
            segTree[pos] += lazy[pos];
            if (low != high) {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }

        void updateSegTree(int low, int high, int pos, int l, int r, int val) {
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
            segTree[pos] = Math.max(segTree[2 * pos + 1], segTree[2 * pos + 2]);
        }

        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();
            int l = 2 * sc.nextInt();

            Point p[] = new Point[n];
            TreeMap<Integer, Integer> yMap = new TreeMap<>();
            TreeSet<Integer> xSet = new TreeSet<>();
            for (int i = 0; i < n; ++i) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                p[i] = new Point(x + y, x - y);
                xSet.add(p[i].x);
                yMap.put(p[i].y, 1);
            }

            int ptr = 0;
            for (int y : yMap.keySet())
                yMap.put(y, ptr++);

            segTree = new int[4 * ptr];
            lazy = new int[4 * ptr];

            Arrays.sort(p, new Comparator<Point>() {

                public int compare(Point o1, Point o2) {
                    return o1.x - o2.x;
                }
            });

//        for(Point cp : p)
//            System.out.println("P:" + cp.x + " " + cp.y + " " + l);

            int pl = 0, pr = -1;
            int ans = 0;
            for (int x : xSet) {
                while (p[pl].x < x) {
                    int lind = yMap.get(yMap.higherKey(p[pl].y - l - 1));
                    int rind = yMap.get(yMap.lowerKey(p[pl].y + 1));
                    updateSegTree(0, ptr - 1, 0, lind, rind, -1);
                    pl++;
                }
                while (pr + 1 < n && p[pr + 1].x <= x + l) {
                    pr++;
                    int lind = yMap.get(yMap.higherKey(p[pr].y - l - 1));
                    int rind = yMap.get(yMap.lowerKey(p[pr].y + 1));
                    updateSegTree(0, ptr - 1, 0, lind, rind, 1);
                }

                //out.println(pl + " " + pr + " " + x);

                ans = Math.max(ans, segTree[0]);
            }

            out.print(ans);
        }

        class Point {
            int x;
            int y;

            Point(int a, int b) {
                x = a;
                y = b;
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