import java.util.*;
import java.io.*;

public class B {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public void quickSort(int[] a, int from, int to) {
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

	public class Pair {
		int x;
		int y;
		
		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
		
		public int intersection(Pair o) {
			if ((x == o.x && y == o.y) || (x == o.y && y == o.x)) {
				return 2;
			}
			if ((x == o.x) || (x == o.y) || (y == o.x) || (y == o.y)) {
				return 1;
			}
			return 0;
		}
	}
	
	public void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		Pair[] a = new Pair[n];
		Pair[] b = new Pair[m];
		for (int i = 0; i < a.length; i++) {
			a[i] = new Pair(in.nextInt() - 1, in.nextInt() - 1);
		}
		for (int i = 0; i < b.length; i++) {
			b[i] = new Pair(in.nextInt() - 1, in.nextInt() - 1);
		}
		boolean[] first = new boolean[9];
		boolean[] second = new boolean[9];
		for (int i = 0; i < a.length; i++) {
			boolean x = false;
			boolean y = false;
			for (int j = 0; j < b.length; j++) {
				if (a[i].intersection(b[j]) == 1) {
					if (a[i].x == b[j].x || a[i].x == b[j].y) {
						x = true;
					} else {
						y = true;
					}
				}
			}
			if (x == true && y == true) {
				out.println(-1);
				return;
			}
			if (x == true) {
				first[a[i].x] = true;
			}
			if (y == true) {
				first[a[i].y] = true;
			}
		}
		for (int i = 0; i < b.length; i++) {
			boolean x = false;
			boolean y = false;
			for (int j = 0; j < a.length; j++) {
				if (b[i].intersection(a[j]) == 1) {
					if (b[i].x == a[j].x || b[i].x == a[j].y) {
						x = true;
					} else {
						y = true;
					}
				}
			}
			if (x == true && y == true) {
				out.println(-1);
				return;
			}
			if (x == true) {
				second[b[i].x] = true;
			}
			if (y == true) {
				second[b[i].y] = true;
			}
		}
		int c = 0;
		for (int i = 0; i < second.length; i++) {
			if (first[i] && second[i]) {
				c++;
			}
		}
		if (c > 1) {
			out.println(0);
		} else {
			for (int i = 0; i < second.length; i++) {
				if (first[i] && second[i]) {
					out.println(i + 1);
				}
			}
		}
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
		new B().run();
	}
}