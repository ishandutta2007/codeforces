//package cf574d2;
import java.io.*;
import java.util.*;

public class B{
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		long n=sc.nextInt(),k=sc.nextInt();
		out.println(bs(n,k,0,n));
		// ------------------------
		out.close();
	}
	//------------------------
	static long bs(long n,long k,long s,long e){
		if(s==e)
			return s;
		long m=(s+e)/2;
		long y=(n-m)*(n-m+1)/2-m;
		if(y == k)
			return m;
		if(y < k)
			return bs(n,k,s,m-1);
		return bs(n,k,m+1,e);
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
		long nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
	}
}