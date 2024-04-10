//package cf603d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class D {
	static int[] dsu = new int[26];
	static boolean[] seen = new boolean[26];
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		for(int i = 0; i < 26; i++) dsu[i] = i;
		for(int i = 0; i < n; i++) {
			char[] s = sc.nextLine().toCharArray();
			for(int j = 0; j < s.length; j++) {
				seen[s[j] - 'a'] = true;
				for(int k = 0; k < s.length; k++)
					dsu[dsu(s[j] - 'a')] = dsu(s[k] - 'a');
			}
		}
		int ct = 0;
		for(int i = 0; i < 26; i++)
			if(dsu[i] == i && seen[i])
				ct++;
		out.println(ct);
		out.close();
	}
	static int dsu(int i) {
		return dsu[i] == i ? i : (dsu[i] = dsu(dsu[i]));
	}
	static PrintWriter out  = new PrintWriter(new BufferedOutputStream(System.out));
	static class MyScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String next() {
			while (st == null || !st.hasMoreElements())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
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