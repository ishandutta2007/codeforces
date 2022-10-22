import java.util.*;

import java.io.*;

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
	
	public class New implements Comparable<New> {
		int a;
		int t;
		int id;
		
		public New(int a, int t, int id) {
			this.a = a;
			this.t = t;
			this.id = id;
		}

		@Override
		public int compareTo(New o) {
			if (t != o.t) {
				return t - o.t;
			}
			if (a != o.a) {
				return a - o.a;
			}
			return id - o.id;
		}
		
	}

	public void solve() {
		int n = in.nextInt();
		New[] news = new New[n];
		int[] a = new int[n];
		int[] t = new int[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = in.nextInt();
		}
		for (int i = 0; i < t.length; i++) {
			t[i] = in.nextInt();
		}
		for (int i = 0; i < n; i++) {
			news[i] = new New(a[i], t[i], i);
		}
		long ans = 0;
		for (int i = 1; i < news.length; i++) {
			int x = random.nextInt(i);
			New th = news[x];
			news[x] = news[i];
			news[i] = th;
		}
		Arrays.sort(news);
		TreeSet<Integer> free = new TreeSet<>();
		HashSet<Integer> used = new HashSet<>();
		for (int i = news.length - 1; i >= 0; i--) {
			Integer place = free.higher(news[i].a);
			if (!used.contains(news[i].a)) {
				place = news[i].a;
			}
			ans += news[i].t * 1L * (place - news[i].a);
			used.add(place);
			if (free.contains(place)) {
				free.remove(place);
			}
			if (!used.contains(place + 1)) {
				free.add(place + 1);
			}
		}
		out.print(ans);
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