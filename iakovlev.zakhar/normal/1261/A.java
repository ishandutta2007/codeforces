import java.util.*;

import java.io.*;
import java.math.BigInteger;

public class G {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Fraction implements Comparable<Fraction> {
		long x;
		long y;

		public Fraction(long x, long y) {
			this.x = x;
			this.y = y;
		}

		public void norm() {
			long gcd = gcd(x, y);
			x /= gcd;
			y /= gcd;
		}

		@Override
		public int compareTo(Fraction o) {
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

	public Fraction sum(Fraction a, Fraction b) {
		Fraction c = new Fraction(a.x * b.y + a.y * b.x, a.y * b.y);
		c.norm();
		return c;
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
		long[] sum;

		public Fenvik(int n) {
			sum = new long[n];
		}

		public void add(int x, long d) {
			for (int i = x; i < sum.length; i = (i | (i + 1))) {
				sum[i] += d;
			}
		}

		public long sum(int r) {
			long ans = 0;
			for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
				ans += sum[i];
			}
			return ans;
		}

		public long sum(int l, int r) {
			if (l > r) {
				return 0;
			}
			return sum(r) - sum(l - 1);
		}
	}

	public class Vector implements Comparable<Vector> {
		long x;
		long y;

		public Vector(long x, long y) {
			this.x = x;
			this.y = y;
		}

		public Vector add(Vector v) {
			return new Vector(x + v.x, y + v.y);
		}

		public Vector subtract(Vector v) {
			return new Vector(x - v.x, y - v.y);
		}

		public long dp(Vector v) {
			return x * v.x + y * v.y;
		}

		public long cp(Vector v) {
			return x * v.y - y * v.x;
		}

		public boolean equals(Vector v) {
			return x == v.x && y == v.y;
		}

		@Override
		public int compareTo(Vector o) {
			int s = sgn(cp(v0));
			int os = sgn(o.cp(v0));
			if (s != os) {
				return s - os;
			}
			return sgn(cp(o));
		}

	}

	public int sgn(long x) {
		if (x > 0) {
			return 1;
		}
		if (x < 0) {
			return -1;
		}
		return 0;
	}
	
	public long min(long a, long b) {
		return a < b ? a : b;
	}

	Vector v0;

	long mod = 1000000007;

	public void solve() {
		int t = in.nextInt();
		for (; t > 0; t--) {
			int n = in.nextInt() / 2;
			int k = in.nextInt();
			boolean[] b = new boolean[2 * n];
			String s = in.next();
			for (int i = 0; i < s.length(); i++) {
				b[i] = s.charAt(i) == '(';
			}
			ArrayList<Pair> ans = new ArrayList<>();
			boolean[] goal = new boolean[2 * n];
			for (int i = 0; i < k; i++) {
				goal[2 * i] = true;
			}
			for (int i = 2 * (k - 1); i <= 2 * (k - 1) + (n - k); i++) {
				goal[i] = true;
			}
			int next = 0;
			for (int i = 0; i < goal.length; i++) {
				if (b[i] != goal[i]) {
					next = Math.max(next, i + 1);
					while (goal[i] != b[next]) {
						next++;
					}
					ans.add(new Pair(i + 1, next + 1));
					b[next] = b[i];
					b[i] = goal[i];
				}
			}
//			for (int i = 0; i < goal.length; i++) {
//				if (goal[i]) {
//					System.out.print("(");
//				} else {
//					System.out.print(")");
//				}
//			}
//			System.out.println();
			out.println(ans.size());
			for (Pair p : ans) {
				out.println(p);
			}
		}
	}

	public long solveFast(int s, int b) {
		b -= s;
		long time = System.currentTimeMillis();
		long[][] dp = new long[1][b + 1];
		dp[0][b] = 1;
		int c = 0;
		for (int x = b; x >= 1; x--) {
			long[][] dp1 = new long[Math.min(b / x, s) + 1][b];
			// for (int i = 0; i < dp1.length; i++) {
			// dp1[i] = new long[b - i * x + 1];
			// }
			for (int i = 0; i < dp.length; i++) {
				for (int j = 0; j < dp[i].length; j++) {
					dp1[i][j] = dp[i][j];
					c++;
				}
			}
			int dl = dp1.length - dp.length;
			if (dl == 0) {
				dl++;
			}
			int len = dp.length;
			for (int j = 0; j < dp1[0].length; j++) {
				long sum = 0;
				long d = 0;
				for (int i = 1; j - i * x >= 0 && i <= s; i++) {
					dp1[i][j - i * x] += d + dp[0][j];
					dp1[i][j - i * x] %= mod;
					if (i < len && j <= b - i) {
						sum += dp[i][j - i * x];
						d += dp[i][j - i * x];
					}
					d += sum;
					// for (int k = dl; k <= i; k++) {
					// c++;
					// if (j + k * x > b) {
					// break;
					// }
					// dp1[i][j] += dp[i - k][j + k * x] * (k + 1);
					// }
				}
			}
			dp = dp1;
			// for (int i = 0; i < dp1.length; i++) {
			// for (int j = 0; j < dp1[0].length; j++) {
			// System.out.print(dp1[i][j] + " ");
			// }
			// System.out.println();
			// }
			// System.out.println();
		}
		long ans = dp[0][0];
		for (int i = 1; i < dp.length; i++) {
			ans += dp[i][0] * (1 + s - i);
		}
		System.err.println(System.currentTimeMillis() - time);
		System.err.println(c);
		return (ans % mod);
		// out.print(dp[s][0] % mod);
	}

	public long solveSlow(int s, int b) {
		long time = System.currentTimeMillis();
		long[][] dp = new long[1][b + 1];
		dp[0][b] = 1;
		int c = 0;
		for (int x = b; x >= 1; x--) {
			System.out.println(x);
			long[][] dp1 = new long[b / x + 1][b + 1];
			for (int i = 0; i < dp.length; i++) {
				for (int j = 0; j < dp[0].length; j++) {
					dp1[i][j] = dp[i][j];
					c++;
				}
			}
			int dl = dp1.length - dp.length;
			if (dl == 0) {
				dl++;
			}
			for (int i = 1; i < dp1.length; i++) {
				for (int j = 0; j < dp1[0].length; j++) {
					for (int k = 1; k < i; k++) {
						if (i - k >= dp.length) {
							continue;
						}
						c++;
						if (j + k * x > b) {
							break;
						}
						dp1[i][j] += dp[i - k][j + k * x] * (k + 1);
					}
					if (j + i * x == b) {
						dp1[i][j]++;
					}
					dp1[i][j] %= mod;
				}
			}
			dp = dp1;
			// System.out.println(x);
			// for (int i = 0; i < dp1.length; i++) {
			// for (int j = 0; j < dp1[0].length; j++) {
			// System.out.print(dp1[i][j] + " ");
			// }
			// System.out.println();
			// }
			// System.out.println();
		}
		System.err.println(System.currentTimeMillis() - time);
		System.err.println(c);
		return (dp[s][0]);
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
		new G().run();
	}
}