import java.io.*;
import java.util.*;

public class D {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		solver.solve(1, in, out);
		out.close();
	}

	static class Task {
		public void solve(int testNumber, InputReader in, PrintWriter out) {
			int n = in.nextInt();
			int mod = 998244353;
			int [][] dp = new int[n + 1][n + 1];
			int [] a = new int [n];
			for (int i = 0; i < n; i++) {
				a[i] = in.nextInt();
			}
			dp[0][0] = 1;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j <= n; j++) {
					dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
					if (j > 0) {
						dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % mod;
					} else {
						if (a[i] > 0 && a[i] <= n)
							dp[i + 1][a[i]] = (dp[i + 1][a[i]] + dp[i][j]) % mod;
					}
				}
			}
			out.println((dp[n][0]+mod-1)%mod);
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

		public long nextLong() {
			return Long.parseLong(next());
		}

	}
}