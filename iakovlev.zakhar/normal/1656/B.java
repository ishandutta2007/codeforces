import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class B {
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

	public class SegmentTreeAdd {
		int pow;
		long[] max;
		long[] delta;
		boolean[] flag;

		public SegmentTreeAdd(long[] a) {
			pow = 1;
			while (pow < a.length) {
				pow *= 2;
			}
			flag = new boolean[2 * pow];
			max = new long[2 * pow];
			delta = new long[2 * pow];
			for (int i = 0; i < max.length; i++) {
				max[i] = Long.MIN_VALUE / 2;
			}
			for (int i = 0; i < a.length; i++) {
				max[pow + i] = a[i];
			}
			for (int i = pow - 1; i > 0; i--) {
				max[i] = f(max[2 * i], max[2 * i + 1]);
			}
		}

		public long get(int v, int tl, int tr, int l, int r) {
			push(v, tl, tr);
			if (l > r) {
				return Long.MIN_VALUE / 2;
			}
			if (l == tl && r == tr) {
				return max[v];
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
			max[v] = f(max[2 * v], max[2 * v + 1]);
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
				max[v] += delta[v];
				delta[v] = 0;
			}
		}

		public long f(long a, long b) {
			return Math.max(a, b);
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
			for (int i = pow - 1; i > 0; i--) {
				sum[i] = f(sum[2 * i], sum[2 * i + 1]);
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

	public void add(Map<Long, Integer> map, long l) {
		if (map.containsKey(l)) {
			map.put(l, map.get(l) + 1);
		} else {
			map.put(l, 1);
		}
	}

	public void remove(Map<Integer, Integer> map, Integer s) {
		if (map.get(s) > 1) {
			map.put(s, map.get(s) - 1);
		} else {
			map.remove(s);
		}
	}

	long max = Long.MAX_VALUE / 2;
	double eps = 1e-10;

	public int signum(double x) {
		if (x > eps) {
			return 1;
		}
		if (x < -eps) {
			return -1;
		}
		return 0;
	}

	public long abs(long x) {
		return x < 0 ? -x : x;
	}

	public long min(long x, long y) {
		return x < y ? x : y;
	}

	public long max(long x, long y) {
		return x > y ? x : y;
	}

	public long gcd(long x, long y) {
		while (y > 0) {
			long c = y;
			y = x % y;
			x = c;
		}
		return x;
	}

	public final Vector ZERO = new Vector(0, 0);

	// public class Vector implements Comparable<Vector> {
	// long x;
	// long y;
	// int type;
	// int number;
	//
	// public Vector() {
	// x = 0;
	// y = 0;
	// }
	//
	// public Vector(long x, long y, int type, int number) {
	// this.x = x;
	// this.y = y;
	// this.type = type;
	// this.number = number;
	// }
	//
	// public Vector(long x, long y) {
	//
	// }
	//
	// public Vector(Point begin, Point end) {
	// this(end.x - begin.x, end.y - begin.y);
	// }
	//
	// public void orient() {
	// if (x < 0) {
	// x = -x;
	// y = -y;
	// }
	// if (x == 0 && y < 0) {
	// y = -y;
	// }
	// }
	//
	// public void normalize() {
	// long gcd = gcd(abs(x), abs(y));
	// x /= gcd;
	// y /= gcd;
	// }
	//
	// public String toString() {
	// return x + " " + y;
	// }
	//
	// public boolean equals(Vector v) {
	// return x == v.x && y == v.y;
	// }
	//
	// public boolean collinear(Vector v) {
	// return cp(this, v) == 0;
	// }
	//
	// public boolean orthogonal(Vector v) {
	// return dp(this, v) == 0;
	// }
	//
	// public Vector ort(Vector v) {
	// return new Vector(-y, x);
	// }
	//
	// public Vector add(Vector v) {
	// return new Vector(x + v.x, y + v.y);
	// }
	//
	// public Vector multiply(long c) {
	// return new Vector(c * x, c * y);
	// }
	//
	// public int quater() {
	// if (x > 0 && y >= 0) {
	// return 1;
	// }
	// if (x <= 0 && y > 0) {
	// return 2;
	// }
	// if (x < 0) {
	// return 3;
	// }
	// return 0;
	// }
	//
	// public long len2() {
	// return x * x + y * y;
	// }
	//
	// @Override
	// public int compareTo(Vector o) {
	// if (quater() != o.quater()) {
	// return quater() - o.quater();
	// }
	// return signum(cp(o, this));
	// }
	// }

	// public long dp(Vector v1, Vector v2) {
	// return v1.x * v2.x + v1.y * v2.y;
	// }
	//
	// public long cp(Vector v1, Vector v2) {
	// return v1.x * v2.y - v1.y * v2.x;
	// }

	// public class Line implements Comparable<Line> {
	// Point p;
	// Vector v;
	//
	// public Line(Point p, Vector v) {
	// this.p = p;
	// this.v = v;
	// }
	//
	// public Line(Point p1, Point p2) {
	// if (p1.compareTo(p2) < 0) {
	// p = p1;
	// v = new Vector(p1, p2);
	// } else {
	// p = p2;
	// v = new Vector();
	// }
	// }
	//
	// public boolean collinear(Line l) {
	// return v.collinear(l.v);
	// }
	//
	// public boolean inLine(Point p) {
	// return hv(p) == 0;
	// }
	//
	// public boolean inSegment(Point p) {
	// if (!inLine(p)) {
	// return false;
	// }
	// Point p1 = p;
	// Point p2 = p.add(v);
	// return p1.x <= p.x && p.x <= p2.x && min(p1.y, p2.y) <= p.y && p.y <=
	// max(p1.y, p2.y);
	// }
	//
	// public boolean equalsSegment(Line l) {
	// return p.equals(l.p) && v.equals(l.v);
	// }
	//
	// public boolean equalsLine(Line l) {
	// return collinear(l) && inLine(l.p);
	// }
	//
	// public long hv(Point p) {
	// Vector v1 = new Vector(this.p, p);
	// return cp(v, v1);
	// }
	//
	// public double h(Point p) {
	// Vector v1 = new Vector(this.p, p);
	// return cp(v, v1) / Math.sqrt(v.len2());
	// }
	//
	// public long[] intersectLines(Line l) {
	// if (collinear(l)) {
	// return null;
	// }
	// long[] ans = new long[4];
	//
	// return ans;
	// }
	//
	// public long[] intersectSegment(Line l) {
	// long[] ans = intersectLines(l);
	// if (ans == null) {
	// return null;
	// }
	// Point p1 = p;
	// Point p2 = p.add(v);
	// boolean f1 = p1.x * ans[1] <= ans[0] && ans[0] <= p2.x * ans[1] && min(p1.y,
	// p2.y) * ans[3] <= ans[2]
	// && ans[2] <= max(p1.y, p2.y) * ans[3];
	// p1 = l.p;
	// p2 = l.p.add(v);
	// boolean f2 = p1.x * ans[1] <= ans[0] && ans[0] <= p2.x * ans[1] && min(p1.y,
	// p2.y) * ans[3] <= ans[2]
	// && ans[2] <= max(p1.y, p2.y) * ans[3];
	// if (!f1 || !f2) {
	// return null;
	// }
	// return ans;
	// }
	//
	// @Override
	// public int compareTo(Line o) {
	// return v.compareTo(o.v);
	// }
	// }

	public class Rect {
		long x1;
		long x2;
		long y1;
		long y2;
		int number;

		public Rect(long x1, long x2, long y1, long y2, int number) {
			this.x1 = x1;
			this.x2 = x2;
			this.y1 = y1;
			this.y2 = y2;
			this.number = number;
		}
	}

	public static class Fenvik {
		int[] t;

		public Fenvik(int n) {
			t = new int[n];
		}

		public void add(int x, int delta) {
			for (int i = x; i < t.length; i = (i | (i + 1))) {
				t[i] += delta;
			}
		}

		private int sum(int r) {
			int ans = 0;
			int x = r;
			while (x >= 0) {
				ans += t[x];
				x = (x & (x + 1)) - 1;
			}
			return ans;
		}

		public int sum(int l, int r) {
			return sum(r) - sum(l - 1);
		}
	}

	public class SegmentTreeMaxSum {
		int pow;
		int[] sum;
		int[] maxPrefSum;
		int[] maxSufSum;
		int[] maxSum;

		public SegmentTreeMaxSum(int[] a) {
			pow = 1;
			while (pow < a.length) {
				pow *= 2;
			}
			sum = new int[2 * pow];
			maxPrefSum = new int[2 * pow];
			maxSum = new int[2 * pow];
			maxSufSum = new int[2 * pow];
			for (int i = 0; i < a.length; i++) {
				sum[pow + i] = a[i];
				maxSum[pow + i] = Math.max(a[i], 0);
				maxPrefSum[pow + i] = maxSum[pow + i];
				maxSufSum[pow + i] = maxSum[pow + i];
			}
			for (int i = pow - 1; i > 0; i--) {
				update(i);
			}
		}

		public int[] get(int v, int tl, int tr, int l, int r) {
			if (r <= tl || l >= tr) {
				int[] ans = { 0, 0, 0, 0 };
				return ans;
			}
			if (l <= tl && r >= tr) {
				int[] ans = { maxPrefSum[v], maxSum[v], maxSufSum[v], sum[v] };
				return ans;
			}
			int tm = (tl + tr) / 2;
			int[] left = get(2 * v, tl, tm, l, r);
			int[] right = get(2 * v + 1, tm, tr, l, r);
			int[] ans = { Math.max(left[0], right[0] + left[3]),
					Math.max(left[1], Math.max(right[1], left[2] + right[0])), Math.max(right[2], left[2] + right[3]),
					left[3] + right[3] };
			return ans;
		}

		public void set(int v, int tl, int tr, int x, int value) {
			if (v >= pow) {
				sum[v] = value;
				maxSum[v] = Math.max(value, 0);
				maxPrefSum[v] = maxSum[v];
				maxSufSum[v] = maxSum[v];
				return;
			}
			int tm = (tl + tr) / 2;
			if (x < tm) {
				set(2 * v, tl, tm, x, value);
			} else {
				set(2 * v + 1, tm, tr, x, value);
			}
			update(v);
		}

		public void update(int i) {
			sum[i] = f(sum[2 * i], sum[2 * i + 1]);
			maxSum[i] = Math.max(maxSum[2 * i], Math.max(maxSum[2 * i + 1], maxSufSum[2 * i] + maxPrefSum[2 * i + 1]));
			maxPrefSum[i] = Math.max(maxPrefSum[2 * i], maxPrefSum[2 * i + 1] + sum[2 * i]);
			maxSufSum[i] = Math.max(maxSufSum[2 * i + 1], maxSufSum[2 * i] + sum[2 * i + 1]);
		}

		public int f(int a, int b) {
			return a + b;
		}
	}

	public class Point implements Comparable<Point> {
		double x;
		double y;

		public Point() {
			x = 0;
			y = 0;
		}

		public Point(double x, double y) {
			this.x = x;
			this.y = y;
		}

		public String toString() {
			return x + " " + y;
		}

		public boolean equals(Point p) {
			return x == p.x && y == p.y;
		}

		public double dist2() {
			return x * x + y * y;
		}

		public Point add(Point v) {
			return new Point(x + v.x, y + v.y);
		}

		@Override
		public int compareTo(Point o) {
			int z = signum(x + y - o.x - o.y);
			if (z != 0) {
				return z;
			}
			return signum(x - o.x) != 0 ? signum(x - o.x) : signum(y - o.y);
		}
	}

	public class Circle implements Comparable<Circle> {
		Point p;
		int r;

		public Circle(Point p, int r) {
			this.p = p;
			this.r = r;
		}

		public Point angle() {
			double z = r / sq2;
			z -= z % 1e-5;
			return new Point(p.x - z, p.y - z);
		}

		public boolean inside(Point p) {
			return hypot2(p.x - this.p.x, p.y - this.p.y) <= sq(r);
		}

		@Override
		public int compareTo(Circle o) {
			Point a = angle();
			Point oa = o.angle();
			int z = signum(a.x + a.y - oa.x - oa.y);
			if (z != 0) {
				return z;
			}
			return signum(a.y - oa.y);
		}

	}

	public class Fraction implements Comparable<Fraction> {
		long x;
		long y;

		public Fraction(long x, long y, boolean needNorm) {
			this.x = x;
			this.y = y;
			if (y < 0) {
				this.x *= -1;
				this.y *= -1;
			}
			if (needNorm) {
				long gcd = gcd(this.x, this.y);
				this.x /= gcd;
				this.y /= gcd;
			}
		}

		public Fraction clone() {
			return new Fraction(x, y, false);
		}

		public String toString() {
			return x + "/" + y;
		}

		@Override
		public int compareTo(Fraction o) {
			long res = x * o.y - y * o.x;
			if (res > 0) {
				return 1;
			}
			if (res < 0) {
				return -1;
			}
			return 0;
		}
	}

	public double sq(double x) {
		return x * x;
	}

	public long sq(long x) {
		return x * x;
	}

	public double hypot2(double x, double y) {
		return sq(x) + sq(y);
	}

	public long hypot2(long x, long y) {
		return sq(x) + sq(y);
	}

	public boolean kuhn(int v, int[][] edge, boolean[] used, int[] mt) {
		used[v] = true;
		for (int u : edge[v]) {
			if (mt[u] < 0 || (!used[mt[u]] && kuhn(mt[u], edge, used, mt))) {
				mt[u] = v;
				return true;
			}
		}
		return false;
	}

	public int matching(int[][] edge) {
		int n = edge.length;
		int[] mt = new int[n];
		Arrays.fill(mt, -1);
		boolean[] used = new boolean[n];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (!used[i] && kuhn(i, edge, used, mt)) {
				Arrays.fill(used, false);
				ans++;
			}
		}
		return ans;
	}

	double sq2 = Math.sqrt(2);

	int small = 20;

	public class MyStack {
		int[] st;
		int sz;

		public MyStack(int n) {
			this.st = new int[n];
			sz = 0;
		}

		public boolean isEmpty() {
			return sz == 0;
		}

		public int peek() {
			return st[sz - 1];
		}

		public int pop() {
			sz--;
			return st[sz];
		}

		public void clear() {
			sz = 0;
		}

		public void add(int x) {
			st[sz++] = x;
		}

		public int get(int x) {
			return st[x];
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

	public class Pol {
		double[] coeff;

		public Pol(double[] coeff) {
			this.coeff = coeff;
		}

		public Pol mult(Pol p) {
			double[] ans = new double[coeff.length + p.coeff.length - 1];
			for (int i = 0; i < ans.length; i++) {
				for (int j = Math.max(0, i - p.coeff.length + 1); j < coeff.length && j <= i; j++) {
					ans[i] += coeff[j] * p.coeff[i - j];
				}
			}
			return new Pol(ans);
		}

		public String toString() {
			String ans = "";
			for (int i = 0; i < coeff.length; i++) {
				ans += coeff[i] + " ";
			}
			return ans;
		}

		public double value(double x) {
			double ans = 0;
			double p = 1;
			for (int i = 0; i < coeff.length; i++) {
				ans += coeff[i] * p;
				p *= x;
			}
			return ans;
		}

		public double integrate(double r) {
			Pol p = new Pol(new double[coeff.length + 1]);
			for (int i = 0; i < coeff.length; i++) {
				p.coeff[i + 1] = coeff[i] / fact[i + 1];
			}
			return p.value(r);
		}

		public double integrate(double l, double r) {
			return integrate(r) - integrate(l);
		}
	}

	double[] fact = new double[100];

	public class SparseTable {
		int pow;
		int[] lessPow;
		int[][] min;

		public SparseTable(int[] a) {
			pow = 0;
			while ((1 << pow) <= a.length) {
				pow++;
			}
			min = new int[pow][a.length];
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

		public int get(int l, int r) { // [l, r)
			int p = lessPow[r - l];
			return func(min[p][l], min[p][r - (1 << p)]);
		}

		public int func(int a, int b) {
			if (a < b) {
				return a;
			}
			return b;
		}
	}

	public double check(int n, ArrayList<Integer> masks) {
		int good = 0;
		for (int colorMask = 0; colorMask < (1 << n); ++colorMask) {
			int best = 2 << n;
			int cnt = 0;
			for (int curMask : masks) {
				int curScore = 0;
				for (int i = 0; i < n; ++i) {
					if (((curMask >> i) & 1) == 1) {
						if (((colorMask >> i) & 1) == 0) {
							curScore += 1;
						} else {
							curScore += 2;
						}
					}
				}

				if (curScore < best) {
					best = curScore;
					cnt = 1;
				} else if (curScore == best) {
					++cnt;
				}
			}

			if (cnt == 1) {
				++good;
			}
		}

		return (double) good / (double) (1 << n);
	}

	public int builtin_popcount(int x) {
		int ans = 0;
		for (int i = 0; i < 14; i++) {
			if (((x >> i) & 1) > 0) {
				ans++;
			}
		}
		return ans;
	}

	public int number(int[] x) {
		int ans = 0;
		for (int i = 0; i < x.length; i++) {
			ans *= 3;
			ans += x[i];
		}
		return ans;
	}

	public int[] rotate(int[] x) {
		int[] ans = { x[2], x[0], x[3], x[1] };
		return ans;
	}

	int MAX = 100000;

	boolean[] b = new boolean[MAX];
	int[][] max0 = new int[MAX][2];
	int[][] max1 = new int[MAX][2];
	int[][] max2 = new int[MAX][2];
	int[] index0 = new int[MAX];
	int[] index1 = new int[MAX];
	int[] p = new int[MAX];

	public int place(String s) {
		if (s.charAt(s.length() - 1) == '1') {
			return 1;
		}
		int number = 16;
		boolean w = true;
		boolean a = true;
		for (int i = 0; i < s.length(); i++) {
			if (number == 1) {
				return 2;
			}
			if (s.charAt(i) == '1') {
				if (w) {
					number /= 2;
				} else {
					if (a) {
						a = false;
					} else {
						number /= 2;
						a = true;
					}
				}
			} else {
				if (w) {
					if (number == 16) {
						w = false;
						number /= 2;
					} else {
						w = false;
						a = false;
					}
				} else {
					if (number == 8) {
						if (a) {
							return 13;
						} else {
							return 9;
						}
					} else if (number == 4) {
						if (a) {
							return 7;
						} else {
							return 5;
						}
					} else if (a) {
						return 4;
					} else {
						return 3;
					}
				}
			}
		}
		return 0;
	}

	public class P implements Comparable<P> {
		Integer x;
		String s;

		public P(Integer x, String s) {
			this.x = x;
			this.s = s;
		}

		@Override
		public String toString() {
			return x + " " + s;
		}

		@Override
		public int compareTo(P o) {
			if (x != o.x) {
				return x - o.x;
			}
			return s.compareTo(o.s);
		}
	}

	public BigInteger prod(int l, int r) {
		if (l + 1 == r) {
			return BigInteger.valueOf(l);
		}
		int m = (l + r) >> 1;
		return prod(l, m).multiply(prod(m, r));
	}

	public class Frac {
		BigInteger p;
		BigInteger q;

		public Frac(BigInteger p, BigInteger q) {
			BigInteger gcd = p.gcd(q);
			this.p = p.divide(gcd);
			this.q = q.divide(gcd);
		}

		public String toString() {
			return p + "\n" + q;
		}

		public Frac(long p, long q) {
			this(BigInteger.valueOf(p), BigInteger.valueOf(q));
		}

		public Frac mul(Frac o) {
			return new Frac(p.multiply(o.p), q.multiply(o.q));
		}

		public Frac sum(Frac o) {
			return new Frac(p.multiply(o.q).add(q.multiply(o.p)), q.multiply(o.q));
		}

		public Frac diff(Frac o) {
			return new Frac(p.multiply(o.q).subtract(q.multiply(o.p)), q.multiply(o.q));
		}
	}

	public int[] transform(int[] x, int k, int step) {
		int n = x.length;
		int[] a = new int[n];
		int[][] prefsum = new int[n][];
		int[] elements = new int[n];
		int[] start = new int[n];
		int[] id = new int[n];
		for (int i = 0; i < n; i++) {
			if (elements[i] > 0) {
				continue;
			}
			int cur = i;
			do {
				elements[i]++;
				cur += step;
				cur %= n;
			} while (cur != i);
			for (int j = 0; j < elements[i]; j++) {
				start[cur] = i;
				id[cur] = j;
				elements[cur] = elements[i];
				cur += step;
				cur %= n;
			}
			prefsum[i] = new int[3 * elements[i] + 1];
			for (int j = 0; j < 3 * elements[i]; j++) {
				prefsum[i][j + 1] = prefsum[i][j] ^ x[cur];
				cur += step;
				cur %= n;
			}
		}
		for (int i = 0; i < x.length; i++) {
			int curlen = k % (2 * elements[i]);
			a[i] = prefsum[start[i]][id[i] + curlen] ^ prefsum[start[i]][id[i]];
		}
		return a;
	}

	public void solve() {
		f : for (int qwerty = in.nextInt(); qwerty > 0; --qwerty) {
			int n = in.nextInt();
			int k = in.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = in.nextInt();
			}
			TreeSet<Integer> set = new TreeSet<>();
			for (int i = 0; i < a.length; i++) {
				if (set.contains(a[i] - k) || set.contains(a[i] + k)) {
					out.println("YES");
					continue f;
				}
				set.add(a[i]);
			}
			out.println("NO");
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