//package cf579d3;
import java.io.*;
import java.util.*;

public class B {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int q = sc.nextInt();
		for(int w = 0; w < q; w++) {
			int n = sc.nextInt();
			Integer[] a = new Integer[4 * n];
			for(int i = 0; i < 4 * n; i++) 
				a[i] = sc.nextInt();
			Arrays.sort(a);
			boolean ok = true;
			int area = a[0] * a[4 * n - 1];
			for(int i = 0; i < 2 * n; i += 2) {
				int g = a[i], h = a[i + 1], j = a[4 * n - 2 - i], k = a[4 * n - 1 - i];
				if(g != h || j != k || g * j != area)
					ok = false;
			}
			out.println(ok ? "YES" : "NO");
		}
		// ------------------------
		out.close();
	}
	//------------------------
	
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