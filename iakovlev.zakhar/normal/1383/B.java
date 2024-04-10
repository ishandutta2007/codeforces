import java.util.*;

import java.io.*;
import java.math.BigInteger;

public class F {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public long pow(long x, long p, long mod) {
		if (p <= 0) {
			return 1;
		}
		long th = pow(x, p / 2, mod);
		th *= th;
		th %= mod;
		if (p % 2 == 1) {
			th *= x;
		}
		return th;
	}

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

	// public class Vertex {
	// Vertex father;
	// Vertex l;
	// Vertex r;
	// int sz;
	// long y;
	// long x;
	// int time;
	// int mintime;
	// int value;
	//
	// public Vertex(Vertex father, Vertex l, Vertex r, int sz, long y, long x, int
	// time, int mintime, int value) {
	// this.father = father;
	// this.l = l;
	// this.r = r;
	// this.sz = sz;
	// this.y = y;
	// this.x = x;
	// this.time = time;
	// this.mintime = mintime;
	// this.value = value;
	// }
	//
	// public Vertex(long x, int time, int value) {
	// this.father = null;
	// this.l = null;
	// this.r = null;
	// this.sz = 1;
	// this.y = random.nextLong();
	// this.x = x;
	// this.time = time;
	// this.mintime = time;
	// this.value = value;
	// }
	//
	// public void update() {
	// sz = 1;
	// mintime = time;
	// if (l != null) {
	// sz += l.sz;
	// mintime = Math.min(time, mintime);
	// }
	// if (r != null) {
	// sz += r.sz;
	// mintime = Math.min(time, mintime);
	// }
	// }
	// }
	//
	// public void add0(Vertex v, Vertex v1, Vertex father) {
	// if (v == null) {
	// v1.father = father;
	// father.r = v1;
	// father.update();
	// return;
	// }
	// if (v.y >= v1.y) {
	// add0(v.r, v1, v);
	// father.update();
	// return;
	// }
	// father.r = v1;
	// v1.father = father;
	// v.father = v1;
	// v1.l = v;
	// v1.update();
	// father.update();
	// }
	//
	// public Vertex pop(Vertex v, Vertex father, int h) {
	// if (v.l == null) {
	// if (h == 0) {
	// father.r = v.r;
	// } else {
	// father.l = v.r;
	// }
	// if (v.r != null) {
	// v.r.father = father;
	// v.r.update();
	// }
	// father.update();
	// v.father = null;
	// v.r = null;
	// v.update();
	// return v;
	// }
	// Vertex ans = pop(v.l, v, h + 1);
	// father.update();
	// return ans;
	// }
	//
	// public void cut(Vertex rl, Vertex rr, Vertex v, int mint) {
	//
	// }
	//
	// public int push(Vertex v, Vertex v1, Vertex father, boolean rson, int szl) {
	//
	// }
	//
	// Vertex root0;

	// public class State implements Comparable<State> {
	// int[] a;
	//
	// public State(int[] a) {
	// this.a = a;
	// }
	//
	// @Override
	// public int compareTo(State o) {
	// for (int i = 0; i < a.length; i++) {
	// if (a[i] != o.a[i]) {
	// return a[i] - o.a[i];
	// }
	// }
	// return 0;
	// }
	// }

