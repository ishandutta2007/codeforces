//package cfed76;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class D {
	static class X implements Comparable<X>{
		int p, s;
		public X(int P, int S) {
			p = P;
			s = S;
		}
		public int compareTo(X x) {
			return p == x.p ? s - x.s : p - x.p;
		}
	}
	static X[] heroes;
	static int[] monsters;
	public static int bSearch(int l, int r, int p) {
		if(l == r) return l;
		int m = (l + r) / 2;
		return heroes[m].p < p ? bSearch(m + 1, r, p) : bSearch(l, m, p);
	}
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int t = sc.nextInt();
		while(t-- > 0) {
			int n = sc.nextInt();
			monsters = new int[n];
			for(int i = 0; i < n; i++)
				monsters[i] = sc.nextInt();
			int m = sc.nextInt();
			heroes = new X[m];
			for(int i = 0; i < m; i++)
				heroes[i] = new X(sc.nextInt(), sc.nextInt());
			Arrays.sort(heroes);
			for(int i = m - 2; i >= 0; i--)
				heroes[i].s = max(heroes[i].s, heroes[i + 1].s);
			int ans = 0, curr = 0, ind = 0, monst = 0;
			boolean works = true;
			while(ind < n) {
				monst = max(monst, monsters[ind]);
				X hero = heroes[bSearch(0, m - 1, monst)];
				if(hero.s < curr + 1 || hero.p < monst) {
					ans++;
					if(curr == 0) {
						works = false;
						ind = n;
					}
					monst = 0;
					curr = 0;
				} else {
					curr++;
					ind++;
				}
			}
			if(curr > 0) ans++;
			out.println(works ? ans : -1);
		}
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