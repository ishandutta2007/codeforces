//package cf582d3;
import java.io.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int t = sc.nextInt();
		for(int w = 0; w < t; w++) {
			long n = sc.nextLong(), m = sc.nextLong();
			long[] a = new long[10];
			a[0] = m % 10;
			for(int i = 1; i < 10; i++)
				a[i] = (a[i - 1] + m) % 10;
			long sum = 0;
			for(long l : a)
				sum += l;
			long d = n / 10 / m, ans = d * sum, curr = d * 10 * m + m;
			int i = 0;
			while(curr <= n) {
				ans += a[i];
				curr += m;
				i = (i + 1) % 10;
			}
			out.println(ans);
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