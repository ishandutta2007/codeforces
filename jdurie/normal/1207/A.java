//package cfed71;
import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		int t = sc.nextInt();
		for(int w = 0; w < t; w++) {
			int b = sc.nextInt(), p = sc.nextInt(), f = sc.nextInt();
			int h = sc.nextInt(), c = sc.nextInt();
			if(h >= c) {
				int burg = Math.min(p, b/2);
				int chic = Math.min(f, (b - 2 * burg) / 2);
				out.println(h * burg + c * chic);
			} else {
				int chic = Math.min(f, b/2);
				int burg = Math.min(p, (b - 2 * chic) / 2);
				out.println(h * burg + c * chic);
			}
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