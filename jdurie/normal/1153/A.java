
import java.io.*;
import java.util.*;

public class A {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		long n=sc.nextlong(),t=sc.nextlong();
		long min=Long.MAX_VALUE;
		long route=-1;
		for(long i=1;i<=n;i++){
			long s=sc.nextlong(),d=sc.nextlong();
			long x=(long)Math.max(0,Math.ceil((t-s)/(double)d))*d+s;
			if(x<min){
				min=x;
				route=i;
			}
		}
		System.out.println(route);
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
		long nextlong() {
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