//package manthan19;
import java.io.*;
import java.util.*;

public class C {
	static int n;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		n = sc.nextInt();
		int[][] a = new int[n][n];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) {
				int m4 = f(i, j);
				int x = g(i % (n / 2), j % (n / 2));
				a[i][j] = x * 4 + m4;
			}
		/*for(int i = 0; i < n; i++) {
			int xor = 0;
			for(int j = 0; j < n; j++)
				xor ^= a[i][j];
			if(xor != 0)
				out.println(i + " "+ xor);
		}
		for(int j = 0; j < n; j++) {
			int xor = 0;
			for(int i = 0; i < n; i++)
				xor ^= a[i][j];
			if(xor != 0)
				out.println(j + "J" + xor);
		}*/
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++)
				out.print(a[i][j] + " ");
			out.println();
		}
		out.close();
	}
	static int g(int i, int j) {
		return i * n / 2 + j;
	}
	static int f(int i, int j) {
		int ans = 0;
		if(i >= n / 2)
			ans += 2;
		if(j >= n / 2)
			ans++;
		return ans;
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