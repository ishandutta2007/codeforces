//package cfed73;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class A {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int t = sc.nextInt();
		for(int w = 0; w < t; w++) {
			TreeMap<Long, Integer> map = new TreeMap<Long, Integer>();
			int n = sc.nextInt();
			boolean f = true;
			for(long i = 1; i <= pow(2, 30); i *= 2) {
				map.put(i, 0);
			}
			for(int i = 0; i < n; i++) {
				long x = sc.nextInt();
				map.put(x, map.get(x) + 1);
			}
			for(long i = 2; i <= 2048; i *= 2)
				map.put(i, map.get(i / 2) / 2 + map.get(i));
			out.println(map.get(2048L) > 0 ? "YES" : "NO");
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