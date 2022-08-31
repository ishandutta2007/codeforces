import java.io.*;
import java.util.*;

public class C {
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
			int m = 100000;
			int l[] = new int [m + 1];
			int r[] = new int [m + 1];
			Arrays.fill(l, n + 1);
			Arrays.fill(r, 0);
			int cnt[] = new int [m + 1];
			for (int i = 1; i <= n; i++) {
				int x = in .nextInt();
				l[x] = Math.min(l[x], i);
				r[x] = Math.max(r[x], i);
			}
			for (int i = 1; i <= m; i++) cnt[r[i]]++;
			for (int i = n - 1; i >= 1; i--) cnt[i] += cnt[i + 1];
			long ans = 0;
			for (int i = 1; i <= m; i++) if (l[i] < n)
					ans += cnt[l[i] + 1];
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