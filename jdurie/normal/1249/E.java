//package cf595d3;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class E {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt(), c = sc.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		for(int i = 1; i < n; i++)
			a[i] = sc.nextInt();
		for(int i = 1; i < n; i++)
			b[i] = sc.nextInt();
		long[] dpE = new long[n];
		long[] dpS = new long[n];
		dpE[0] = c;
		out.print("0");
		for(int i = 1; i < n; i++) {
			dpS[i] = a[i] + min(dpE[i - 1], dpS[i - 1]);
			dpE[i] = b[i] + min(dpE[i - 1], dpS[i - 1] + c);
			out.print(" " + min(dpE[i], dpS[i]));
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