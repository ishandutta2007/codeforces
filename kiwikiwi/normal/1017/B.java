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
			String a = in.next();
			String b = in.next();
			long c0 = 0;
			long c1 = 0;
			long d0 = 0;
			long d1 = 0;
			for (int i = 0; i < n; i++) {
				if (b.charAt(i) == '1') {
					if (a.charAt(i) == '0') c0 += 1;
					else c1 += 1;
				} else {
					if (a.charAt(i) == '0') d0 += 1;
					else d1 += 1;
				}
			}
			out.println(d0 * d1 + d0 * c1 + d1 * c0);
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