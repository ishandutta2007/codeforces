import java.io.*;
import java.util.*;

public class A {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		long n=sc.nextInt(),k=sc.nextInt(),a=sc.nextInt(),b=sc.nextInt();
		long[]start={a,k-a};
		long max=Long.MIN_VALUE,min=Long.MAX_VALUE;
		for(long i=0;i<n;i++){
			long[]next={(k*i-b+n*k)%(n*k),k*i+b};
			for(long s:start)
				for(long nx:next){
						long l=(nx-s+n*k)%(n*k);
						long x=n*k/gcd(n*k,l);
						max=Math.max(max,x);
						min=Math.min(min,x);
				}
		}
		out.println(min+" "+max);
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