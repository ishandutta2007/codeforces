import java.util.*;

import java.io.*;
import java.math.BigInteger;

public class E {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Pair {
		int v;
		int place;
		
		public Pair(int v, int place) {
			this.v = v;
			this.place = place;
		}
	}
	
	public class Edge implements Comparable<Edge> {
		int from;
		int to;
		long len;
		
		public Edge(int from, int to, long len) {
			this.from = from;
			this.to = to;
			this.len = len;
		}

		@Override
		public int compareTo(Edge o) {
			if (len > o.len) {
				return 1;
			}
			if (len < o.len) {
				return -1;
			}
			return 0;
		}
		
	}
	
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
			if (sz[pa] == 1) {
				p[pa] = pb;
				sz[pb] += sz[pa];
				return true;
			}
			if (sz[pb] == 1) {
				p[pb] = pa;
				sz[pa] += sz[pb];
				return true;
			}
			return false;
		}
	}
	
	public class SegmentTree {
		int pow;
		int[][] sum;
		int[][] delta;
		boolean[] flag;
		
		public SegmentTree(int[][] a) {
			pow = 1;
			while (pow < a.length) {
				pow *= 2;
			}
			flag = new boolean[2 * pow];
			sum = new int[2 * pow][24];
			delta = new int[2 * pow][24];
			for (int i = 0; i < a.length; i++) {
				sum[pow + i] = a[i];
			}
			for (int i = pow - 1; i > 0; i--) {
				sum[i] = f(sum[2 * i], sum[2 * i + 1]);
			}
		}
		
		public int[] get(int v, int tl, int tr, int l, int r) {
			push(v, tl, tr);
			if (l > r) {
				return new int[24];
			}
			if (l == tl && r == tr) {
				return sum[v];
			}
			int tm = (tl + tr) / 2;
			return f(get(2 * v, tl, tm, l, Math.min(r, tm)), get(2 * v + 1, tm + 1, tr, Math.max(l, tm + 1), r));
		}
		
		public void set(int v, int tl, int tr, int l, int r, int[] x) {
			push(v, tl, tr);
			if (l > tr || r < tl) {
				return;
			}
			if (l <= tl && r >= tr) {
				delta[v] = x.clone();
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
					delta[2 * v] = delta[v].clone();
					delta[2 * v + 1] = delta[v].clone();
				}
				flag[v] = false;
				for (int i = 0; i < 24; i++) {
					sum[v][i] = delta[v][i] * (tr - tl + 1);
				}
			}
		}
		
		public int[] f(int[] a, int[] b) {
			int[] ans = new int[24];
			for (int i = 0; i < ans.length; i++) {
				ans[i] = a[i] + b[i];
			}
			return ans;
		}
	}
	
	public class Output {
		int x1;
		int y1;
		int x2;
		int y2;

		public Output(int x1, int y1, int x2, int y2) {
			this.x1 = x1 + 1;
			this.y1 = y1 + 1;
			this.x2 = x2 + 1;
			this.y2 = y2 + 1;
		}
		
		public String toString() {
			return x1 + " " + y1 + " " + x2 + " " + y2;
		}
	}
	
	public void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		ArrayList<Output> ans = new ArrayList<>();
		String[][] s1 = new String[n][m];
		String[][] s2 = new String[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				s1[i][j] = in.next();
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				s2[i][j] = in.next();
			}
		}
		int zero = 0;
		int one = 0;
		for (int i = 0; i < s1[0][0].length(); i++) {
			if (s1[0][0].charAt(s1[0][0].length() - 1 - i) == '0') {
				ans.add(new Output(0, 0, 1, 0));
			} else {
				ans.add(new Output(0, 0, 0, 1));
			}
		}
		for (int i = 0; i < s1[0][1].length(); i++) {
			if (s1[0][1].charAt(s1[0][1].length() - 1 - i) == '0') {
				ans.add(new Output(0, 1, 0, 0));
			} else {
				ans.add(new Output(0, 1, 1, 1));
			}
		}
		for (int j = 1; j < n; j++) {
			for (int i = 0; i < s1[j][0].length(); i++) {
				if (s1[j][0].charAt(s1[j][0].length() - 1 - i) == '0') {
					ans.add(new Output(j, 0, 0, 0));
				} else {
					ans.add(new Output(j, 0, j, 1));
				}
			}
			for (int i = 0; i < s1[j][1].length(); i++) {
				if (s1[j][1].charAt(s1[j][1].length() - 1 - i) == '0') {
					ans.add(new Output(j, 1, j, 0));
				} else {
					ans.add(new Output(j, 1, 0, 1));
				}
			}
			for (int i = 0; i < s1[j][0].length(); i++) {
				if (s1[j][0].charAt(s1[j][0].length() - 1 - i) == '1') {
					ans.add(new Output(j, 1, 0, 1));
				}
			}
			for (int i = 0; i < s1[j][1].length(); i++) {
				if (s1[j][1].charAt(s1[j][1].length() - 1 - i) == '0') {
					ans.add(new Output(j, 0, 0, 0));
				}
			}
		}
		for (int i = 0; i < s1[0][0].length(); i++) {
			if (s1[0][0].charAt(s1[0][0].length() - 1 - i) == '0') {
				ans.add(new Output(1, 0, 0, 0));
			}
		}
		for (int i = 0; i < s1[0][1].length(); i++) {
			if (s1[0][1].charAt(s1[0][1].length() - 1 - i) == '1') {
				ans.add(new Output(1, 1, 0, 1));
			}
		}
		for (int i = 1; i < n; i++) {
			for (int j = 2; j < m; j++) {
				for (int k = 0; k < s1[i][j].length(); k++) {
					ans.add(new Output(i, j, 0, j));
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 2; j < m; j++) {
				for (int k = 0; k < s1[i][j].length(); k++) {
					if (s1[i][j].charAt(s1[i][j].length() - 1 - k) == '0') {
						ans.add(new Output(0, j, 0, 0));
					} else {
						ans.add(new Output(0, j, 0, 1));
					}
				}
			}
		}
//		for (int i = 0; i < s1[0][0].length(); i++) {
//			if (s1[0][0].charAt(s1[0][0].length() - 1 - i) == '0') {
//				ans.add(new Output(1, 0, 0, 0));
//				zero++;
//			} else {
//				ans.add(new Output(1, 0, 0, 1));
//				one++;
//			}
//		}
//		for (int i = 0; i < s1[0][1].length(); i++) {
//			if (s1[0][1].charAt(s1[0][1].length() - 1 - i) == '0') {
//				ans.add(new Output(1, 1, 0, 0));
//				zero++;
//			} else {
//				ans.add(new Output(1, 1, 0, 1));
//				one++;
//			}
//		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 2; j < m; j++) {
				for (int k = 0; k < s2[i][j].length(); k++) {
					if (s2[i][j].charAt(s2[i][j].length() - 1 - k) == '0') {
						ans.add(new Output(0, 0, 0, j));
					} else {
						ans.add(new Output(0, 1, 0, j));
					}
					if (i > 0) {
						ans.add(new Output(0, j, i, j));
					}
				}
			}
		}
		for (int i = 0; i < s2[0][0].length(); i++) {
			if (s2[0][0].charAt(s2[0][0].length() - 1 - i) == '0') {
				ans.add(new Output(0, 0, 1, 0));
			}
		}
		for (int i = 0; i < s2[0][1].length(); i++) {
			if (s2[0][1].charAt(s2[0][1].length() - 1 - i) == '1') {
				ans.add(new Output(0, 1, 1, 1));
			}
		}
		for (int j = 1; j < n; j++) {
			for (int i = 0; i < s2[j][0].length(); i++) {
				if (s2[j][0].charAt(s2[j][0].length() - 1 - i) == '1') {
					ans.add(new Output(0, 1, j, 1));
				}
			}
			for (int i = 0; i < s2[j][1].length(); i++) {
				if (s2[j][1].charAt(s2[j][1].length() - 1 - i) == '0') {
					ans.add(new Output(0, 0, j, 0));
				}
			}
			for (int i = 0; i < s2[j][0].length(); i++) {
				if (s2[j][0].charAt(s2[j][0].length() - 1 - i) == '0') {
					ans.add(new Output(0, 0, j, 0));
				} else {
					ans.add(new Output(j, 1, j, 0));
				}
			}
			for (int i = 0; i < s2[j][1].length(); i++) {
				if (s2[j][1].charAt(s2[j][1].length() - 1 - i) == '0') {
					ans.add(new Output(j, 0, j, 1));
				} else {
					ans.add(new Output(0, 1, j, 1));
				}
			}
		}
		for (int i = 0; i < s2[0][0].length(); i++) {
			if (s2[0][0].charAt(s2[0][0].length() - 1 - i) == '0') {
				ans.add(new Output(1, 0, 0, 0));
			} else {
				ans.add(new Output(0, 1, 0, 0));
			}
		}
		for (int i = 0; i < s2[0][1].length(); i++) {
			if (s2[0][1].charAt(s2[0][1].length() - 1 - i) == '1') {
				ans.add(new Output(1, 1, 0, 1));
			} else {
				ans.add(new Output(0, 0, 0, 1));
			}
		}
		out.println(ans.size());
		for (Output o : ans) {
			out.println(o.toString() + " ");
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
		new E().run();
	}
}