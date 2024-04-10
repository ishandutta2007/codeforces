import java.util.*;

import java.io.*;
import java.math.BigInteger;

public class G {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Fraction implements Comparable<Fraction> {
		long x;
		long y;

		public Fraction(long x, long y) {
			this.x = x;
			this.y = y;
		}

		public void norm() {
			long gcd = gcd(x, y);
			x /= gcd;
			y /= gcd;
		}

		@Override
		public int compareTo(Fraction o) {
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

	public Fraction sum(Fraction a, Fraction b) {
		Fraction c = new Fraction(a.x * b.y + a.y * b.x, a.y * b.y);
		c.norm();
		return c;
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
				return -1;
			}
			if (x < o.x) {
				return 1;
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

	public class Request implements Comparable<Request> {
		int k;
		int pos;
		int number;
		
		public Request(int k, int pos, int number) {
			this.k = k;
			this.pos = pos;
			this.number = number;
		}

		@Override
		public int compareTo(Request o) {
			if (k != o.k) {
				return k - o.k;
			}
			if (pos != o.pos) {
				return pos - o.pos;
			}
			return number - o.number;
		}
	}
	
	public class Fenvik {
		long[] sum;

		public Fenvik(int n) {
			sum = new long[n];
		}

		public void add(int x, long d) {
			for (int i = x; i < sum.length; i = (i | (i + 1))) {
				sum[i] += d;
			}
		}

		public long sum(int r) {
			long ans = 0;
			for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
				ans += sum[i];
			}
			return ans;
		}

		public long sum(int l, int r) {
			if (l > r) {
				return 0;
			}
			return sum(r) - sum(l - 1);
		}
	}

	public class Vector implements Comparable<Vector> {
		long x;
		long y;

		public Vector(long x, long y) {
			this.x = x;
			this.y = y;
		}

		public Vector add(Vector v) {
			return new Vector(x + v.x, y + v.y);
		}

		public Vector subtract(Vector v) {
			return new Vector(x - v.x, y - v.y);
		}

		public long dp(Vector v) {
			return x * v.x + y * v.y;
		}

		public long cp(Vector v) {
			return x * v.y - y * v.x;
		}

		public boolean equals(Vector v) {
			return x == v.x && y == v.y;
		}

		@Override
		public int compareTo(Vector o) {
			int s = sgn(cp(v0));
			int os = sgn(o.cp(v0));
			if (s != os) {
				return s - os;
			}
			return sgn(cp(o));
		}

	}

	public int sgn(long x) {
		if (x > 0) {
			return 1;
		}
		if (x < 0) {
			return -1;
		}
		return 0;
	}
	
	public long min(long a, long b) {
		return a < b ? a : b;
	}
	
	public class Treap implements Comparable<Treap> {
		Vertex root;

		public Treap(Vertex root) {
			this.root = root;
		}

		public Treap() {
			root = null;
		}

		public int size() {
			return size(root);
		}

		public boolean contains(int x) {
			PairVertex p = cut(x - 1);
			PairVertex p1 = cut(p.r, x);
			boolean ans = size(p1.l) > 0;
			p.r = unite(p1);
			root = unite(p);
			return ans;
		}

		public void add(int x) {
			root = add(new Vertex(x), root);
		}

		public Vertex add(Vertex v, Vertex th) {
			if (th == null) {
				v.update();
				return v;
			}
			if (v.y > th.y) {
				PairVertex p = cut(th, v.x - 1);
				v.l = p.l;
				v.r = cut(p.r, v.x).r;
				v.update();
				return v;
			}
			if (v.x < th.x) {
				th.l = add(v, th.l);
			} else if (v.x > th.x) {
				th.r = add(v, th.r);
			}
			th.update();
			return th;
		}

		public void addSlow(int x) {
			Vertex v = new Vertex(x);
			PairVertex p = cut(x - 1);
			PairVertex p1 = cut(p.r, x);
			p1.l = v;
			p.r = unite(p1);
			root = unite(p);
		}

		public void remove(int x) {
			root = remove(root, x);
		}

		public Vertex remove(Vertex v, int x) {
			if (v == null) {
				return v;
			}
			if (x < v.x) {
				v.l = remove(v.l, x);
				v.update();
				return v;
			}
			if (x > v.x) {
				v.r = remove(v.r, x);
				v.update();
				return v;
			}
			return unite(new PairVertex(v.l, v.r));
		}

		public boolean removeSlow(int x) {
			PairVertex p = cut(x - 1);
			PairVertex p1 = cut(p.r, x);
			boolean ans = size(p1.l) > 0;
			p1.l = null;
			p.r = unite(p1);
			root = unite(p);
			return ans;
		}

		public Vertex get(int x) {
			return get(root, x);
		}
		
		public Vertex get(Vertex v, int x) {
			if (v == null) {
				return null;
			}
			int sz = size(v.l);
			if (sz > x) {
				return get(v.l, x);
			}
			if (sz == x) {
				return v;
			}
			return get(v.r, x - sz - 1);
		}
		
		public int numberLess(int x) {
			return numberLess(root, x);
		}

		public int numberLess(Vertex v, int x) {
			if (v == null) {
				return 0;
			}
			if (v.x < x) {
				return size(v.l) + 1 + numberLess(v.r, x);
			}
			return numberLess(v.l, x);
		}

		public int numberLessSlow(int x) {
			PairVertex p = cut(x - 1);
			int ans = size(p.l);
			root = unite(p);
			return ans;
		}

		public int numberFloor(int x) {
			return numberLess(x + 1);
		}

		public int numberFloorSlow(int x) {
			PairVertex p = cut(x);
			int ans = size(p.l);
			root = unite(p);
			return ans;
		}

		public int numberHigher(int x) {
			return size(root) - numberLess(x + 1);
		}

		public int numberHigherSlow(int x) {
			PairVertex p = cut(x);
			int ans = size(p.r);
			root = unite(p);
			return ans;
		}

		public int numberCeiling(int x) {
			return size(root) - numberLess(x);
		}

		public int numberCeilingSlow(int x) {
			PairVertex p = cut(x - 1);
			int ans = size(p.r);
			root = unite(p);
			return ans;
		}

		public int[] all() {
			int[] ans = new int[size()];
			int sz = 0;
			sz = dfs(root, ans, sz);
			return ans;
		}

		public int dfs(Vertex v, int[] a, int sz) {
			if (v == null) {
				return sz;
			}
			sz = dfs(v.l, a, sz);
			a[sz] = v.x;
			sz++;
			return dfs(v.r, a, sz);
		}

		public PairVertex cut(int x) {
			return cut(root, x);
		}

		public PairVertex cut(Vertex v, int x) {
			if (v == null) {
				return new PairVertex();
			}
			PairVertex ans = new PairVertex();
			if (v.x <= x) {
				PairVertex p = cut(v.r, x);
				v.r = p.l;
				update(v);
				ans.l = v;
				ans.r = p.r;
			} else {
				PairVertex p = cut(v.l, x);
				v.l = p.r;
				update(v);
				ans.l = p.l;
				ans.r = v;
			}
			return ans;
		}

		public Vertex unite(PairVertex p) {
			if (p.l == null) {
				return p.r;
			}
			if (p.r == null) {
				return p.l;
			}
			if (p.l.y > p.r.y) {
				p.l.r = unite(new PairVertex(p.l.r, p.r));
				p.l.update();
				return p.l;
			}
			p.r.l = unite(new PairVertex(p.l, p.r.l));
			p.r.update();
			return p.r;
		}

		public class Vertex {
			int x;
			long y;
			int sz;
			Vertex l;
			Vertex r;

			public Vertex(int x) {
				this.x = x;
				this.y = random.nextLong();
				this.sz = 1;
				this.l = null;
				this.r = null;
			}

			public void update() {
				sz = 1 + size(l) + size(r);
			}
		}

		public void update(Vertex v) {
			if (v != null) {
				v.update();
			}
		}

		public int size(Vertex v) {
			if (v == null) {
				return 0;
			}
			return v.sz;
		}

		public class PairVertex {
			Vertex l;
			Vertex r;

			public PairVertex(Vertex l, Vertex r) {
				this.l = l;
				this.r = r;
			}

			public PairVertex() {
				l = null;
				r = null;
			}
		}

		@Override
		public int compareTo(Treap o) {
			return size() - o.size();
		}
	}

	Vector v0;

	long mod = 1000000007;
	Random random = new Random();

	public void solve() {
		int n = in.nextInt();
		Pair[] a = new Pair[n];
		int[] before = new int[n];
		for (int i = 0; i < a.length; i++) {
			before[i] = in.nextInt();
			a[i] = new Pair(before[i], i);
		}
		for (int i = 0; i < a.length; i++) {
			int x = random.nextInt(i + 1);
			Pair p = a[x];
			a[x] = a[i];
			a[i] = p;
		}
		Arrays.sort(a);
		int m = in.nextInt();
		Request[] q = new Request[m];
		for (int i = 0; i < q.length; i++) {
			q[i] = new Request(in.nextInt(), in.nextInt() - 1, i);
		}
		for (int i = 0; i < q.length; i++) {
			int x = random.nextInt(i + 1);
			Request p = q[x];
			q[x] = q[i];
			q[i] = p;
		}
		Arrays.sort(q);
		int[] ans = new int[m];
		Treap treap = new Treap();
		for (int i = 0; i < q.length; i++) {
			while (treap.size() < q[i].k) {
				treap.add(a[treap.size()].y);
			}
			ans[q[i].number] = before[treap.get(q[i].pos).x];
		}
		for (int i = 0; i < ans.length; i++) {
			out.println(ans[i]);
		}
	}

	public long solveFast(int s, int b) {
		b -= s;
		long time = System.currentTimeMillis();
		long[][] dp = new long[1][b + 1];
		dp[0][b] = 1;
		int c = 0;
		for (int x = b; x >= 1; x--) {
			long[][] dp1 = new long[Math.min(b / x, s) + 1][b];
			// for (int i = 0; i < dp1.length; i++) {
			// dp1[i] = new long[b - i * x + 1];
			// }
			for (int i = 0; i < dp.length; i++) {
				for (int j = 0; j < dp[i].length; j++) {
					dp1[i][j] = dp[i][j];
					c++;
				}
			}
			int dl = dp1.length - dp.length;
			if (dl == 0) {
				dl++;
			}
			int len = dp.length;
			for (int j = 0; j < dp1[0].length; j++) {
				long sum = 0;
				long d = 0;
				for (int i = 1; j - i * x >= 0 && i <= s; i++) {
					dp1[i][j - i * x] += d + dp[0][j];
					dp1[i][j - i * x] %= mod;
					if (i < len && j <= b - i) {
						sum += dp[i][j - i * x];
						d += dp[i][j - i * x];
					}
					d += sum;
					// for (int k = dl; k <= i; k++) {
					// c++;
					// if (j + k * x > b) {
					// break;
					// }
					// dp1[i][j] += dp[i - k][j + k * x] * (k + 1);
					// }
				}
			}
			dp = dp1;
			// for (int i = 0; i < dp1.length; i++) {
			// for (int j = 0; j < dp1[0].length; j++) {
			// System.out.print(dp1[i][j] + " ");
			// }
			// System.out.println();
			// }
			// System.out.println();
		}
		long ans = dp[0][0];
		for (int i = 1; i < dp.length; i++) {
			ans += dp[i][0] * (1 + s - i);
		}
		System.err.println(System.currentTimeMillis() - time);
		System.err.println(c);
		return (ans % mod);
		// out.print(dp[s][0] % mod);
	}

	public long solveSlow(int s, int b) {
		long time = System.currentTimeMillis();
		long[][] dp = new long[1][b + 1];
		dp[0][b] = 1;
		int c = 0;
		for (int x = b; x >= 1; x--) {
			System.out.println(x);
			long[][] dp1 = new long[b / x + 1][b + 1];
			for (int i = 0; i < dp.length; i++) {
				for (int j = 0; j < dp[0].length; j++) {
					dp1[i][j] = dp[i][j];
					c++;
				}
			}
			int dl = dp1.length - dp.length;
			if (dl == 0) {
				dl++;
			}
			for (int i = 1; i < dp1.length; i++) {
				for (int j = 0; j < dp1[0].length; j++) {
					for (int k = 1; k < i; k++) {
						if (i - k >= dp.length) {
							continue;
						}
						c++;
						if (j + k * x > b) {
							break;
						}
						dp1[i][j] += dp[i - k][j + k * x] * (k + 1);
					}
					if (j + i * x == b) {
						dp1[i][j]++;
					}
					dp1[i][j] %= mod;
				}
			}
			dp = dp1;
			// System.out.println(x);
			// for (int i = 0; i < dp1.length; i++) {
			// for (int j = 0; j < dp1[0].length; j++) {
			// System.out.print(dp1[i][j] + " ");
			// }
			// System.out.println();
			// }
			// System.out.println();
		}
		System.err.println(System.currentTimeMillis() - time);
		System.err.println(c);
		return (dp[s][0]);
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
		new G().run();
	}
}