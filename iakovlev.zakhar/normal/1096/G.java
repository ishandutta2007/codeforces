import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;

public class FFT {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Vector {
		int sz = 1 << 20;
		long[] v;
		
		public Vector(long[] a) {
			v = new long[sz];
			for (int i = 0; i < a.length; i++) {
				v[i] = a[i];
			}
		}
		
		public long[] FFT() {
			return DFT(0, 1, true);
		}
		
		public long[] FFT1() {
			long[] x = DFT(0, 1, false);
			for (int i = 0; i < x.length; i++) {
				x[i] = x[i] * szinv % mod;
			}
			return x;
		}
		
		public long[] DFT(int first, int pow, boolean straight) {
			if (pow == sz) {
				long[] ans = {v[first]};
				return ans;
			}
			long[] zero = DFT(first, 2 * pow, straight);
			long[] one = DFT(first + pow, 2 * pow, straight);
			int n = zero.length;
			long[] ans = new long[2 * n];
			for (int i = 0; i < n; i++) {
				ans[i] = (zero[i] + (straight ? warr[i * pow] : winvarr[i * pow]) * one[i]) % mod;
			}
			for (int i = 0; i < n; i++) {
				ans[n + i] = (((zero[i] - (straight ? warr[i * pow] : winvarr[i * pow]) * one[i]) % mod) + mod) % mod;
			}
			return ans;
		}
	}
	
	public long[] fft(long[] a) {
		long wth = 1;
		int sz = 1 << 20;
		long[] ans = new long[sz];
		for (int i = 0; i < ans.length; i++) {
			long x = 1;
			for (int j = 0; j < a.length; j++) {
				ans[i] += a[j] * x;
				ans[i] %= mod;
				x *= wth;
				x %= mod;
			}
			wth *= w;
			wth %= mod;
		}
		return ans;
	}
	
	public long[] pow(long[] ans, int p) {
		for (int i = 0; i < ans.length; i++) {
			ans[i] = pow(ans[i], p);
		}
		return ans;
	}
	
	public long pow(long x, int p) {
		if (p == 0) {
			return 1;
		}
		if (p % 2 == 1) {
			return pow(x, p - 1) * x % mod;
		}
		long y = pow(x, p / 2);
		return y * y % mod;
	}
	
	long mod = 998244353;
	long w = 646;
	long winv = (new BigInteger(w + "")).modInverse(new BigInteger(mod + "")).longValueExact();
	long[] warr = new long[1 << 20];
	long[] winvarr = new long[1 << 20];
	long szinv = (new BigInteger((1 << 20) + "")).modInverse(new BigInteger(mod + "")).longValueExact();

	public void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		long[] arr = new long[10];
		for (int i = 0; i < k; i++) {
			arr[in.nextInt()] = 1;
		}
		warr[0] = 1;
		winvarr[0] = 1;
		for (int i = 1; i < warr.length; i++) {
			warr[i] = warr[i - 1] * w % mod;
			winvarr[i] = winvarr[i - 1] * w % mod;
		}
		long[] x = fft(arr);
		x = pow(x, n / 2);
		Vector v = new Vector(x);
		x = v.FFT1();
		long ans = 0;
		for (int i = 0; i < x.length; i++) {
			ans += x[i] * x[i];
			ans %= mod;
		}
		out.println(ans);
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
		new FFT().run();
	}
}