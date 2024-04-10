//package cfglobal3;
import java.io.*;
import java.util.*;

public class B{
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),m=sc.nextInt();
		long ta=sc.nextLong(),tb=sc.nextLong(),k=sc.nextLong();
		if(k>=n){
			out.println(-1);
		}else{
			long[]a=new long[n];
			for(int i=0;i<n;i++)
				a[i]=sc.nextInt();
			long[]b=new long[m];
			for(int i=0;i<m;i++)
				b[i]=sc.nextInt();
			long ans=0;
			for(int i=0;i<=k;i++){//i=first AB flight they go in on
				int x=bSearch(a[i]+ta,b,0,m-1);//x=first possible BC flight
				int total=(int)k-i;//total=removals left
				if(x==-1||total>=(m-x))
					ans=Long.MAX_VALUE;
				else
					ans=Math.max(ans,b[x+total]+tb);
			}
			out.println(ans==Long.MAX_VALUE?-1:ans);
		}
		// ------------------------
		out.close();
	}
	//------------------------
	private static int bSearch(long x,long[]b,int start,int end){
		if(start==end)
			return b[start]>=x?start:-1;
		int mid=(start+end)/2;
		if(b[mid]>=x)
			return bSearch(x,b,start,mid);
		return bSearch(x,b,mid+1,end);
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