import java.io.*;
import java.util.*;

public class A{
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),m=sc.nextInt();
		long last=sc.nextLong(),g=-1,min=last;
		for(int i=0;i<n-1;i++){
			long next=sc.nextLong();
			if(g==-1)
				g=next-last;
			else
				g=gcd(g,next-last);
			last=next;
		}
		int ind=-1;
		for(int i=1;i<=m;i++)
			if(g%sc.nextLong()==0)
				ind=i;
		if(ind==-1)
			System.out.println("NO");
		else
			System.out.println("YES\n"+min+" "+ind);
		// ------------------------
		out.close();
	}
	//------------------------
	private static long gcd(long a,long b){
		return b==0?a:gcd(b,a%b);
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