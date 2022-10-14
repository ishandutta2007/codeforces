//package cfed74;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class C {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int q = sc.nextInt();
		for(int qq = 0; qq < q; qq++) {
			int h = sc.nextInt(), n = sc.nextInt();
			int[] out = new int[n + 1];
			for(int i = 0; i < n; i++)
				out[i] = sc.nextInt();
			out[n] = 0;
			int[] dp = new int[n + 1];
			for(int i = n - 2; i >= 0; i--)
				if(out[i + 1] - out[i + 2] <= 1)
					dp[i] = dp[i + 2];
				else
					dp[i] = dp[i + 1] + 1;
			System.out.println(dp[0]);
		}
		out.close();
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