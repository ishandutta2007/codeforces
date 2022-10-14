import java.io.*;
import java.util.*;

public class B {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		int[]p=new int[n];
		int min=0;
		for(int i=1;i<n;i++){
			p[i]=sc.nextInt()+p[i-1];
			min=Math.min(min, p[i]);
		}
		boolean[] contains=new boolean[n];
		for(int i=0;i<n;i++){
			p[i]+=1-min;
			if(p[i]-1>=0&&p[i]-1<n)
				contains[p[i]-1]=true;
		}
		boolean b=true;
		for(boolean c:contains)
			if(!c)
				b=false;
		if(!b)
			System.out.println(-1);
		else
			for(int i:p)
				System.out.print(i+" ");
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