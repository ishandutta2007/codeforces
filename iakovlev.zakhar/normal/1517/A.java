import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.Map.Entry;

public class D {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

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

	public class FenvikMax {
		int[] max;

		public FenvikMax(int n) {
			max = new int[n];
		}

		public void add(int x, int d) {
			for (int i = x; i < max.length; i = (i | (i + 1))) {
				if (d > max[i]) {
					max[i] = d;
				}
			}
		}

		public int max(int r) {
			int ans = -1;
			for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
				if (max[i] > ans) {
					ans = max[i];
				}
			}
			return ans;
		}
	}

	public class SegmentTree {
		int pow;
		long[] min;

		public SegmentTree(long[] a) {
			pow = 1;
			while (pow < a.length) {
				pow *= 2;
			}
			min = new long[2 * pow];
			for (int i = 0; i < a.length; i++) {
				min[pow + i] = a[i];
			}
			for (int i = a.length; i < pow; i++) {
				min[pow + i] = Long.MAX_VALUE / 2;
			}
			for (int i = pow - 1; i > 0; i--) {
				min[i] = f(min[2 * i], min[2 * i + 1]);
			}
		}

		public long get(int l, int r) {
			return get(1, 0, pow, l, r);
		}

		private long get(int v, int tl, int tr, int l, int r) {
			if (l >= tr || r <= tl) {
				return Long.MAX_VALUE / 2;
			}
			if (l <= tl && r >= tr) {
				return min[v];
			}
			int tm = (tl + tr) / 2;
			return f(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm, tr, l, r));
		}

		public void set(int x, long value) {
			set(1, 0, pow, x, value);
		}

		private void set(int v, int tl, int tr, int x, long value) {
			if (x >= tr || x < tl) {
				return;
			}
			if (v >= pow) {
				min[v] = value;
				return;
			}
			int tm = (tl + tr) / 2;
			set(2 * v, tl, tm, x, value);
			set(2 * v + 1, tm, tr, x, value);
			min[v] = f(min[2 * v], min[2 * v + 1]);
		}

		public long f(long a, long b) {
			return Math.min(a, b);
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

	public long mult(long a, long b) {
		return a * b % mod;
	}

	public long sum(long a, long b) {
		if (a + b > mod) {
			return a + b - mod;
		}
		return a + b;
	}

	long mod = 1000000007;

	public class VectorInt {
		long x;
		long y;

		public VectorInt(long x, long y) {
			this.x = x;
			this.y = y;
		}

		public VectorInt subtract(VectorInt v) {
			return new VectorInt(x - v.x, y - v.y);
		}

		public double norm() {
			return Math.sqrt(x * x + y * y);
		}
	}

	public class VectorDouble {
		double x;
		double y;

		public VectorDouble(double x, double y) {
			this.x = x;
			this.y = y;
		}

		public VectorDouble(VectorInt v) {
			x = v.x;
			y = v.y;
		}

		public String toString() {
			return x + " " + y;
		}

		public VectorDouble add(VectorDouble v) {
			return new VectorDouble(x + v.x, y + v.y);
		}

		public VectorDouble subtract(VectorDouble v) {
			return new VectorDouble(x - v.x, y - v.y);
		}

		public VectorDouble mult(double c) {
			return new VectorDouble(x * c, y * c);
		}

		public double norm() {
			return Math.sqrt(x * x + y * y);
		}

		public double norm2() {
			return x * x + y * y;
		}

		public void normalize() {
			double n = norm();
			x /= n;
			y /= n;
		}
	}

	public long dp(VectorInt a, VectorInt b) {
		return a.x * b.x + a.y * b.y;
	}

	public long cp(VectorInt a, VectorInt b) {
		return a.x * b.y - a.y * b.x;
	}

	public double dp(VectorDouble a, VectorDouble b) {
		return a.x * b.x + a.y * b.y;
	}

	public double cp(VectorDouble a, VectorDouble b) {
		return a.x * b.y - a.y * b.x;
	}

	Random random = new Random(566);

	public class Fret implements Comparable<Fret> {
		int value;
		int index;

		public Fret(int value, int index) {
			this.value = value;
			this.index = index;
		}

		@Override
		public int compareTo(Fret o) {
			if (value != o.value) {
				return value - o.value;
			}
			return index - o.index;
		}

	}

	public int[][] readGraph(int n, int m) {
		int[][] to = new int[n][];
		int[] sz = new int[n];
		int[] x = new int[m];
		int[] y = new int[m];
		for (int i = 0; i < m; i++) {
			x[i] = in.nextInt() - 1;
			y[i] = in.nextInt() - 1;
			sz[x[i]]++;
			sz[y[i]]++;
		}
		for (int i = 0; i < to.length; i++) {
			to[i] = new int[sz[i]];
			sz[i] = 0;
		}
		for (int i = 0; i < x.length; i++) {
			to[x[i]][sz[x[i]]++] = y[i];
			to[y[i]][sz[y[i]]++] = x[i];
		}
		return to;
	}

	public double volume(double x0, double y0, double dxdz, double dydz, double dz) {
		return x0 * y0 * dz - (dxdz * y0 + dydz * x0) * dz * dz / 2 + dxdz * dydz * dz * dz * dz / 3;
	}

	public class Vector {
		double x;
		double y;
		double z;

		public Vector(double x, double y, double z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}

		public double norm() {
			return Math.sqrt(x * x + y * y + z * z);
		}

		public double norm2() {
			return x * x + y * y + z * z;
		}

		public Vector subtract(Vector v) {
			return new Vector(x - v.x, y - v.y, z - v.z);
		}
	}

	public Vector cp(Vector a, Vector b) {
		return new Vector(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
	}

	public double sin(Vector a, Vector b) {
		return cp(a, b).norm() / a.norm() / b.norm();
	}

	public double dp(Vector a, Vector b) {
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	public double cos(Vector a, Vector b) {
		return dp(a, b) / a.norm() / b.norm();
	}

	double eps = 1e-9;

	int[] mult(int[] a, int[] b) {
		int[] res = new int[a.length];
		for (int i = 0; i < a.length; ++i) {
			res[i] = b[a[i]];
		}
		return res;
	}

	int[] rev(int[] a) {
		int[] res = new int[a.length];
		for (int i = 0; i < a.length; ++i) {
			res[a[i]] = i;
		}
		return res;
	}

	int[] conj(int[] pi, int[] f) {
		return mult(mult(rev(pi), f), pi);
	}

	void print(int[] p) {
		for (int i : p) {
			System.out.print(i + 1 + " ");
		}
		System.out.println();
	}

	public class Triangle implements Comparable<Triangle> {
		Pair p1;
		Pair p2;

		public Triangle(Pair p1, Pair p2) {
			this.p1 = p1.clone();
			this.p2 = p2.clone();
			if (p1.compareTo(p2) > 0) {
				Pair p = p1;
				this.p1 = p2;
				this.p2 = p;
			}
		}

		@Override
		public int compareTo(Triangle o) {
			if (p1.compareTo(o.p1) != 0) {
				return p1.compareTo(o.p1);
			}
			return p2.compareTo(o.p2);
		}

	}

	public class Color implements Comparable<Color> {
		int a;
		int b;

		public Color(int a, int b) {
			this.a = a;
			this.b = b;
		}

		public int day() {
			return a - b + 1;
		}

		@Override
		public int compareTo(Color o) {
			if (b == 0 && o.b == 0) {
				return 0;
			}
			if (b == 0) {
				return 1;
			}
			if (o.b == 0) {
				return -1;
			}
			return day() - o.day();
		}

	}

	public class DSU {
		int[] sz;
		int[] p;
		boolean[] one;

		public DSU(int n) {
			sz = new int[n];
			p = new int[n];
			one = new boolean[n];
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

		public boolean set(int x) {
			int p = get(x);
			if (one[p]) {
				return false;
			}
			one[p] = true;
			return true;
		}

		public boolean unite(int a, int b) {
			int pa = get(a);
			int pb = get(b);
			if (pa == pb || (one[pa] && one[pb])) {
				return false;
			}
			if (sz[pa] < sz[pb]) {
				p[pa] = pb;
				sz[pb] += sz[pa];
				one[pb] |= one[pa];
			} else {
				p[pb] = pa;
				sz[pa] += sz[pb];
				one[pa] |= one[pb];
			}
			return true;
		}
	}

	public void solve() throws IOException {
		int test = in.nextInt();
		for (int qwerty = 1; qwerty <= test; qwerty++) {
			long x = in.nextLong();
			if (x % 2050 != 0) {
				out.println(-1);
			} else {
				x /= 2050;
				long ans = 0;
				while (x > 0) {
					ans += x % 10;
					x /= 10;
				}
				out.println(ans);
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
//		long time = System.currentTimeMillis();
		new D().run();
//		System.err.println(System.currentTimeMillis() - time);
	}
}