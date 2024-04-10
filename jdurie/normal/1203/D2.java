//package cf579d3;
import java.io.*;
import java.util.*;

public class D {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		char[] s = sc.nextLine().toCharArray();
		char[] t = sc.nextLine().toCharArray();
		int[] posPref = new int[t.length];
		int ind = 0;
		for(int i = 0; i < s.length; i++) {
			if(ind < t.length && s[i] == t[ind]) {
				posPref[ind] = i;
				ind++;
			}
		}
		ind = t.length - 1;
		int[] posSuff = new int[t.length];
		for(int i = s.length - 1; i >= 0; i--) {
			if(ind >= 0 && s[i] == t[ind]) {
				posSuff[ind] = i;
				ind--;
			}
		}
		int max = Math.max(posSuff[0], s.length - 1 - posPref[t.length - 1]);
		//out.println(max);
		for(int i = 0; i < t.length - 1; i++)
			max = Math.max(max, posSuff[i + 1] - posPref[i] - 1 );
		out.println(max);
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