import java.util.*;
import java.io.*;

public class D {
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

	public static void recursion(int l, int r) {
		int m = (l + r) / 2;
		if (r - l > 2) {
			recursion(l, m);
			recursion(m, r);
		}
		double max1 = 0;
		double max2 = 0;
		for (int i = l; i < m; i++) {
			max1 = Math.max(max1, c[i]);
		}
		for (int i = m; i < r; i++) {
			max2 = Math.max(max2, c[i]);
		}
		double[] p1 = new double[p.length];
		for (int i = l; i < m; i++) {
			c[i] += max2;
			for (int j = m; j < r; j++) {
				c[i] += p[i] * p[j] * w[i][j] * (m - l);
//				System.out.println(i + " " + j + " " + p1[i] + " " + p[i] + " " + p[j] + " " + w[i][j] + " " + p[i] * p[j] * w[i][j]);
				p1[i] += p[i] * p[j] * w[i][j];
//				System.out.println(i + " " + j + " " + p1[i] + " " + p[i] + " " + p[j] + " " + w[i][j]);
			}
		}
		for (int i = m; i < r; i++) {
			c[i] += max1;
			for (int j = l; j < m; j++) {
				c[i] += p[i] * p[j] * w[i][j] * (m - l);
				p1[i] += p[i] * p[j] * w[i][j];
			}
		}
		for (int i = l; i < r; i++) {
			p[i] = p1[i];
		}
//		System.out.println(l + " " + r);
//		for (int i = 0; i < c.length; i++) {
//			System.out.print(c[i] + " ");
//		}
//		System.out.println();
//		for (int i = 0; i < p.length; i++) {
//			System.out.print(p[i] + " ");
//		}
//		System.out.println();
	}

	static double[] p;
	static double[][] w;
	static double[] c;

	public void solve() {
		int n = 1 << in.nextInt();
		p = new double[n];
		w = new double[n][n];
		c = new double[n];
		for (int i = 0; i < c.length; i++) {
			p[i] = 1.0;
		}
		for (int i = 0; i < w.length; i++) {
			for (int j = 0; j < w.length; j++) {
				w[i][j] = in.nextInt() / 100.0;
			}
		}
		recursion(0, n);
		double ans = 0;
		for (int i = 0; i < c.length; i++) {
			ans = Math.max(ans, c[i]);
		}
		out.print(ans);
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
		new D().run();
	}
}