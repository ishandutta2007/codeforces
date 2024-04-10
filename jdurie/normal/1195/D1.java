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
		long sum=0;
		String[]arr=sc.nextLine().split(" ");
		for(String s:arr){
			char[]st=s.toCharArray();
			for(int i=0;i<st.length;i++){
				int p=2*(st.length-1-i);
				sum=(sum+n*pow(10,p)%MOD*(st[i]-'0')%MOD*11%MOD)%MOD;
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