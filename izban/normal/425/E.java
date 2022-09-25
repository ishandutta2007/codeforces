import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author izban
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    final int mod = 1000000007;

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();

        int pw[] = new int[n + 1];
        pw[0] = 1;
        for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * 2 % mod;
        int dp[][][] = new int[2][n + 1][k + 1];
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            // j < i
            for (int j = 0; j < i; j++) {
                for (int l = 0; l <= k; l++) {
                    dp[1][j][l] = dp[0][j][l];
                }
            }
            // j == i
            for (int l = 0; l <= Math.min(i, k); l++) {
                // l - 1 -> l
                if (l > 0) {
                    for (int j = 0; j < i; j++) {
                        dp[1][i][l] = (int)((dp[1][i][l] + 1L * dp[0][j][l - 1] * pw[j] % mod * (pw[i - j] - 1 + mod)) % mod);
                    }
                }
                // l -> l
                for (int j = 0; j < i; j++) {
                    dp[1][j][l] = (int)((dp[1][j][l] + 1L * dp[0][j][l] * (pw[j] - 1 + mod)) % mod);
                }
            }
            for (int j = 0; j <= n; j++) {
                for (int l = 0; l <= k; l++) {
                    dp[0][j][l] = dp[1][j][l];
                    dp[1][j][l] = 0;
                }
            }
        }
        int res = 0;
        for (int j = 0; j <= n; j++) res = (res + dp[0][j][k]) % mod;
        out.println(res);
    }
}

class Scanner {
    BufferedReader in;
    StringTokenizer tok;

    public Scanner(InputStream in) {
        this.in = new BufferedReader(new InputStreamReader(in));
        tok = new StringTokenizer("");
    }

    private String tryReadNextLine() {
        try {
            return in.readLine();
        } catch (Exception e) {
            throw new InputMismatchException();
        }
    }

    public String nextToken() {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(next());
        }
        return tok.nextToken();
    }

    public String next() {
        String newLine = tryReadNextLine();
        if (newLine == null)
            throw new InputMismatchException();
        return newLine;
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

}