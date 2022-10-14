//package cf584d12;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		boolean[] on = new boolean[n];
		char[] s = sc.nextLine().toCharArray();
		for(int i = 0; i < n; i++)
			on[i] = s[i] == '1';
		for(int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
		}
		int max = 0;
		for(int i = 0; i < 1000; i++) {
			for(int j = 0; j < n; j++)
				if(i >= b[j] && ((i - b[j]) % a[j]) == 0)
					on[j] = !on[j];
			int ct = 0;
			for(int j = 0; j < n; j++)
				if(on[j])
					ct++;
			max = max(max, ct);
		}
		out.println(max);
		out.close();
	}
	public static PrintWriter out  = new PrintWriter(new BufferedOutputStream(System.out));
	public static class MyScanner {
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