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
        F2MicrotransactionsHardVersion solver = new F2MicrotransactionsHardVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class F2MicrotransactionsHardVersion {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();
            int m = sc.nextInt();

            long totcnt = 0;

            long k[] = new long[n];
            for (int i = 0; i < n; ++i) {
                k[i] = sc.nextLong();
                totcnt += k[i];
            }

            Pair p[] = new Pair[m];
            for (int i = 0; i < m; ++i) {
                p[i] = new Pair(sc.nextInt(), sc.nextInt() - 1);
            }

            Arrays.sort(p, new Comparator<Pair>() {

                public int compare(Pair o1, Pair o2) {
                    return o2.day - o1.day;
                }
            });

            long start = 0, end = (long) 1e11, ans = (long) 1e11;
            while (start <= end) {
                long mid = (start + end) >> 1;

                long req[] = new long[n];
                for (int i = 0; i < n; ++i)
                    req[i] = k[i];

                long alr = 0;
                int lastDay = (int) (Math.min((long) 2e5, mid));

                for (int i = 0; i < m; ++i) {
                    if (p[i].day > mid)
                        continue;

                    if (lastDay > p[i].day)
                        lastDay = p[i].day;

                    while (lastDay > 0 && req[p[i].type] > 0) {
                        req[p[i].type]--;
                        lastDay--;
                        alr++;
                    }
                }

                long reqDays = 2 * totcnt - alr;
                if (reqDays <= mid) {
                    ans = mid;
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }

            out.print(ans);
        }

        class Pair {
            int day;
            int type;

            Pair(int a, int b) {
                day = a;
                type = b;
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