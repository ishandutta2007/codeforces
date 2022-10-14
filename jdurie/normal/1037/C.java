//package manthan18;
import java.io.*;
import java.util.*;

public class C {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n = sc.nextInt();
		char[] a = sc.nextLine().trim().toCharArray();
		char[] b = sc.nextLine().trim().toCharArray();
		long cost = 0;
		for(int i = 0; i < a.length - 1; i++)
			if((a[i] != b[i]) && (a[i + 1] != b[i + 1]) && (a[i] != a[i + 1])) {
				a[i] = b[i];
				a[i + 1] = b[i + 1];
				cost++;
			}
		for(int i = 0; i < a.length; i++)
			if(a[i] != b[i])
				cost++;
		out.println(cost);
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