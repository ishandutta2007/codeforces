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

	Random random = new Random(566);

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

		public Vector clone() {
			return new Vector(x, y);
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

	public void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		ArrayList<Long> arr = new ArrayList<>(n);
		long[] b = new long[m];
		for (int i = 0; i < n; i++) {
			arr.add(in.nextLong());
		}
		Collections.shuffle(arr);
		long[] a = new long[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = arr.get(i);
		}
		Arrays.sort(a);
		for (int i = 0; i < b.length; i++) {
			b[i] = in.nextLong();
		}
		long gcd = 0;
		for (int i = 1; i < n; i++) {
			gcd = gcd(gcd, a[i] - a[0]);
		}
		for (int i = 0; i < b.length; i++) {
			out.print(gcd(gcd, a[0] + b[i]) + " ");
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
		new C().run();
	}
}