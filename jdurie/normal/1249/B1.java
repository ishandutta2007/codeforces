//package cf595d3;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int q = sc.nextInt();
		while(q-- > 0) {
			int n = sc.nextInt();
			int[] p = new int[n];
			int[] par = new int[n];
			int[] ans = new int[n];
			for(int i = 0; i < n; i++) {
				p[i] = sc.nextInt() - 1;
				par[i] = -1;
			}
			for(int i = 0; i < n; i++)
				if(par[i] == -1) {
					par[i] = i;
					int steps = 1, j = i;
					while(p[j] != i) {
						j = p[j];
						par[j] = i;
						steps++;
					}
					ans[i] = steps;
				}
			for(int i = 0; i < n; i++)
				out.print(ans[par[i]] + " ");
			out.println();
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