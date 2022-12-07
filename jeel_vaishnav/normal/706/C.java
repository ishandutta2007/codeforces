import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main implements Runnable {
	long gcd(long a, long b) {
		if(b == 0)
			return a;
		return gcd(b, a % b);
	}
	String reverse(String a) {
		char[] ans = new char[a.length()];
		for(int i = 0; i < a.length(); ++i) {
			ans[a.length() - 1 - i] = a.charAt(i); 
		}
		return new String(ans);
	}
	public void solve() {
		FastReader sc = new FastReader();
		PrintWriter out = new PrintWriter(System.out);

		int n = sc.nextInt();

		int c[] = new int[n];
		for(int i = 0; i < n; ++i) {
			c[i] = sc.nextInt();
		}

		String s[] = new String[n];
		for(int i = 0; i < n; ++i)
			s[i] = sc.next();

		long dp[][] = new long[n][2];
		dp[0][0] = 0;
		dp[0][1] = c[0];
		for(int i = 1; i < n; ++i) {
			dp[i][1] = (long)1e18;
			dp[i][0] = (long)1e18;
			if(reverse(s[i]).compareTo(s[i - 1]) >= 0) {
				dp[i][1] = dp[i - 1][0] + c[i];
			} if(s[i].compareTo(s[i - 1]) >= 0) {
				dp[i][0] = dp[i - 1][0];
			} if(reverse(s[i]).compareTo(reverse(s[i - 1])) >= 0) {
				dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
			} if(s[i].compareTo(reverse(s[i - 1])) >= 0) {
				dp[i][0] = min(dp[i][0], dp[i - 1][1]);
			}
			dp[i][0] = min((long)1e18, dp[i][0]);
			dp[i][1] = min((long)1e18, dp[i][1]);
		}

		if(min(dp[n - 1][0], dp[n - 1][1]) == (long)1e18) {
			out.print("-1");
		}
		else
			out.print(min(dp[n - 1][0], dp[n - 1][1]));
		
		out.close();
	}
	public static void main(String[] args) {
		new Thread(null, new Main(), "Main", 1 << 26).start();	
	}

	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while(st == null || !st.hasMoreElements()) {
				try {
					String str = br.readLine();

					if(str == null)
						throw new InputMismatchException();

					st = new StringTokenizer(str);
				} catch(IOException e) {
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

		String nextLine() {
			String str = "";

			try {
				str = br.readLine();
			} catch(IOException e) {
				e.printStackTrace();
			}

			if(str == null) 
				throw new InputMismatchException();
			return str;
		}
	}

	public void run() {
		solve();
	}
}