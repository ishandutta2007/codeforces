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
		int n = in.nextInt();
		String s = in.next();
		boolean[][] burn = new boolean[n][10000];
		for (int i = 0; i < burn.length; i++) {
			if (s.charAt(i) == '1') {
				burn[i][0] = true;
			}
		}
		for (int i = 0; i < burn.length; i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			for (int j = 0; j < b; j++) {
				burn[i][j] = burn[i][0];
			}
			int x = b;
			while (x < burn[0].length) {
				burn[i][x] = !burn[i][x - 1];
				for (int j = 0; j < a && x + j < burn[0].length; j++) {
					burn[i][x + j] = burn[i][x];
				}
				x += a;
			}
		}
		int ans = 0;
		for (int i = 0; i < burn[0].length; i++) {
			int th = 0;
			for (int j = 0; j < burn.length; j++) {
				if (burn[j][i]) {
					th++;
				}
			}
			ans = Math.max(ans, th);
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
		new A().run();
	}
}