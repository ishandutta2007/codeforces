//package cf574d2;
import java.io.*;
import java.util.*;

public class C{
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=(int) sc.nextInt();
		long[][]arr=new long[n][2];
		for(int i=0;i<n;i++)
			arr[i][0]=sc.nextInt();
		for(int i=0;i<n;i++)
			arr[i][1]=sc.nextInt();
		long[][]dp=new long[n][3];
		dp[0][0]=arr[0][0];
		dp[0][1]=arr[0][1];
		for(int i=1;i<n;i++){
			dp[i][0]=arr[i][0]+Math.max(dp[i-1][1],dp[i-1][2]);
			dp[i][1]=arr[i][1]+Math.max(dp[i-1][0],dp[i-1][2]);
			dp[i][2]=Math.max(dp[i-1][0],Math.max(dp[i-1][1],dp[i-1][2]));
		}
		out.println(Math.max(dp[n-1][0],Math.max(dp[n-1][1],dp[n-1][2])));
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
		long nextInt() {
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