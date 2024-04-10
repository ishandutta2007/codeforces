import java.io.*;
import java.util.*;

public class A {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),m=sc.nextInt();
		int[]a=new int[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		out.println(bSearch(m,a,0,m-1));
		// ------------------------
		out.close();
	}
	//------------------------
	private static int bSearch(int m,int[]a,int st,int en){
		if(en-st<2)
			return works(a,st,m)?st:en;
		int mid=(st+en)/2;
		if(works(a,mid,m))
			return bSearch(m,a,st,mid);
		return bSearch(m,a,mid+1,en);
	}
	private static boolean works(int[]a,int x,int m){
		int last=0;
		for(int i:a){
			int del=(last-i+m)%m;
			if(del>x&&i>=last)
				last=i;
			else if(del>x)
				return false;
		}
		return true;
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