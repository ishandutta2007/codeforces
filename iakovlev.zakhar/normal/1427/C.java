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
			if (y > o.y) {
				return 1;
			}
			if (y < o.y) {
				return -1;
			}
			if (x > o.x) {
				return 1;
			}
			if (x < o.x) {
				return -1;
			}
			return 0;
		}
	}

	long mod = 1000000;

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
			for (int i = x; i >= 0; i = (i & (i+1)) - 1) {
				for (int j = y; j >= 0; j = (j & (j+1)) - 1) {
					result += t[i][j];
				}
			}
			return result;
		}

		public void add(int x, int y, int delta) {
			for (int i = x; i < n; i = (i | (i+1))) {
				for (int j = y; j < m; j = (j | (j+1))) {
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
	
	public class Stack {
		int[] st;
		int sz;
		
		public Stack(int max) {
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
	
	public void solve() {
		long time = System.currentTimeMillis();
		int r = in.nextInt();
		int n = in.nextInt();
		int[] t = new int[n + 1];
		int[] x = new int[n + 1];
		int[] y = new int[n + 1];
		int[] dp = new int[n + 1];
		x[0] = 1;
		y[0] = 1;
		for (int i = 1; i <= n; i++) {
			dp[i] = Integer.MIN_VALUE / 2;
			t[i] = in.nextInt();
			x[i] = in.nextInt();
			y[i] = in.nextInt();
		}
		for (int i = 1; i < dp.length; i++) {
			for (int j = (i - (r << 2) > 0 ? (i - (r << 2)) : 0); j < i; j++) {
				if (dp[j] + 1 > dp[i] && (x[i] > x[j] ? x[i] - x[j] : x[j] - x[i]) + (y[i] > y[j] ? y[i] - y[j] : y[j] - y[i]) <= t[i] - t[j]) {
					dp[i] = dp[j] + 1;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < dp.length; i++) {
			if (dp[i] > ans) {
				ans = dp[i];
			}
		}
		out.println(ans);
		System.err.println(System.currentTimeMillis() - time);
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
		new C().run();
	}
}