//package cf579d3;
import java.io.*;
import java.util.*;

public class C {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n = sc.nextInt();
		long x = sc.nextLong();
		for(int i = 0; i < n - 1; i++)
			x = gcd(x, sc.nextLong());
		long ans = 0;
		for(long i = 1; i * i <= x; i++)
			if(x % i == 0)
				ans += i * i == x ? 1 : 2;
		out.println(ans);
		// ------------------------
		out.close();
	}
	//------------------------
	static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
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