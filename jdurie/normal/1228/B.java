//package cf589d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int h = sc.nextInt(), w = sc.nextInt();
		int[][]grid = new int[h][w];
		boolean ok = true;
		for(int i = 0; i < h; i++) {
			int rh = sc.nextInt();
			for(int j = 0; j < rh; j++)
				if(grid[i][j] == 2)
					ok = false;
				else
					grid[i][j] = 1;
			if(rh < w && grid[i][rh] == 1)
				ok = false;
			else if(rh < w)
				grid[i][rh] = 2;
		}
		for(int j = 0; j < w; j++) {
			int cw = sc.nextInt();
			for(int i = 0; i < cw; i++)
				if(grid[i][j] == 2)
					ok = false;
				else
					grid[i][j] = 1;
			if(cw < h && grid[cw][j] == 1)
				ok = false;
			else if(cw < h)
				grid[cw][j] = 2;
		}
		long zeroes = 0;
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
				if(grid[i][j] == 0)
					zeroes++;
		if(!ok)
			out.println(0);
		else
			out.println(mPow(zeroes));
		out.close();
	}
	static long MOD = 1000000007L;
	public static long mPow(long x) {
		if(x == 0)
			return 1;
		long l = mPow(x / 2);
		return l * l % MOD * (x % 2 == 1 ? 2 : 1) % MOD;
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