//package cf580d1;
import java.io.*;
import java.util.*;

public class C {
	static int[][] a;
	static MyScanner sc;
	static int n;
	public static void main(String[] args) {
		sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		n = sc.nextInt();
		a = new int[n][n];
		a[0][0] = 1;
		for(int j = 2; j < n; j += 2)
			a[0][j] = query(0, j - 2, 0, j, false);
		for(int j = 1; j < n; j += 2)
			a[1][j] = query(0, j - 1, 1, j, false);
		for(int i = 2; i < n; i++)
			for(int j = 0; j < n; j++)
				if((i + j) % 2 == 0 && i + j > 0 && i + j < 2 * n - 2)
					a[i][j] = query(i - 2, j, i, j, false);
		a[0][1] = 1;
		for(int j = 3; j < n; j += 2)
			a[0][j] = query(0, j - 2, 0, j, false);
		for(int i = 2; i < n; i += 2)
			a[i][1] = query(i - 2, 1, i, 1, false);
		for(int i = 1; i < n; i++)
			for(int j = 2; j < n; j++)
				if((i + j) % 2 == 1)
					a[i][j] = query(i - 1, j - 1, i, j, false);
		for(int i = 1; i < n; i += 2)
			a[i][0] = query(i + 1, 1, i, 0, true);
		boolean swapOdd = false;
		int[] dx = {1, 0}, dy = {0, 1};
		loop:
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				for(int k = 0; k < 2; k++)
					for(int l = 0; l < 2; l++)
						for(int m = 0; m < 2; m++)
							if(valid(i - dx[k], j - dy[k]) && valid(i + dx[l], j + dy[l]) && valid(i + dx[l] + dx[m], j + dy[l] + dy[m])) {
								int A = a[i - dx[k]][j - dy[k]];
								int B = a[i][j];
								int C = a[i + dx[l]][j + dy[l]];
								int D = a[i + dx[l] + dx[m]][j + dy[l] + dy[m]];
								if((A == C) == (B == D)) {
									out.println("? " + (i - dx[k] + 1) + " " + (j - dy[k] + 1) + " " + (i + dx[l] + dx[m] + 1) + " " + (j + dy[l] + dy[m] + 1));
									out.flush();
									int res = sc.nextInt();
									if(res == -1) return;
									if((res == 1 && A != D) || (res == 0 && A == D))
										swapOdd = true;
									break loop;
								}
							}
		out.println("!");
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				out.print((i + j) % 2 == 1 && swapOdd ? 1 - a[i][j] : a[i][j]);
			out.println();
		}
		out.close();
	}
	private static boolean valid(int r, int c) {
		return r >= 0 && c >= 0 && r < n && c < n;
	}
	static int query(int x1, int y1, int x2, int y2, boolean swap) {
		if(swap)
			out.println("? " + (x2 + 1) + " " + (y2 + 1) + " " + (x1 + 1) + " " + (y1 + 1));
		else
			out.println("? " + (x1 + 1) + " " + (y1 + 1) + " " + (x2 + 1) + " " + (y2 + 1));
		out.flush();
		int resp = sc.nextInt();
		if(resp == -1) System.exit(0);
		return resp == 1 ? a[x1][y1] : 1 - a[x1][y1];
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