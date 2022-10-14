//package cf594d1;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class A {
	static long MOD = 1000000007;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt(), m = sc.nextInt();
		long[][][] dp = new long[max(n, m)][2][2];
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				if(dp.length > 1)
					dp[1][i][j] = 1;
		for(int i = 2; i < dp.length; i++) {
			dp[i][0][0] = dp[i - 1][0][1];
			dp[i][1][1] = dp[i - 1][1][0];
			dp[i][0][1] = (dp[i - 1][1][0] + dp[i - 1][1][1]) % MOD;
			dp[i][1][0] = (dp[i - 1][0][1] + dp[i - 1][0][0]) % MOD;
		}
		long dpN = 0, dpM = 0;
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++) {
				dpN = (dpN + dp[n - 1][i][j]) % MOD;
				dpM = (dpM + dp[m - 1][i][j]) % MOD;
			}
		if(n == 1) dpN = 2;
		if(m == 1) dpM = 2;
		out.println((dpN - 2 + dpM + MOD) % MOD);
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