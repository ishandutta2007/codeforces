
import java.io.*;
import java.util.*;

public class E {
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
			final long mod = 998244353;
			int n = in.nextInt();
			long pw[] = new long[n + 1];
			pw[0] = 1;
			for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * 2 % mod;
			long ans = 0;
			for (int i = 1; i <= n; i++) {
				long x = in.nextInt();
				if (i != n) {
					ans = (ans + (pw[n - i] + (n - i ) * pw[n - i - 1]) % mod * x) % mod;
				} else {
					ans = (ans + x) % mod;
				}
			}
			out.println(ans);
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