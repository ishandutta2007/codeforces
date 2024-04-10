import java.util.*;

import javax.swing.Painter;

import java.io.*;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;
	
	public static class Point implements Comparable<Point> {
		int t;
		int type;
		public Point(int t, int type) {
			super();
			this.t = t;
			this.type = type;
		}
		@Override
		public int compareTo(Point o) {
			// TODO Auto-generated method stub
			if (t != o.t) {
				return t - o.t;
			}
			return type - o.type;
		}
		
	}
	
	public static void quickSort(long[] a, int from, int to) {
		if (to - from <= 1) {
			return;
		}
		int i = from;
		int j = to - 1;
		long x = a[from + (new Random()).nextInt(to - from)];
		while (i <= j) {
			while (a[i] < x) {
				i++;
			}
			while (a[j] > x) {
				j--;
			}
			if (i <= j) {
				long t = a[i];
				a[i] = a[j];
				a[j] = t;
				i++;
				j--;
			}
		}
		quickSort(a, from, j + 1);
		quickSort(a, j + 1, to);
	}
	
	public void solve() throws IOException {
		int n = in.nextInt();
		ArrayList<Point> a = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			a.add(new Point(in.nextInt(), 0));
			a.add(new Point(in.nextInt(), 1));
		}
		int th = 0;
		Collections.sort(a);
		for (Point p : a) {
			if (p.type == 0) {
				th++;
			} else {
				th--;
			}
			if (th > 2) {
				out.println("NO");
				return;
			}
		}
		out.print("YES");
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