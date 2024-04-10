import java.io.*;
import java.util.*;

public class C {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		Integer[]a=new Integer[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		Arrays.sort(a);
		int size=0;
		for(int i=0;i<n;i++)
			size=Math.max(size,bSearch(a,a[i]+5,i,n-1)-i+1);
		out.println(size);
		// ------------------------
		out.close();
	}
	//------------------------
	private static int bSearch(Integer[]a,int x,int start,int end){
		if(end-start<2)
			if(a[end]<=x)
				return end;
			else
				return start;
		int mid=(start+end)/2;
		if(a[mid]>x)
			return bSearch(a,x,start,mid-1);
		else
			return bSearch(a,x,mid,end);
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