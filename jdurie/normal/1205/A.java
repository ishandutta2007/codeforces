//package cf580d1;
import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		int n = sc.nextInt();
		long[] a = new long[2 * n];
		for(int i = 0; i < n; i++)
			if(i % 2 == 0) {
				a[i] = 2 * i + 1;
				a[n + i] = 2 * i + 2;
			} else {
				a[i] = 2 * i + 2;
				a[n + i] = 2 * i + 1;
			}
		long sum = 0;
		for(int i = 0; i < n; i++)
			sum += a[i];
		long curSum = sum;
		boolean ok = true;
		int above = 0;
		for(int i = n; i < 3 * n; i++) {
			curSum += a[i % (2 * n)];
			curSum -= a[(i + n) % (2 * n)];
			if(Math.abs(sum - curSum) > 1)
				ok = false;
			if(sum - curSum == 1) {
				if(above == -1)
					ok = false;
				above = 1;
			}
			if(sum - curSum == -1) {
				if(above == 1)
					ok = false;
				above = -1;
			}
		}
		out.println(ok ? "YES" : "NO");
		if(ok) {
			for(long i : a)
				out.print(i + " ");
			out.println();
		}
		out.close();
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