//package cf560d3;
import java.io.*;
import java.util.*;

public class D{
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int t=sc.nextInt();
		for(int w=0;w<t;w++){
			int n=sc.nextInt();
			TreeSet<Long>div=new TreeSet<Long>();
			HashSet<Long>div2=new HashSet<Long>();
			for(int i=0;i<n;i++){
				long x=sc.nextLong();
				div.add(x);
				div2.add(x);
			}
			long ans=-1;
			boolean ok=true;
			while(!div.isEmpty()){
				long prod=div.pollFirst();
				if(div.isEmpty())
					prod*=prod;
				else
					prod*=div.pollLast();
				if(ans==-1)
					ans=prod;
				if(ans!=prod)
					ok=false;
			}
			for(long i=2;i<=Math.sqrt(ans);i++)
				if(ans%i==0)
					if(!(div2.contains(i)&&div2.contains(ans/i)))
						ok=false;
			out.println(ok?ans:-1);
		}
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