//package cf577d2;
import java.io.*;
import java.util.*;

public class A {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n = sc.nextInt(), m = sc.nextInt();
		int[][] ans = new int[m][5];
		for(int i = 0; i < n; i++) {
			char[]s = sc.nextLine().toCharArray();
			for(int j = 0; j < m; j++)
				ans[j][s[j] - 'A']++;
		}
		long a = 0;
		for(int i = 0; i < m; i++) {
			int max = 0;
			for(int j = 0; j < 5; j++)
				max = Math.max(ans[i][j], max);
			a += max * sc.nextInt();
		}
		out.println(a);
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