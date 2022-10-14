//package cf589d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class E {
	static long MOD = 1000000007;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		long k = sc.nextLong();
		long[][] choose = new long[n + 1][n + 1];
		long[][] pow = new long[n + 1][2];
		for(int i = 0; i <= n; i++) {
			choose[i][0] = 1;
			choose[i][i] = 1;
		}
		for(int i = 2; i <= n; i++)
			for(int j = 1; j < i; j++)
				choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % MOD;
		for(int i = 0; i <= n; i++)
			for(int j = 0; j < 2; j++)
				pow[i][j] = pMod(k - j, i);
		long[][] dp = new long[n + 1][n + 1];
		dp[0][n] = 1;
		for(int i = 1; i <= n; i++)
			for(int j = 0; j <= n; j++)
				for(int l = 0; l <= j; l++) {
					long del = dp[i - 1][j] * choose[j][l] % MOD * pow[l][1] % MOD;
					if(l < j)
						del = del * pow[n - j][0] % MOD;
					else
						del = del * (pow[n - j][0] - pow[n - j][1] + MOD) % MOD;
					dp[i][l] = (dp[i][l] + del) % MOD;
				}
		out.println(dp[n][0]);
		out.close();
	}
	public static long pMod(long x, long p) {
		if(p == 0)
			return 1;
		long l = pMod(x, p / 2);
		return l * l % MOD * (p % 2 == 1 ? x : 1) % MOD;
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