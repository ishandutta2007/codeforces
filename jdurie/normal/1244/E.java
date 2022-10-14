//package cf592d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class E {
	static int n;
	static long[] a, dp, dp2;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		n = sc.nextInt();
		long k = sc.nextLong();
		a = new long[n];
		for(int i = 0; i < n; i++)
			a[i] = sc.nextLong();
		Arrays.sort(a);
		dp = new long[n];
		for(int i = n - 2; i >= 0; i--)
			dp[i] = dp[i + 1] + (n - 1 - i) * (a[i + 1] - a[i]);
		dp2 = new long[n];
		for(int i = 1; i < n; i++)
			dp2[i] = dp2[i - 1] + i * (a[i] - a[i - 1]);
		out.println(bSearch(0, (long)pow(10, 9), k));
		out.close();
	}
	static long bSearch(long l, long r, long k) {
		if(l == r)
			return l;
		long m = (l + r) / 2;
		if(works(m, k) || works2(m, k))
			return bSearch(l, m, k);
		return bSearch(m + 1, r, k);
	}
	static boolean works(long m, long k) {
		long cl = 0;
		int idx = 0;
		for(int i = 0; i < n; i++) {
			while(idx < n && a[idx] <= a[i] + m)
				idx++;
			if(idx == n)
				return cl <= k;
			if(cl + dp[idx] + (a[idx] - a[i] - m) * (n - idx) <= k)
				return true;
			if(i < n - 1)
				cl += (i + 1) * (a[i + 1] - a[i]);
		}
		return false;
	}
	static boolean works2(long m, long k) {
		long cl = 0;
		int idx = n - 1;
		for(int i = n - 1; i >= 0; i--) {
			while(idx >= 0 && a[idx] >= a[i] - m)
				idx--;
			if(idx == -1)
				return cl <= k;
			if(cl + dp2[idx] + (a[i] - m - a[idx]) * (idx + 1) <= k)
				return true;
			if(i > 0)
				cl += (n - i) * (a[i] - a[i - 1]);
		}
		return false;
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