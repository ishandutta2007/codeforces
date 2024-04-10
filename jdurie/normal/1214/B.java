//package cf583d12;
import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int b = sc.nextInt(), g = sc.nextInt(), n = sc.nextInt();
		int maxBoys = Math.min(n, b);
		int minBoys = Math.max(0, n - g);
		System.out.println(maxBoys - minBoys + 1);
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