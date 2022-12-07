import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        FTwoPizzas solver = new FTwoPizzas();
        solver.solve(1, in, out);
        out.close();
    }

    static class FTwoPizzas {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();
            int m = sc.nextInt();

            int mask[] = new int[n];
            for (int i = 0; i < n; ++i) {
                int cnt = sc.nextInt();

                for (int j = 0; j < cnt; ++j) {
                    mask[i] |= (1 << (sc.nextInt() - 1));
                }
            }

            int cnt[] = new int[1 << 9];
            for (int i = 0; i < n; ++i) {
                cnt[mask[i]]++;
            }

            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < (1 << 9); ++j) {
                    if ((j >> i & 1) == 1) {
                        cnt[j] += cnt[j ^ (1 << i)];
                    }
                }
            }

            long cost[] = new long[m];
            int ind[] = new int[1 << 9];
            int pmask[] = new int[m];
            Arrays.fill(ind, -1);
            for (int i = 0; i < m; ++i) {
                cost[i] = sc.nextLong();

                int cmask = 0;
                int ccnt = sc.nextInt();

                for (int j = 0; j < ccnt; ++j) {
                    cmask |= (1 << (sc.nextInt() - 1));
                }

                pmask[i] = cmask;

                if (ind[cmask] == -1)
                    ind[cmask] = i;
                else if (cost[ind[cmask]] > cost[i])
                    ind[cmask] = i;
            }

            int maxCnt = -1;
            int ind1 = 0, ind2 = 0;

            for (int cmask = 0; cmask < (1 << 9); ++cmask) {
                if (ind[cmask] == -1)
                    continue;

                int cind1 = ind[cmask];

                int newInd[] = new int[1 << 9];
                Arrays.fill(newInd, -1);
                for (int i = 0; i < m; ++i) {
                    if (i == cind1)
                        continue;

                    if (newInd[pmask[i]] == -1)
                        newInd[pmask[i]] = i;
                    else if (cost[newInd[pmask[i]]] > cost[i])
                        newInd[pmask[i]] = i;
                }

                for (int i = 0; i < (1 << 9); ++i) {
                    if (newInd[i] == -1)
                        continue;

                    if (cnt[i | cmask] > maxCnt) {
                        maxCnt = cnt[i | cmask];
                        ind1 = cind1;
                        ind2 = newInd[i];
                    } else if (cnt[i | cmask] == maxCnt && cost[ind1] + cost[ind2] > cost[cind1] + cost[newInd[i]]) {
                        ind1 = cind1;
                        ind2 = newInd[i];
                    }
                }
            }

            out.print((ind1 + 1) + " " + (ind2 + 1));
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