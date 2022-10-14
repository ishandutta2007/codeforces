import java.io.*;
import java.util.*;

public class E{
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		long[]a=new long[n];
		TreeMap<Long,Integer>b=new TreeMap<Long,Integer>();
		for(int i=0;i<n;i++)
			a[i]=sc.nextLong();
		for(int i=0;i<n;i++){
			long x=sc.nextLong();
			b.put(x,b.containsKey(x)?b.get(x)+1:1);
		}
		for(int i=0;i<n;i++)
			out.print((a[i]+remCeil(n-a[i],b))%n+" ");
		out.println();
		// ------------------------
		out.close();
	}
	private static long remCeil(long a,TreeMap<Long,Integer>b){
		Long x=b.ceilingKey(a);
		if(x==null)
			x=b.firstKey();
		if(b.get(x)==1)
			b.remove(x);
		else
			b.put(x,b.get(x)-1);
		return x;
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