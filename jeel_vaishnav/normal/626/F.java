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
 * @author Da Vinchchi
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        FGroupProjects solver = new FGroupProjects();
        solver.solve(1, in, out);
        out.close();
    }

    static class FGroupProjects {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();
            int k = sc.nextInt();

            int a[] = new int[n + 1];
            for (int i = 1; i <= n; ++i)
                a[i] = sc.nextInt();

            Arrays.sort(a, 1, n + 1);

            long mod = (long) 1e9 + 7;

            long dp[][] = new long[n + 1][k + 1];
            long prevDp[][] = new long[n + 1][k + 1];
            prevDp[0][0] = 1;

            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j <= n; ++j) {
                    for (int l = 0; l <= k; ++l)
                        dp[j][l] = 0;
                }

                for (int j = n; j >= 0; --j) {
                    for (int imbalance = 0; imbalance <= k; ++imbalance) {
                        // Group added
                        if (j != 0 && (imbalance - (j - 1) * (a[i] - a[i - 1])) >= 0)
                            dp[j][imbalance] = (dp[j][imbalance] + prevDp[j - 1][imbalance - (j - 1) * (a[i] - a[i - 1])]) % mod;

                        // Group not added
                        if (imbalance - j * (a[i] - a[i - 1]) >= 0)
                            dp[j][imbalance] = (dp[j][imbalance] + prevDp[j][imbalance - j * (a[i] - a[i - 1])] * j % mod) % mod;
                    }
                }
                for (int j = 0; j < n; ++j) {
                    for (int imbalance = 0; imbalance <= k; ++imbalance) {
                        // Group closed
                        dp[j][imbalance] = (dp[j][imbalance] + dp[j + 1][imbalance]) % mod;
                    }
                }

                for (int j = 0; j <= n; ++j) {
                    for (int l = 0; l <= k; ++l)
                        prevDp[j][l] = dp[j][l];
                }
            }

            long ans = 0;
            for (int imbalance = 0; imbalance <= k; ++imbalance)
                ans = (ans + prevDp[0][imbalance]) % mod;

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