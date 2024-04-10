//package a2oj;
import java.io.*;
import java.util.*;

public class PrefixesAndSuffixes{
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		char[] s = sc.nextLine().toCharArray();
		int n = s.length;
		int[] lps = new int[n];
		int ind = 1, len = 0;
		while(ind < n)
			if(s[ind] == s[len])
				lps[ind++] = ++len;
			else if(len == 0)
				lps[ind++] = 0;
			else
				len = lps[len - 1];
		int[] a = new int[n];
		for(int i : lps)
			a[i]++;
		for(int i = n - 1; i > 0; i--)
			a[lps[i - 1]] += a[i];
		LinkedList<String> ll = new LinkedList<String>();
		int x = lps[n - 1];
		while(x != 0) { 
			ll.addFirst(x + " " + (a[x] + 1));
			x = lps[x - 1];
		}
		ll.addLast(n + " 1");
		out.println(ll.size());
		for(String st : ll)
			out.println(st);
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