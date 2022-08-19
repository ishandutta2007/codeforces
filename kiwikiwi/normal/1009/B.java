
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
			String s = in.next();
			int n = s.length();
			int c0 = 0;
			int c1 = 0;
			int c2 = 0;
			int a[] = new int[n];
			for (int i = 0; i < n; i++) {
				if (s.charAt(i) == '1') c1++;
				else if (s.charAt(i) == '2') {
					a[c2] = 2;
					c2++;
				} else {
					if (c2 == 0) c0++;
					else {
						a[c2] = 0;
						c2++;
					}
				}
			}
			for (int i = 0; i < c0; i++) out.print('0');
			for (int i = 0; i < c1; i++) out.print('1');
			for (int i = 0; i < c2; i++) out.print(a[i] == 0 ? '0' : '2');
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