//package cfed71;
import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		int n = sc.nextInt(), m = sc.nextInt();
		int[][] A = new int[n][m];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				A[i][j] = sc.nextInt();
		int[][] B = new int[n][m];
		LinkedList<String> ll = new LinkedList<String>();
		for(int i = 0; i < n - 1; i++)
			for(int j = 0; j < m - 1; j++)
				if(A[i][j] == 1 && A[i + 1][j] == 1 && A[i][j + 1] == 1 && A[i + 1][j + 1] == 1) {
					B[i][j] = 1;
					B[i + 1][j] = 1;
					B[i][j + 1] = 1;
					B[i + 1][j + 1] = 1;
					ll.add((i + 1) + " " + (j + 1));
				}
		boolean ok = true;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(A[i][j] != B[i][j])
					ok = false;
		out.println(ok ? ll.size() : -1);
		if(ok)
			for(String s : ll)
				out.println(s);
		out.close();
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