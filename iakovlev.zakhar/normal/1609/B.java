import java.io.*;
import java.util.*;

public class A {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Fenvik {
		long[] sum;

		public Fenvik(int n) {
			sum = new long[n];
		}

		public void add(int x, long d) {
			for (; x < sum.length; x = (x | (x + 1))) {
				sum[x] += d;
			}
		}

		public long sum(int r) {
			long ans = 0;
			for (; r >= 0; r = (r & (r + 1)) - 1) {
				ans += sum[r];
			}
			return ans;
		}
	}

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
	
	

	public void solve() {
		int n = in.nextInt();
		int q = in.nextInt();
		String s = in.next();
		int[] a = new int[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = s.charAt(i) - 'a';
		}
		int ans = 0;
		for (int i = 0; i + 2 < a.length; i++) {
			if (a[i] == 0 && a[i + 1] == 1 && a[i + 2] == 2) {
				ans++;
			}
		}
		for (int i = 0; i < q; i++) {
			int x = in.nextInt() - 1;
			for (int j = Math.max(0, x - 2); j <= x && j + 2 < a.length; j++) {
				if (a[j] == 0 && a[j + 1] == 1 && a[j + 2] == 2) {
					ans--;
				}
			}
			a[x] = in.next().charAt(0) - 'a';
			for (int j = Math.max(0, x - 2); j <= x && j + 2 < a.length; j++) {
				if (a[j] == 0 && a[j + 1] == 1 && a[j + 2] == 2) {
					ans++;
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
		new A().run();
	}
}