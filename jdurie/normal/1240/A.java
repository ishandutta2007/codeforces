//package cf591d1;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class A {
	static int n;
	static long k, x, y, a, b, g;
	static Long[] prices;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int q = sc.nextInt();
		while(q-- > 0) {
			n = sc.nextInt();
			prices = new Long[n];
			for(int i = 0; i < n; i++)
				prices[i] = sc.nextLong();
			Arrays.sort(prices);
			x = sc.nextLong(); a = sc.nextLong();
			y = sc.nextLong(); b = sc.nextLong();
			k = sc.nextLong(); g = gcd(a, b);
			out.println(bSearch(0, n));
			int i = bSearch(0, n);
		}
		out.close();
	}
	static boolean works(int m) {
		long lcm = a * b / g;
		long both = m / lcm, as = m / a - both, bs = m / b - both;
		//out.println(m + " "  + both + " "  + as + " " + bs);
		int ind = n - 1;
		long sum = 0;
		for(int i = 0; i < both; i++)
			sum += prices[ind--] * (x + y) / 100;
		if(y > x) {
			for(int i = 0; i < bs; i++)
				sum += prices[ind--] * y / 100;
			for(int i = 0; i < as; i++)
				sum += prices[ind--] * x / 100;
		} else {
			for(int i = 0; i < as; i++)
				sum += prices[ind--] * x / 100;
			for(int i = 0; i < bs; i++)
				sum += prices[ind--] * y / 100;
		}
		//out.println(sum);
		return sum >= k;
	}
	static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	static int bSearch(int l, int r) {
		if(!works(r))
			return -1;
		if(l == r)
			return l;
		int m = (l + r) / 2;
		return works(m) ? bSearch(l, m) : bSearch(m + 1, r);
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