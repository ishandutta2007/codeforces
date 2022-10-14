//package a2oj;
import java.io.*;
import java.util.*;
 
public class EnemyIsWeak {
	static HashMap<Integer, Integer> rev = new HashMap<Integer, Integer>();
	static long[] inv, inv2;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		int[] a = new int[n], b = new int[n];
		for(int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			b[n - 1 - i] = a[i];
			rev.put(a[i], i);
		}
		inv = new long[n];
		mergesort(a, true);
		inv2 = new long[n];
		mergesort(b, false);
		long ans = 0;
		for(int i = 0; i < n; i++)
			ans += inv[i] * (long)(n - 1 - i - inv2[i]);
		out.println(ans);
		out.close();
	}
	static int[] mergesort(int[] a, boolean first) {
		if(a.length == 1)
			return a;
		int[] x = new int[a.length / 2], y = new int[(a.length + 1) / 2];
		for(int i = 0; i < a.length; i++)
			if(i < a.length / 2)
				x[i] = a[i];
			else
				y[i - a.length / 2] = a[i];
		mergesort(x, first);
		mergesort(y, first);
		int iX = 0, iY = 0, iA = 0;
		while(iX < x.length || iY < y.length)
			if(iY == y.length || (iX != x.length && x[iX] < y[iY]))
				a[iA++] = x[iX++];
			else {
				if(first)
					inv[rev.get(y[iY])] += x.length - iX;
				else
					inv2[rev.get(y[iY])] += x.length - iX;
				a[iA++] = y[iY++];
			}
		return a;
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