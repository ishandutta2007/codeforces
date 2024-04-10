//package cf585d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class A {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int[] a = new int[]{sc.nextInt(), sc.nextInt()};
		int[] k = new int[]{sc.nextInt(), sc.nextInt()};
		int n = sc.nextInt();
		int min0 = a[0] * (k[0] - 1) + a[1] * (k[1] - 1);
		out.print(max(0, n - min0) + " ");
		if(k[0] < k[1]) {
			int x = min(a[0], n / k[0]);
			if(x == a[0])
				x += (n - a[0] * k[0]) / k[1];
			out.println(x);
		} else {
			int x = min(a[1], n / k[1]);
			if(x == a[1])
				x += (n - a[1] * k[1]) / k[0];
			out.println(x);
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