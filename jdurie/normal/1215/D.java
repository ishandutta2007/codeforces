//package cf585d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class D {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		char[] s = sc.nextLine().toCharArray();
		int sum = 0, q = 0;
		for(int i = 0; i < n / 2; i++)
			if(s[i] == '?')
				q--;
			else
				sum += s[i] - '0';
		for(int i = n / 2; i < n; i++)
			if(s[i] == '?')
				q++;
			else
				sum -= s[i] - '0';
		out.println(sum == q * 9 / 2 ? "Bicarp" : "Monocarp");
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