	public long[] mult1(long[] a, long[] b) {
		int n = a.length;
		long[] c = new long[n];
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n; k++) {
				c[i] += a[i ^ k] * b[k];
				c[i] %= mod;
			}
		}
		return c;
	}

	public long[][] mult(long[][] a, long[][] b) {
		int n = a.length;
		long[][] c = new long[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					c[i][j] += a[i][k] * b[k][j];
					c[i][j] %= mod;
				}
			}
		}
		return c;
	}

	public long[][] pow(long[][] x, long p) {
		if (p == 0) {
			long[][] e = new long[x.length][x.length];
			for (int i = 0; i < e.length; i++) {
				e[i][i] = 1;
			}
			return e;
		}
		long[][] ans = pow(x, p / 2);
		ans = mult(ans, ans);
		if (p % 2 == 1) {
			ans = mult(ans, x);
		}
		return ans;
	}

	public long[] mult(long[] a, long[] b) {
		int n = a.length;
		long[] c = new long[n];
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n; k++) {
				c[i] += a[k] * b[k ^ i];
				c[i] %= mod;
			}
		}
		return c;
	}

	public long[] pow(long[] x, long p) {
		if (p == 0) {
			long[] e = new long[x.length];
			e[0] = 1;
			return e;
		}
		long[] ans = pow(x, p / 2);
		ans = mult(ans, ans);
		if (p % 2 == 1) {
			ans = mult(ans, x);
		}
		return ans;
	}

	public long pow(long x, long p) {
		if (p <= 0) {
			return 1;
		}
		long ans = pow(x, p / 2);
		ans = (ans * ans) % mod;
		if (p % 2 == 1) {
			ans = (ans * x) % mod;
		}
		return ans;
	}

	public long modInv(long x) {
		return pow(x, mod - 2);
	}

	Random random = new Random(566);
	ArrayList<Integer>[] to;

	public static class Factorizator {
		int[] div;
		ArrayList<Integer> primes;

		public Factorizator(int max) {
			div = new int[max + 1];
			primes = new ArrayList<Integer>();
			for (int i = 2; i < div.length; i++) {
				if (div[i] == 0) {
					div[i] = i;
					primes.add(i);
				}
				for (int j : primes) {
					if (i * j > max) {
						break;
					}
					div[i * j] = j;
				}
			}
		}

		public ArrayList<Integer> factorization(int x) {
			ArrayList<Integer> ans = new ArrayList<Integer>();
			while (div[x] > 0) {
				ans.add(div[x]);
				x /= div[x];
			}
			return ans;
		}

		public int[] all_divisors(int x) {
			ArrayList<Integer> div = factorization(x);
			int len = div.size();
			TreeSet<Integer> set = new TreeSet<>();
			for (int mask = 0; mask < (1 << len); mask++) {
				int th = 1;
				for (int i = 0; i < len; i++) {
					if ((mask & (1 << i)) > 0) {
						th *= div.get(i);
					}
				}
				set.add(th);
			}
			int[] ans = new int[set.size()];
			int iter = 0;
			for (int i : set) {
				ans[iter++] = i;
			}
			return ans;
		}

		public int[] divisors(int x) {
			ArrayList<Integer> div = factorization(x);
			int pr = 0;
			for (int i = 0; i < div.size(); i++) {
				if (i == 0 || div.get(i) != div.get(i - 1)) {
					pr++;
				}
			}
			int[] primes = new int[pr];
			int[] sz = new int[pr];
			pr = -1;
			for (int i = 0; i < div.size(); i++) {
				if (i == 0 || div.get(i) != div.get(i - 1)) {
					pr++;
					primes[pr] = div.get(i);
					sz[pr] = 1;
				} else {
					sz[pr]++;
				}
			}
			pr++;
			int[][] pow = new int[pr][];
			for (int i = 0; i < pow.length; i++) {
				pow[i] = new int[sz[i] + 1];
				pow[i][0] = 1;
				for (int j = 1; j < pow[i].length; j++) {
					pow[i][j] = pow[i][j - 1] * primes[i];
				}
			}
			int[] th = new int[pr];
			TreeSet<Integer> ans = new TreeSet<>();
			do {
				int z = 1;
				for (int i = 0; i < th.length; i++) {
					z *= pow[i][th[i]];
				}
				ans.add(z);
			} while (next(th, sz));
			int[] answer = new int[ans.size()];
			int iter = 0;
			for (int i : ans) {
				answer[iter++] = i;
			}
			return answer;
		}

		public boolean next(int[] th, int[] max) {
			for (int i = th.length - 1; i >= 0; i--) {
				if (th[i] != max[i]) {
					th[i]++;
					for (int j = i + 1; j < max.length; j++) {
						th[j] = 0;
					}
					return true;
				}
			}
			return false;
		}

		public String factorizationToString(int x) {
			if (x == 1) {
				return "1 = 1";
			}
			ArrayList<Integer> list = factorization(x);
			String ans = x + " = ";
			for (int i = 0; i < list.size(); i++) {
				ans += list.get(i);
				if (i < list.size() - 1) {
					ans += " * ";
				}
			}
			return ans;
		}
	}

	public class Rect {
		int x1;
		int y1;
		int x2;
		int y2;

		public Rect(int x1, int y1, int x2, int y2) {
			this.x1 = x1;
			this.y1 = y1;
			this.x2 = x2;
			this.y2 = y2;
		}

		public String toString() {
			return x1 + " " + y1 + " " + x2 + " " + y2;
		}

		public boolean equals(Rect r) {
			return x1 == r.x1 && y1 == r.y1 && x2 == r.x2 && y2 == r.y2;
		}

		public int inside(int x, int y) {
			int inx = in(x1, x2, x);
			int iny = in(y1, y2, y);
			return inx * iny;
		}

		public int additional(Rect r) {
			if (equals(r)) {
				return 0;
			}
			if (inside(r.x1, r.y1) == 4 || inside(r.x2, r.y2) == 4 || inside(r.x1, r.y2) == 4
					|| inside(r.x2, r.y1) == 4) {
				return 1;
			}
			if (inside(r.x1, r.y1) == 1 || inside(r.x2, r.y2) == 1) {
				return 1;
			}
			return 2;
		}
	}

	public int in(int min, int max, int x) {
		if (x == min || x == max) {
			return 1;
		}
		if (x > min && x < max) {
			return 2;
		}
		return 0;
	}

	public long sum(long x, long y) {
		return ((x + y) % mod + mod) % mod;
	}

	public long mult(long x, long y) {
		return x * y % mod;
	}

	public long div(long x, long y) {
		return x * modInv(y) % mod;
	}
	
	long mod = 998244353;

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
		
		public SegmentTreeAdd(int n) {
			pow = 1;
			while (pow < n) {
				pow *= 2;
			}
			flag = new boolean[2 * pow];
			max = new long[2 * pow];
			delta = new long[2 * pow];
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
	
	public class Circle implements Comparable<Circle> {
		int x;
		int y;
		int r;
		
		public Circle(int x, int y, int r) {
			this.x = x;
			this.y = y;
			this.r = r;
		}
		
		public Circle clone() {
			return new Circle(x, y, r);
		}

		@Override
		public int compareTo(Circle o) {
			if (r != o.r) {
				return r - o.r;
			}
			if (x != o.x) {
				return x - o.x;
			}
			return y - o.y;
		}
	}
	
	public class Point implements Comparable<Point> {
		double angle;
		int type;
		
		public Point(double angle, int type) {
			this.angle = angle;
			this.type = type;
		}
		
		public String toString() {
			return angle + " " + type;
		}

		@Override
		public int compareTo(Point o) {
			if (angle > o.angle) {
				return 1;
			}
			if (angle < o.angle) {
				return -1;
			}
			return type - o.type;
		}
		
	}
	
	public boolean inside(Circle small, Circle big) {
		return (small.x - big.x) * (small.x - big.x) + (small.y - big.y) * (small.y - big.y) <= (big.r - small.r) * (big.r - small.r);
	}
	
	public double[] tangent(Circle c1, Circle c2) {
		Circle a = c1.clone();
		Circle b = c2.clone();
		int minr = Math.min(a.r, b.r);
		a.r -= minr;
		b.r -= minr;
		b.x -= a.x;
		b.y -= a.y;
		double a0 = Math.atan2(b.y, b.x);
		double len = Math.sqrt(b.x * b.x + b.y * b.y);
		double da = 0;
		if (a.r == 0) {
			da = Math.asin(b.r / len) + Math.PI / 2;
		} else {
			da = Math.acos(a.r / len);
		}
		double[] ans = {a0 - da, a0 + da};
		return ans;
	}
	
	public double[] norm(double[] ans) {
		for (int i = 0; i < ans.length; i++) {
			while (ans[i] < 0) {
				ans[i] += 2 * Math.PI;
			}
			while (ans[i] > 2 * Math.PI) {
				ans[i] -= 2 * Math.PI;
			}
		}
		if (ans[0] > ans[1]) {
			double[] answer = {0, ans[1], ans[0], 2 * Math.PI};
			return answer;
		}
		return ans;
	}
	
	public void solve() {
		f : for (int qwerty = in.nextInt(); qwerty > 0; qwerty--) {
			int n = in.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = in.nextInt();
			}
			int[] b = new int[31];
			int xor = 0;
			for (int i = 0; i < a.length; i++) {
				xor ^= a[i];
				for (int j = 0; j < b.length; j++) {
					if ((a[i] & (1 << j)) > 0) {
						b[j]++;
					}
				}
			}
			if (xor == 0) {
				out.println("DRAW");
				continue;
			}
			for (int i = b.length - 1; i >= 0; i--) {
				if (b[i] % 2 == 1) {
					if (b[i] % 4 == 1 || (n - b[i]) % 2 == 1) {
						out.println("WIN");
					} else {
						out.println("LOSE");
					}
					break;
				}
			}
		}
	}

	public class Line {
		long k;
		long b;

		public Line(long k, long b) {
			this.k = k;
			this.b = b;
		}

		public Line(long x, long y, long k) {
			this(k, y - x * k);
		}

		public String toString() {
			return k + "x + " + b;
		}

		public long value(long x) {
			return k * x + b;
		}
	}

	public class LiChaoTree {
		boolean branchUp;
		long neutral;
		int pow;
		Line[] ch;

		public LiChaoTree(int n, boolean branchUp) {
			this.branchUp = branchUp;
			if (branchUp) {
				neutral = Long.MIN_VALUE / 2;
			} else {
				neutral = Long.MAX_VALUE / 2;
			}
			pow = 1;
			while (pow < n) {
				pow *= 2;
			}
			ch = new Line[2 * pow];
		}

		public boolean better(double a, double b) {
			return branchUp ^ a < b;
		}

		public long function(long a, long b) {
			return branchUp ^ a < b ? a : b;
		}

		private void add(int v, int l, int r, Line line) {
			if (ch[v] == null) {
				ch[v] = line;
				return;
			}
			if (v >= pow) {
				if (v % 2 == 0) {
					if (better(line.value(l), ch[v].value(l))) {
						ch[v] = line;
					}
				} else {
					if (better(line.value(r), ch[v].value(r))) {
						ch[v] = line;
					}
				}
				return;
			}
			int m = (l + r) / 2;
			if (better(line.value(m), ch[v].value(m))) {
				Line c = line;
				line = ch[v];
				ch[v] = c;
			}
			if (better(line.value(l), ch[v].value(l))) {
				add(2 * v, l, m, line);
			}
			if (better(line.value(r), ch[v].value(r))) {
				add(2 * v + 1, m, r, line);
			}
		}

		public void add(Line line) {
			add(1, 0, pow, line);
		}

		private long get(int v, int l, int r, int x) {
			if (ch[v] == null) {
				return neutral;
			}
			if (v >= pow) {
				return ch[v].value(x);
			}
			long ans = ch[v].value(x);
			int m = (l + r) / 2;
			if (x <= m) {
				ans = function(ans, get(2 * v, l, m, x));
			}
			if (x >= m) {
				ans = function(ans, get(2 * v + 1, m, r, x));
			}
			return ans;
		}

		public long get(int x) {
			return get(1, 0, pow, x);
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
		new F().run();
	}
}