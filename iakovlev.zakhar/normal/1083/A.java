import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.rmi.dgc.DGC;

public class A {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public int gcd(int a, int b) {
		if (a == 0) {
			return b;
		}
		return gcd(b % a, a);
	}

	public class Pair {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

	}

	public class Edge {
		int to;
		long c;
		long up;
		
		public Edge(int to, long c, long up) {
			this.to = to;
			this.c = c;
			this.up = up;
		}
	}
	
	public long dfs1(int v, int prev) {
		long cUp = 0;
		for (Edge e : to[v]) {
			if (e.to == prev) {
				cUp = e.c;
			} else {
				e.up = dfs1(e.to, v);
				if (e.up > max1[v]) {
					max2[v] = max1[v];
					max1[v] = e.up;
				} else if (e.up > max2[v]) {
					max2[v] = e.up;
				}
			}
		}
		return max1[v] + w[v] - cUp;
	}
	
	public void dfs2(int v, int prev, long pref) {
		if (pref > max1[v]) {
			max2[v] = max1[v];
			max1[v] = pref;
		} else if (pref > max2[v]) {
			max2[v] = pref;
		}
		ans = Math.max(ans, max1[v] + w[v]);
		for (Edge e : to[v]) {
			if (e.to != prev) {
				if (e.up != max1[v]) {
					dfs2(e.to, v, max1[v] + w[v] - e.c);
				} else {
					dfs2(e.to, v, max2[v] + w[v] - e.c);
				}
			}
		}
	}
	
	long ans = 0;
	long[] max1;
	long[] max2;
	ArrayList<Edge>[] to;
	long[] w;

	public void solve() {
		int n = in.nextInt();
		w = new long[n];
		max1 = new long[n];
		max2 = new long[n];
		for (int i = 0; i < w.length; i++) {
			w[i] = in.nextLong();
		}
		to = new ArrayList[n];
		for (int i = 0; i < to.length; i++) {
			to[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			int x = in.nextInt() - 1;
			int y = in.nextInt() - 1;
			long c = in.nextLong();
			to[x].add(new Edge(y, c, 0));
			to[y].add(new Edge(x, c, 0));
		}
		dfs1(0, -1);
		dfs2(0, -1, 0);
		System.out.println(ans);
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