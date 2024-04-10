//package cfed77;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class A {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int T = sc.nextInt();
		while(T-- > 0) {
			long c = sc.nextLong(), x = sc.nextLong();
			long ans = x * x;
			for(int rad = 1; rad <= c; rad++) {
				long big = x % rad;
				long temp = big * sq((x + rad - 1) / rad) + (rad - big) * sq(x / rad);
				ans = min(temp, ans);
			}
			out.println(ans);
		}
		out.close();
	}
	static long sq(long l) {
		return l * l;
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