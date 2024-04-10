import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class C {
	static int x3, x4, x5, x6, y3, y4, y5, y6;
	static int sx1, bx1, sy1, by1, sx2, bx2, sy2, by2;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int x1 = sc.nextInt(), y1 = sc.nextInt();
		int x2 = sc.nextInt(), y2 = sc.nextInt();
		x3 = sc.nextInt();
		y3 = sc.nextInt();
		x4 = sc.nextInt();
		y4 = sc.nextInt();
		x5 = sc.nextInt();
		y5 = sc.nextInt();
		x6 = sc.nextInt();
		y6 = sc.nextInt();
		sx1 = min(x3, x4); bx1 = max(x3, x4);
		sy1 = min(y3, y4); by1 = max(y3, y4);
		sx2 = min(x5, x6); bx2 = max(x5, x6);
		sy2 = min(y5, y6); by2 = max(y5, y6);
		boolean ok = false;
		for(double i = min(x1, x2); i <= max(x1, x2); i += 0.5)
			if(!inside(i, y1) || !inside(i, y2))
				ok = true;
		for(double i = min(y1, y2); i <= max(y1, y2); i += 0.5)
			if(!inside(x1, i) || !inside(x2, i))
				ok = true;
		out.println(ok ? "YES" : "NO");
		out.close();
	}
	static boolean inside(double x, double y) {
		boolean in1 = x >= sx1 && x <= bx1 && y >= sy1 && y <= by1;
		boolean in2 = x >= sx2 && x <= bx2 && y >= sy2 && y <= by2;
		return in1 || in2;
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