//package cf600d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class D {
	static int[] dsu, mx;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt(), m = sc.nextInt();
		dsu = new int[n];
		mx = new int[n];
		for(int i = 0; i < n; i++)
			dsu[i] = mx[i] = i;
		for(int i = 0; i < m; i++)
			join(sc.nextInt() - 1, sc.nextInt() - 1);
		int ans = 0;
		for(int i = 1; i < n; i++) {
			if(dsu(i) == i && mx[dsu(i - 1)] > i) {
				join(i, i - 1);
				ans++;
			}
		}
		out.println(ans);
		out.close();
	}
	static void join(int u, int v) {
		u = dsu(u);
		v = dsu(v);
		mx[min(u, v)] = max(mx[u], mx[v]);
		dsu[max(u, v)] = min(u, v);
	}
	static int dsu(int x) {
		return dsu[x] == x ? x : (dsu[x] = dsu(dsu[x]));
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