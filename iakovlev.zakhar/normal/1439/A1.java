import java.io.*;
import java.util.*;

public class D {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public int add(int x, int y) {
		if (x + y >= mod) {
			return x + y - mod;
		}
		return x + y;
	}

	public int subtract(int x, int y) {
		if (x >= y) {
			return x - y;
		}
		return x - y + mod;
	}

	public int multiply(long x, long y) {
		return (int) (x * 1L * y % mod);
	}

	public int divide(long x, long y) {
		return (int) (x * 1L * modInv(y) % mod);
	}

	public class Pair implements Comparable<Pair> {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public String toString() {
			return x + " " + y;
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

	public long[][] pow(long[][] x, long p) {
		if (p == 0) {
			long[][] ans = new long[x.length][x.length];
			for (int i = 0; i < ans.length; i++) {
				ans[i][i] = 1;
			}
			return ans;
		}
		long[][] t = pow(x, p / 2);
		t = multiply(t, t);
		if (p % 2 == 1) {
			t = multiply(t, x);
		}
		return t;
	}

	public long[][] multiply(long[][] a, long[][] b) {
		long[][] ans = new long[a.length][b[0].length];
		for (int i = 0; i < ans.length; i++) {
			for (int j = 0; j < ans[0].length; j++) {
				for (int k = 0; k < b.length; k++) {
					ans[i][j] += a[i][k] * b[k][j];
					ans[i][j] %= mod;
				}
			}
		}
		return ans;
	}

	public long pow(long x, long p) {
		if (p == 0) {
			return 1;
		}
		long t = pow(x, p / 2);
		t *= t;
		t %= mod;
		if (p % 2 == 1) {
			t *= x;
			t %= mod;
		}
		return t;
	}

	public long modInv(long x) {
		return pow(x, mod - 2);
	}

	int mod = 1000000007;

	Random random = new Random(566);
	
	
	
	public void solve() {
		int[][] dp = new int[5][16];
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[0].length; j++) {
				dp[i][j] = -1;
			}
		}
		dp[0][0] = 0;
		for (int i = 0; i < 4; i++) {
			for (int p = 0; p < 4; p++) {
				int x = 15 - (1 << p);
				for (int j = 0; j < dp[0].length; j++) {
					if (dp[i][j] >= 0) {
						dp[i + 1][j ^ x] = p;
					}
				}
			}
		}
		for (int qwerty = in.nextInt(); qwerty > 0; qwerty--) {
			int n = in.nextInt();
			int m = in.nextInt();
			ArrayList<int[]> list = new ArrayList<>();
			boolean[][] a = new boolean[n][m];
			for (int i = 0; i < n; i++) {
				String s = in.next();
				for (int j = 0; j < m; j++) {
					a[i][j] = s.charAt(j) == '1';
				}
			}
			if (m % 2 == 1) {
				for (int i = 0; i < n - 1; i++) {
					if (a[i][m - 1]) {
						int[] cur = {i, m - 1, i, m - 2, i + 1, m - 2};
						a[i][m - 1] = false;
						a[i][m - 2] ^= true;
						a[i + 1][m - 2] ^= true;
						list.add(cur);
					}
				}
				if (a[n - 1][m - 1]) {
					int[] cur = {n - 1, m - 1, n - 1, m - 2, n - 2, m - 2};
					a[n - 1][m - 1] = false;
					a[n - 1][m - 2] ^= true;
					a[n - 2][m - 2] ^= true;
					list.add(cur);
				}
			}
			if (n % 2 == 1) {
				if (a[n - 1][0]) {
					int[] cur = {n - 1, 0, n - 2, 0, n - 2, 1};
					a[n - 1][0] = false;
					a[n - 2][0] ^= true;
					a[n - 2][1] ^= true;
					list.add(cur);
				}
				for (int j = 1; j < m - m % 2; j++) {
					if (a[n - 1][j]) {
						int[] cur = {n - 1, j, n - 2, j, n - 2, j - 1};
						a[n - 1][j] = false;
						a[n - 2][j] ^= true;
						a[n - 2][j - 1] ^= true;
						list.add(cur);
					}
				}
			}
			for (int i = 0; i < n - n % 2; i += 2) {
				for (int j = 0; j < m - m % 2; j += 2) {
					int x = 0;
					if (a[i][j]) {
						x++;
					}
					if (a[i + 1][j]) {
						x += 2;
					}
					if (a[i][j + 1]) {
						x += 4;
					}
					if (a[i + 1][j + 1]) {
						x += 8;
					}
					for (int k = 0; k <= 4; k++) {
						if (dp[k][x] >= 0) {
							while (k > 0) {
								int delta = dp[k][x];
								x ^= 15 - (1 << delta);
								if (delta == 0) {
									int[] cur = {i + 1, j, i, j + 1, i + 1, j + 1};
									list.add(cur);
								} else if (delta == 1) {
									int[] cur = {i, j, i, j + 1, i + 1, j + 1};
									list.add(cur);
								} else if (delta == 2) {
									int[] cur = {i + 1, j, i, j, i + 1, j + 1};
									list.add(cur);
								} else {
									int[] cur = {i + 1, j, i, j + 1, i, j};
									list.add(cur);
								}
								k--;
							}
							break;
						}
					}
				}
			}
			out.println(list.size());
			for (int[] arr : list) {
				for (int j = 0; j < arr.length; j++) {
					out.print(arr[j] + 1 + " ");
				}
				out.println();
			}
		}
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
		long time = System.currentTimeMillis();
		new D().run();
		System.err.println(System.currentTimeMillis() - time);
	}
}