import java.io.*;
import java.util.*;

public class D {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Pair implements Comparable<Pair> {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
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

	public long modInv(long x) {
		return pow(x, mod - 2);
	}

	long mod = 1000000007;

	Random random = new Random(566);

	public void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int[][] a = new int[n][m];
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[0].length; j++) {
				a[i][j] = in.nextInt();
			}
		}
		TreeSet<Integer> free = new TreeSet<>();
		for (int i = 1; i <= n * m; i++) {
			free.add(i);
		}
		TreeSet<Integer> r = new TreeSet<>();
		TreeSet<Integer> c = new TreeSet<>();
		for (int i = 0; i < a.length; i++) {
			int max = 0;
			for (int j = 0; j < a[0].length; j++) {
				max = Math.max(max, a[i][j]);
			}
			r.add(max);
			free.remove(max);
		}
		for (int i = 0; i < a[0].length; i++) {
			int max = 0;
			for (int j = 0; j < a.length; j++) {
				max = Math.max(max, a[j][i]);
			}
			c.add(max);
			free.remove(max);
		}
		int[][] b = new int[n][m];
		int x = -1;
		int y = -1;
		Stack<Pair> st = new Stack<>();
		while (!r.isEmpty() && !c.isEmpty()) {
			int max = Math.max(r.last(), c.last());
			if (max == r.last()) {
				x++;
				r.pollLast();
			}
			if (max == c.last()) {
				y++;
				c.pollLast();
			}
			b[x][y] = max;
			st.add(new Pair(x, y));
		}
		while (!r.isEmpty()) {
			x++;
			b[x][y] = r.pollLast();
			st.add(new Pair(x, y));
		}
		while (!c.isEmpty()) {
			y++;
			b[x][y] = c.pollLast();
			st.add(new Pair(x, y));
		}
		while (!st.isEmpty()) {
			Pair p = st.pop();
			for (int j = 0; b[p.x][j] == 0; j++) {
				b[p.x][j] = free.pollFirst();
			}
			for (int i = 0; b[i][p.y] == 0; i++) {
				b[i][p.y] = free.pollFirst();
			}
		}
		for (int i = 0; i < b.length; i++) {
			for (int j = 0; j < b[0].length; j++) {
				out.print(b[i][j] + " ");
			}
			out.println();
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
		long time = System.currentTimeMillis();
		new D().run();
		System.err.println(System.currentTimeMillis() - time);
	}
}