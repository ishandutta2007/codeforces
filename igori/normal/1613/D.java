import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static int MOD = 998244353;

    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solver solver = new Solver();
        int testCount = in.nextInt();
        for (int i = 1; i <= testCount; i++) {
            solver.solve(i, in, out);
        }
        out.close();
    }

    static class Solver {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            //code starts here

            int n = in.nextInt();
            int a[] = new int[n];
            for (int i = 0; i < n; i++) a[i] = in.nextInt();

            long cnt[] = new long[n + 1];
            long suff[] = new long[n];
            for (int i = n - 1; i >= 0; i--) {
                if (cnt[a[i]] == 0) {
                    cnt[a[i]] = 1;
                } else {
                    cnt[a[i]] = cnt[a[i]] * 2 % MOD;
                }
                suff[i] = cnt[a[i]];
                if (a[i] >= 2 && cnt[a[i] - 2] > 0) {
                    suff[i] = (int)((suff[i] + cnt[a[i]] * (cnt[a[i] - 2] * 2 - 1)) % MOD);
                }
            }

            long dp[] = new long[n + 1];
            long ans = 0;
            if (a[0] == 1) ans = suff[0];
            for (int i = 0; i < n; i++) {
                if (a[i] > 0) {
                    ans = (ans + dp[a[i]] + dp[a[i] - 1]) % MOD;
                    dp[a[i]] = (2 * dp[a[i]] + dp[a[i] - 1]) % MOD;
                } else {
                    ans = (ans + dp[a[i]] + 1) % MOD;
                    dp[a[i]] = (2 * dp[a[i]] + 1) % MOD;
                }
                if (i + 1 < n && a[i + 1] >= 1) {
                    if (a[i + 1] >= 2) {
                        ans = (ans + dp[a[i + 1] - 2] * suff[i + 1]) % MOD;
                    } else {
                        ans = (ans + suff[i + 1]) % MOD;
                    }
                }
            }
            out.println(ans);

            //and ends here
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}