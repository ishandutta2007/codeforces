import java.util.*;

import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public long C(int n, int k) {
		if (k > n) {
			return 0;
		}
		BigInteger c = fact[n].multiply(factInv[k]).multiply(factInv[n - k]);
		c = c.mod(m);
		return c.longValue();
	}

	long mod = 1000000007;
	BigInteger m = BigInteger.valueOf(mod);
	int[] len = new int[1001];
	BigInteger[] fact = new BigInteger[1001];
	BigInteger[] factInv = new BigInteger[1001];
	
	public void solve() {
		String s = in.next();
		int n = s.length();
		int k = in.nextInt();
		for (int i = 2; i < len.length; i++) {
			int x = i;
			int num = 0;
			while (x > 0) {
				if (x % 2 == 1) {
					num++;
				}
				x /= 2;
			}
			len[i] = len[num] + 1;
		}
		int max = 0;
		for (int i = 0; i < len.length; i++) {
			max = Math.max(max, len[i]);
		}
		if (k > 5) {
			out.print(0);
			return;
		}
		if (k == 0) {
			out.print(1);
			return;
		}
		k--;
		fact[0] = BigInteger.ONE;
		for (int i = 1; i < fact.length; i++) {
			fact[i] = fact[i - 1].multiply(BigInteger.valueOf(i));
		}
		for (int i = 0; i < fact.length; i++) {
			fact[i] = fact[i].mod(m);
			factInv[i] = fact[i].modInverse(m);
		}
		ArrayList<Integer> one = new ArrayList();
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '1') {
				one.add(i);
			}
		}
		long ans = 0;
		if (k == 0) {
			ans = mod - 1;
		}
		for (int i = 1; i < len.length; i++) {
			if (len[i] == k) {
				int x = i;
				if (x == one.size()) {
					ans++;
					ans %= mod;
				}
				for (int j : one) {
					if (x < 0) {
						break;
					}
					ans += C(n - 1 - j, x);
					x--;
					ans %= mod;
				}
			}
		}
		out.print(ans);
	}

	public void run() {
		try {
			if (systemIO) {
				in = new FastScanner(System.in);
				out = new PrintWriter(System.out);
			} else {
				in = new FastScanner(new File("segments.in"));
				out = new PrintWriter(new File("segments.out"));
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