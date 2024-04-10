//package cf590d3;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class A {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int q = sc.nextInt();
		for(int w = 0; w < q; w++) {
			long n = sc.nextLong(), sum = 0;
			for(int i = 0; i < n; i++)
				sum += sc.nextLong();
			out.println((int)ceil(sum / (double)n));
		}
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