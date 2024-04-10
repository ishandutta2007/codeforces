//package cfglobal5;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;
public class D{
	// ------------------------
	static int[][] arr;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n = sc.nextInt(), min = Integer.MAX_VALUE, max = 0;
		int[] a = new int[n];
		for(int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			min = min(min, a[i]);
			max = max(max, a[i]);
		}
		if(min >= (max + 1) / 2)
			for(int i = 0; i < n; i++)
				out.print("-1 ");
		else {
			arr = new int[3 * n][20];
			for(int i = 0; i < 3 * n; i++)
				arr[i][0] = a[i % n];
			for(int j = 1; j < 20; j++)
				for(int i = 0; i < 3 * n; i++) {
					int i2 = i + (1 << (j - 1));
					arr[i][j] = i2 < 3 * n ? min(arr[i][j - 1], arr[i2][j - 1]) : arr[i][j - 1];
				}
			int[] o = new int[n];
			for(int i = 0; i < n; i++)
				o[i] = bSearch(i, 3 * n - 1, i, a[i]) - i;
			int maxI = 0;
			for(int i = 0; i < n; i++)
				if(a[i] > a[maxI])
					maxI = i;
			int d = 1, oia = maxI;
			for(int i = (maxI - 1 + n) % n; i != oia; i = (i - 1 + n) % n) {
				if(o[i] < o[maxI] + d) {
					maxI = i;
					d = 0;
				} else
					o[i] = o[maxI] + d;
				d++;
			}
			for(int i = 0; i < n; i++)
				out.print(o[i] + " ");
		}
		out.println();
		// ------------------------
		out.close();
	}
	static int rmq(int l, int r) {
		int w = Integer.highestOneBit(r - l + 1), logw = Integer.numberOfTrailingZeros(w);
		return min(arr[l][logw], arr[r - w + 1][logw]);
	}
	static int bSearch(int l, int r, int i, int v) {
		if(l == r)
			return l;
		int m = (l + r) / 2;
		return rmq(i, m) < (v + 1) / 2 ? bSearch(l, m, i, v) : bSearch(m + 1, r, i, v);
	}
	//------------------------
	public static PrintWriter out;
	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
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