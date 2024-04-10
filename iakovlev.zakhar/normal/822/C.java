import java.util.*;

import javax.swing.Painter;

import java.io.*;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;
	
	public static class Pair implements Comparable<Pair> {
		int l;
		int r;
		int x;
		int cost;
		
		public Pair(int x, int y, int cost) {
			super();
			this.l = x;
			this.r = y;
			this.x = r - l + 1;
			this.cost = cost;
		}
		@Override
		public int compareTo(Pair o) {
			return r - o.r;
		}
		
	}
	
	public static class Pair1 implements Comparable<Pair1> {
		int l;
		int r;
		int x;
		int cost;
		
		public Pair1(int x, int y, int cost) {
			super();
			this.l = x;
			this.r = y;
			this.x = r - l + 1;
			this.cost = cost;
		}
		@Override
		public int compareTo(Pair1 o) {
			return l - o.l;
		}
		
	}
	
	public static void quickSort(Pair[] a, int from, int to) {
		if (to - from <= 1) {
			return;
		}
		int i = from;
		int j = to - 1;
		int c = from + (new Random()).nextInt(to - from);
		Pair x = new Pair(a[c].l, a[c].r, a[c].cost);
		while (i <= j) {
			while (a[i].compareTo(x) < 0) {
				i++;
			}
			while (a[j].compareTo(x) > 0) {
				j--;
			}
			if (i <= j) {
				Pair t = a[i];
				a[i] = a[j];
				a[j] = t;
				i++;
				j--;
			}
		}
		quickSort(a, from, j + 1);
		quickSort(a, j + 1, to);
	}
	
	public static void quickSort1(Pair1[] a, int from, int to) {
		if (to - from <= 1) {
			return;
		}
		int i = from;
		int j = to - 1;
		int c = from + (new Random()).nextInt(to - from);
		Pair1 x = new Pair1(a[c].l, a[c].r, a[c].cost);
		while (i <= j) {
			while (a[i].compareTo(x) < 0) {
				i++;
			}
			while (a[j].compareTo(x) > 0) {
				j--;
			}
			if (i <= j) {
				Pair1 t = a[i];
				a[i] = a[j];
				a[j] = t;
				i++;
				j--;
			}
		}
		quickSort1(a, from, j + 1);
		quickSort1(a, j + 1, to);
	}
	
	public void solve() throws IOException {
		int n = in.nextInt();
		int x = in.nextInt();
		Pair[] p = new Pair[n];
		for (int i = 0; i < p.length; i++) {
			p[i] = new Pair(in.nextInt(), in.nextInt(), in.nextInt());
		}
		quickSort(p, 0, n);
		HashMap<Integer, Integer> h = new HashMap<>();
		Pair1[] p1 = new Pair1[n];
		for (int i = 0; i < p1.length; i++) {
			p1[i] = new Pair1(p[i].l, p[i].r, p[i].cost);
		}
		quickSort1(p1, 0, n);
		int y = 0;
		int y1 = 0;
		int ans = Integer.MAX_VALUE;
		for (int i = 0; i <= 200001; i++) {
			while (y1 < n && p1[y1].l == i) {
				if (h.containsKey(x - p1[y1].x)) {
					ans = Math.min(ans, h.get(x - p1[y1].x) + p1[y1].cost);
				}
				y1++;
			}
			while (y < n && p[y].r == i) {
				if (!h.containsKey(p[y].x)) {
					h.put(p[y].x, p[y].cost);
				} else {
					h.put(p[y].x, Math.min(p[y].cost, h.get(p[y].x)));
				}
				y++;
			}
		}
		if (ans == Integer.MAX_VALUE) {
			System.out.println(-1);
		} else {
			System.out.println(ans);
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