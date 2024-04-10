//package cf589d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class A {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int l = sc.nextInt(), r = sc.nextInt();
		int works = -1;
		for(int i = l; i <= r; i++)
			if(works(i))
				works = i;
		out.println(works);
		out.close();
	}
	public static boolean works(int i) {
		boolean[] used = new boolean[10];
		while(i > 0) {
			int d = i % 10;
			if(used[d])
				return false;
			used[d] = true;
			i /= 10;
		}
		return true;
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