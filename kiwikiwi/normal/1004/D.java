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
		long h1 = 0;
		long h2 = 0;
		long mod1 = 1000000007;
		long mod2 = 1000000009;
		long seed = 13331;
		long pw1[] = new long [1000001];
		long pw2[] = new long [1000001];
		int t = 0;
		int cnt[] = new int [1000001];
		int verify(int r, int c, int r0, int c0) {
			int cc[] = new int[t];
			for (int p = 0; p < r; p++) for (int q = 0; q < c; q++) {
					cc[Math.abs(p - r0) + Math.abs(q - c0)]++;
				}
			for (int i = 0; i < t; i++) if (cc[i] != cnt[i]) {
					return 0;
				}
			return 1;
		}
		int check(int maxc, PrintWriter out) {
			for (int r = 1; r * r <= t; r++)
				if (t % r == 0) {
					int c = t / r;
					if (maxc > r + c - 2 || maxc < (r + c) / 2 - 5) continue;
					for (int c0 = 0; c0 * 2 <= c; c0++)
						for (int r0 = 0; r0 * 2 <= r; r0++) {
							long t1 = (pw1[c0] + pw1[c - c0 - 1] - 1)
							          * (pw1[r0] + pw1[r - r0 - 1] - 1) % mod1;
							long t2 = (pw2[c0] + pw2[c - c0 - 1] - 1)
							          * (pw2[r0] + pw2[r - r0 - 1] - 1) % mod2;
							if (t1 < 0) t1 += mod1;
							if (t2 < 0) t2 += mod2;
							if (h1 == t1 && h2 == t2) {
								if (verify(r, c, r0, c0) == 1) {
									out.println(r + " " + c);
									out.println((r0 + 1) + " " + (c0 + 1));
									return 1;
								}
							}
						}
				}
			return 0;
		}
		public void solve(int testNumber, InputReader in, PrintWriter out) {
			t=in.nextInt();
			int maxc = 0;
			for (int i = 0; i < t; i++) {
				int x = in.nextInt();
				cnt[x]++;
				maxc = Math.max(maxc, x);
			}
			pw1[0] = 1;
			pw2[0] = 1;
			for (int i = 1; i <= t; i++) {
				pw1[i] = (pw1[i - 1] * seed + 1) % mod1;
				pw2[i] = (pw2[i - 1] * seed + 1) % mod2;
			}
			for (int i = t - 1; i >= 0; i--) {
				h1 = (h1 * seed + cnt[i]) % mod1;
				h2 = (h2 * seed + cnt[i]) % mod2;
			}
			if (check(maxc, out) == 0) {
				out.println(-1);
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