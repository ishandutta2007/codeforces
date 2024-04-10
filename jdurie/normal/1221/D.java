//package cfed73;
import java.io.*;
import java.util.*;

public class D {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int q = sc.nextInt();
		for(int w = 0; w < q; w++) {
			int n = sc.nextInt();
			long[] a = new long[n];
			long[] b = new long[n];
			long[][] dp = new long[n][3];
			for(int i = 0; i < n; i++) {
				a[i] = sc.nextLong();
				b[i] = sc.nextLong();
			}
			dp[0][0] = 0;
			dp[0][1] = b[0];
			dp[0][2] = 2 * b[0];
			for(int i = 1; i < n; i++) 
				for(int j = 0; j < 3; j++)
					dp[i][j] = j * b[i] + min(dp[i - 1], a[i] + j - a[i - 1]);
			out.println(min(dp[n - 1], 100000));
		}
		out.close();
	}
	public static long min(long[] dp, long d) {
		long ans = Long.MAX_VALUE;
		for(int j = 0; j < 3; j++)
			if(j != d)
				ans = Math.min(ans, dp[j]);
		return ans;
	}
	public static PrintWriter out  = new PrintWriter(new BufferedOutputStream(System.out));
	public static class MyScanner {
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