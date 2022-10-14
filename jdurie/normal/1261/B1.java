//package cf602d1;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		long[] a = new long[n];
		long[] x = new long[n];
		for(int i = 0; i < n; i++) {
			x[i] = sc.nextLong();
			a[i] = x[i] * 10000l + n - i;
		}
		Arrays.sort(a);
		int m = sc.nextInt();
		for(int q = 0; q < m; q++) {
			int k = sc.nextInt(), p = sc.nextInt();
			TreeSet<Long> neow = new TreeSet<Long>();
			for(int i = n - 1; i >= n - k; i--) neow.add(n - a[i] % 10000);
			for(int i = 1; i < p; i++) neow.pollFirst();
			long l = neow.first();
			out.println(x[(int)l]);
		}
		out.close();
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