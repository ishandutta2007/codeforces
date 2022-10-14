import java.io.*;
import java.util.*;

public class C {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
int n=sc.nextInt(),min=0,max=0;
		
		for(int i=0;i<n;i++){
			String s=sc.nextLine();
			char c=s.charAt(0);
			s=s.substring(2);
			int a=Integer.parseInt(s.substring(0,s.indexOf(' ')));
			int b=Integer.parseInt(s.substring(s.indexOf(' ')+1));
			if(c=='+'){
				min=Math.max(Math.min(a, b), min);
				max=Math.max(Math.max(a, b), max);
			}else
				out.println(min<=Math.min(a, b)&&max<=Math.max(a, b)?"YES":"NO");
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