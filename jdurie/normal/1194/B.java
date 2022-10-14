//package cfed68;
import java.io.*;
import java.util.*;

public class B {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int q=sc.nextInt();
		for(int w=0;w<q;w++){
			int n=sc.nextInt(),m=sc.nextInt();
			int[]rowX=new int[n];
			int[]colX=new int[m];
			char[][]grid=new char[n][m];
			for(int i=0;i<n;i++){
				char[]s=sc.nextLine().toCharArray();
				for(int j=0;j<m;j++){
					grid[i][j]=s[j];
					if(s[j]=='.'){
						rowX[i]++;
						colX[j]++;
					}
				}
			}
			int min=Integer.MAX_VALUE;
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					min=Math.min(min,rowX[i]+colX[j]+(grid[i][j]=='.'?-1:0));
			System.out.println(min);
		}
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