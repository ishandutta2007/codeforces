//package cf583d12;
import java.io.*;
import java.util.*;

public class E {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		ArrayList<X> d = new ArrayList<X>();
		for(int i = 0; i < n; i++)
			d.add(new X(2 * i + 2, sc.nextInt()));
		Collections.sort(d);
		for(int i = 0; i < n - 1; i++)
			out.println(d.get(i).r + " " + d.get(i + 1).r);
		for(int i = 0; i < n; i++) {
			int newNode = d.get(i).r - 1, pos = i + d.get(i).d - 1;
			out.println(newNode + " " + d.get(pos).r);
			if(pos == d.size() - 1)
				d.add(new X(newNode, -1));
		}
		out.close();
	}
	static class X implements Comparable<X>{
		int r, d;
		public X(int I, int D) {
			r = I;
			d = D;
		}
		public int compareTo(X x) {
			if(x.d == d) return r - x.r;
			return x.d - d;
		}
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