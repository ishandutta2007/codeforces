import java.util.*;

import java.io.*;
import java.math.BigInteger;

public class D {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Pair implements Comparable<Pair> {
		long x;
		long y;

		public Pair(long x, long y) {
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
			long[][] ans = new long[m][m];
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
	
	public class Segment implements Comparable<Segment>{
		int beg;
		int end;
		int number;

		public Segment(int beg, int end, int number) {
			this.beg = beg;
			this.end = end;
			this.number = number;
		}

		@Override
		public int compareTo(Segment o) {
			if (beg != o.beg) {
				return beg - o.beg;
			}
			if (end != o.end) {
				return end - o.end;
			}
			return number - o.number;
		}
		
	}

	long mod = 998244353;
	int m;

	public void solve() {
		int n = in.nextInt();
		long[] fact = new long[n + 1];
		long[] factInv = new long[n + 1];
		fact[0] = 1;
		factInv[0] = modInv(fact[0]);
		for (int i = 1; i < factInv.length; i++) {
			fact[i] = (fact[i - 1] * i) % mod;
			factInv[i] = modInv(fact[i]);
		}
		long k = in.nextLong();
		if (n == 1 || k == 1) {
			out.println(0);
			return;
		}
		long[] powk = new long[n + 1];
		long[] powk2 = new long[n + 1];
		powk[0] = 1;
		powk2[0] = 1;
		for (int i = 1; i < powk.length; i++) {
			powk[i] = (powk[i - 1] * k) % mod;
			powk2[i] = (powk2[i - 1] * (k - 2)) % mod;
		}
		int[] h = new int[n];
		for (int i = 0; i < h.length; i++) {
			h[i] = in.nextInt();
		}
		long all = powk[n];
		int x = 0;
		for (int i = 0; i < h.length; i++) {
			if (h[i] != h[(i + 1) % n]) {
				x++;
			}
		}
		long zero = 0;
		for (int i = 0; i <= x / 2; i++) {
			long th = fact[x];
			th *= factInv[i];
			th %= mod;
			th *= factInv[i];
			th %= mod;
			th *= factInv[x - 2 * i];
			th %= mod;
			th *= powk2[x - 2 * i];
			th %= mod;
			th *= powk[n - x];
			th %= mod;
			zero += th;
			zero %= mod;
		}
		long ans = (all - zero + mod) % mod;
		ans *= modInv(2);
		ans %= mod;
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
		new D().run();
	}
}