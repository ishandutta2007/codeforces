//package cf578d2;
import java.io.*;
import java.util.*;

public class A {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n = sc.nextInt();
		char[] s = sc.nextLine().toCharArray();
		int[] a = new int[10];
		for(char c : s) {
			if(c == 'L') {
				for(int i = 0; i < 10; i++)
					if(a[i] == 0) {
						a[i] = 1;
						break;
					}
			} else if (c == 'R') {
				for(int i = 9; i >= 0; i--)
					if(a[i] == 0) {
						a[i] = 1;
						break;
					}
			} else
				a[c - '0'] = 0;
		}
		for(int i : a)
			out.print(i);
		out.println();
		// ------------------------
		out.close();
	}
	//------------------------
	
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