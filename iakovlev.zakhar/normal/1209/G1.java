import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class A {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Fenvik {
		int[] sum;

		public Fenvik(int n) {
			sum = new int[n];
		}

		public void add(int x) {
			for (; x < sum.length; x = (x | (x + 1))) {
				sum[x]++;
			}
		}

		public int sum(int r) {
			int ans = 0;
			for (; r >= 0; r = (r & (r + 1)) - 1) {
				ans += sum[r];
			}
			return ans;
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

	public long dfs(int v, int prev, long sumth, long minsum, long s) {
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
				mxdown = Math.max(mxdown, dfs(e.to, v, sumth + e.s, minsum, e.s));
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

	public class Col implements Comparable<Col> {
		int[] c;
		int[] s;
		int n;

		public Col(int[] c, int n) {
			this.c = c;
			this.s = c.clone();
			Arrays.sort(s);
			for (int i = 0; i < c.length / 2; i++) {
				int d = s[i];
				s[i] = s[s.length - 1 - i];
				s[s.length - i - 1] = d;
			}
			this.n = n;
		}

		public int compareTo(Col o) {
			for (int i = 0; i < s.length; i++) {
				if (s[i] != o.s[i]) {
					return o.s[i] - s[i];
				}
			}
			return n - o.n;
		}
	}

	public void solve() {
		int t = 1;
		f: for (; t > 0; t--) {
			int n = in.nextInt();
			in.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = in.nextInt();
			}
			HashMap<Integer, Integer> last = new HashMap<>();
			for (int i = 0; i < a.length; i++) {
				last.put(a[i], i);
			}
			HashMap<Integer, Integer> number = new HashMap<>();
			int left = -1;
			int right = 0;
			int ans = 0;
			for (int i = 0; i < a.length; i++) {
				right = Math.max(right, last.get(a[i]));
				if (number.containsKey(a[i])) {
					number.put(a[i], number.get(a[i]) + 1);
				} else {
					number.put(a[i], 1);
				}
				if (i == right) {
					int max = 0;
					for (int x : number.keySet()) {
						max = Math.max(max, number.get(x));
					}
					number.clear();
					ans += right - left - max;
					left = right;
					right++;
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