import java.io.*;
import java.util.*;

public class CowProgram {
	static long[][] dp;
	static int[] a;
	static int n;
	static TreeSet<Integer> inds;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		n = sc.nextInt() - 1;
		dp = new long[n][2];
		a = new int[n];
		for(int i = 0; i < n; i++)
			a[i] = sc.nextInt();
		for(int i = 0; i < n; i++) {
			inds = new TreeSet<Integer>();
			if(dp(i, 1) == -1)
				out.println(-1);
			else
				out.println(dp[i][1] + i + 1);
		}
		out.close();
	}
	public static long dp(int i, int j) {
		if(i == -1)
			return -1;
		if(i < 0 || i >= n)
			return 0;
		if(dp[i][j] != 0)
			return dp[i][j];
		if(inds.contains(2 * i + j))
			return dp[i][j] = -1;
		inds.add(2 * i + j);
		long d = dp(i + (j == 0 ? a[i] : -a[i]), 1 - j);
		if(d == -1)
			return dp[i][j] = -1;
		return dp[i][j] = d + a[i];
	}
	public static PrintWriter out;
	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
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