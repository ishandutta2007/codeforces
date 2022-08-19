
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

		int arr[] = new int[5];
		int ss[][] = new int[100][3];
		int cc = 0;

		void dfs(int u, int c) {
			if (u == 8) {
				if (c == 3) {
					for (int s = 1; s <= 7; s++) {
						int cnt1 = 0, cnt2 = 0;
						for (int j = 0; j < 3; j++) {
							if ((s & (1 << j)) != 0) cnt2++;
							if ((s & arr[j]) != 0) cnt1++;
						}
						if (cnt1 < cnt2) {
							return;
						}
					}
					for (int j = 0; j < 3; j++) ss[cc][j] = arr[j];
					cc++;
				}
			} else {
				dfs(u + 1, c);
				if (c < 3) {
					arr[c] = u;
					dfs(u, c + 1);
				}
			}
		}

		public void solve(int testNumber, InputReader in, PrintWriter out) {
			int m = 100000;
			long d[] = new long [m + 1];
			for (int i = 1; i <= m; i++) {
				for (int j = i; j <= m; j += i) d[j]++;
			}
			dfs(1, 0);

			int T = in.nextInt();
			for (int i = 0; i < T; i++) {
				int a = in.nextInt();
				int b = in.nextInt();
				int c = in.nextInt();
				long ans = 0;
				long pa = d[a];
				long pb = d[b];
				long pc = d[c];
				long pab = d[gcd(a, b)];
				long pac = d[gcd(a, c)];
				long pbc = d[gcd(b, c)];
				long pabc = d[gcd(gcd(a, b), c)];
				pab -= pabc;
				pac -= pabc;
				pbc -= pabc;
				pa -= pab + pac + pabc;
				pb -= pab + pbc + pabc;
				pc -= pac + pbc + pabc;
				long z[] = new long[8];
				z[1] = pa;
				z[2] = pb;
				z[3] = pab;
				z[4] = pc;
				z[5] = pac;
				z[6] = pbc;
				z[7] = pabc;
				for (int j = 0; j < cc; j++) {
					long w = 1;
					int eq = 0;
					for (int k = 0; k < 3; k++) {
						if (k == 0 || ss[j][k] != ss[j][k - 1]) eq = 1;
						else eq++;
						w = w * (z[ss[j][k]] + eq - 1) / eq;
					}
					ans+=w;
				}
				out.println(ans);
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