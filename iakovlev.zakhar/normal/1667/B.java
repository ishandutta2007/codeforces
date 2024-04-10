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

	public void solve() {
		for (int qwerty = in.nextInt(); qwerty > 0; --qwerty) {
			int n = in.nextInt();
			long[] a = new long[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = in.nextLong();
			}
			long[] pref = new long[n + 1];
			for (int i = 0; i < n; i++) {
				pref[i + 1] = pref[i] + a[i];
			}
			a = pref.clone();
			for (int i = 1; i < n; i++) {
				int x = random.nextInt(i);
				a[x] ^= a[i];
				a[i] ^= a[x];
				a[x] ^= a[i];
			}
			Arrays.sort(a);
			HashMap<Long, Integer> map = new HashMap<>();
			map.put(a[0], 0);
			int last = 0;
			for (int i = 1; i < pref.length; i++) {
				if (a[i] > a[i - 1]) {
					map.put(a[i], ++last);
				}
			}
			int[] dp = new int[n + 1];
			for (int i = 1; i < dp.length; i++) {
				dp[i] = Integer.MIN_VALUE / 2;
			}
			int[] maxEq = new int[map.size()];
			for (int i = 0; i < maxEq.length; i++) {
				maxEq[i] = Integer.MIN_VALUE / 2;
			}
			maxEq[map.get(0L)] = 0;
			int[] max = maxEq.clone();
			Fenvik tree = new Fenvik(map.size());
			tree.upd(map.get(0L), 0);
			for (int i = 1; i < dp.length; i++) {
				dp[i] = dp[i - 1] - 1;
				int id = map.get(pref[i]);
				if (dp[i] < maxEq[id]) {
					dp[i] = maxEq[id];
				}
				int val = tree.max(id - 1) + i;
				if (val > dp[i]) {
					dp[i] = val;
				}
				if (dp[i] > maxEq[id]) {
					maxEq[id] = dp[i];
				}
				if (dp[i] - i > max[id]) {
					max[id] = dp[i] - i;
				}
				tree.upd(id, dp[i] - i);
			}
			out.println(dp[n]);
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