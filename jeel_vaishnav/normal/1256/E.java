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
        EYetAnotherDivisionIntoTeams solver = new EYetAnotherDivisionIntoTeams();
        solver.solve(1, in, out);
        out.close();
    }

    static class EYetAnotherDivisionIntoTeams {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();

            long a[] = new long[n];
            for (int i = 0; i < n; ++i)
                a[i] = sc.nextLong();

            Pair p[] = new Pair[n];
            for (int i = 0; i < n; ++i)
                p[i] = new Pair(i, a[i]);
            Arrays.sort(p, new Comparator<Pair>() {

                public int compare(Pair o1, Pair o2) {
                    if (o1.val < o2.val)
                        return -1;
                    if (o1.val > o2.val)
                        return 1;
                    return 0;
                }
            });

            long dp[][] = new long[n][3];
            for (int i = 0; i < n; ++i)
                Arrays.fill(dp[i], Long.MAX_VALUE);

            dp[0][0] = -p[0].val;
            for (int i = 1; i < n; ++i) {
                if (dp[i - 1][2] != Long.MAX_VALUE)
                    dp[i][0] = dp[i - 1][2] - p[i].val + p[i - 1].val;
                if (dp[i - 1][0] != Long.MAX_VALUE)
                    dp[i][1] = dp[i - 1][0];
                if (dp[i - 1][2] != Long.MAX_VALUE)
                    dp[i][2] = dp[i - 1][2];
                if (dp[i - 1][1] != Long.MAX_VALUE && dp[i - 1][1] < dp[i][2]) {
                    dp[i][2] = dp[i - 1][1];
                }
            }

            int teams[] = new int[n];
            int members = 3;
            int curTeam = 1;
            for (int i = n - 1; i >= 0; --i) {
                teams[p[i].ind] = curTeam;

                if (i == 0)
                    break;

                if (members == 3) {
                    if (dp[i - 1][1] == dp[i][2])
                        members = 2;
                } else if (members == 2)
                    members = 1;
                else {
                    curTeam++;
                    members = 3;
                }
            }

            out.println((dp[n - 1][2] + p[n - 1].val) + " " + curTeam);
            for (int i = 0; i < n; ++i)
                out.print(teams[i] + " ");
        }

        class Pair {
            int ind;
            long val;

            Pair(int a, long b) {
                ind = a;
                val = b;
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