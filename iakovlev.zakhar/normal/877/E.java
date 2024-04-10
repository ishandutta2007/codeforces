import java.util.*;
import java.io.*;

public class E {
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

	class SegmentTree {
		int[] tree;
		boolean[] reverse;
		int power;
		private int ideal = 0;

		public SegmentTree(int[] a) {
			power = 1;
			while (power < a.length) {
				power *= 2;
			}
			tree = new int[2 * power];
			reverse = new boolean[2 * power];
			for (int i = 0; i < a.length; i++) {
				tree[i + power] = a[i];
			}
			for (int i = power + a.length; i < tree.length; i++) {
				tree[i] = ideal;
			}
			for (int i = power - 1; i > 0; i--) {
				tree[i] = function(tree[2 * i], tree[2 * i + 1]);
			}
		}

		public void update(int v, int a, int b, int l, int r) {
			push(v, a, b);
			if (b < l || r < a) {
				return;
			}
			if (l <= a && b <= r) {
				reverse[v] = !reverse[v];
				push(v, a, b);
				return;
			}
			int m = (a + b) / 2;
			update(2 * v, a, m, l, r);
			update(2 * v + 1, m + 1, b, l, r);
			tree[v] = function(tree[2 * v], tree[2 * v + 1]);
		}

		public int get(int v, int a, int b, int l, int r) {
//			System.out.println(v + " " + a + " " + b + " " + l + " " + r);
			push(v, a, b);
			if (b < l || r < a) {
				return 0;
			}
			if (l <= a && b <= r) {
				return tree[v];
			}
			int m = (a + b) / 2;
			return function(get(2 * v, a, m, l, r), get(2 * v + 1, m + 1, b, l, r));
		}

		public void push(int v, int a, int b) {
			if (!reverse[v]) {
				return;
			}
			if (v < power) {
				reverse[2 * v] ^= reverse[v];
				reverse[2 * v + 1] ^= reverse[v];
			}
//			System.out.println(v + " " + a + " " + b + " " + reverse[v] + " " + tree[v]);
			if (reverse[v]) {
				tree[v] = (b - a + 1 - tree[v]);
			}
			reverse[v] = false;
		}

		public int function(int a, int b) {
			return a + b;
		}
	}
	
	public int dfs(int v) {
		time[v] = th;
		max[v] = th;
		th++;
		for (int i : ch[v]) {
			if (i != p[v]) {
				max[v] = Math.max(max[v], dfs(i));
			}
		}
		return max[v];
	}

	ArrayList<Integer>[] ch;
	SegmentTree tree;
	int[] time;
	int[] max;
	int[] p;
	int th = 0;

	public void solve() {
		int n = in.nextInt();
		p = new int[n];
		int[] light = new int[n];
		time = new int[n];
		max = new int[n];
		ch = new ArrayList[n];
		for (int i = 0; i < ch.length; i++) {
			ch[i] = new ArrayList<>();
		}
		for (int i = 1; i < p.length; i++) {
			p[i] = in.nextInt() - 1;
			ch[p[i]].add(i);
		}
		dfs(0);
		for (int i = 0; i < light.length; i++) {
			light[time[i]] = in.nextInt();
		}
		tree = new SegmentTree(light);
//		for (int i = 0; i < time.length; i++) {
//			System.out.println(time[i] + " " + max[i]);
//		}
//		System.out.println();
//		System.out.println();
//		System.out.println();
//		System.out.println();
//		System.out.println();
//				for (int i = 0; i < tree.tree.length; i++) {
//					System.out.println(tree.tree[i] + " " + tree.reverse[i] + " " /*+ tree.get(1, 0, tree.power - 1, 0, i)*/);
//				}
		int q = in.nextInt();
		for (int u = 0; u < q; u++) {
			if (in.next().charAt(0) == 'g') {
				int x = in.nextInt() - 1;
				out.println(tree.get(1, 0, tree.power - 1, time[x], max[x]));
			} else {
				int x = in.nextInt() - 1;
				tree.update(1, 0, tree.power - 1, time[x], max[x]);
//				System.out.println(tree.get(1, 0, tree.power - 1, 0, 0));
//				System.out.println(tree.get(1, 0, tree.power - 1, 0, 0));
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
		new E().run();
	}
}