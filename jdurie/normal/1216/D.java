//package cf587d3;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class D {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		Long[] a = new Long[n];
		long sum = 0;
		for(int i = 0; i < n; i++) {
			a[i] = sc.nextLong();
			sum += a[i];
		}
		Arrays.sort(a);
		long g = a[1] - a[0];
		for(int i = 2; i < n; i++)
			g = gcd(g, a[i] - a[i - 1]);
		long min = Long.MAX_VALUE, ans = -1;
		for(int i = 1; i * i <= g; i++)
			if(g % i == 0) {
				long x1 = f(n, sum, i, a[n - 1]);
				if(x1 < min) {
					min = x1;
					ans = i;
				}
				long x2 = f(n, sum, g / i, a[n - 1]);
				if(x2 < min) {
					min = x2;
					ans = g / i;
				}
			}
		out.println(min + " " + ans);
		out.close();
	}
	public static long f(long n, long sum, long gcd, long last) {
		return (n * last - sum) / gcd;
	}
	public static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
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