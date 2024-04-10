import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class E {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

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
			if (sz[pa] == 1) {
				p[pa] = pb;
				sz[pb] += sz[pa];
				return true;
			}
			if (sz[pb] == 1) {
				p[pb] = pa;
				sz[pa] += sz[pb];
				return true;
			}
			return false;
		}
	}

	public class SegmentTree {
		int pow;
		long[] sum;

		public SegmentTree(long[] a) {
			pow = 1;
			while (pow < a.length) {
				pow *= 2;
			}
			sum = new long[2 * pow];
			for (int i = 0; i < a.length; i++) {
				sum[pow + i] = a[i];
			}
			for (int i = pow - 1; i > 0; i--) {
				sum[i] = f(sum[2 * i], sum[2 * i + 1]);
			}
		}

		public long get(int v, int tl, int tr, int l, int r) {
			if (l > r) {
				return 0;
			}
			if (l == tl && r == tr) {
				return sum[v];
			}
			int tm = (tl + tr) / 2;
			return f(get(2 * v, tl, tm, l, Math.min(r, tm)), get(2 * v + 1, tm + 1, tr, Math.max(l, tm + 1), r));
		}

		public void set(int v, int tl, int tr, int l, int r, long x) {
			if (l > tr || r < tl) {
				return;
			}
			if (l <= tl && r >= tr) {
				return;
			}
			int tm = (tl + tr) / 2;
			set(2 * v, tl, tm, l, r, x);
			set(2 * v + 1, tm + 1, tr, l, r, x);
			sum[v] = f(sum[2 * v], sum[2 * v + 1]);
		}

		public long f(long a, long b) {
			return a + b;
		}
	}

	public class SegmentTreeAdd {
		int pow;
		long[] sum;
		long[] delta;
		boolean[] flag;

		public SegmentTreeAdd(long[] a) {
			pow = 1;
			while (pow < a.length) {
				pow *= 2;
			}
			flag = new boolean[2 * pow];
			sum = new long[2 * pow];
			delta = new long[2 * pow];
			for (int i = 0; i < a.length; i++) {
				sum[pow + i] = a[i];
			}
			for (int i = pow - 1; i > 0; i--) {
				sum[i] = f(sum[2 * i], sum[2 * i + 1]);
			}
		}

		public long get(int v, int tl, int tr, int l, int r) {
			push(v, tl, tr);
			if (l > r) {
				return 0;
			}
			if (l == tl && r == tr) {
				return sum[v];
			}
			int tm = (tl + tr) / 2;
			return f(get(2 * v, tl, tm, l, Math.min(r, tm)), get(2 * v + 1, tm + 1, tr, Math.max(l, tm + 1), r));
		}

		public void set(int v, int tl, int tr, int l, int r, long x) {
			push(v, tl, tr);
			if (l > tr || r < tl) {
				return;
			}
			if (l <= tl && r >= tr) {
				delta[v] += x;
				flag[v] = true;
				push(v, tl, tr);
				return;
			}
			int tm = (tl + tr) / 2;
			set(2 * v, tl, tm, l, r, x);
			set(2 * v + 1, tm + 1, tr, l, r, x);
			sum[v] = f(sum[2 * v], sum[2 * v + 1]);
		}

		public void push(int v, int tl, int tr) {
			if (flag[v]) {
				if (v < pow) {
					flag[2 * v] = true;
					flag[2 * v + 1] = true;
					delta[2 * v] += delta[v];
					delta[2 * v + 1] += delta[v];
				}
				flag[v] = false;
				sum[v] += delta[v] * (tr - tl + 1);
			}
		}

		public long f(long a, long b) {
			return a + b;
		}
	}

	public class SegmentTreeSet {
		int pow;
		int[] sum;
		int[] delta;
		boolean[] flag;

		public SegmentTreeSet(int[] a) {
			pow = 1;
			while (pow < a.length) {
				pow *= 2;
			}
			flag = new boolean[2 * pow];
			sum = new int[2 * pow];
			delta = new int[2 * pow];
			for (int i = 0; i < a.length; i++) {
				sum[pow + i] = a[i];
			}
		}

		public int get(int v, int tl, int tr, int l, int r) {
			push(v, tl, tr);
			if (l > r) {
				return 0;
			}
			if (l == tl && r == tr) {
				return sum[v];
			}
			int tm = (tl + tr) / 2;
			return f(get(2 * v, tl, tm, l, Math.min(r, tm)), get(2 * v + 1, tm + 1, tr, Math.max(l, tm + 1), r));
		}

		public void set(int v, int tl, int tr, int l, int r, int x) {
			push(v, tl, tr);
			if (l > tr || r < tl) {
				return;
			}
			if (l <= tl && r >= tr) {
				delta[v] = x;
				flag[v] = true;
				push(v, tl, tr);
				return;
			}
			int tm = (tl + tr) / 2;
			set(2 * v, tl, tm, l, r, x);
			set(2 * v + 1, tm + 1, tr, l, r, x);
			sum[v] = f(sum[2 * v], sum[2 * v + 1]);
		}

		public void push(int v, int tl, int tr) {
			if (flag[v]) {
				if (v < pow) {
					flag[2 * v] = true;
					flag[2 * v + 1] = true;
					delta[2 * v] = delta[v];
					delta[2 * v + 1] = delta[v];
				}
				flag[v] = false;
				sum[v] = delta[v] * (tr - tl + 1);
			}
		}

		public int f(int a, int b) {
			return a + b;
		}
	}

	public class Pair implements Comparable<Pair> {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public Pair clone() {
			return new Pair(x, y);
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
			return -(y - o.y);
		}
	}

	long mod;
	Random random = new Random();

	public void shuffle(Pair[] a) {
		for (int i = 0; i < a.length; i++) {
			int x = random.nextInt(i + 1);
			Pair t = a[x];
			a[x] = a[i];
			a[i] = t;
		}
	}

	public void sort(int[][] a) {
		for (int i = 0; i < a.length; i++) {
			Arrays.sort(a[i]);
		}
	}

	public static class Fenvik {
		long[] t;

		public Fenvik(int n) {
			t = new long[n];
		}

		public void add(int x, long delta) {
			for (int i = x; i < t.length; i = (i | (i + 1))) {
				t[i] += delta;
			}
		}

		private long sum(int r) {
			long ans = 0;
			int x = r;
			while (x >= 0) {
				ans += t[x];
				x = (x & (x + 1)) - 1;
			}
			return ans;
		}

		public long sum(int l, int r) {
			return sum(r) - sum(l - 1);
		}
	}

	public int gcd(int x, int y) {
		if (x == 0) {
			return y;
		}
		return gcd(y % x, x);
	}

	public class Vector {
		int x;
		int y;

		public Vector(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public Vector add(Vector v) {
			return new Vector(x + v.x, y + v.y);
		}
	}

	public long cp(Vector v0, Vector v1, Vector v2) {
		return (v1.x - v0.x) * (v2.y - v0.y) - (v1.y - v0.y) * (v2.x - v0.x);
	}

	// public class Fract {
	// BigInteger p;
	// BigInteger q;
	//
	// public Fract(BigInteger p, BigInteger q) {
	// this.p = p;
	// this.q = q;
	// }
	// }

	int[] dx = { 1, 0, -1, 0 };
	int[] dy = { 0, 1, 0, -1 };

	public void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		int even = n / 2;
		for (int i = 0; i < a.length; i++) {
			a[i] = in.nextInt();
			if (a[i] % 2 == 0 && a[i] > 0) {
				even--;
			}
		}
		int[][][] dp = new int[n][even + 1][2];
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[0].length; j++) {
				for (int k = 0; k < dp[0][0].length; k++) {
					dp[i][j][k] = Integer.MAX_VALUE / 2;
				}
			}
		}
		if (a[0] == 0) {
			dp[0][even][1] = 0;
			if (even > 0) {
				dp[0][even - 1][0] = 0;
			}
		} else {
			dp[0][even][a[0] % 2] = 0;
		}
		for (int i = 1; i < a.length; i++) {
			if (a[i] > 0) {
				for (int j = 0; j < dp[0].length; j++) {
					dp[i][j][a[i] % 2] = Math.min(dp[i][j][a[i] % 2], dp[i - 1][j][a[i] % 2]);
					dp[i][j][a[i] % 2] = Math.min(dp[i][j][a[i] % 2], dp[i - 1][j][1 - a[i] % 2] + 1);
				}
			} else {
				for (int j = 0; j < dp[0].length; j++) {
					if (j < even) {
						dp[i][j][0] = Math.min(dp[i][j][0], dp[i - 1][j + 1][0]);
						dp[i][j][0] = Math.min(dp[i][j][0], dp[i - 1][j + 1][1] + 1);
					}
					dp[i][j][1] = Math.min(dp[i][j][1], dp[i - 1][j][1]);
					dp[i][j][1] = Math.min(dp[i][j][1], dp[i - 1][j][0] + 1);
				}
			}
		}
//		for (int i = 0; i < dp.length; i++) {
//			for (int j = 0; j < dp[0].length; j++) {
//				System.out.print(dp[i][j][0] + " " + dp[i][j][1] + " \t\t");
//			}
//			System.out.println();
//		}
		out.print(Math.min(dp[n - 1][0][0], dp[n - 1][0][1]));
	}

	public void run() {
		try {
			if (systemIO) {
				in = new FastScanner(System.in);
				out = new PrintWriter(System.out);
			} else {
				in = new FastScanner(new File("frequent.in"));
				out = new PrintWriter(new File("frequent.out"));
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
		new E().run();
	}
}