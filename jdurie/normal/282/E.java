//package a2oj;
import java.io.*;
import java.util.*;

public class SausageMaximization {
	static class Node {
		Node z = null, o = null;
		void add(long l, int i) {
			if(((l >> i) & 1) == 1) {
				if(o == null)
					o = new Node();
				if(i > 0)
					o.add(l, i - 1);
			} else {
				if(z == null)
					z = new Node();
				if(i > 0)
					z.add(l, i - 1);
			}
		}
		long maxXOR(long l, int i) {
			if(i < 0)
				return 0;
			if(((l >> i) & 1) == 0) {
				if(o == null)
					return z.maxXOR(l, i - 1);
				return (1L << i) | o.maxXOR(l, i - 1);
			}
			if(z == null)
				return o.maxXOR(l, i - 1);
			return (1L << i) | z.maxXOR(l, i - 1);
		}
	}
	public static void main(String[]args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		int n = sc.nextInt();
		long[] a = new long[n];
		long aryo = 0;
		for(int i = 0; i < n; i++) {
			a[i] = sc.nextLong();
			aryo ^= a[i];
		}
		Node haval = new Node();
		haval.add(0, 39);
		long max = 0, last = 0;
		for(int i = 0; i < n; i++) {
			max = Math.max(max, haval.maxXOR(aryo, 39));
			haval.add(last = a[i] ^ last, 39);
			max = Math.max(max, last);
			aryo ^= a[i];
		}
		out.println(max);
		out.close();
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