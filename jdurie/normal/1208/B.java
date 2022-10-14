//package manthan19;
import java.io.*;
import java.util.*;

public class B {
	static int[] a;
	static int n;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		n = sc.nextInt();
		a = new int[n];
		for(int i = 0; i < n; i++)
			a[i] = sc.nextInt();
		out.println(bSearch(0, n));
		out.close();
	}
	static int bSearch(int l, int r) {
		if(l == r)
			return l;
		int m = (l + r) / 2;
		boolean globalOk = false;
		for(int j = 0; j + m - 1 < n; j++) {
			HashSet<Integer> set = new HashSet<Integer>();
			boolean ok = true;
			for(int i = 0; i < n; i++)
				if(i < j || i > j + m - 1)
					if(set.contains(a[i])) {
						ok = false;
						break;
					} else
						set.add(a[i]);
			if(ok) {
				globalOk = true;
				break;
			}
		}
		if(globalOk)
			return bSearch(l, m);
		return bSearch(m + 1, r);
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