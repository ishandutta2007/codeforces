//package cfed67;
import java.io.*;
import java.util.*;

public class B{
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		int[][]grid=new int[26][n];
		char[]s=sc.nextLine().toCharArray();
		int[]inds=new int[26];
		for(int i=0;i<n;i++){
			int x=s[i]-'a';
			grid[x][inds[x]]=i;
			inds[x]++;
		}
		int m=sc.nextInt();
		for(int w=0;w<m;w++){
			char[]t=sc.nextLine().toCharArray();
			int[]cts=new int[26];
			for(char c:t)
				cts[c-'a']++;
			int max=-1;
			for(int i=0;i<26;i++)
				if(cts[i]>0)
					max=Math.max(max,grid[i][cts[i]-1]);
			System.out.println(max+1);
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