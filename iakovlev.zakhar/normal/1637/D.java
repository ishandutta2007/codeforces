import java.io.*;
import java.util.*;

public class D {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	int mod = 1000000007;
	
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

	public int mult(int x, int y) {
		return (int) (x * 1L * y % mod);
	}

	public int div(int x, int y) {
		return (int) (x * 1L * modInv(y) % mod);
	}

	public int modInv(int x) {
		return pow(x, mod - 2);
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

	public int pow(int x, int p) {
		if (p == 0) {
			return 1;
		}
		int t = pow(x, p / 2);
		t = mult(t, t);
		if (p % 2 == 1) {
			t = mult(t, x);
		}
		return t;
	}



	Random random = new Random(566);

	public class DSU {
		int[] sz;
		int[] p;

		public DSU(int n) {
			sz = new int[n];
			p = new int[n];
			for (int i = 0; i < p.length; i++) {
				p[i] = i;
				sz[i] = 1;
			}
		}

		public int get(int x) {
			if (x == p[x]) {
				return x;
			}
			int par = get(p[x]);
			p[x] = par;
			return par;
		}

		public boolean unite(int a, int b) {
			int pa = get(a);
			int pb = get(b);
			if (pa == pb) {
				return false;
			}
			if (sz[pa] < sz[pb]) {
				p[pa] = pb;
				sz[pb] += sz[pa];
			} else {
				p[pb] = pa;
				sz[pa] += sz[pb];
			}
			return true;
		}
	}
	
	public class SparseTable {
		int pow;
		int[] lessPow;
		long[][] min;

		public SparseTable(long[] a) {
			pow = 0;
			while ((1 << pow) <= a.length) {
				pow++;
			}
			min = new long[pow][a.length];
			for (int i = 0; i < a.length; i++) {
				min[0][i] = a[i];
			}
			for (int i = 1; i < pow; i++) {
				for (int j = 0; j < a.length; j++) {
					min[i][j] = min[i - 1][j];
					if (j + (1 << (i - 1)) < a.length) {
						min[i][j] = func(min[i][j], min[i - 1][j + (1 << (i - 1))]);
					}
				}
			}
			lessPow = new int[a.length + 1];
			for (int i = 1; i < lessPow.length; i++) {
				if (i < (1 << (lessPow[i - 1]) + 1)) {
					lessPow[i] = lessPow[i - 1];
				} else {
					lessPow[i] = lessPow[i - 1] + 1;
				}
			}
		}

		public long get(int l, int r) { // [l, r)
			int p = lessPow[r - l];
			return func(min[p][l], min[p][r - (1 << p)]);
		}

		public long func(long a, long b) {
			if (a < b) {
				return a;
			}
			return b;
		}
	}
	
	int inv2 = modInv(2);
	
	public void solve() {
		f : for (int qwerty = in.nextInt(); qwerty > 0; --qwerty) {
			int n = in.nextInt();
			int[] a = new int[n];
			int[] b = new int[n];
			int ans = 0;
			for (int i = 0; i < a.length; i++) {
				a[i] = in.nextInt();
			}
			for (int i = 0; i < b.length; i++) {
				b[i] = in.nextInt();
			}
			int sum = 0;
			for (int i = 0; i < b.length; i++) {
				ans += (n - 2) * (a[i] * a[i] + b[i] * b[i]);
				sum += a[i];
				sum += b[i];
			}
			boolean[][] dp = new boolean[2][sum + 1];
			int cur = 0;
			dp[cur][0] = true;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j + a[i] <= sum; j++) {
					dp[cur ^ 1][j + a[i]] |= dp[cur][j];
				}
				for (int j = 0; j + b[i] <= sum; j++) {
					dp[cur ^ 1][j + b[i]] |= dp[cur][j];
				}
				for (int j = 0; j <= sum; j++) {
					dp[cur][j] = false;
				}
				cur ^= 1;
			}
			int min = sum * sum;
			for (int i = 0; i <= sum; i++) {
				if (dp[cur][i]) {
					min = Math.min(min, i * i + (sum - i) * (sum - i));
				}
			}
			out.println(ans + min);
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