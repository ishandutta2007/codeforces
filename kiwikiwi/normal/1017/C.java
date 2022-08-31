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
			int x = 1;
			while (x * x < n) x += 1;
			int y = (n + x - 1) / x;
			for (int i = (x - 1) * y + 1; i <= n; i++) out.print(i + " ");
			for (int i = x - 2; i >= 0; i--) {
				for (int j = 1; j <= y; j++)
					out.print((i * y + j) + " ");
			}
			out.println();
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