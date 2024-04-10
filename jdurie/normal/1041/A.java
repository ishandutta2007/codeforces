import java.io.*;
import java.util.*;

public class Heist {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));

		// Start writing your solution here.
		// -------------------------------------
		int n=sc.nextInt();
		int min=Integer.MAX_VALUE;
		int max=0;
		for(int i=0;i<n;i++){
			int num=sc.nextInt();
			if(num<min)
				min=num;
			if(num>max)
				max=num;
		}
		out.println(max-min+1-n);
		// Stop writing your solution here.
		// -------------------------------------
		out.close();
	}

	// -----------PrintWriter for faster output---------------------------------
	public static PrintWriter out;

	// -----------MyScanner class for faster input----------
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