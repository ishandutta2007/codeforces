import java.util.*;

import java.io.*;
import java.math.BigInteger;

public class D {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Pair implements Comparable<Pair> {
		long x;
		long y;

		public Pair(long x, long y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Pair o) {
			if (x > o.x) {
				return 1;
			}
			if (x < o.x) {
				return -1;
			}
			if (y > o.y) {
				return 1;
			}
			if (y < o.y) {
				return -1;
			}
			return 0;
		}

	}

	public class Fenvik {
		int[] sum;

		public Fenvik(int n) {
			sum = new int[n];
		}

		public void add(int x, int d) {
			for (int i = x; i < sum.length; i = (i | (i + 1))) {
				sum[i] += d;
			}
		}

		public int sum(int r) {
			int ans = 0;
			for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
				ans += sum[i];
			}
			return ans;
		}

		public int sum(int l, int r) {
			if (l > r) {
				return 0;
			}
			return sum(r) - sum(l - 1);
		}
	}

	public long gcd(long x, long y) {
		if (y == 0) {
			return x;
		}
		if (x == 0) {
			return y;
		}
		return gcd(y, x % y);
	}

	public void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int[] a = new int[m];
		for (int i = 0; i < n; i++) {
			a[in.nextInt() - 1]++;
		}
		int[][] dp = new int[6][6];
		boolean[][] can = new boolean[6][6];
		can[0][0] = true;
		for (int i = 0; i < a.length; i++) {
			int[][] dp1 = new int[6][6];
			boolean[][] can1 = new boolean[6][6];
			for (int j = 0; j < 6 && j <= a[i]; j++) {
				int d = (a[i] - j) / 3;
				for (int x = j; x < 6; x++) {
					for (int y = j; y < 6; y++) {
						if (can[x][y]) {
							can1[y - j][a[i] - 3 * d - j] = true;
							dp1[y - j][a[i] - 3 * d - j] = Math.max(dp1[y - j][a[i] - 3 * d - j], d + j + dp[x][y]);
							if (a[i] - 3 * d - j + 3 < 6 && d > 0) {
								can1[y - j][a[i] - 3 * d - j + 3] = true;
								dp1[y - j][a[i] - 3 * d - j + 3] = Math.max(dp1[y - j][a[i] - 3 * d - j + 3], d - 1 + j + dp[x][y]);
							}
						}
					}
				}
			}
			dp = dp1;
			can = can1;
//			for (int j = 0; j < can1.length; j++) {
//				for (int k = 0; k < can1.length; k++) {
//					System.out.print(can[j][k] + " ");
//				}
//				System.out.println();
//			}
//			System.out.println();
//			for (int j = 0; j < can1.length; j++) {
//				for (int k = 0; k < can1.length; k++) {
//					System.out.print(dp[j][k] + " ");
//				}
//				System.out.println();
//			}
//			System.out.println();
		}
		int ans = 0;
		for (int i = 0; i < can.length; i++) {
			for (int j = 0; j < can.length; j++) {
				if (can[i][j]) {
					ans = Math.max(ans, dp[i][j]);
				}
			}
		}
		System.out.println(ans);
	}

	public void run() {
		try {
			if (systemIO) {
				in = new FastScanner(System.in);
				out = new PrintWriter(System.out);
			} else {
				in = new FastScanner(new File("input.txt"));
				out = new PrintWriter(new File("output.txt"));
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
		new D().run();
	}
}