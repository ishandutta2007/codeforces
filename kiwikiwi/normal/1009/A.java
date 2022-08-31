
import java.io.*;
import java.util.*;

public class A {
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
			int a[] = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = in.nextInt();
			}
			int ans = 0;
			int r = 0;
			for (int i = 0; i < m; i++) {
				int x = in.nextInt();
				while (r < n && a[r] > x) ++r;
				if (r < n) {
					ans += 1;
					++r;
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