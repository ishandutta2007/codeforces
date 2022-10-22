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

	Vector v0;

	long mod = 1000000007;

	public void solve() {
		int n = in.nextInt();
		long sumAll = 0;
		long[] a = new long[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = in.nextLong();
			sumAll += a[i];
		}
		ArrayList<Long> div = new ArrayList<>();
		for (long i = 2; i * i <= sumAll; i++) {
			if (sumAll % i == 0) {
				div.add(i);
				while (sumAll % i == 0) {
					sumAll /= i;
				}
			}
		}
		if (sumAll > 1) {
			div.add(sumAll);
		}
		if (div.isEmpty()) {
			out.print(-1);
			return;
		}
		long[] sum = new long[n];
		sum[0] = a[0];
		for (int i = 0; i < a.length - 1; i++) {
			sum[i + 1] = sum[i] + a[i + 1];
		}
		long ans = Long.MAX_VALUE / 2;
		for (long x : div) {
			long th = 0;
			int last = 0;
			for (int i = 0; i < sum.length; i++) {
				if (sum[i] - sum[last] / x * x >= x) {
					long[] s = new long[i - last + 1];
					long[] number = new long[i - last + 1];
					s[0] = last * (sum[last] % x);
					number[0] = sum[last] % x;
					for (int j = 1; j < s.length - 1; j++) {
						s[j] = s[j - 1] + a[last + j] * (last + j);
						number[j] = number[j - 1] + a[last + j];
					}
					s[i - last] = s[i - last - 1] + i * (x - sum[i - 1] % x);
					number[i - last] = number[i - last - 1] + (x - sum[i - 1] % x);
					long min = Long.MAX_VALUE / 2;
					for (int j = 0; j < number.length; j++) {
						min = Math.min(min, (s[i - last] - number[i - last] * (last + j)) - 2 * (s[j] - number[j] * (last + j)));
					}
//					System.out.println(x + " " + i + " " + last + " " + min);
//					for (int j = 0; j < number.length; j++) {
//						System.out.println(number[j] + " " + s[j]);
//					}
//					System.out.println();
					th += min;
					last = i;
				}
			}
			ans = Math.min(ans, th);
//			System.out.println(x + " " + th);
		}
		out.print(ans);
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