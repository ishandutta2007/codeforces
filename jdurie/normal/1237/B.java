//package cfglobal5;
import java.io.*;
import java.util.*;

public class B{
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n = sc.nextInt();
		int[] in = new int[n], ou = new int[n];
		for(int i = 0; i < n; i++)
			in[i] = sc.nextInt();
		for(int i = 0; i < n; i++)
			ou[i] = sc.nextInt();
		int iIn = 0, iOut = 0, ans = 0;
		TreeSet<Integer> seen = new TreeSet<Integer>();
		while(iIn < n && iOut < n) {
			if(seen.contains(in[iIn]))
				iIn++;
			else if(in[iIn] == ou[iOut]) {
				iIn++;
				iOut++;
			} else {
				seen.add(ou[iOut++]);
				ans++;
			}
		}
		out.println(ans);
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