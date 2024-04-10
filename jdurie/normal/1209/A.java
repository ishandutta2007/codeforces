//package cf584d12;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class A {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		Integer[] a = new Integer[n];
		for(int i = 0; i < n; i++)
			a[i] = sc.nextInt();
		Arrays.sort(a);
		boolean[] b = new boolean[n];
		int ans = 0;
		for(int i = 0; i < n; i++)
			if(!b[i]) {
				ans++;
				for(int j = i + 1; j < n; j++)
					if(a[j] % a[i] == 0)
						b[j] = true;
			}
		out.println(ans);
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