import java.io.*;
import java.util.*;

public class D {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		Long[]s=new Long[n];
		for(int i=0;i<n;i++)
			s[i]=sc.nextLong();
		Arrays.sort(s);
		Long[]g=new Long[n];
		g[n-1]=Long.MAX_VALUE;
		for(int i=0;i<n-1;i++)
			g[i]=s[i+1]-s[i];
		Arrays.sort(g);
		long[]pSum=new long[n];
		for(int i=0;i<n;i++)
			pSum[i]=(i>0?pSum[i-1]:0)+g[i];
		int q=sc.nextInt();
		for(int w=0;w<q;w++){
			long l=sc.nextLong(),r=sc.nextLong();
			long d=r-l+1;
			int i=bSearch(0,n-1,d,g);
			System.out.println((i>0?pSum[i-1]:0)+(n-i)*d);
		}
		// ------------------------
		out.close();
	}
	//------------------------
	private static int bSearch(int st,int en,long d,Long[]g){
		if(en-st<2){
			if(g[st]>d)
				return st;
			if(g[en]>d)
				return en;
			return -1;
		}
		int mid=(st+en)/2;
		if(g[mid]>d)
			return bSearch(st,mid,d,g);
		return bSearch(mid+1,en,d,g);
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