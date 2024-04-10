//package cf570d3;
import java.io.*;
import java.util.*;

public class D{
	// ------------------------
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int q=sc.nextInt();
		for(int w=0;w<q;w++){
			int n=sc.nextInt();
			int[]arr=new int[n];
			for(int i=0;i<n;i++)
				arr[sc.nextInt()-1]++;
			Arrays.sort(arr);
			int x=Integer.MAX_VALUE;
			long ans=0;
			for(int i=n-1;i>=0;i--){
				int y=Math.min(x,arr[i]);
				ans+=y;
				x=Math.max(0,y-1);
			}
			out.println(ans);
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