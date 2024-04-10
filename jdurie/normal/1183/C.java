//package cf570d3;
import java.io.*;
import java.util.*;

public class C{
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		long q=sc.nextInt();
		for(long w=0;w<q;w++){
			long k=sc.nextInt(),n=sc.nextInt(),a=sc.nextInt(),b=sc.nextInt();
			out.println(bSearch(k,n,0,n,a,b));
		}
		// ------------------------
		out.close();
	}
	//------------------------
	private static long bSearch(long k,long n,long start,long end,long a,long b){
		if(end-start<2){
			if(end*a+(n-end)*b<k)
				return end;
			if(start*a+(n-start)*b<k)
				return start;
			return -1;
		}
		long mid=(start+end)/2;
		if(mid*a+(n-mid)*b<k)
			return bSearch(k,n,mid,end,a,b);
		return bSearch(k,n,start,mid-1,a,b);
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