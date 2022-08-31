import java.io.*;
import java.util.*;

public class B {
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
			int [] a = new int[n + 2];
			for (int i = 1; i <= n; i++) {
				a[i] = in.nextInt();
			}
			a[0] = 0;
			a[n + 1] = m;
			int [] odd = new int[n + 2];
			for (int i = n; i >= 0 ; i--) {
				odd[i] = odd[i + 1];
				if (i % 2 == 1) odd[i] += a[i + 1] - a[i];
			}
			int lit = 0, ans = 0;
			for (int i = 0; i <= n; i++) {
				if (a[i + 1] != a[i] + 1) {
					ans = Math.max(ans, lit + a[i + 1] - a[i] - 1 + odd[i + 1]);
				}
				//out.println(i + " " + ans);
				if (i % 2 == 0) lit += a[i + 1] - a[i];
			}
			ans = Math.max(ans, lit);
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

	}
}