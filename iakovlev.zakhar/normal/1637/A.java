import java.io.*;
import java.util.*;

public class A {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Pair {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public int gcd(int x, int y) {
		if (y == 0) {
			return x;
		}
		if (x == 0) {
			return y;
		}
		return gcd(y, x % y);
	}

	public class Edge {
		int to;
		long s;

		public Edge(int to, long s) {
			this.to = to;
			this.s = s;
		}
	}

	public long dfsLCA(int v, int prev, long sumth, long minsum, long s) {
		tin[v] = timer;
		timer++;
		up[v][0] = new Edge(prev, s);
		for (int i = 1; i <= l; i++) {
			Edge e = up[v][i - 1];
			up[v][i] = new Edge(up[e.to][i - 1].to, up[e.to][i - 1].s + e.s);
		}
		minsum = Math.min(minsum, sumth);
		maxup[v] = sumth - minsum;
		long mxdown = sumth;
		for (Edge e : list[v]) {
			if (e.to != prev) {
				mxdown = Math.max(mxdown, dfsLCA(e.to, v, sumth + e.s, minsum, e.s));
			}
		}
		tout[v] = timer;
		timer++;
		maxdown[v] = mxdown - sumth;
		return mxdown;
	}

	public boolean upper(int a1, int b1) {
		return tin[a1] <= tin[b1] && tout[a1] >= tout[b1];
	}

	public Edge lca(int a, int b) {
		if (a == b) {
			return new Edge(a, 0);
		}
		int v = -1;
		int a1 = a;
		int b1 = b;
		if (tin[a] <= tin[b] && tout[a] >= tout[b]) {
			v = b;
			long lenb = 0;
			for (int i = l; i >= 0; i--) {
				a1 = up[v][i].to;
				b1 = a;
				if (!(tin[a1] <= tin[b1] && tout[a1] >= tout[b1])) {
					lenb += up[v][i].s;
					v = up[v][i].to;
				}
			}
			lenb += up[v][0].s;
			v = up[v][0].to;
			return new Edge(v, lenb);
		}
		if (upper(b, a)) {
			v = a;
			long lena = 0;
			for (int i = l; i >= 0; i--) {
				a1 = up[v][i].to;
				b1 = b;
				if (!(tin[a1] <= tin[b1] && tout[a1] >= tout[b1])) {
					lena += up[v][i].s;
					v = up[v][i].to;
				}
			}
			lena += up[v][0].s;
			v = up[v][0].to;
			return new Edge(v, lena);
		}
		v = a;
		long lena = 0;
		for (int i = l; i >= 0; i--) {
			a1 = up[v][i].to;
			b1 = b;
			if (!(tin[a1] <= tin[b1] && tout[a1] >= tout[b1])) {
				lena += up[v][i].s;
				v = up[v][i].to;
			}
		}
		lena += up[v][0].s;
		v = up[v][0].to;
		v = b;
		long lenb = 0;
		for (int i = l; i >= 0; i--) {
			a1 = up[v][i].to;
			b1 = a;
			if (!(tin[a1] <= tin[b1] && tout[a1] >= tout[b1])) {
				lenb += up[v][i].s;
				v = up[v][i].to;
			}
		}
		lenb += up[v][0].s;
		v = up[v][0].to;
		return new Edge(v, lena + lenb);
	}

	int n;
	int l;
	int[] tin;
	int[] tout;
	int timer = 0;
	long[] maxup;
	long[] maxdown;
	Edge[][] up;
	ArrayList<Edge>[] list;

	public int signum(long x) {
		if (x > 0) {
			return 1;
		}
		if (x < 0) {
			return -1;
		}
		return 0;
	}

	public class Point implements Comparable<Point> {
		long x;
		long y;

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

		public long sqDist(Point o) {
			return (x - o.x) * (x - o.x) + (y - o.y) * (y - o.y);
		}

		public void subtract(Point p) {
			x -= p.x;
			y -= p.y;
		}

		@Override
		public int compareTo(Point o) {
			if (x != o.x) {
				return signum(x - o.x);
			}
			return signum(y - o.y);
		}
	}

	public class DSU {
		int[] p;
		int[] sz;

		public DSU(int n) {
			p = new int[n];
			sz = new int[n];
			for (int i = 0; i < p.length; i++) {
				p[i] = i;
				sz[i] = 1;
			}
		}

		public int get(int v) {
			if (p[v] == v) {
				return v;
			}
			return p[v] = get(p[v]);
		}

		public boolean unite(int a, int b) {
			a = get(a);
			b = get(b);
			if (a == b) {
				return false;
			}
			if (sz[a] < sz[b]) {
				sz[b] += sz[a];
				p[a] = b;
			} else {
				sz[a] += sz[b];
				p[b] = a;
			}
			return true;
		}
	}

	public class Arr implements Comparable<Arr> {
		int[] a;

		public Arr(int[] a) {
			this.a = a;
		}

		@Override
		public int compareTo(Arr o) {
			return a[0] - o.a[0];
		}
	}

	public class Segment implements Comparable<Segment> {
		double quantity;
		int color;
		int number;

		public Segment(double quantity, int color, int number) {
			this.quantity = quantity;
			this.color = color;
			this.number = number;
		}

		@Override
		public int compareTo(Segment o) {
			return (int) Math.signum(o.quantity - quantity);
		}
	}

	public class Fenvik {
		int[] sum;

		public Fenvik(int n) {
			sum = new int[n];
		}

		public void add(int x, int d) {
			for (; x < sum.length; x = (x | (x + 1))) {
				sum[x] += d;
			}
		}

		public int sum(int r) {
			int ans = 0;
			for (; r >= 0; r = (r & (r + 1)) - 1) {
				ans += sum[r];
			}
			return ans;
		}

		public int sum(int l, int r) {
			return sum(r) - sum(l - 1);
		}
	}

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

	public int mint(int x) {
		return x % mod;
	}

	public int pow(int x, long p) {
		int ans = 1;
		while (p > 0) {
			if ((p & 1) == 1) {
				ans = mult(ans, x);
			}
			x = mult(x, x);
			p >>= 1;
		}
		return ans;
	}

	public class State implements Comparable<State> {
		int x;
		int y;
		int sum;
		int diff;
		int id;
		int xplus;
		int xminus;

		public State(int x, int y, int id) {
			this.x = x;
			this.y = y;
			this.id = id;
			sum = sum(mint(x), mint(y));
			diff = diff(mint(x), mint(y));
		}

		@Override
		public int compareTo(State o) {
			if (x != o.x) {
				return x - o.x;
			}
			return y - o.y;
		}
	}

	State[][] sum;
	int[] last = new int[200010];
	int time = 0;

	public void solve() {
		f : for (int qwerty = in.nextInt(); qwerty > 0; --qwerty) {
			int n = in.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = in.nextInt();
			}
			int[] b = a.clone();
			Arrays.sort(a);
			for (int i = 0; i < b.length; i++) {
				if (a[i] != b[i]) {
					out.println("YES");
					continue f;
				}
			}
			out.println("NO");
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
		new A().run();
	}
}