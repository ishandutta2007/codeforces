//package cf597d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class C {
	static long MOD = 1000000007;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		char[] s = sc.nextLine().toCharArray();
		for(char c : s)
			if(c == 'w' || c == 'm') {
				out.println(0);
				out.close();
				return;
			}
		int n = s.length;
		long[] dp = new long[n];
		dp[0] = 1;
		if(n > 1)
			dp[1] = s[0] == s[1] && (s[0] == 'u' || s[0] == 'n') ? 2 : 1;
		for(int i = 2; i < n; i++) {
			dp[i] = dp[i - 1];
			if(s[i] == s[i - 1] && (s[i] == 'u' || s[i] == 'n'))
				dp[i] = (dp[i] + dp[i - 2]) % MOD;
		}
		out.println(dp[n - 1]);
		out.close();
	}
	static PrintWriter out  = new PrintWriter(new BufferedOutputStream(System.out));
	static class MyScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String next() {
			while (st == null || !st.hasMoreElements())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
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
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
}