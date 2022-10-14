import java.io.*;
import java.util.*;

public class D{
	// ------------------------
	private static long MOD=1000000007;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		long[][]dp=new long[n+1][n+1];
		long ans=0;
		for(int i=0;i<=n;i++){
			dp[i][0]=1;
			if(i%2==1)
				ans++;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++){
				dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
				if((i+j)%2==1)
					ans=(ans+dp[i][j])%MOD;
			}
		System.out.println(ans);
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