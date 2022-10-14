//package cf587d3;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		Long[] arr = new Long[n];
		for(int i = 0; i < n; i++)
			arr[i] = sc.nextLong() * 1000 + i;
		Arrays.sort(arr);
		long ans = 0;
		for(int i = n - 1; i >= 0; i--)
			ans += (arr[i] / 1000) * (n - 1 - i) + 1;
		out.println(ans);
		for(int i = n - 1; i >= 0; i--)
			out.print((arr[i] % 1000 + 1) + " ");
		out.println();
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