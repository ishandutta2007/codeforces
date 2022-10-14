//package a2oj;
import java.util.*;
import java.io.*;

public class MUHCubeWalls {
	public static void main(String[]args){
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		int n = sc.nextInt(), w = sc.nextInt();
		if(w == 1) 
			out.println(n);
		else {
			int[] bears = new int[n - 1];
			int last = sc.nextInt();
			for(int i = 0; i < n - 1; i++)
				bears[i] = last - (last = sc.nextInt());
			last = sc.nextInt();
			int[]elephant=new int[w - 1];
			for(int i = 0; i < w - 1; i++)
				elephant[i] = last - (last = sc.nextInt());
			int[] lps = new int[w - 1];
			int ind = 1, len = 0;
			while(ind < w - 1)
				if(elephant[ind] == elephant[len]) {
					lps[ind] = ++len;
					ind++;
				} else if(len == 0) { 
					lps[ind] = 0;
					ind++;
				} else
					len = lps[len - 1];
			int ans = 0, e = 0, b = 0;
			while(b < n - 1) {
				if(bears[b] == elephant[e]) {
					e++;
					b++;
					if(e == w - 1) {
						ans++;
						e = lps[e - 1];
					}
				} else if(e == 0)
					b++;
				else
					e = lps[e - 1];
			}
			out.println(ans);
		}
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