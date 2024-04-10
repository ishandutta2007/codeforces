import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;

public class D {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public int gcd(int a, int b) {
		if (a == 0) {
			return b;
		}
		return gcd(b % a, a);
	}
	
	
	
	public void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		long mod = 998244353;
		long[][][] dp = new long[n][k + 2][4];
		dp[0][1][0]++;
		dp[0][2][1]++;
		dp[0][2][2]++;
		dp[0][1][3]++;
		for (int i = 1; i < dp.length; i++) {
			for (int j = 1; j < dp[0].length; j++) {
				dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2];
				dp[i][j][3] = dp[i - 1][j][3] + dp[i - 1][j][1] + dp[i - 1][j][2];
				if (j > 0) {
					dp[i][j][0] += dp[i - 1][j - 1][3];
					dp[i][j][3] += dp[i - 1][j - 1][0];
				}
				if (j > 1) {
					dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j][1] + dp[i - 1][j - 1][3];
					dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j][2] + dp[i - 1][j - 1][3];
					dp[i][j][1] += dp[i - 1][j - 2][2];
					dp[i][j][2] += dp[i - 1][j - 2][1];
				}
				for (int x = 0; x < dp[0][0].length; x++) {
					dp[i][j][x] %= mod;
				}
			}
		}
//		for (int i = 0; i < dp.length; i++) {
//			int x = 0;
//			for (int j = 0; j < dp[0].length; j++) {
//				for (int l = 0; l < dp[0][0].length; l++) {
//					x += dp[i][j][l];
//					out.print(dp[i][j][l] + " ");
//				}
//				out.println();
//			}
//			out.println(x);
//		}
		out.println((dp[n - 1][k][0] + dp[n - 1][k][1] + dp[n - 1][k][2] + dp[n - 1][k][3]) % mod);
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
		new D().run();
	}
}