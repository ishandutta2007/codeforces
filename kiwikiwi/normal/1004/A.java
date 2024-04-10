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
			int d = in.nextInt();
			int a[] = new int[n];
			int c[] = new int[2 * n];
			for (int i = 0; i < n; i++) {
				a[i] = in.nextInt();
				c[2 * i] = a[i] - d;
				c[2 * i + 1] = a[i] + d;
			}
			Arrays.sort(c);
			int ans = 0;
			for (int i = 0; i < 2 * n; i++) {
				if (i != 0 && c[i] == c[i - 1]) continue;
				int mind = d + 1;
				for (int j = 0; j < n; j++)
					mind = Math.min(mind, Math.abs(a[j] - c[i]));
				if (mind == d) {
					ans += 1;
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