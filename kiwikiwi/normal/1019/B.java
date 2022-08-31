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
		int n = 0;
		int query(int p, InputReader in) {
			p %= n;
			if (p <= 0) p += n;
			System.out.println("? " + p);
			System.out.flush();
			int x = in.nextInt();
			return x;
		}
		public void solve(int testNumber, InputReader in, PrintWriter out) {
			n = in.nextInt();
			if (n % 4 != 0) {
				out.println("! -1");
				return;
			}
			int p = query(0, in);
			int q = query(n / 2, in);
			int l = 0;
			int r = n / 2;
			if (p == q) {
				out.println("! " + (n / 2));
				return;
			}
			while (l + 1 < r) {
				int mid = (l + r) / 2;
				int u = query(mid, in);
				int v = query(mid + n / 2, in);
				if (u == v) {
					out.println("! " + (mid + n / 2));
					return;
				}
				if ((p < q) == (u < v)) {
					l = mid;
				} else {
					r = mid;
				}
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