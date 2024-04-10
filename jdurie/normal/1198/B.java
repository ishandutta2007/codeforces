//package cf576d1;
import java.io.*;
import java.util.*;

public class B {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		int[]a=new int[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		int q=sc.nextInt();
		ArrayList<Integer>payouts=new ArrayList<Integer>();
		int[]lastP=new int[n];
		for(int w=0;w<q;w++)
			if(sc.nextInt()==1){
				int p=sc.nextInt()-1;
				lastP[p]=payouts.size();
				a[p]=sc.nextInt();
			}else
				payouts.add(sc.nextInt());
		for(int i=payouts.size()-2;i>=0;i--)
			payouts.set(i,Math.max(payouts.get(i),payouts.get(i+1)));
		for(int i=0;i<n;i++)
			out.print(Math.max(lastP[i]<payouts.size()?payouts.get(lastP[i]):0,a[i])+" ");
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