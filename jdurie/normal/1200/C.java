//package cf578d2;
import java.io.*;
import java.util.*;

public class C {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		long n = sc.nextLong(), m = sc.nextLong(), g = gcd(n, m);
		int q = sc.nextInt();
		for(int w = 0; w < q; w++) {
			long sx = sc.nextLong(), sy = sc.nextLong() - 1, ex = sc.nextLong(), ey = sc.nextLong() - 1;
			if(sx == 1)
				sy /= (n/g);
			else
				sy /= (m/g);
			if(ex == 1)
				ey /= (n/g);
			else
				ey /= (m/g);
			out.println(sy == ey ? "YES" : "NO");
		}
		// ------------------------
		out.close();
	}
	//------------------------
	public static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
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