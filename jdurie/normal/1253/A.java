//package cf600d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class A {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int t = sc.nextInt();
		while(t-- > 0) {
			int n = sc.nextInt();
			int[] a = new int[n], b = new int[n];
			for(int i = 0; i < n; i++)
				a[i] = sc.nextInt();
			for(int i = 0; i < n; i++)
				b[i] = sc.nextInt();
			int del = -1;
			boolean ok = true;
			for(int i = 0; i < n; i++)
				if(a[i] != b[i]) {
					if(del == -1 && b[i] > a[i])
						del = b[i] - a[i];
					if(b[i] < a[i] || del != (b[i] - a[i]))
						ok = false;
				} else if(del != -1)
					del = 0;
			out.println(ok ? "YES" : "NO");
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