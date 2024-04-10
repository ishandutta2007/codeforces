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
			int m = in.nextInt();
			int q = in.nextInt();
			int dp[][] = new int[1 << n][101];
			int olddp[][] = new int[1 << n][101];
			int w[] = new int [n];
			for (int i = 0; i < n; i++)
				w[i] = in.nextInt();
			for (int i = 0; i < m; i++) {
				String s = in.next();
				int key = 0;
				for (int j = 0; j < n; j++) {
					key = key * 2 + (int)(s.charAt(j)) - 48;
				}
				dp[key][0] += 1;
			}
			for (int k = 0; k < n; k++) {
				for (int i = 0; i < (1 << n); i++)
					for (int j = 0; j <= 100; j++) {
						olddp[i][j] = dp[i][j];
						dp[i][j] = 0;
					}
				for (int i = 0; i < (1 << n); i++)
					for (int j = 0; j <= 100; j++) {
						if (j + w[n - 1 - k] <= 100) {
							dp[i][j + w[n - 1 - k]] += olddp[i][j];
						}
						dp[i ^ (1 << k)][j] += olddp[i][j];
					}
			}
			for (int i = 0; i < (1 << n); i++) {
				for (int j = 1; j <= 100; j++) dp[i][j] += dp[i][j - 1];
			}
			for (int i = 0; i < q; i++) {
				String s = in.next();
				int d = in.nextInt();
				int key = 0;
				for (int j = 0; j < n; j++) {
					key = key * 2 + (int)(s.charAt(j)) - 48;
				}
				out.println(dp[key][d]);
			}
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