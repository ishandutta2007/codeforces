import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;

public class B {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Point implements Comparable<Point> {
		int x;
		int y;
		int n;

		public Point(int x, int y, int n) {
			this.x = x;
			this.y = y;
			this.n = n;
		}

		@Override
		public int compareTo(Point o) {
			if (x != o.x) {
				return o.x - x;

			}
			return y - o.y;
		}

	}
	
	public int ans(Point a, Point b, Point c) {
		int[] x = {a.x, b.x, c.x};
		int[] y = {a.y, b.y, c.y};
		Arrays.sort(x);
		Arrays.sort(y);
		return 2 * (x[2] + y[2] - x[0] - y[0]);
	}

	public void solve() {
		int n = in.nextInt();
		Point[] p = new Point[n];
		int minx = Integer.MAX_VALUE;
		int maxx = Integer.MIN_VALUE;
		int miny = minx;
		int maxy = maxx;
		for (int i = 0; i < p.length; i++) {
			p[i] = new Point(in.nextInt(), in.nextInt(), i);
			minx = Math.min(minx, p[i].x);
			miny = Math.min(miny, p[i].y);
			maxx = Math.max(maxx, p[i].x);
			maxy = Math.max(maxy, p[i].y);
		}
		ArrayList<Point> list = new ArrayList<>();
		for (int i = 0; i < p.length; i++) {
			if (p[i].x == minx || p[i].x == maxx || p[i].y == miny || p[i].y == maxy) {
				list.add(p[i]);
			}
		}
		int ans = 0;
		Point[] s = new Point[list.size()];
		for (int i = 0; i < s.length; i++) {
			s[i] = list.get(i);
		}
		for (int i = 0; i < s.length; i++) {
			for (int j = i + 1; j < s.length; j++) {
				for (int k = 0; k < p.length; k++) {
					ans = Math.max(ans, ans(s[i], s[j], p[k]));
				}
			}
		}
		out.print(ans + " ");
		for (int i = 0; i < n - 3; i++) {
			out.print((maxx + maxy - minx - miny) * 2 + " ");
		}
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
		new B().run();
	}
}