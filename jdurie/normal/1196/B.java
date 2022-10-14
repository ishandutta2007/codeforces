//package cf575d3;
import java.io.*;
import java.util.*;

public class B {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int t=sc.nextInt();
		for(int w=0;w<t;w++){
			int n=sc.nextInt(),k=sc.nextInt(),j=0,s=0;
			int[]a=new int[k];
			for(int i=0;i<n;i++){
				s=(s+sc.nextInt())%2;
				if(s==1&&j<k){
					a[j++]=i+1;
					s=0;
				}
			}
			if(j==k&&a[k-1]!=n){
				if(s==0)
					a[k-1]=n;
				else
					j=-1;
			}
			out.println(j==k?"YES":"NO");
			if(j==k){
				for(int i:a)
					out.print(i+" ");
				out.println();
			}
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