//package cf585d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		int[] a = new int[n + 1];
		for(int i = 1; i <= n; i++)
			a[i] = a[i - 1] + (sc.nextInt() < 0 ? 1 : 0);
		long po = 0;
		for(int i = 0; i <= n; i++)
			if(a[i] % 2 == 0)
				po++;
		long ne = n + 1 - po;
		long pos = po * (po - 1) / 2 + ne * (ne - 1) / 2;
		long neg = (long) n * (long) (n + 1) / 2 - pos;
		out.println(neg + " " + pos);
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