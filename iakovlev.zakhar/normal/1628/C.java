import java.util.*;

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

	public class Tree {
		long[] sum;
		long[] min;
		int[] alive;
		int pow;
		long inf = Long.MAX_VALUE / 2;

		public Tree(long[] a, long[] b) {
			pow = 1;
			while (pow < a.length) {
				pow *= 2;
			}
			sum = new long[2 * pow];
			min = new long[2 * pow];
			for (int i = 0; i < min.length; i++) {
				min[i] = inf;
			}
			alive = new int[2 * pow];
			for (int i = 0; i < b.length; i++) {
				sum[pow + i] = a[i];
				min[pow + i] = a[i] + b[i];
				alive[pow + i] = 1;
			}
			for (int i = pow - 1; i > 0; i--) {
				merge(i);
			}
		}

		public void merge(int v) {
			sum[v] = sum[2 * v] + sum[2 * v + 1];
			min[v] = inf;
			if (min[2 * v] < min[v]) {
				min[v] = min[2 * v];
			}
			if (min[2 * v + 1] + sum[2 * v] < min[v]) {
				min[v] = min[2 * v + 1] + sum[2 * v];
			}
			alive[v] = alive[2 * v] + alive[2 * v + 1];
		}

		public void add(long a, long b, int c) {
			add(1, 0, pow, a, b, c - 1);
		}

		private void add(int v, int l, int r, long a, long b, int c) {
			if (v >= pow) {
				sum[v] = a;
				min[v] = a + b;
				alive[v] = 1;
				return;
			}
			int m = (l + r) / 2;
			if (c < m) {
				add(2 * v, l, m, a, b, c);
			} else {
				add(2 * v + 1, m, r, a, b, c);
			}
			merge(v);
		}

		public int update(long x) {
			return update(1, 0, pow, x);
		}

		private int update(int v, int l, int r, long x) {
			if (v >= pow) {
				if (x > min[v]) {
					sum[v] = 0;
					min[v] = inf;
					alive[v] = 0;
					return 1;
				}
				if (alive[v] == 1 && x >= sum[v]) {
					return 1;
				}
				return 0;
			}
			int m = (l + r) / 2;
			if (sum[2 * v] > x) {
				int ans = update(2 * v, l, m, x);
				merge(v);
				return ans;
			}
			int ans = alive[2 * v] + update(2 * v + 1, m, r, x - sum[2 * v]);
			if (x > min[2 * v]) {
				update(2 * v, l, m, x);
			}
			merge(v);
			return ans;
		}
	}

	public class MyStack {
		int[] st;
		int sz;

		public MyStack(int max) {
			st = new int[max];
			sz = 0;
		}

		public int size() {
			return sz;
		}

		public boolean isEmpty() {
			return sz == 0;
		}

		public int peek() {
			return st[sz - 1];
		}

		public int pop() {
			return st[--sz];
		}

		public void add(int x) {
			st[sz++] = x;
		}

		public void clear() {
			sz = 0;
		}
	}

	public long[][] mult(long[][] a, long[][] b) {
		long[][] c = new long[a.length][b[0].length];
		for (int i = 0; i < c.length; i++) {
			for (int j = 0; j < c[0].length; j++) {
				for (int k = 0; k < b.length; k++) {
					c[i][j] += a[i][k] * b[k][j];
					c[i][j] %= mod;
				}
			}
		}
		return c;
	}

	int mod = 998244353;

	public long[][] pow(long p, long[][] m) {
		if (p == 0) {
			long[][] matrix = new long[m.length][m.length];
			for (int i = 0; i < matrix.length; i++) {
				matrix[i][i] = 1;
			}
			return matrix;
		}
		if (p % 2 == 1) {
			return mult(m, pow(p - 1, m));
		}
		long[][] cur = pow(p / 2, m);
		return mult(cur, cur);
	}

	public void add(HashMap<Integer, Integer> map, int x) {
		if (map.containsKey(x)) {
			map.put(x, map.get(x) + 1);
		} else {
			map.put(x, 1);
		}
	}

	public class Point implements Comparable<Point> {
		long x;
		long y;
		int n;

		public Point(long x, long y, int n) {
			this.x = x;
			this.y = y;
			this.n = n;
		}

		public void norm() {
			long gcd = gcd(Math.abs(x), Math.abs(y));
			x /= gcd;
			y /= gcd;
		}

		public int quater() {
			if (x > 0 && y >= 0) {
				return 0;
			}
			if (x <= 0 && y > 0) {
				return 1;
			}
			if (x < 0) {
				return 2;
			}
			return 3;
		}

		public long mod2() {
			return x * x + y * y;
		}

		@Override
		public int compareTo(Point o) {
			if (quater() != o.quater()) {
				return quater() - o.quater();
			}
			int s = sign(cp(o, this));
			if (s != 0) {
				return s;
			}
			return sign(mod2() - o.mod2());
		}
	}

	public long cp(Point a, Point b) {
		return a.x * b.y - a.y * b.x;
	}

	public int sign(long x) {
		if (x > 0) {
			return 1;
		}
		if (x < 0) {
			return -1;
		}
		return 0;
	}

	public class Vector {
		double x;
		double y;

		public Vector(double x, double y) {
			this.x = x;
			this.y = y;
		}

		public double norm() {
			return Math.sqrt(norm2());
		}

		public double norm2() {
			return x * x + y * y;
		}

		public String toString() {
			return x + " " + y;
		}

		public Vector negative() {
			return new Vector(-x, -y);
		}

		public Vector add(Vector v) {
			return new Vector(x + v.x, y + v.y);
		}

		public Vector subtract(Vector v) {
			return new Vector(x - v.x, y - v.y);
		}

	}

	public double dp(Vector a, Vector b) {
		return a.x * b.x + a.y * b.y;
	}

	public double cp(Vector a, Vector b) {
		return a.x * b.y - a.y * b.x;
	}

	public class Polygon {
		Vector[] v;
		double s;

		public Polygon(Vector[] v) {
			this.v = v;
			s = Math.abs(s());
		}

		public double s() {
			double ans = 0;
			for (int i = 1; i < v.length - 1; i++) {
				Vector a = v[i].subtract(v[0]);
				Vector b = v[i + 1].subtract(v[0]);
				ans += cp(a, b);
			}
			return ans / 2;
		}

		public boolean intersect(Vector o, double r) {
			for (int i = 0; i < v.length; i++) {
				if (intersectSeg(v[i], v[(i + 1) % v.length], o, r)) {
					return true;
				}
			}
			boolean inside = false;
			for (int i = 0; i < v.length; i++) {
				inside ^= intersectRay(v[i], v[(i + 1) % v.length], o);
			}
			if (inside) {
				System.err.println(o + " " + s);
				return true;
			}
			return false;
		}
	}

	public double sq(double x) {
		return x * x;
	}

	public boolean intersectSeg(Vector a, Vector b, Vector o, double r) {
		Vector ao = o.subtract(a);
		Vector bo = o.subtract(b);
		if (ao.norm2() <= r * r * (1 + eps) || bo.norm2() <= r * r * (1 + eps)) {
			return true;
		}
		Vector ab = b.subtract(a);
		if (sq(Math.abs(cp(ao, bo))) > ab.norm2() * r * r * (1 + eps)) {
			return false;
		}
		if (dp(ao, ab) < -eps || dp(bo, ab) > eps) {
			return false;
		}
		return true;
	}

	public boolean intersectRay(Vector a, Vector b, Vector o) {
		if (a.y == b.y) {
			return false;
		}
		if (o.y == Math.max(a.y, b.y) && o.x < Math.min(a.x, b.x)) {
			return true;
		}
		if (o.y == Math.min(a.y, b.y)) {
			return false;
		}
		if ((o.y - a.y) * (o.y - b.y) < 0) {
			if (a.y < b.y) {
				if (cp(b.subtract(a), o.subtract(a)) > 0) {
					return true;
				}
			} else {
				if (cp(b.subtract(a), o.subtract(a)) < 0) {
					return true;
				}
			}
		}
		return false;
	}

	double eps = 0;

	Random random = new Random(566);

	public class SegmentTreeSet {
		int pow;
		long[] sum;
		long[] max;
		long[] min;
		long[] delta;
		boolean[] flag;

		public SegmentTreeSet(long[] a) {
			pow = 1;
			while (pow < a.length) {
				pow *= 2;
			}
			flag = new boolean[2 * pow];
			sum = new long[2 * pow];
			max = new long[2 * pow];
			min = new long[2 * pow];
			delta = new long[2 * pow];
			for (int i = 0; i < a.length; i++) {
				sum[pow + i] = a[i];
				max[pow + i] = a[i];
				min[pow + i] = a[i];
			}
			for (int i = pow - 1; i > 0; i--) {
				sum[i] = sum[2 * i] + sum[2 * i + 1];
				max[i] = max[2 * i];
				min[i] = min[2 * i + 1];
			}
		}

		public int get(int v, int tl, int tr, int l, int r) {
			push(v, tl, tr);
			if (l >= tr || r <= tl) {
				return 0;
			}
			if (l <= tl && r >= tr) {
				if (money >= sum[v]) {
					money -= sum[v];
					return tr - tl;
				}
				if (money < min[v]) {
					return 0;
				}
			}
			int tm = (tl + tr) / 2;
			return get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm, tr, l, r);
		}

		public void set(int v, int tl, int tr, int l, int r, long x) {
			push(v, tl, tr);
			if (l >= tr || r <= tl) {
				return;
			}
			if (l <= tl && r >= tr) {
				if (x >= max[v]) {
					delta[v] = x;
					flag[v] = true;
					push(v, tl, tr);
				} else if (v < pow) {
					int tm = (tl + tr) / 2;
					push(2 * v + 1, tm, tr);
					if (x >= max[2 * v + 1]) {
						delta[2 * v + 1] = x;
						flag[2 * v + 1] = true;
						push(2 * v + 1, tm, tr);
						set(2 * v, tl, tm, l, r, x);
					} else {
						push(2 * v, tl, tm);
						set(2 * v + 1, tm, tr, l, r, x);
					}
					sum[v] = (sum[2 * v] + sum[2 * v + 1]);
					max[v] = max[2 * v];
					min[v] = min[2 * v + 1];
				}
				return;
			}
			int tm = (tl + tr) / 2;
			set(2 * v, tl, tm, l, r, x);
			set(2 * v + 1, tm, tr, l, r, x);
			sum[v] = (sum[2 * v] + sum[2 * v + 1]);
			max[v] = max[2 * v];
			min[v] = min[2 * v + 1];
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
				sum[v] = delta[v] * (tr - tl);
				max[v] = delta[v];
				min[v] = delta[v];
			}
		}
		
		public int f(int a, int b) {
			return a + b;
		}
	}
	
	long money = 0;

	public long[] diofant(long a, long b) {
		long[] ans = new long[2];
		if (b == 0) {
			ans[0] = 1;
			ans[1] = 0;
			return ans;
		}
		long div = a / b;
		long mod = a % b;
		long[] get = diofant(b, mod);
		ans[0] = get[1];
		ans[1] = get[0] - (get[1] * div);
		return ans;
	}

	public class Arr implements Comparable<Arr> {
		int[] a;

		public Arr(int[] a) {
			this.a = a;
		}

		@Override
		public int compareTo(Arr o) {
			for (int i = 0; i < comp.length; i++) {
				if (a[comp[i]] != o.a[comp[i]]) {
					return a[comp[i]] - o.a[comp[i]];
				}
			}
			return 0;
		}
		
	}
	
	int[] comp;
	
	public void dfs(int v) {
		boolean flag = false;
		if (!used[v]) {
			used[v] = true;
			flag = true;
			ans.add(v);
		}
		for (int x = 0; x < sz; x++) {
			if (!used[x] && g[v][x]) {
				used[x] = flag;
				dfs(x);
			}
		}
	}
	
	public int components() {
		int c = 0;
		for (int i = 0; i < sz; i++) {
			if (!used[i]) {
				dfs(i);
				c++;
			}
		}
		return c;
	}

	int max = 500;
	boolean[][] g = new boolean[2 * max][2 * max];
	boolean[] used = new boolean[2 * max];
	int[][] value = new int[max][max];
	int sz = -1;
	ArrayList<Integer> ans = new ArrayList<>();
	
	public boolean check(int x, int y) {
		return x >= 0 && y >= 0 && x < n && y < n;
	}
	
	int n;
	
	int[] dx = {-1, 0, 1, 0};
	int[] dy = {0, -1, 0, 1};
	
	public void solve() {
		for (int qwerty = in.nextInt(); qwerty > 0; qwerty--) {
			n = in.nextInt();
			boolean[][] used = new boolean[n][n];
			for (int i = 0; i < n; i += 2) {
				used[0][i] = true;
				for (int row = 0; row < i; row++) {
					int x = row;
					int y = i - 1 - row;
					int sum = 0;
					for (int j = 0; j < dx.length; j++) {
						if (check(x + dx[j], y + dy[j]) && used[x + dx[j]][y + dy[j]]) {
							sum++;
						}
					}
					if (sum % 2 == 0) {
						used[row + 1][y] = true;
					}
				}
			}
			for (int i = n; i < 2 * n; i += 2) {
				for (int row = i - n; row < n - 1; row++) {
					int x = row;
					int y = i - 1 - row;
					int sum = 0;
					for (int j = 0; j < dx.length; j++) {
						if (check(x + dx[j], y + dy[j]) && used[x + dx[j]][y + dy[j]]) {
							sum++;
						}
					}
					if (sum % 2 == 0) {
						used[row + 1][y] = true;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if ((i + j) % 2 == 1) {
						used[i][j] = used[i][n - 1 - j];
					}
				}
			}
			int ans = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					int x = in.nextInt();
					if (used[i][j]) {
						ans ^= x;
					}
				}
			}
			out.println(ans);
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
		new C().run();
		System.err.println(System.currentTimeMillis() - time);
	}
}