
import java.io.*;
import java.util.*;

public class A {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		double n=sc.nextDouble(), m=sc.nextDouble();
		int n2=0,n3=0;
		while(n%2==0){
			n2++;
			n/=2;
		}
		while(n%3==0){
			n3++;
			n/=3;
		}
		int m2=0,m3=0;
		while(m%2==0){
			m2++;
			m/=2;
		}
		while(m%3==0){
			m3++;
			m/=3;
		}
		if(n==m&&m2>=n2&&m3>=n3)
			System.out.println(m2-n2+m3-n3);
		else
			System.out.println(-1);
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