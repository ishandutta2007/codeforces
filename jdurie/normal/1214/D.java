//package cf583d12;
import java.io.*;
import java.util.*;

public class D {
	static int n, m;
	static char[][] grid;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		n = sc.nextInt();
		m = sc.nextInt();
		grid = new char[n][];
		for(int i = 0; i < n; i++)
			grid[i] = sc.nextLine().toCharArray();
		int[] arr = new int[n + m];
		grid[n - 1][m - 1] = 'P';
		for(int i = n - 1; i >= 0; i--)
			for(int j = m - 1; j >= 0; j--)
				if(grid[i][j] != '#' && ((valid(i, j + 1) && grid[i][j + 1] == 'P') || (valid(i + 1, j) && grid[i + 1][j] == 'P')))
					grid[i][j] = 'P';
		grid[0][0] = 'Q';
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(grid[i][j] == 'P' && ((valid(i, j - 1) && grid[i][j - 1] == 'Q') || (valid(i - 1, j) && grid[i - 1][j] == 'Q'))) {
					grid[i][j] = 'Q';
					arr[i + j]++;
				}
		int ans = n;
		for(int i = 1; i < n + m - 2; i++)
			ans = Math.min(ans, arr[i]);
		System.out.println(ans);
		out.close();
	}
	static class Pair {
		int i, j;
		public Pair(int I, int J) {
			i = I;
			j = J;
		}
		public boolean equals(Object o) {
			return o instanceof Pair && ((Pair)o).i == i && ((Pair)o).j == j;
		}
		public String toString() {
			return "(" + i + ", " + j + ")";
		}
	}
	static boolean valid(int i, int j) {
		return i >= 0 && j >= 0 && i < n && j < m;
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