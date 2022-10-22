import java.util.*;
import java.util.Map.Entry;
import java.io.*;
import java.math.BigInteger;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public static void quickSort(int[] a, int from, int to) {
		if (to - from <= 1) {
			return;
		}
		int i = from;
		int j = to - 1;
		int x = a[from + (new Random()).nextInt(to - from)];
		while (i <= j) {
			while (a[i] < x) {
				i++;
			}
			while (a[j] > x) {
				j--;
			}
			if (i <= j) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
				i++;
				j--;
			}
		}
		quickSort(a, from, j + 1);
		quickSort(a, j + 1, to);
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

	public boolean prime(long x) {
		for (int i = 2; i * i <= x; i++) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
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

	public class Pair implements Comparable<Pair> {
		int x;
		int y;

		public Pair(int x, int y) {
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

	long mod = 1000000007;

	public class Fenvik2D {
		long[][] t;
		int n, m;

		public Fenvik2D(int n, int m) {
			t = new long[n][m];
			this.n = n;
			this.m = m;
		}

		public int sum(int x1, int y1, int x2, int y2) {
			return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
		}

		public int sum(int x, int y) {
			int result = 0;
			for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
				for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
					result += t[i][j];
				}
			}
			return result;
		}

		public void add(int x, int y, int delta) {
			for (int i = x; i < n; i = (i | (i + 1))) {
				for (int j = y; j < m; j = (j | (j + 1))) {
					t[i][j] += delta;
				}
			}
		}
	}

	public int[] prefF(int[] a) {
		int[] p = new int[a.length];
		for (int i = 1; i < p.length; i++) {
			int j = p[i - 1];
			while (j > 0) {
				if (a[j] == a[i]) {
					break;
				}
				if (j == 0) {
					break;
				}
				j = p[j - 1];
			}
			if (a[i] == a[j]) {
				p[i] = j + 1;
			}
		}
		return p;
	}

	public class Request implements Comparable<Request> {
		int x;
		int y;
		int number;

		public Request(int x, int y, int number) {
			this.x = x;
			this.y = y;
			this.number = number;
		}

		@Override
		public int compareTo(Request o) {
			return y - o.y;
		}
	}

	public class SegmentTree {
		int[] max;
		int[] delta;
		int pow;

		public SegmentTree(int size) {
			pow = 1;
			while (pow < size) {
				pow *= 2;
			}
			max = new int[2 * pow];
			delta = new int[2 * pow];
		}

		public void push(int v, int tl, int tr) {
			if (delta[v] == 0) {
				return;
			}
			max[v] += delta[v];
			if (v < pow) {
				delta[2 * v] += delta[v];
				delta[2 * v + 1] += delta[v];
			}
			delta[v] = 0;
		}

		public int get(int x) {
			return get(x, x + 1);
		}

		public int get(int l, int r) {
			return get(1, 0, pow, l, r);
		}

		private int get(int v, int tl, int tr, int l, int r) {
			push(v, tl, tr);
			if (tl >= r || tr <= l) {
				return 0;
			}
			if (tl >= l && tr <= r) {
				return max[v];
			}
			int tm = (tl + tr) / 2;
			return Math.max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm, tr, l, r));
		}

		public void add(int l, int r, int x) {
			add(1, 0, pow, l, r, x);
		}

		private void add(int v, int tl, int tr, int l, int r, int x) {
			push(v, tl, tr);
			if (tl >= r || tr <= l) {
				return;
			}
			if (tl >= l && tr <= r) {
				delta[v] += x;
				push(v, tl, tr);
				return;
			}
			int tm = (tl + tr) / 2;
			add(2 * v, tl, tm, l, r, x);
			add(2 * v + 1, tm, tr, l, r, x);
			max[v] = Math.max(max[2 * v], max[2 * v + 1]);
		}

		public int lastMax(int x) {
			return lastMax(1, 0, pow, x);
		}

		private int lastMax(int v, int tl, int tr, int x) {
			push(v, tl, tr);
			if (max[v] < x) {
				return -1;
			}
			if (v >= pow) {
				return tl;
			}
			int tm = (tl + tr) / 2;
			push(2 * v + 1, tm, tr);
			if (max[2 * v + 1] >= x) {
				return lastMax(2 * v + 1, tm, tr, x);
			}
			return lastMax(2 * v, tl, tm, x);
		}
	}

	int module = 1000000007;

	public int sum(int x, int y) {
		if (x + y >= module) {
			return x + y - module;
		}
		return x + y;
	}

	public long calc(long a, long b, long c, long d, long n) {
		long cd = c / d;
		if (n <= cd) {
			return (n + 1) * a - n * (n + 1) / 2 * d * b;
		}
		return (n + 1) * a - n * c * b + cd * c * b + cd * (cd + 1) / 2 * d * b;
	}

	public class Vector implements Comparable<Vector> {
		long x;
		long y;

		public Vector(long x, long y) {
			this.x = x;
			this.y = y;
		}

		public Vector(Point begin, Point end) {
			this(end.x - begin.x, end.y - begin.y);
		}

		public Vector clone() {
			return new Vector(x, y);
		}

		public double len() {
			return Math.sqrt(x * x + y * y);
		}

		public void norm() {
			long gcd = gcd(x, Math.abs(y));
			x /= gcd;
			y /= gcd;
		}

		@Override
		public int compareTo(Vector o) {
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

	public long dp(Vector a, Vector b) {
		return a.x * b.x + a.y * b.y;
	}

	public long cp(Vector a, Vector b) {
		return a.x * b.y - a.y * b.x;
	}

//	public class Line implements Comparable<Line> {
//		long a;
//		long b;
//		long c;
//		long vec2;
//
//		public Line(Pair p0, Pair p1) {
//			Line0(p0, new Vector(p1.x - p0.x, p1.y - p0.y));
//		}
//
//		public void Line0(Pair p0, Vector vec) {
//			vec2 = vec.x * vec.x + vec.y * vec.y;
//			vec.norm();
//			a = vec.y;
//			b = -vec.x;
//			c = -a * p0.x - b * p0.y;
//		}
//
//		@Override
//		public int compareTo(Line o) {
//			if (a > o.a) {
//				return 1;
//			}
//			if (a < o.a) {
//				return -1;
//			}
//			if (b > o.b) {
//				return 1;
//			}
//			if (b < o.b) {
//				return -1;
//			}
//			if (vec2 > o.vec2) {
//				return 1;
//			}
//			if (vec2 < o.vec2) {
//				return -1;
//			}
//			if (c > o.c) {
//				return 1;
//			}
//			if (c < o.c) {
//				return -1;
//			}
//			return 0;
//		}
//
//	}

	public boolean can(int a, int x, int b, int y) {
		if (x + y == 0) {
			return false;
		}
		if (a < b && y > 0) {
			return true;
		}
		if (a + 1 < b) {
			return true;
		}
		if (a + 1 == b) {
			if (a == 1) {
				return true;
			}
			return false;
		}
		// a == b && (x > 0 || y > 0)
		if (a == 1) {
			return true;
		}
		if (y == 0) {
			return false;
		}
		if (a == 2) {
			return true;
		}
		if (x > 0 && y > 0) {
			return true;
		}
		return false;
	}

	public class Point implements Comparable<Point> {
		long x;
		long y;

		public Point() {
			x = 0;
			y = 0;
		}

		public Point(long x, long y) {
			this.x = x;
			this.y = y;
		}

		public String toString() {
			return x + " " + y;
		}

		public boolean equals(Point p) {
			return x == p.x && y == p.y;
		}

		public long dist2() {
			return x * x + y * y;
		}

		public double dist() {
			return Math.hypot(x, y);
		}

		public Point add(Point v) {
			return new Point(x + v.x, y + v.y);
		}

		public Point subtract(Point v) {
			return new Point(x - v.x, y - v.y);
		}

		@Override
		public int compareTo(Point o) {
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

	public class Circle {
		Point p;
		long r;

		public Circle(Point p, long r) {
			this.p = p;
			this.r = r;
		}

		public boolean intersect(Line l, int sign) {
			return Math.abs(l.a * p.x + l.b * p.y + l.c) / Math.hypot(l.a, l.b) < r + sign * 1e-9;
		}
	}

	public class Line {
		long a;
		long b;
		long c;

		public Line(long a, long b, long c) {
			this.a = a;
			this.b = b;
			this.c = c;
		}

		public Line(Point a, Point b) {
			this.a = a.y - b.y;
			this.b = b.x - a.x;
			this.c = a.x * b.y - a.y * b.x;
		}

		public long value(Point p) {
			return a * p.x + b * p.y + c;
		}
	}

	public class Guess implements Comparable<Guess> {
		int index;
		BigInteger max;

		public Guess(int index, BigInteger max) {
			this.index = index;
			this.max = max;
		}

		public String toString() {
			StringBuilder sb = new StringBuilder(index + " ");
			for (int i = 0; i < b; i++) {
				sb.append(max.testBit(b - 1 - i) ? 1 : 0);
			}
			return sb.toString();
		}

		@Override
		public int compareTo(Guess o) {
			return o.max.compareTo(max);
		}

	}

	Random random = new Random(566);

	public boolean ask(int index, BigInteger bi) {
		StringBuilder sb = new StringBuilder(index + " ");
		for (int i = 0; i < b; i++) {
			sb.append(bi.testBit(b - 1 - i) ? 1 : 0);
		}
//		System.out.println(sb.toString());
		if (cur % step == 0) {
			return true;
		}
		return false;
//		return in.next().charAt(0) == 'y';
	}

	int b;
	int cur;
	int step;

	BigInteger left = BigInteger.ZERO;

	public int f(long n) {
		long ans = 1;
		long pow = 1;
		while (n >= pow) {
			pow *= 10;
			ans = (ans * (n % pow)) % (n + 1);
		}
		return (int) ans;
	}

	public double partCylinder(double r, double k, double x1, double x2) {
		return partCylinder(r, k, x2) - partCylinder(r, k, x1);
	}

	public double partCylinder(double r, double k, double x) {
		return Math.pow(r, 3) / k
				* (Math.pow(Math.cos(x), 3) / 3 - Math.PI / 2 * Math.sin(x) - Math.cos(x) - x * Math.sin(x));
	}

	public double sliceCylinder(double r, double l) {
		return Math.PI * Math.pow(r, 2) * l;
	}

	public double sliceSphere(double r, double x1, double x2) {
		return sliceSphere(r, x2) - sliceSphere(r, x1);
	}

	public double sliceSphere(double r, double x) {
		return Math.PI * Math.pow(r, 3) * sin3(x);
	}

	public double sin3(double x) {
		return -Math.cos(x) + Math.pow(Math.cos(x), 3) / 3;
	}

	public double partSphere(double r, double k, double x1, double x2) {
		return partSphere(r, k, x2) - partSphere(r, k, x1);
	}

	public double partSphere(double r, double k, double x) {
		return -2 * Math.pow(r, 3) / k * (sin4cos2(x) + xsin3cos(x) + Math.PI / 2 * sin3cos(x));
	}

	public double sin4cos2(double x) {
		return x / 16 - Math.sin(4 * x) / 64 - Math.pow(Math.sin(2 * x), 3) / 48;
	}

	public double xsin3cos(double x) {
		return x * Math.pow(Math.sin(x), 4) / 4 - 3 * x / 32 + Math.sin(2 * x) / 16 - Math.sin(4 * x) / 128;
	}

	public double sin3cos(double x) {
		return Math.pow(Math.sin(x), 4) / 4;
	}

	public double horCyl(double r, double l, double x) {
		System.out.println(x + " " + Math.cos(x) + " " + (x + Math.PI / 2));
		return Math.pow(r, 2) * (Math.sin(x) * Math.cos(x) + (x + Math.PI / 2)) * l;
	}

	public double horSphere(double r, double x1, double x2) {
		return horSphere(r, x2) - horSphere(r, x1);
	}

	public double horSphere(double r, double x) {
		return Math.pow(r, 3) * (sin4cos(x) + Math.PI / 2 * sin3(x) + xsin3(x));
	}

	public double sin4cos(double x) {
		return Math.pow(Math.sin(x), 5) / 5;
	}

	public double xsin3(double x) {
		return x * sin3(x) + 2 * Math.sin(x) / 3 + Math.pow(Math.sin(x), 3) / 9;
	}

	public class Vd {
		double x;
		double y;

		public Vd(double x, double y) {
			this.x = x;
			this.y = y;
		}

		public Vd clone() {
			return new Vd(x, y);
		}

		public String toString() {
			return x + " " + y;
		}

		public double norm() {
			return Math.hypot(x, y);
		}

		public Vd mult(double c) {
			return new Vd(x * c, y * c);
		}

		public double dp(Vd v) {
			return v.x * x + v.y * y;
		}

		public double cp(Vd v) {
			return x * v.y - y * v.x;
		}

		public Vd add(Vd v) {
			return new Vd(x + v.x, y + v.y);
		}

		public Vd subtract(Vd v) {
			return new Vd(x - v.x, y - v.y);
		}
	}

	public class Ld {
		Vd p1;
		Vd p2;

		public Ld(Vd p1, Vd p2) {
			this.p1 = p1;
			this.p2 = p2;
		}

		public Ld clone() {
			return new Ld(p1.clone(), p2.clone());
		}

		public String toString() {
			return p1 + " " + p2;
		}

		public Vd n() {
			double dx = p2.x - p1.x;
			double dy = p2.y - p1.y;
			double norm = Math.hypot(dx, dy);
			return new Vd(-dy / norm, dx / norm);
		}

		public Vd reflected(Vd p) {
			Vd n = n();
			return p.subtract(n.mult(2 * n.dp(p.subtract(p1))));
		}
	}

	public class Syst {
		Ld[] m;
		Vd e;
		boolean[] used;

		public Syst(Ld[] m, Vd e, boolean[] used) {
			this.m = m;
			this.e = e;
			this.used = used;
		}

		public void print() {
			for (int i = 0; i < m.length; i++) {
				System.err.println(m[i]);
			}
			System.err.println(e);
			for (int i = 0; i < used.length; i++) {
				System.err.println(used[i]);
			}
		}

		public Syst reflect(int i) {
			boolean[] used1 = used.clone();
			used1[i] = true;
			Ld[] m1 = new Ld[m.length];
			for (int j = 0; j < m.length; j++) {
				if (used1[j]) {
					m1[j] = m[j].clone();
				} else {
					m1[j] = new Ld(m[i].reflected(m[j].p1), m[i].reflected(m[j].p2));
				}
			}
			return new Syst(m1, m[i].reflected(e), used1);
		}
	}

	public boolean nextPermutation(int[] a) {
		int n = a.length;
		for (int i = n - 2; i >= 0; --i) {
			if (a[i] < a[i + 1]) {
				int len = n - i - 1;
				for (int j = 0; j < len / 2; ++j) {
					a[i + 1 + j] ^= a[n - 1 - j];
					a[n - 1 - j] ^= a[i + 1 + j];
					a[i + 1 + j] ^= a[n - 1 - j];
				}
				for (int j = i + 1; j < a.length; ++j) {
					if (a[j] > a[i]) {
						a[j] ^= a[i];
						a[i] ^= a[j];
						a[j] ^= a[i];
						return true;
					}
				}
			}
		}
		return false;
	}

	public double dist(Vd e, Ld l) {
		Vd v = l.p2.subtract(l.p1);
		if (Math.abs(v.cp(e)) < eps) {
			return 2;
		}
		return (l.p1.dp(e) * v.dp(v) - l.p1.dp(v) * e.dp(v)) / Math.pow(v.cp(e), 2);
	}

	public boolean achieve(Syst s, int[] a) {
		Syst[] syst = new Syst[a.length + 1];
		syst[0] = s;
		for (int i = 0; i < a.length; i++) {
			syst[i + 1] = syst[i].reflect(a[i]);
		}
		double min = 0;
		Vd e = syst[a.length].e;
		for (int i = 0; i < a.length; i++) {
			double cur = dist(e, syst[i].m[a[i]]);
			if (cur > 1 - eps || cur < min + eps) {
				return false;
			}
			for (int j = 0; j < s.m.length; j++) {
				if (!syst[i + 1].used[j]) {
					double d = dist(e, syst[i].m[j]);
					if (d > min - eps && d < cur + eps) {
						return false;
					}
				}
			}
			min = cur;
		}
		for (int i = 0; i < s.m.length; i++) {
			if (!syst[a.length].used[i]) {
				double d = dist(e, syst[a.length].m[i]);
				if (d > min - eps && d < 1 + eps) {
					return false;
				}
			}
		}
		return true;
	}

	double eps = 1e-9;

	public void add(HashMap<Integer, Long> map, int key, long value) {
		if (map.containsKey(key)) {
			map.put(key, map.get(key) + value);
		} else {
			map.put(key, value);
		}
	}


	public boolean check(int n, int x1, int y1, int x2, int y2) {
		return x1 < n && x2 < n && y1 < n && y2 < n;
	}

	public void solve() throws IOException {
		long[] maxn = new long[100001];
		long[] sum = new long[100001];
		for (int i = 1; i < sum.length; i++) {
			maxn[i] = sum[i - 1] + 1;
			sum[i] = sum[i - 1] + maxn[i];
			if (maxn[i] > 1e18 + 10) {
				maxn[i] = Long.MAX_VALUE / 4;
				sum[i] = maxn[i];
			}
		}
		maxn[0] = 1;
		for (int qwerty = in.nextInt(); qwerty > 0; qwerty--) {
			int n = in.nextInt();
			long k = in.nextLong();
//			int n = random.nextInt(100);
//			long k = random.nextLong() % 1000000000000000000L + 1;
//			System.err.println(n + " " + k);
			if (k > maxn[n]) {
				out.println(-1);
				continue;
			}
			int[] a = new int[n];
			for (int i = 0; i < n;) {
				int len = 1;
				while (k > maxn[n - i - len]) {
					k -= maxn[n - i - len];
					len++;
				}
				for (int j = 0; j < len; j++) {
					a[i + j] = i + len - j;
				}
				i += len;
			}
			for (int i = 0; i < a.length; i++) {
				out.print(a[i] + " ");
			}
			out.println();
		}
	}

	public void run() {
		try {
			if (systemIO) {
				in = new FastScanner(System.in);
				out = new PrintWriter(System.out);
			} else {
				in = new FastScanner(new File("adjustment.in"));
				out = new PrintWriter(new File("adjustment.out"));
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