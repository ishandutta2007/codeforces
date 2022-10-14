//package cfed69;
//package bs;
import java.io.*;
import java.util.*;

public class D {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),m=sc.nextInt(),k=sc.nextInt();
		long[]a=new long[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		long[]maxes=new long[n];
		long[]ms=new long[n];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(i+j<n){
					ms[i]+=a[i+j];
					maxes[i]=Math.max(maxes[i],ms[i]);
				}
		for(int i=0;i<n;i++){
			ms[i]-=k;
			maxes[i]-=k;
			if(maxes[i]<0)
				maxes[i]=0;
		}
		long ans=0;
		for(int i=0;i<m;i++){
			long sum=0;
			int j=i;
			while(j<n){
				ans=Math.max(ans,sum+maxes[j]);
				sum+=ms[j];
				if(sum<0)
					sum=0;
				j+=m;
			}
		}
		out.println(ans);
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