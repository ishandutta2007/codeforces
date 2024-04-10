//package cf560d3;
import java.io.*;
import java.util.*;

public class E{
	// ------------------------
	private static long MOD=998244353;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		Long[]a=new Long[n];
		Long[]b=new Long[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextLong()*(i+1)*(n-i);
		for(int i=0;i<n;i++)
			b[i]=sc.nextLong();
		Arrays.sort(a);
		Arrays.sort(b);
		long sum=0;
		for(int i=0;i<n;i++)
			sum=(sum+((a[i]%MOD)*b[n-1-i])%MOD)%MOD;
		out.println(sum);
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