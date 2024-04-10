//package cfed76;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class C {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int t = sc.nextInt();
		while(t-- > 0) {
			int n = sc.nextInt();
			int[] a = new int[n];
			int[] last = new int[n + 1];
			Arrays.fill(last, -1);
			int ans = 2 * n;
			for(int i = 0; i < n; i++) {
				int ai = sc.nextInt();
				if(last[ai] != -1)
					ans = min(ans, i - last[ai] + 1);
				last[ai] = i;
			}
			out.println(ans == 2 * n ? -1 : ans);
		}
		out.close();
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