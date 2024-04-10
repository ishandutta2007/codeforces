//package cf603d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class E {
	static int n = 1000100;
	static MM[] a, seg;
	static int[] pend;
	static class MM {
		int min, max;
		public MM(int mn, int mx) {
			min = mn;
			max = mx;
		}
	}
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		seg = new MM[4 * n];
		Arrays.fill(seg, new MM(0, 0));
		pend = new int[4 * n];
		int m = sc.nextInt(), idx = 0;
		char[] s = sc.nextLine().toCharArray();
		int balCt = 0;
		char[] curr = new char[n];
		Arrays.fill(curr, 'a');
		for(int i = 0; i < m; i++) {
			if(s[i] == 'R') idx++;
			else if(s[i] == 'L') idx = max(idx - 1, 0);
			else if(s[i] == '(' && curr[idx] != '(') {
				int uCt = curr[idx] == ')' ? 2 : 1;
				update(1, 0, n - 1, idx, n - 1, uCt);
				balCt += uCt;
			} else if(s[i] == ')' && curr[idx] != ')') {
				int uCt = curr[idx] == '(' ? -2 : -1;
				update(1, 0, n - 1, idx, n - 1, uCt);
				balCt += uCt;
			} else if(s[i] != '(' && s[i] != ')') {
				if(curr[idx] == '(') {
					update(1, 0, n - 1, idx, n - 1, -1);
					balCt--;
				} else if(curr[idx] == ')') {
					update(1, 0, n - 1, idx, n - 1, 1);
					balCt++;
				}
			}
			if(s[i] != 'R' && s[i] != 'L')
				curr[idx] = s[i];
			propagate(1, 0, n - 1);
			if(seg[1].min < 0 || balCt != 0) out.print("-1 ");
			else out.print(seg[1].max + " ");
		}
		out.close();
	}
	static MM comb(MM a, MM b) {
		return new MM(min(a.min, b.min), max(a.max, b.max)); //combining two nodes
	}
	static MM update(int i, int l, int r, int qL, int qR, int x) {
		propagate(i, l, r);
		if(qR < l || qL > r)
			return seg[i];
		if(qL <= l && qR >= r) {
			pend[i] = x;
			propagate(i, l, r);
			return seg[i];
		}
		int m = (l + r) / 2; 
		return seg[i] = comb(update(2 * i, l, m, qL, qR, x), update(2 * i + 1, m + 1, r, qL, qR, x));
	}
	static void propagate(int i, int l, int r) {
		if(l != r) {
			pend[2 * i] += pend[i];
			pend[2 * i + 1] += pend[i];
		}
		seg[i] = new MM(seg[i].min + pend[i], seg[i].max + pend[i]);
		pend[i] = 0;
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