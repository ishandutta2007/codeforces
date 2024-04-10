import java.util.*;
import java.io.*;

public class A {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public static void quickSort(int[] a, int from, int to) {
		if (to - from <= 1) {
			return;
		}
		int i = from;
		int j = to - 1;
		int x = a[from + (new Random()).nextInt(to - from)];
		while (i <= j) {
			while (a[i] < x) {
				i++;
			}
			while (a[j] > x) {
				j--;
			}
			if (i <= j) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
				i++;
				j--;
			}
		}
		quickSort(a, from, j + 1);
		quickSort(a, j + 1, to);
	}

	public class Point {
		int x;
		int y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public class Square {
		int minx;
		int miny;
		int maxx;
		int maxy;

		public Square(int minx, int miny, int maxx, int maxy) {
			this.minx = minx;
			this.miny = miny;
			this.maxx = maxx;
			this.maxy = maxy;
		}
	}

	public void solve() {
		Point[] p1 = new Point[4];
		Point[] p2 = new Point[4];
		for (int i = 0; i < p2.length; i++) {
			p1[i] = new Point(in.nextInt(), in.nextInt());
		}
		for (int i = 0; i < p2.length; i++) {
			p2[i] = new Point(in.nextInt(), in.nextInt());
		}
		int minx = Integer.MAX_VALUE;
		int miny = Integer.MAX_VALUE;
		int maxx = Integer.MIN_VALUE;
		int maxy = Integer.MIN_VALUE;
		for (int i = 0; i < p1.length; i++) {
			minx = Math.min(minx, p1[i].x);
			miny = Math.min(miny, p1[i].y);
			maxx = Math.max(maxx, p1[i].x);
			maxy = Math.max(maxy, p1[i].y);
		}
		Point p0 = new Point((minx + maxx) / 2, (miny + maxy) / 2);
		Square a = new Square(minx, miny, maxx, maxy);
		minx = Integer.MAX_VALUE;
		miny = Integer.MAX_VALUE;
		maxx = Integer.MIN_VALUE;
		maxy = Integer.MIN_VALUE;
		for (int i = 0; i < p2.length; i++) {
			minx = Math.min(minx, p2[i].x);
			miny = Math.min(miny, p2[i].y);
			maxx = Math.max(maxx, p2[i].x);
			maxy = Math.max(maxy, p2[i].y);
		}
		Point p = new Point((minx + maxx) / 2, (miny + maxy) / 2);
		Square b = new Square(minx, miny, maxx, maxy);
		for (int i = 0; i < p2.length; i++) {
			if (p2[i].x >= a.minx && p2[i].x <= a.maxx && p2[i].y >= a.miny && p2[i].y <= a.maxy) {
				out.println("Yes");
				return;
			}
		}
		if (p.x >= a.minx && p.x <= a.maxx && p.y >= a.miny && p.y <= a.maxy) {
			out.println("Yes");
			return;
		}
		for (int i = 0; i < p2.length; i++) {
			int f = p1[i].y - p1[i].x;
			int s = p1[i].x + p1[i].y;
			if (f >= b.miny - (b.minx + b.maxx) / 2 && f <= b.maxy - (b.minx + b.maxx) / 2
					&& s >= b.miny + (b.minx + b.maxx) / 2 && s <= b.maxy + (b.minx + b.maxx) / 2) {
				out.println("Yes");
				return;
			}
		}
		int f = p0.y - p0.x;
		int s = p0.x + p0.y;
		if (f >= b.miny - (b.minx + b.maxx) / 2 && f <= b.maxy - (b.minx + b.maxx) / 2
				&& s >= b.miny + (b.minx + b.maxx) / 2 && s <= b.maxy + (b.minx + b.maxx) / 2) {
			out.println("Yes");
			return;
		}
		out.println("No");
	}

	public void run() {

		try {
			if (systemIO) {
				in = new FastScanner(System.in);
				out = new PrintWriter(System.out);
			} else {
				in = new FastScanner(new File("input.txt"));
				out = new PrintWriter(new File("output.txt"));
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
	public static void main(String[] args) {
		new A().run();
	}
}