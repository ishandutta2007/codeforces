//package manthan19;
import java.io.*;
import java.util.*;

public class D {
	static TreeSet<Long> avail = new TreeSet<Long>();
	static long[] segtree;
	static int n;
	static long[] a;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		n = sc.nextInt();
		a = new long[n];
		for(int i = 0; i < n; i++)
			a[i] = (long)i + 1;
		segtree = new long[4 * n];
		getSegtree(1, 0, n - 1);
		for(long i = 1; i <= n; i++)
			avail.add(i);
		long[] s = new long[n];
		for(int i = 0; i < n; i++)
			s[i] = sc.nextLong();
		long[] p = new long[n];
		for(int i = n - 1; i >= 0; i--) {
			p[i] = avail.ceiling(desum(s[i], 1, n));
			avail.remove(p[i]);
			update(1, 0, n - 1, (int)p[i] - 1, -p[i]);
		}
		for(long i : p)
			out.print(i + " ");
		out.println();
		out.close();
	}
	public static long desum(long s, long l, long r) {
		if(r == l) return l;
		long m = (l + r) / 2;
		long sum = query(1, 0, n - 1, 0, (int)m - 2);
		if(sum < s)
			return desum(s, m + 1, r);
		return desum(s, l, m);
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
	public static long update(int i, int l, int r, int q, long x) {
		if(q < l || q > r)
			return segtree[i];
		if(q == l && q == r)
			return segtree[i] = segtree[i] + x;
		int m = (l + r) / 2;
		return segtree[i] = update(2 * i, l, m, q, x) + update(2 * i + 1, m + 1, r, q, x);
	}
	public static long query(int i, int l, int r, int qL, int qR) {
		if(qR < l || qL > r)
			return 0;
		if(qL <= l && qR >= r)
			return segtree[i];
		int m = (l + r) / 2;
		return query(2 * i, l, m, qL, qR) + query(2 * i + 1, m + 1, r, qL, qR);
	}
	public static long getSegtree(int i, int l, int r) {
		if(l == r)
			return segtree[i] = a[l];
		int m = (l + r) / 2;
		return segtree[i] = getSegtree(2 * i, l, m) + getSegtree(2 * i + 1, m + 1, r);
	}
}