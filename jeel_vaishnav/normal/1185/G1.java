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
        G1PlaylistForPolycarpEasyVersion solver = new G1PlaylistForPolycarpEasyVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class G1PlaylistForPolycarpEasyVersion {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();
            int T = sc.nextInt();

            int mod = (int) 1e9 + 7;

            int dp[][][] = new int[1 << n][226][3];

            int t[] = new int[n];
            int g[] = new int[n];
            for (int i = 0; i < n; ++i) {
                t[i] = sc.nextInt();
                g[i] = sc.nextInt() - 1;
                dp[1 << i][t[i]][g[i]] = 1;
            }

            for (int i = 0; i < (1 << n); ++i) {
                for (int j = 0; j < n; ++j) {
                    if ((i >> j & 1) == 1) {
                        int newMask = i ^ (1 << j);

                        for (int k = t[j]; k <= T; ++k) {
                            for (int l = 0; l < 3; ++l) {
                                if (l == g[j])
                                    continue;

                                dp[i][k][g[j]] = (dp[i][k][g[j]] + dp[newMask][k - t[j]][l]) % mod;
                            }
                        }
                    }
                }
            }

            long ans = 0;
            for (int i = 0; i < (1 << n); ++i) {
                for (int j = 0; j < 3; ++j) {
                    ans += dp[i][T][j];
                }
            }

            ans %= mod;
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