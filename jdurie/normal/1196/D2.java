//package cf575d3;
import java.io.*;
import java.util.*;

public class D {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int q=sc.nextInt();
		for(int w=0;w<q;w++){
			int n=sc.nextInt(),k=sc.nextInt();
			char[]s=sc.nextLine().toCharArray();
			int[][][]dp=new int[n][3][3];
			char[]rgb=new char[]{'R','G','B'};
			for(int i=0;i<n;i++)
				for(int j=0;j<3;j++)
					for(int c=0;c<3;c++){
						if(i>0)
							dp[i][j][c]=dp[i-1][j][c];
						if(i%3==j&&rgb[c]==s[i])
							dp[i][j][c]++;
					}
			int ans=0;
			for(int i=0;i<n-k+1;i++)
				for(int j=0;j<3;j++){
					int x=0;
					for(int c=0;c<3;c++){
						x+=dp[i+k-1][(j+c)%3][c];
						if(i>0)
							x-=dp[i-1][(j+c)%3][c];
					}
					ans=Math.max(ans,x);
				}
			out.println(k-ans);
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