//package a2oj;
import java.io.*;
import java.util.*;

public class GregAndGraph {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		long[][] d = new long[n][n];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				d[i][j] = sc.nextLong();
		int[] p = new int[n];
		for(int i = 0; i < n; i++)
			p[n - 1 - i] = sc.nextInt() - 1;
		Stack<Long> ans = new Stack<Long>();
		for(int k = 0; k < n; k++) {
			long x = 0;
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++) {
					d[p[i]][p[j]] = Math.min(d[p[i]][p[j]], d[p[i]][p[k]] + d[p[k]][p[j]]);
					if(i <= k && j <= k)
						x += d[p[i]][p[j]];
				}
			ans.push(x);
		}
		while(!ans.isEmpty())
			out.print(ans.pop() + " ");
		out.println();
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