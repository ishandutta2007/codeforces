//package cfglobal4;
import java.io.*;
import java.util.*;

public class D{
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		int ind=-1;
		for(int i=0;i<=n/2;i++)
			if(prime(n+i))
				ind=i;
		if(ind==-1)
			out.println(-1);
		else{
			System.out.println(n+ind);
			for(int i=0;i<n;i++)
				System.out.println((i+1)+" "+((i+1)%n+1));
			for(int i=0;i<ind;i++)
				System.out.println((i+1)+" "+(i+n/2+1));
		}
		// ------------------------
		out.close();
	}
	//------------------------
	static boolean prime(int n){
		for(int i=2;i<=Math.sqrt(n);i++)
			if(n%i==0)
				return false;
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