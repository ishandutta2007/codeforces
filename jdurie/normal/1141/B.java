import java.io.*;
import java.util.*;

public class C {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		boolean[]a=new boolean[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt()==1;
		int max=0,curr=0;
		for(int i=0;i<n;i++)
			if(a[i]){
				curr++;
				max=Math.max(curr,max);
			}else
				curr=0;
		int ind=0,ct=0;
		while(a[ind]){
			ind++;
			ct++;
		}
		int ind2=n-1;
		while(a[ind2]){
			ind2--;
			ct++;
		}
		out.println(Math.max(max,ct));
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