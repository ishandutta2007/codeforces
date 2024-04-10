//package cf592d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int t = sc.nextInt();
		for(int qw = 0; qw < t; qw++) {
			int n = sc.nextInt();
			char[] s = sc.nextLine().toCharArray();
			int first1 = -1, last1 = -1;
			for(int i = 0; i < n; i++) {
				if(s[i] == '1') {
					if(first1 == -1)
						first1 = i;
					last1 = i;
				}
			}
			if(first1 == -1)
				out.println(n);
			else {
				int d1 = first1, d2 = n - 1 - last1;
				out.println(2 * (n - min(d1, d2)));
			}
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