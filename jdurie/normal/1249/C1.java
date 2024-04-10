//package cf595d3;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class C {
	public static void main(String[] args) {
		TreeSet<Integer> good = new TreeSet<Integer>();
		for(int i = 0; i < 1 << 15; i++) {
			int x = 0;
			for(int p = 0; p < 15; p++)
				if((i & (1 << p)) > 0)
					x += pow(3, p);
			good.add(x);
		}
		MyScanner sc = new MyScanner();
		int t = sc.nextInt();
		while(t-- > 0)
			out.println(good.ceiling(sc.nextInt()));
		out.close();
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