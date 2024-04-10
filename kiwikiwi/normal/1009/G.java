import java.io.*;
import java.util.*;

public class G {
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
			int S = 1 << 6;
			int cnt[] = new int[6];
			for (int i = 0; i < n; i++) {
				cnt[(int)(s.charAt(i)) - 97]++;
			}
			int st[] = new int[n];
			int hall[][] = new int[n + 1][S];
			int scnt[] = new int[S];
			Arrays.fill(st, S - 1);
			int m = in.nextInt();
			for (int i = 0; i < m; i++) {
				int pos = in.nextInt() - 1;
				String t = in.next();
				st[pos] = 0;
				for (int j = 0; j < t.length(); j++) {
					st[pos] |= 1 << ((int)(t.charAt(j)) - 97);
				}
			}
			for (int i = n - 1; i >= 0; i--) {
				for (int j = 0; j < S; j++) {
					if ((st[i] & j) != 0) hall[i][j] = hall[i + 1][j] + 1;
					else hall[i][j] = hall[i + 1][j];
				}
			}
			for (int i = 0; i < S; i++) for (int j = 0; j < 6; j++)
					if ((i & (1 << j)) != 0) scnt[i] += cnt[j];
			for (int i = 0; i < S; i++) if (scnt[i] > hall[0][i]) {
					out.println("Impossible");
					return;
				}
			for (int i = 0; i < n; i++) {
				int use = -1;
				for (int j = 0; j < 6; j++)
					if (cnt[j] > 0 && (st[i] & (1 << j)) != 0) {
						boolean val = true;
						for (int k = 0; k < S; k++)
							if (scnt[k] - ((k & (1 << j)) != 0 ? 1 : 0) > hall[i + 1][k]) {
								val = false;
								break;
							}
						if (val) {
							use = j;
							break;
						}
					}
				assert use != -1;
				out.print((char)(97 + use));
				for (int k = 0; k < S; k++) if ((k & (1 << use)) != 0)
						scnt[k] -= 1;
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