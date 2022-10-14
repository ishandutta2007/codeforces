//package cf595d3;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class A {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int s = sc.nextInt();
		while(s-- > 0) {
			int n = sc.nextInt();
			Integer[] a = new Integer[n];
			for(int i = 0; i < n; i++)
				a[i] = sc.nextInt();
			Arrays.sort(a);
			boolean oneGap = false;
			for(int i = 1; i < n; i++)
				if(a[i] - a[i - 1] == 1)
					oneGap = true;
			out.println(oneGap ? 2 : 1);
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