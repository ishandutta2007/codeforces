import java.util.*;

import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public static class Point implements Comparable<Point> {
		int x;
		int type;
		
		public Point(int x, int type) {
			this.x = x;
			this.type = type;
		}

		@Override
		public int compareTo(Point o) {
			if (x != o.x) {
				return x - o.x;
			}
			return type - o.type;
		}
		
	}
	
	public void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		ArrayList<Point> list = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			list.add(new Point(in.nextInt() - 1, 0));
			list.add(new Point(in.nextInt() - 1, 1));
		}
		Collections.sort(list);
		Point[] p = new Point[2 * n];
		for (int i = 0; i < p.length; i++) {
			p[i] = list.get(i);
		}
		int j = 0;
		int[] h = new int[m];
		int th = 0;
		for (int i = 0; i < h.length; i++) {
			while (p[j].type == 0 && p[j].x == i) {
				th++;
				j++;
			}
			h[i] = th;
			while (j < 2 * n && p[j].x == i) {
				th--;
				j++;
			}
			if (j == 2 * n) {
				break;
			}
		}
		int[] dpUp = new int[m + 1];
		int[] maxUp = new int[m + 1];
		for (int i = 1; i < maxUp.length; i++) {
			dpUp[i] = Integer.MAX_VALUE;
		}
		for (int i = 0; i < h.length; i++) {
			int l = -1;
			int r = m;
			while (l + 1 < r) {
				int med = (l + r) / 2;
				if (dpUp[med] > h[i]) {
					r = med;
				} else {
					l = med;
				}
			}
			maxUp[i + 1] = maxUp[i];
			if (dpUp[r] == Integer.MAX_VALUE) {
				maxUp[i + 1]++;
			}
			dpUp[r] = h[i];
		}
		int[] dpDown = new int[m + 1];
		int[] maxDown = new int[m + 1];
		for (int i = 1; i < maxUp.length; i++) {
			dpDown[i] = Integer.MAX_VALUE;
		}
		for (int i = h.length - 1; i >= 0; i--) {
			int l = -1;
			int r = m;
			while (l + 1 < r) {
				int med = (l + r) / 2;
				if (dpDown[med] > h[i]) {
					r = med;
				} else {
					l = med;
				}
			}
			maxDown[h.length - i] = maxDown[h.length - 1 - i];
			if (dpDown[r] == Integer.MAX_VALUE) {
				maxDown[h.length - i]++;
			}
			dpDown[r] = h[i];
		}
		int ans = 0;
		for (int i = 0; i < maxDown.length; i++) {
			ans = Math.max(ans, maxUp[i] + maxDown[m - i]);
		}
		out.print(ans);
	}

	public void run() {
		try {
			if (systemIO) {
				in = new FastScanner(System.in);
				out = new PrintWriter(System.out);
			} else {
				in = new FastScanner(new File("segments.in"));
				out = new PrintWriter(new File("segments.out"));
			}
			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				return null;
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
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

	}

	// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
	public static void main(String[] arg) {
		new C().run();
	}
}