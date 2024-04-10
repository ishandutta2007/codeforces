//package cf587d3;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class E {
	static long[] arr = new long[22000];
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		for(int i = 1; i < 22000; i++)
			arr[i] = len(i) + arr[i - 1];
		int q = sc.nextInt();
		for(int i = 0; i < q; i++)
			out.println(bSearch(1, 21999, sc.nextLong()));
		out.close();
	}
	public static long bSearch(int l, int r, long x) {
		if(l == r)
			return charAtPos(x - arr[l - 1], l);
		int m = (l + r) / 2;
		if(arr[m] < x)
			return bSearch(m + 1, r, x);
		return bSearch(l, m, x);
	}
	public static long ans(long x) {
		long block = 1, temp = -1;
		while(x > (temp = len(block))) {
			x -= temp;
			block++;
		}
		return charAtPos(x, block);
	}
	public static long charAtPos(long x, long block) {
		for(int i = 1;; i++) {
			if(x <= 9 * i * pow(10, i - 1)) {
				long dig = i - 1 - (x - 1) % i;
				if(dig == i - 1)
					return (((x - 1) / i) % (long)pow(10, dig + 1)) / (long)pow(10, dig) + 1;
				return ((x - 1) / i) % (long)pow(10, dig + 1) / (long)pow(10, dig);
			}
			x -= 9 * i * pow(10, i - 1);
		}
	}
	public static long len(long x) {
		long ans = 0;
		for(int i = 0; pow(10, i) <= x; i++)
			ans += x - pow(10, i) + 1;
		return ans;
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