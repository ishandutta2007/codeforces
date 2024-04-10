//package cf581d2;
import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		long n = sc.nextLong();
		System.out.print(f(n, sc.nextLong()) + " " + g(n, sc.nextLong()));
		out.close();
	}
	public static long f(long n, long x) {
		long sum = 0;
		for(int i = 0; i < n; i++)
			sum += (i >= x ? 1 : 1L << i);
		return sum;
	}
	public static long g(long n, long x) {
		long sum = 0;
		for(int i = 0; i < n; i++)
			sum += (i >= x ? 1L << (x - 1) : 1L << i);
		return sum;
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