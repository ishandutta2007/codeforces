import java.io.*;
import java.util.*;

public class D {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

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

	public int div(int x, int y) {
		return (int) (x * 1L * modInv(y) % mod);
	}

	public int modInv(int x) {
		return pow(x, mod - 2);
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

	public class Fenvik {
		int[] sum;

		public Fenvik(int n) {
			sum = new int[n];
		}

		public void add(int x, int d) {
			for (int i = x; i < sum.length; i = (i | (i + 1))) {
				sum[i] += d;
			}
		}

		public int sum(int r) {
			int ans = 0;
			for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
				ans += sum[i];
			}
			return ans;
		}

		public int sum(int l, int r) {
			if (l > r) {
				return 0;
			}
			return sum(r) - sum(l - 1);
		}
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

	public long[][] pow(long[][] x, long p) {
		if (p == 0) {
			long[][] ans = new long[x.length][x.length];
			for (int i = 0; i < ans.length; i++) {
				ans[i][i] = 1;
			}
			return ans;
		}
		long[][] t = pow(x, p / 2);
		t = multiply(t, t);
		if (p % 2 == 1) {
			t = multiply(t, x);
		}
		return t;
	}

	public long[][] multiply(long[][] a, long[][] b) {
		long[][] ans = new long[a.length][b[0].length];
		for (int i = 0; i < ans.length; i++) {
			for (int j = 0; j < ans[0].length; j++) {
				for (int k = 0; k < b.length; k++) {
					ans[i][j] += a[i][k] * b[k][j];
					ans[i][j] %= mod;
				}
			}
		}
		return ans;
	}

	public int pow(int x, int p) {
		if (p == 0) {
			return 1;
		}
		int t = pow(x, p / 2);
		t = mult(t, t);
		if (p % 2 == 1) {
			t = mult(t, x);
		}
		return t;
	}



	Random random = new Random(566);

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
			if (pa == pb) {
				return false;
			}
			if (sz[pa] < sz[pb]) {
				p[pa] = pb;
				sz[pb] += sz[pa];
			} else {
				p[pb] = pa;
				sz[pa] += sz[pb];
			}
			return true;
		}
	}
	
	public class SparseTable {
		int pow;
		int[] lessPow;
		long[][] min;

		public SparseTable(long[] a) {
			pow = 0;
			while ((1 << pow) <= a.length) {
				pow++;
			}
			min = new long[pow][a.length];
			for (int i = 0; i < a.length; i++) {
				min[0][i] = a[i];
			}
			for (int i = 1; i < pow; i++) {
				for (int j = 0; j < a.length; j++) {
					min[i][j] = min[i - 1][j];
					if (j + (1 << (i - 1)) < a.length) {
						min[i][j] = func(min[i][j], min[i - 1][j + (1 << (i - 1))]);
					}
				}
			}
			lessPow = new int[a.length + 1];
			for (int i = 1; i < lessPow.length; i++) {
				if (i < (1 << (lessPow[i - 1]) + 1)) {
					lessPow[i] = lessPow[i - 1];
				} else {
					lessPow[i] = lessPow[i - 1] + 1;
				}
			}
		}

		public long get(int l, int r) { // [l, r)
			int p = lessPow[r - l];
			return func(min[p][l], min[p][r - (1 << p)]);
		}

		public long func(long a, long b) {
			if (a < b) {
				return a;
			}
			return b;
		}
	}
	
	int inv2 = modInv(2);
	
	public class Arr implements Comparable<Arr> {
		int w;
		int[] a;
		
		public Arr(int w, int[] a) {
			this.w = w;
			this.a = a;
		}

		@Override
		public int compareTo(Arr o) {
			return w - o.w;
		}
	}
	
	final int threshold = 500;
	
	public void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
//		int n = 100000;
//		int m = 5;
		HashMap<Integer, Integer> map = new HashMap<>();
		Arr[] a = new Arr[n];
		for (int i = 0; i < n; i++) {
			int[] x = new int[m];
			for (int j = 0; j < x.length; j++) {
				int y = in.nextInt();
//				int y = 0;
//				if (random.nextBoolean()) {
//					y = random.nextInt(1);
//				} else {
//					y = random.nextInt(1000000000);
//				}
				if (map.containsKey(y)) {
					x[j] = map.get(y);
				} else {
					x[j] = map.size();
					map.put(y, map.size());
				}
			}
			a[i] = new Arr(in.nextInt(), x);
//			a[i] = new Arr(random.nextInt(n), x);
		}
		Arrays.sort(a);
		System.err.println(map.size());
		int[] number = new int[map.size()];
		for (int i = 0; i < n; i++) {
			for (int j : a[i].a) {
				number[j]++;
			}
		}
		BitSet[] set = new BitSet[map.size()];
		for (int i = 0; i < set.length; i++) {
			if (number[i] > threshold) {
				set[i] = new BitSet(n + 1);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j : a[i].a) {
				if (number[j] > threshold) {
					set[j].set(i);
				}
			}
		}
		int ans = Integer.MAX_VALUE;
		BitSet banned = new BitSet(n + 1);
		for (int i = 0; i < n; i++) {
			banned.clear();
			for (int j : a[i].a) {
				if (number[j] > threshold) {
					banned.or(set[j]);
				}
			}
			int cur = i;
			w : while (true) {
				cur = banned.nextClearBit(cur + 1);
				if (cur >= n) {
					break;
				}
				for (int j : a[i].a) {
					for (int k : a[cur].a) {
						if (j == k) {
							continue w;
						}
					}
				}
				ans = Math.min(ans, a[i].w + a[cur].w);
				break;
			}
		}
		if (ans == Integer.MAX_VALUE) {
			out.println(-1);
		} else {
			out.println(ans);
		}
		System.err.println((Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) >> 20);
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
		long time = System.currentTimeMillis();
		new D().run();
		System.err.println(System.currentTimeMillis() - time);
	}
}