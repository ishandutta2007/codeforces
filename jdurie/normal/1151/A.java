
import java.io.*;
import java.util.*;

public class A {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		String bs=sc.nextLine();
		char[]s=sc.nextLine().toCharArray();
		int[]ans=new int[s.length];
		for(int i=0;i<s.length;i++){
			int c=(int)(s[i]-'A');
			ans[i]+=dist(c,0);
			if(i>0)
				ans[i-1]+=dist(c,2);
			if(i>1)
				ans[i-2]+=dist(c,19);
			if(i>2)
				ans[i-3]+=dist(c,6);
		}
		int min=Integer.MAX_VALUE;
		for(int i=0;i+3<s.length;i++)
			min=Math.min(min,ans[i]);
		System.out.println(min);
		// ------------------------
		out.close();
	}
	//------------------------
	private static int dist(int a,int b){
		int d1=a-b;
		while(d1<0)
			d1+=26;
		int d2=b-a;
		while(d2<0)
			d2+=26;
		return Math.min(d1, d2);
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