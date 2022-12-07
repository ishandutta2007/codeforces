import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
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
        FMaximumWeightSubset solver = new FMaximumWeightSubset();
        solver.solve(1, in, out);
        out.close();
    }

    static class FMaximumWeightSubset {
        long ans;
        int[] a;
        ArrayList<Integer>[] adj;
        long[][] dp;
        int k;

        void dfs(int i, int par) {
            for (int j = 0; j < k; ++j)
                dp[i][j] = Integer.MIN_VALUE;
            dp[i][1] = a[i];
            dp[i][k] = 0;
            for (int j : adj[i]) {
                if (j != par)
                    dfs(j, i);
            }
            for (int j : adj[i]) {
                if (j != par) {
                    for (int l = 1; l <= k; ++l) {
                        long sum = dp[j][l] == Long.MIN_VALUE ? 0 : dp[j][l];
                        int newDist = Math.max(l, k - l);
                        for (int p : adj[i]) {
                            if (p != j && p != par) {
                                sum += dp[p][newDist] != Long.MIN_VALUE ? dp[p][newDist] : 0;
                            }
                        }
                        dp[i][Math.min(k, l + 1)] = Math.max(dp[i][Math.min(k, l + 1)], sum);
                    }
                }
            }
            long sum = a[i];
            for (int j : adj[i]) {
                if (j != par)
                    sum += dp[j][k] != Long.MIN_VALUE ? dp[j][k] : 0;
            }
            dp[i][1] = Math.max(dp[i][1], sum);
            for (int l = k - 1; l >= 1; --l)
                dp[i][l] = Math.max(dp[i][l], dp[i][l + 1]);

            for (int l = 1; l <= k; ++l) {
                ans = Math.max(ans, dp[i][l]);
            }
        }

        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();
            k = sc.nextInt() + 1;

            a = new int[n];
            for (int i = 0; i < n; ++i)
                a[i] = sc.nextInt();

            adj = new ArrayList[n];
            for (int i = 0; i < n; ++i)
                adj[i] = new ArrayList<>();

            dp = new long[n][k + 1];
            for (int i = 0; i < n - 1; ++i) {
                int u = sc.nextInt() - 1;
                int v = sc.nextInt() - 1;
                adj[u].add(v);
                adj[v].add(u);
            }

            ans = 0;

            dfs(0, -1);
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