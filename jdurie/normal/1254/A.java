//package cf601d1;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class A {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int T = sc.nextInt();
		while(T-- > 0) {
			int r = sc.nextInt(), c = sc.nextInt(), k = sc.nextInt();
			char[][] grid = new char[r][c];
			for(int i = 0; i < r; i++)
				grid[i] = sc.nextLine().toCharArray();
			int rice = 0;
			for(int i = 0; i < r; i++) 
				for(int j = 0; j < c; j++)
					if(grid[i][j] == 'R') rice++;
			int curr = 0, idx = 0;
			char[] s = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890".toCharArray();
			char[][] ans = new char[r][c];
			for(int i = 0; i < r; i++)
				for(int j = i % 2 == 0 ? 0 : c - 1; j >= 0 && j < c; j += (i % 2 == 0 ? 1 : -1)) {
					ans[i][j] = s[idx];
					if(grid[i][j] == 'R')
						curr++;
					if(curr >= (rice + k - 1) / k && k > 1) {
						rice -= curr;
						k--;
						idx++;
						curr = 0;
					}
				}
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++)
					out.print(ans[i][j]);
				out.println();
			}
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