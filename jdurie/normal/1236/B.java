//package cf593d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class B {
	static int M = 1000000007;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		long n = sc.nextLong(), m = sc.nextLong();
		out.println(mPow(mPow(2, m) - 1, n));
		out.close();
	}
	static long mPow(long a, long p) {
		if(p == 0)
			return 1;
		long x = mPow(a, p / 2);
		return x * x % M * (p % 2 == 1 ? a : 1) % M;
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