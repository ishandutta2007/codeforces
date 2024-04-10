import java.util.*;
import java.awt.Point;
import java.io.*;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;
	
	public static class Point implements Comparable<Point> {
		int x;
		int type;
		public Point(int x, int type) {
			super();
			this.x = x;
			this.type = type;
		}
		@Override
		public int compareTo(Point o) {
			// TODO Auto-generated method stub
			if (x != o.x) {
				return x - o.x;
			}
			return type - o.type;
		}
		
	}
	
	public void solve() throws IOException {
		int n = in.nextInt();
		int[] a = new int[n];
		int[] type = new int[n];
		int[] sum = new int[n + 1];
		for (int i = 0; i < a.length; i++) {
			a[i] = in.nextInt();
			type[i] = in.nextInt();
			sum[i + 1] = sum[i] + a[i];
		}
		Point[] p = new Point[2 * n];
		if (a.length == 1) {
			if (type[0] == 1) {
				p[0] = new Point(1900, 0);
				p[1] = new Point(Integer.MAX_VALUE / 2, 1);
			} else {
				p[0] = new Point(Integer.MIN_VALUE / 2, 0);
				p[1] = new Point(1899, 1);
			}
		} else {
			for (int i = 0; i < a.length - 1; i++) {
				if (type[i] == 1) {
					int min = 1900 - sum[i];
					int max = Integer.MAX_VALUE / 2;
					if (type[i + 1] == 1) {
						min = Math.max(min, 1900 - a[i] - sum[i]);
					} else {
						max = 1899 - a[i] - sum[i];
					}
					p[2 * i] = new Point(min, 0);
					p[2 * i + 1] = new Point(max, 1);
				} else {
					int min = Integer.MIN_VALUE / 2;
					int max = 1899 - sum[i];
					if (type[i + 1] == 1) {
						min = 1900 - a[i] - sum[i];
					} else {
						max = Math.min(1899 - a[i] - sum[i], max);
					}
					p[2 * i] = new Point(min, 0);
					p[2 * i + 1] = new Point(max, 1);
				}
//				System.out.println(p[2 * i].x + " " + p[2 * i + 1].x);
			}
			if (type[n - 1] == 1) {
				int min = 1900 - sum[n - 1];
				int max = Integer.MAX_VALUE / 2;
				p[2 * n - 2] = new Point(min, 0);
				p[2 * n - 1] = new Point(max, 1);
			} else {
				int min = Integer.MIN_VALUE / 2;
				int max = 1899 - sum[n - 1];
				p[2 * n - 2] = new Point(min, 0);
				p[2 * n - 1] = new Point(max, 1);
			}
//			System.out.println(p[2 * n - 2].x + " " +p[2 * n - 1].x);
		}
		Arrays.sort(p);
//		for (int i = 0; i < p.length; i++) {
//			System.out.println(p[i].x);
//		}
		int th = 0;
		for (int i = 0; i < p.length; i++) {
			if (p[i].type == 0) {
				th++;
			} else {
				if (th == n) {
					if (p[i].x == Integer.MAX_VALUE / 2) {
						System.out.println("Infinity");
					} else {
						System.out.println(p[i].x + sum[n]);
					}
				} else {
					System.out.println("Impossible");
				}
				return;
			}
		}
	}

	public void run() throws IOException {
		if (systemIO) {
			in = new FastScanner(System.in);
			out = new PrintWriter(System.out);
		} else {
			in = new FastScanner(new File("input.txt"));
			out = new PrintWriter(new File("output.txt"));
		}
		solve();

		out.close();
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
	public static void main(String[] arg) throws IOException {
		new C().run();
	}
}