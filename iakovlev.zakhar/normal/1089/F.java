import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Side implements Comparable<Side> {
		long sq;
		int n;

		public Side(long sq, int n) {
			this.sq = sq;
			this.n = n;
		}

		@Override
		public int compareTo(Side o) {
			if (sq > o.sq) {
				return 1;
			}
			if (sq < o.sq) {
				return -1;
			}
			return n - o.n;
		}
	}

	public class Fract {
		long p;
		long q;

		public Fract(long p, long q) {
			this.p = p;
			this.q = q;
			long gcd = gcd(Math.abs(p), q);
			p /= gcd;
			q /= gcd;
		}
	}

	public Fract sum(Fract a, Fract b) {
		return new Fract(a.p * b.q + a.q * b.p, a.q * b.q);
	}

	public Fract neg(Fract a) {
		return new Fract(-a.p, a.q);
	}

	public Fract subtr(Fract a, Fract b) {
		return sum(a, neg(b));
	}

	public class Pair implements Comparable<Pair> {
		int l;
		int r;
		int number;
		int segment;

		public Pair(int l, int r, int number) {
			this.l = l;
			this.r = r;
			this.number = number;
			segment = l / 300;
		}

		@Override
		public int compareTo(Pair o) {
			if (segment != o.segment) {
				return segment - o.segment;
			}
			if (segment % 2 == 0) {
				return r - o.r;
			}
			return o.r - r;
		}
	}

	public long gcd(long a, long b) {
		if (a == 0) {
			return b;
		}
		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}

	public int gcd1(int a, int b) {
		if (a == 0) {
			return b;
		}
		if (b == 0) {
			return a;
		}
		return gcd1(b, a % b);
	}

	public long pow(long x, long p) {
		if (p == 0) {
			return 1;
		}
		if (p % 2 == 0) {
			long y = pow(x, p / 2);
			return y * y % mod;
		}
		return pow(x, p - 1) * x % mod;
	}

	public void lAdd() {
		l--;
		if (map.containsKey(s[l])) {
			map.put(s[l], map.get(s[l]) + 1);
		} else {
			map.put(s[l], 1);
		}
		th *= (r - l + 1);
		th %= mod;
		th *= modInv[map.get(s[l])];
		th %= mod;
	}

	public void rAdd() {
		r++;
		if (map.containsKey(s[r])) {
			map.put(s[r], map.get(s[r]) + 1);
		} else {
			map.put(s[r], 1);
		}
		th *= (r - l + 1);
		th %= mod;
		th *= modInv[map.get(s[r])];
		th %= mod;
	}

	public void lDel() {
		th *= modInv[r - l + 1];
		th %= mod;
		th *= map.get(s[l]);
		th %= mod;
		if (map.get(s[l]) == 1) {
			map.remove(s[l]);
		} else {
			map.put(s[l], map.get(s[l]) - 1);
		}
		l++;
	}

	public void rDel() {
		th *= modInv[r - l + 1];
		th %= mod;
		th *= map.get(s[r]);
		th %= mod;
		if (map.get(s[r]) == 1) {
			map.remove(s[r]);
		} else {
			map.put(s[r], map.get(s[r]) - 1);
		}
		r--;
	}

	final long mod = 1000000007;

	int l = 0;
	int r = -1;
	int[] s;
	long th = 1;
	long[] modInv;
	HashMap<Integer, Integer> map = new HashMap<>();

	public void solve() {
		long n = in.nextLong();
		long c = 1;
		long d = 1;
		for (long i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				while (n % i == 0) {
					c *= i;
					n /= i;
				}
				break;
			}
		}
		d = n / 1;
		long x = Math.min(c, d);
		long y = Math.max(c, d);
		if (x == 1) {
			out.println("NO");
			return;
		}
		out.println("YES");
		for (int a = 1; a < x; a++) {
			long t = x * y - 1 - a * y;
			if (t % x == 0) {
				long b = t / x;
				out.println(2);
				out.println(a + " " + x);
				out.println(b + " " + y);
				return;
			}
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
		new C().run();
	}
}