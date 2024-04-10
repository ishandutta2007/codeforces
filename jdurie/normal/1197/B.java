//package cfed69;
//package bs;
import java.io.*;
import java.util.*;

public class B {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),maxInd=0;
		int[]a=new int[n];
		for(int i=0;i<n;i++){
			a[i]=sc.nextInt();
			if(a[i]>a[maxInd])
				maxInd=i;
		}
		boolean ok=true;
		for(int i=maxInd-1;i>=0;i--)
			if(a[i]>a[i+1])
				ok=false;
		for(int i=maxInd+1;i<n;i++)
			if(a[i]>a[i-1])
				ok=false;
		System.out.println(ok?"yes":"no");
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