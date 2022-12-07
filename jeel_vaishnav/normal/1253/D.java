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
        DHarmoniousGraph solver = new DHarmoniousGraph();
        solver.solve(1, in, out);
        out.close();
    }

    static class DHarmoniousGraph {
        int[] par;
        int[] max;

        int findSet(int i) {
            if (par[i] == i)
                return i;
            par[i] = findSet(par[i]);
            return par[i];
        }

        void union(int i, int j) {
            i = findSet(i);
            j = findSet(j);

            if (i == j)
                return;

            max[i] = Math.max(max[i], max[j]);
            par[j] = i;
        }

        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();
            int m = sc.nextInt();

            par = new int[n];
            max = new int[n];
            for (int i = 0; i < n; ++i) {
                par[i] = i;
                max[i] = i;
            }

            for (int i = 0; i < m; ++i) {
                int u = sc.nextInt() - 1;
                int v = sc.nextInt() - 1;
                union(u, v);
            }

            int ans = 0;
            int ptr = 0;
            while (ptr < n) {
                int curInd = ptr;
                int maxRange = max[findSet(curInd)];
                while (curInd <= maxRange) {
                    if (findSet(curInd) != findSet(ptr)) {
                        union(curInd, ptr);
                        ans++;
                        maxRange = max[findSet(curInd)];
                    }
                    curInd++;
                }
                ptr = curInd;
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