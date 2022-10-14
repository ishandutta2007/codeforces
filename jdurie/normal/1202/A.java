//package cfed70;
import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		int t = sc.nextInt();
		for(int w = 0; w < t; w++) {
			char[] x = sc.nextLine().toCharArray();
			char[] y = sc.nextLine().toCharArray();
			int ind = 0, yPos = -1;
			for(int i = 0; i < y.length; i++)
				if(y[i] == '1')
					yPos = i;
			int ans = -1;
			for(int i = 0; i <= yPos + x.length - y.length; i++)
				if(x[i] == '1')
					ans = yPos - i + x.length - y.length;
			out.println(ans);
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