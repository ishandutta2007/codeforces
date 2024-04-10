//package cfed77;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class D {
	static int m, n, k, t;
	static int[] l, r, d;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		m = sc.nextInt();
		n = sc.nextInt();
		k = sc.nextInt();
		t = sc.nextInt();
		int[] a = new int[m];
		for(int i = 0; i < m; i++) a[i] = sc.nextInt();
		l = new int[k]; r = new int[k]; d = new int[k];
		for(int i = 0; i < k; i++) {
			l[i] = sc.nextInt();
			r[i] = sc.nextInt();
			d[i] = sc.nextInt();
		}
		long Q = bSearch(0, 100000000000000l), ans = 0;
		for(int i : a) if(i >= Q) ans++;
		out.println(ans);
		out.close();
	}
	static long bSearch(long l, long r) {
		if(l == r) return l;
		long mid = (l + r) / 2;
		return works(mid) ? bSearch(l, mid) : bSearch(mid + 1, r);
	}
	static boolean works(long mid) {
		TreeSet<Trap> set = new TreeSet<Trap>();
		for(int i = 0; i < k; i++)
			if(d[i] > mid) {
				Trap t = new Trap(l[i], r[i]), s;
				while((s = set.floor(t)) != null && s.rt >= l[i]) {
					t.lf = min(t.lf, s.lf);
					t.rt = max(t.rt, s.rt);
					set.remove(s);
				}
				while((s = set.ceiling(t)) != null && s.lf <= r[i]) {
					t.lf = min(t.lf, s.lf);
					t.rt = max(t.rt, s.rt);
					set.remove(s); 
				}
				set.add(t);
			}
		long len = n + 1;
		for(Trap t : set) len += 2 * (t.rt - t.lf + 1);
		return len <= t;
	}
	static class Trap implements Comparable<Trap>{
		int lf, rt;
		public Trap(int L, int R) {
			lf = L;
			rt = R;
		}
		public int compareTo(Trap t) {
			return lf - t.lf;
		}
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
/*
5 6 4 14
1 2 3 4 5
1 5 2
1 2 5
2 3 5
3 5 3
*/