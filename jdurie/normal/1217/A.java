//package cfed72;
import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int t = sc.nextInt();
		for(int w = 0; w < t; w++) {
			int st = sc.nextInt(), in = sc.nextInt(), ex = sc.nextInt();
			int x = (in + ex - st);
			if(x < 0)
				x--;
			if(st + ex <= in)
				System.out.println(0);
			else
				System.out.println(ex - Math.max(-1, x / 2));
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