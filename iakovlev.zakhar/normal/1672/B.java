import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class B {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	int mod = 1000000007;

	public int mult(int x, int y) {
		return (int) (x * 1L * y % mod);
	}

	public int sum(int x, int y) {
		if (x + y >= mod) {
			return x + y - mod;
		}
		return x + y;
	}

	public int diff(int x, int y) {
		if (x >= y) {
			return x - y;
		}
		return x - y + mod;
	}

	public int div(int x, int y) {
		return mult(x, modInv(y));
	}

	public int[][] mult(int[][] a, int[][] b) {
		int[][] c = new int[a.length][b[0].length];
		for (int i = 0; i < c.length; i++) {
			for (int j = 0; j < c[0].length; j++) {
				for (int k = 0; k < b.length; k++) {
					c[i][j] = sum(c[i][j], mult(a[i][k], b[k][j]));
				}
			}
		}
		return c;
	}

	public int pow(int x, long p) {
		if (p == 0) {
			return 1;
		}
		int ans = pow(x, p / 2);
		ans = mult(ans, ans);
		if ((p & 1) > 0) {
			ans = mult(ans, x);
		}
		return ans;
	}

	public int[][] pow(int[][] x, long p) {
		if (p == 0) {
			int[][] ans = { { 1, 0 }, { 0, 1 } };
			return ans;
		}
		int[][] ans = pow(x, p / 2);
		ans = mult(ans, ans);
		if ((p & 1) > 0) {
			ans = mult(ans, x);
		}
		return ans;
	}

	public int modInv(int x) {
		return pow(x, mod - 2);
	}

	int[] dx = { -1, 0, 1, 0 };
	int[] dy = { 0, -1, 0, 1 };
	int sz = 0;
	int[] ans;
	boolean[][] a;
	boolean[][] b;
	int n;
	boolean[][] used = new boolean[n][n];

	public boolean check(int x, int y, int dir) {
		if (x + dx[dir] < 0 || x + dx[dir] >= n) {
			return false;
		}
		if (y + dy[dir] < 0 || y + dy[dir] >= n) {
			return false;
		}
		boolean flag = true;
		if (dir == 0) {
			flag = b[y][x - 1];
			b[y][x - 1] = false;
		}
		if (dir == 2) {
			flag = b[y][x];
			b[y][x] = false;
		}
		if (dir == 1) {
			flag = a[y - 1][x];
			a[y - 1][x] = false;
		}
		if (dir == 3) {
			flag = a[y][x];
			a[y][x] = false;
		}
		return flag;
	}

	public void dfsRec() {
		Stack<Integer> xst = new Stack<>();
		Stack<Integer> yst = new Stack<>();
		Stack<Integer> prevst = new Stack<>();
		Stack<Integer> dirst = new Stack<>();
		Stack<Boolean> toAns = new Stack<>();
		xst.add(0);
		yst.add(0);
		prevst.add(-1);
		dirst.add(-1);
		toAns.add(false);
		while (!xst.isEmpty()) {
			int x = xst.pop();
			int y = yst.pop();
			int prev = prevst.pop();
			int dir = dirst.pop();
//			System.out.println(x + " " + y + " " + prev + " " + dir + " " + toAns.peek());
			if (toAns.pop()) {
				ans[sz++] = dir ^ 2;
			}
			used[x][y] = true;
			for (dir = dir + 1; dir < 4; dir++) {
				if (dir == (prev ^ 2)) {
					continue;
				}
				if (check(x, y, dir)) {
					ans[sz++] = dir;
					xst.add(x);
					yst.add(y);
					prevst.add(prev);
					dirst.add(dir);
					toAns.add(true);
					if (!used[x + dx[dir]][y + dy[dir]]) {
						xst.add(x + dx[dir]);
						yst.add(y + dy[dir]);
						prevst.add(dir);
						dirst.add(-1);
						toAns.add(false);
					}
					break;
				}
			}
		}
	}

	public void dfs(int x, int y, int prev) {
		System.out.println(x + " " + y);
		if (used[x][y]) {
			return;
		}
		used[x][y] = true;
		for (int dir = 0; dir < 4; dir++) {
			if (dir == (prev ^ 2)) {
				continue;
			}
			if (check(x, y, dir)) {
				ans[sz++] = dir;
				dfs(x + dx[dir], y + dy[dir], dir);
				ans[sz++] = dir ^ 2;
			}
		}
	}

	Random random = new Random();

	public static class Fenvik {
		int[] t;

		public Fenvik(int n) {
			t = new int[n];
			for (int i = 0; i < t.length; i++) {
				t[i] = Integer.MIN_VALUE / 2;
			}
		}

		public void upd(int x, int value) {
			for (int i = x; i < t.length; i = (i | (i + 1))) {
				t[i] = Math.max(t[i], value);
			}
		}

		public int max(int r) {
			int ans = Integer.MIN_VALUE / 2;
			int x = r;
			while (x >= 0) {
				ans = Math.max(t[x], ans);
				x = (x & (x + 1)) - 1;
			}
			return ans;
		}
	}

	public int calcMax(int[] a, int[] b) {
		int n = a.length;
		int[][] dp = new int[n + 1][n + 1];
		boolean[][] can = new boolean[n + 1][n + 1];
		can[n][n] = true;
		for (int i = n - 1; i >= 0; --i) {
			for (int j = n; j >= 0; --j) {
				if (a[i] < 2) {
					if (j == n) {
						continue;
					}
					dp[i][j] = 1;
					if (a[i] == b[j]) {
						dp[i][j] = sum(dp[i][j], dp[i + 1][j + 1]);
						can[i][j] = can[i + 1][j + 1];
					}
				} else if (a[i] == 3) {
					if (j == n) {
						continue;
					}
					dp[i][j] = 1;
					dp[i][j] = sum(dp[i + 1][j + 1], dp[i][j]);
					can[i][j] = can[i + 1][j + 1];
				} else {
					for (int l = n - j; l >= 0; --l) {
						dp[i][j] = sum(dp[i][j], 1);
						dp[i][j] = sum(dp[i][j], dp[i + 1][j + l]);
						if (can[i + 1][j + l]) {
							can[i][j] = true;
							break;
						}
					}
				}
			}
		}
		if (can[0][0]) {
			return dp[0][0];
		}
		return -1;
	}

	public int calcMin(int[] a, int[] b) {
		int n = a.length;
		int[][] dp = new int[n + 1][n + 1];
		boolean[][] can = new boolean[n + 1][n + 1];
		can[n][n] = true;
		for (int i = n - 1; i >= 0; --i) {
			for (int j = n; j >= 0; --j) {
				if (a[i] < 2) {
					if (j == n) {
						continue;
					}
					dp[i][j] = 1;
					if (a[i] == b[j]) {
						dp[i][j] += dp[i + 1][j + 1];
						can[i][j] = can[i + 1][j + 1];
					}
				} else if (a[i] == 3) {
					if (j == n) {
						continue;
					}
					dp[i][j] = 1;
					dp[i][j] += dp[i + 1][j + 1];
					can[i][j] = can[i + 1][j + 1];
				} else {
					for (int l = 0; l <= n - j; ++l) {
						dp[i][j]++;
						dp[i][j] += dp[i + 1][j + l];
						if (can[i + 1][j + l]) {
							can[i][j] = true;
							break;
						}
					}
				}
			}
		}
		if (can[0][0]) {
			return dp[0][0];
		}
		return -1;
	}

	public class Ticket implements Comparable<Ticket> {
		int id;
		int value;

		public Ticket(int id, int value) {
			this.id = id;
			this.value = value;
		}

		@Override
		public int compareTo(Ticket o) {
			if (value != o.value) {
				return value - o.value;
			}
			return id - o.id;
		}
	}
	
	public int res(int four, int one, int two, int three, int n, int nfour) {
		return four * 4000 + (one + two + three) * 500 + Integer.signum(n - one - two - three - nfour) * 300000;
	}
	
	public void solve() {
		f : for (int qwerty = in.nextInt(); qwerty > 0; --qwerty) {
			int delta = 0;
			String s = in.next();
			boolean wasA = false;
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) == 'A') {
					delta++;
				} else {
					delta--;
				}
				if (delta < 0) {
					out.println("NO");
					continue f;
				}
			}
			if (s.charAt(s.length() - 1) == 'A') {
				out.println("NO");
			} else {
				out.println("YES");
			}
		}
	}

	public void print(int[] a) {
		for (int i = 0; i < a.length; i++) {
			if (a[i] < 2) {
				out.print(a[i]);
			} else if (a[i] == 2) {
				out.print("*");
			} else {
				out.print("^");
			}
		}
		out.println();
	}

	public void finder() {
		for (int n = 0; n < 9; n++) {
			int maxmax = -2;
			int maxmin = -2;
			for (int mask = 0; mask < (1 << (2 * n)); mask++) {
				for (int mask1 = 0; mask1 < (1 << n); mask1++) {
					int[] a = new int[n];
					int[] b = new int[n];
					int x = mask;
					for (int i = 0; i < n; i++) {
						a[i] = x % 4;
						x >>= 2;
					}
					x = mask1;
					for (int i = 0; i < n; i++) {
						b[i] = x & 1;
						x >>= 1;
					}
					int v1 = calcMax(a, b);
					int v2 = calcMin(a, b);
					maxmax = Math.max(maxmax, v1);
					maxmin = Math.max(maxmin, v2);
				}
			}
			System.out.println(n);
			System.out.println(maxmax + " " + maxmin);
//			for (int mask = 0; mask < (1 << (2 * n)); mask++) {
//				for (int mask1 = 0; mask1 < (1 << n); mask1++) {
//					int[] a = new int[n];
//					int[] b = new int[n];
//					int x = mask;
//					for (int i = 0; i < n; i++) {
//						a[i] = x % 4;
//						x >>= 2;
//					}
//					x = mask1;
//					for (int i = 0; i < n; i++) {
//						b[i] = x & 1;
//						x >>= 1;
//					}
//					int v1 = calcMax(a, b);
//					int v2 = calcMin(a, b);
////					if (v1 == maxmax) {
////						System.out.print("MAX ");
////					}
//					if (v2 == maxmin) {
//						System.out.print("MIN");
//					}
//					if (v2 == maxmin) {
//						System.out.println();
//						for (int i = 0; i < a.length; i++) {
//							if (a[i] < 2) {
//								System.out.print(a[i]);
//							} else if (a[i] == 2) {
//								System.out.print("*");
//							} else {
//								System.out.print("^");
//							}
//						}
//						System.out.println();
//						for (int i = 0; i < b.length; i++) {
//							System.out.print(b[i]);
//						}
//						System.out.println();
//					}
//				}
//			}
		}
	}

	public void add(HashMap<Integer, Integer> map, int x) {
		if (map.containsKey(x)) {
			map.put(x, map.get(x) + 1);
		} else {
			map.put(x, 1);
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
		new B().run();
	}
}