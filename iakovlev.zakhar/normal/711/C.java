import java.util.*;
import java.io.*;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		int[] c = new int[n];
		for (int i = 0; i < c.length; i++) {
			c[i] = in.nextInt();
		}
		int[][] p = new int[n][m];
		for (int i = 0; i < p.length; i++) {
			for (int j = 0; j < p[0].length; j++) {
				p[i][j] = in.nextInt();
			}
		}
		long[][][] dp = new long[n][m][n + 2];
		long[][] min = new long[n][n + 2];
		long[][] secondMin = new long[n][n + 2];
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[0].length; j++) {
				for (int j2 = 0; j2 < dp[0][0].length; j2++) {
					dp[i][j][j2] = Long.MAX_VALUE / 2;
				}
			}
		}
		if (c[0] == 0) {
			for (int j = 0; j < dp[0].length; j++) {
				dp[0][j][1] = p[0][j];
			}
		} else {
			dp[0][c[0] - 1][1] = 0;
		}
		for (int i = 0; i < secondMin.length; i++) {
			for (int j = 0; j < secondMin[0].length; j++) {
				min[i][j] = Long.MAX_VALUE / 2;
				secondMin[i][j] = Long.MAX_VALUE / 2;
			}
		}
		for (int i = 0; i < dp[0].length; i++) {
			if (dp[0][i][1] < secondMin[0][1]) {
				if (dp[0][i][1] < min[0][1]) {
					secondMin[0][1] = min[0][1];
					min[0][1] = dp[0][i][1];
				} else {
					secondMin[0][1] = dp[0][i][1];
				}
			}
		}
		for (int i = 1; i < dp.length; i++) {
			if (c[i] == 0) {
				for (int j = 0; j < dp[0].length; j++) {
					for (int k1 = 1; k1 < dp[0][0].length; k1++) {
						dp[i][j][k1] = Math.min(Long.MAX_VALUE / 2, dp[i - 1][j][k1]);
						if (dp[i - 1][j][k1 - 1] == min[i - 1][k1 - 1]) {
							dp[i][j][k1] = Math.min(dp[i][j][k1], secondMin[i - 1][k1 - 1]);
						} else {
							dp[i][j][k1] = Math.min(dp[i][j][k1], min[i - 1][k1 - 1]);
						}
						dp[i][j][k1] = Math.min(Long.MAX_VALUE / 2, dp[i][j][k1] + p[i][j]);
					}
				}
			} else {
				int j = c[i] - 1;
				for (int k1 = 1; k1 < dp[0][0].length; k1++) {
					dp[i][j][k1] = Math.min(Long.MAX_VALUE / 2, dp[i - 1][j][k1]);
					if (dp[i - 1][j][k1 - 1] == min[i - 1][k1 - 1]) {
						dp[i][j][k1] = Math.min(dp[i][j][k1], secondMin[i - 1][k1 - 1]);
					} else {
						dp[i][j][k1] = Math.min(dp[i][j][k1], min[i - 1][k1 - 1]);
					}
				}
			}
			for (int j = 0; j < dp[0][0].length; j++) {
				for (int x = 0; x < dp[0].length; x++) {
					if (dp[i][x][j] < secondMin[i][j]) {
						if (dp[i][x][j] < min[i][j]) {
							secondMin[i][j] = min[i][j];
							min[i][j] = dp[i][x][j];
						} else {
							secondMin[i][j] = dp[i][x][j];
						}
					}
				}
			}
		}
		long min1 = Long.MAX_VALUE / 2;
		for (int i = 0; i < dp[0].length; i++) {
			min1 = Math.min(min1, dp[n - 1][i][k]);
		}
		if (min1 == Long.MAX_VALUE / 2) {
			out.println(-1);
		} else {
			out.print(min1);
		}
	}

	public void run() {
		try {
			if (systemIO) {
				in = new FastScanner(System.in);
				out = new PrintWriter(System.out);
			} else {
				in = new FastScanner(new File("segments.in"));
				out = new PrintWriter(new File("segments.out"));
			}
			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				return null;
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

	}

	// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
	public static void main(String[] arg) {
		new C().run();
	}
}