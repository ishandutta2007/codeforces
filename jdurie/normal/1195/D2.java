//package cf574d2;
import java.io.*;
import java.util.*;

public class D{
	// ------------------------
	static long MOD=998244353;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		int[]len=new int[11];
		long sum=0;
		long[][]digits=new long[11][11];
		for(int i=0;i<n;i++){
			long x=sc.nextLong();
			int l=(x+"").length();
			len[l]++;
			for(int j=0;j<l;j++){
				digits[l][j]+=x%10;
				x/=10;
			}
		}
		for(int i=1;i<=10;i++){
			for(int d=0;d<i;d++){
				for(int j=1;j<=10;j++){
					int p=2*d;
					if(j<d)
						p-=d-j;
					sum=(sum+len[j]*pow(10,p)%MOD*(digits[i][d])%MOD)%MOD;
					p=2*d+1;
					if(j<d+1)
						p-=d+1-j;
					sum=(sum+len[j]*pow(10,p)%MOD*(digits[i][d])%MOD)%MOD;
				}
			}
		}
		out.println(sum);
		// ------------------------
		out.close();
	}
	//------------------------
	static long pow(long a,int p){
		if(p==0)
			return 1;
		long x=pow(a,p/2);
		return x*x%MOD*(p%2==1?a:1)%MOD;
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