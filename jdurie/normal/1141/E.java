
import java.io.*;
import java.util.*;

public class E {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		long H=sc.nextLong();
		int n=sc.nextInt();
		long[]d=new long[n];
		long min=0;
		for(int i=0;i<n;i++){
			d[i]=sc.nextLong()+(i>0?d[i-1]:0);
			min=Math.min(min,d[i]);
		}
		if(d[n-1]>=0)
			out.print(ind(d,H));
		else{
			long rs=Math.max(0,(long)Math.ceil((H+min)/(double)-d[n-1]));
			out.print(rs*n+ind(d,H+rs*d[n-1]));
		}
		// ------------------------
		out.close();
	}
	//------------------------
	private static long ind(long[]d,long x){
		if(x==0)
			return 0;
		for(int i=0;i<d.length;i++)
			if(x+d[i]<=0)
				return i+1;
		return -1;
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