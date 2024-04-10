
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

		int gcd(int a, int b) {
			if (b == 0) return a;
			else return gcd(b, a % b);
		}
		public void solve(int testNumber, InputReader in, PrintWriter out) {
			int n = in.nextInt();
			int m = in.nextInt();
			int e[][] = new int[m][2];
			int t = 0;
			if (m < n - 1) {
				out.println("Impossible");
				return;
			}
			for (int i = 2; i <= n; i++) {
				e[t][0] = 1;
				e[t][1] = i;
				t += 1;
			}
			if (t == m) {
				out.println("Possible");
				for (int i = 0; i < t; i++) {
					out.println(e[i][0] + " " + e[i][1]);
				}
				return;
			}
			for (int i = 2; i <= n; i++) {
				for (int j = i + 1; j <= n; j++) if (gcd(i, j) == 1) {
						e[t][0] = i;
						e[t][1] = j;
						t += 1;
						if (t == m) {
							out.println("Possible");
							for (int k = 0; k < t; k++) {
								out.println(e[k][0] + " " + e[k][1]);
							}
							return;
						}
					}
			}
			out.println("Impossible");
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