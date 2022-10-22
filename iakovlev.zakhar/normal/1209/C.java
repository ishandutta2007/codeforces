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

	public void solve() {
		int t = in.nextInt();
		f :
		for (; t > 0; t--) {
			int n = in.nextInt();
			String s = in.next();
			int[] a = new int[n];
			int[] first = new int[12];
			int[] last = new int[12];
			for (int i = 0; i < last.length; i++) {
				last[i] = -2;
				first[i] = n + 1;
			}
			first[0] = -1;
			last[0] = -1;
			first[11] = n;
			last[11] = n;
			for (int i = 0; i < a.length; i++) {
				a[i] = s.charAt(i) - '0' + 1;
				first[a[i]] = Math.min(first[a[i]], i);
				last[a[i]] = i;
			}
			int[] prev = new int[12];
			prev[1] = 0;
			for (int i = 2; i < prev.length; i++) {
				if (last[i - 1] > -2) {
					prev[i] = i - 1;
				} else {
					prev[i] = prev[i - 1];
				}
			}
//			for (int i = 0; i < prev.length; i++) {
//				System.out.println(i + ") " + first[]);
//			}
			for (int med = 1; med < 11; med++) {
				boolean flag = true;
				for (int i = 1; i < med; i++) {
					if (last[i] > -2 && last[prev[i]] > first[i]) {
						flag = false;
						break;
					}
				}
				int next = med + 1;
				for (int i = next; i < prev.length; i++) {
					if (last[i] > -2) {
						next = i;
						break;
					}
				}
				for (int i = next + 1; i < prev.length; i++) {
					if (last[i] > -2 && last[prev[i]] > first[i]) {
						flag = false;
						break;
					}
				}
				int one = last[prev[med]];
				int two = first[next];
				if (two < one) {
					for (int i = two; i < one; i++) {
						if (a[i] == med) {
							flag = false;
							break;
						}
					}
				}
				if (flag) {
					boolean[] th = new boolean[n];
					for (int i = 0; i < th.length; i++) {
						th[i] = a[i] < med || (a[i] == med && i > one);
					}
					for (int i = 0; i < th.length; i++) {
						if (th[i]) {
							out.print(1);
						} else {
							out.print(2);
						}
					}
					out.println();
					continue f;
				}
			}
			out.println("-");
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