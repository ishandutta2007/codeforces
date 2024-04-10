//package cf593d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class C {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		int[][] grid = new int[n][n];
		int curr = 1;
		for(int j = 0; j < n; j++)
			if(j % 2 == 0)
				for(int i = 0; i < n; i++)
					grid[i][j] = curr++;
			else
				for(int i = n - 1; i >= 0; i--)
					grid[i][j] = curr++;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++)
				out.print(grid[i][j] + " ");
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