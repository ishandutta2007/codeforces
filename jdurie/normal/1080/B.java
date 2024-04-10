//package cf524d2;
import java.io.*;
import java.util.*;

public class B {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int q = sc.nextInt();
		for(int w = 0; w < q; w++) {
			long l = sc.nextInt(), r = sc.nextInt();
			long ans = 0;
			if(l % 2 == 1)
				ans -= l++;
			if(r % 2 == 0)
				ans += r--;
			ans -= (r - l + 1)/2;
			out.println(ans);
		}
		// ------------------------
		out.close();
	}
	//------------------------
	static long sum(long i){
		if(i<=0)
			return 0;
		return i*(i+1)/2;
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