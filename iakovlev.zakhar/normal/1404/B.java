import java.util.*;

import java.io.*;

public class B {
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

	public long gcd(long x, long y) {
		if (y == 0) {
			return x;
		}
		if (x == 0) {
			return y;
		}
		return gcd(y, x % y);
	}

	public boolean prime(long x) {
		for (int i = 2; i * i <= x; i++) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	}

	public long pow(long x, long p) {
		if (p == 0) {
			return 1;
		}
		long t = pow(x, p / 2);
		t *= t;
		t %= mod;
		if (p % 2 == 1) {
			t *= x;
			t %= mod;
		}
		return t;
	}

	public class Fenvik {
		long[] sum;

		public Fenvik(int n) {
			sum = new long[n];
		}

		public void add(int x, long d) {
			for (int i = x; i < sum.length; i = (i | (i + 1))) {
				sum[i] += d;
			}
		}

		public long sum(int r) {
			long ans = 0;
			for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
				ans += sum[i];
			}
			return ans;
		}

		public long sum(int l, int r) {
			if (l > r) {
				return 0;
			}
			return sum(r) - sum(l - 1);
		}
	}

	public class Pair implements Comparable<Pair> {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Pair o) {
			if (x > o.x) {
				return 1;
			}
			if (x < o.x) {
				return -1;
			}
			if (y > o.y) {
				return 1;
			}
			if (y < o.y) {
				return -1;
			}
			return 0;
		}
	}

	long mod = 1000000007;

	public class Vector implements Comparable<Vector> {
		int x;
		int y;

		public Vector(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public String toString() {
			return x + " " + y;
		}

		public int quater() {
			if (x > 0 && y >= 0) {
				return 1;
			}
			if (y > 0 && x <= 0) {
				return 2;
			}
			if (y <= 0 && x < 0) {
				return 3;
			}
			return 4;
		}

		@Override
		public int compareTo(Vector o) {
			if (quater() != o.quater()) {
				return quater() - o.quater();
			}
			return -dp(this, o);
		}
	}

	public int dp(Vector a, Vector b) {
		return a.x * b.y - a.y * b.x;
	}

	public double[] leftAdd(double[] auxil, double[] input) {
		double[] ans = new double[auxil.length + input.length];
		for (int i = 0; i < auxil.length; i++) {
			ans[i] = auxil[i];
		}
		for (int i = 0; i < input.length; i++) {
			ans[i + auxil.length] = input[i];
		}
		return ans;
	}

	public double[] tensorProduct(double[] auxil, double[] input) {
		double[] ans = new double[auxil.length * input.length];
		for (int i = 0; i < auxil.length; i++) {
			for (int j = 0; j < input.length; j++) {
				ans[i * input.length + j] = auxil[i] * input[j];
			}
		}
		return ans;
	}

	public double[] tensorProductSquare(double[] auxil, double[] input) {
		double[] ans = new double[auxil.length * input.length * input.length];
		for (int i = 0; i < auxil.length; i++) {
			for (int j = 0; j < input.length; j++) {
				for (int k = 0; k < input.length; k++) {
					ans[i * input.length * input.length + j * input.length + k] = auxil[i] * input[j] * input[k];
				}
			}
		}
		return ans;
	}

	public double[] halfTensor(double[] auxil, double[] input) {
		int halfLa = auxil.length / 2;
		int halfLi = input.length / 2;
		double[] left = new double[halfLa + halfLi];
		for (int i = 0; i < halfLa; i++) {
			left[i] = auxil[i];
		}
		for (int i = 0; i < halfLi; i++) {
			left[halfLa + i] = input[i];
		}
		double[] right = new double[auxil.length + input.length - halfLa - halfLi];
		for (int i = halfLa; i < auxil.length; i++) {
			right[i - halfLa] = auxil[i];
		}
		for (int i = halfLi; i < input.length; i++) {
			right[auxil.length - halfLa + i - halfLi] = input[i];
		}
		auxil = left;
		input = right;
		return tensorProduct(auxil, input);
	}

	public double[] resize(double[] input) {
		int pow = 1;
		while (pow < input.length) {
			pow *= 2;
		}
		double[] ans = new double[pow];
		for (int i = 0; i < input.length; i++) {
			ans[i] = input[i];
		}
		for (int i = input.length; i < ans.length; i++) {
			ans[i] = 0;
		}
		return ans;
	}

	public void normalize(double[] input) {
		double norm = 0;
		for (int i = 0; i < input.length; i++) {
			norm += input[i] * input[i];
		}
		norm = Math.sqrt(norm);
		for (int i = 0; i < input.length; i++) {
			input[i] /= norm;
		}
	}

	public double[] transformation(int mode, double[] auxil, double[] input, boolean norm) {
		if (mode == 1) {
			input = leftAdd(auxil, input);
		} else if (mode == 2) {
			input = tensorProduct(auxil, input);
		} else if (mode == 3) {
			input = tensorProductSquare(auxil, input);
		} else if (mode == 4) {
			input = halfTensor(auxil, input);
		}
		input = resize(input);
		if (norm) {
			normalize(input);
		}
		return input;
	}

	public class Edge implements Comparable<Edge> {
		int to;
		int w;

		public Edge(int to, int w) {
			this.to = to;
			this.w = w;
		}

		@Override
		public int compareTo(Edge o) {
			return w - o.w;
		}
	}

	public int[][] readGraph(int n, int m) {
		int[][] to = new int[n][];
		int[] sz = new int[n];
		int[] x = new int[m];
		int[] y = new int[m];
		for (int i = 0; i < m; i++) {
			x[i] = in.nextInt() - 1;
			y[i] = in.nextInt() - 1;
			sz[x[i]]++;
			sz[y[i]]++;
		}
		for (int i = 0; i < to.length; i++) {
			to[i] = new int[sz[i]];
			sz[i] = 0;
		}
		for (int i = 0; i < x.length; i++) {
			to[x[i]][sz[x[i]]++] = y[i];
			to[y[i]][sz[y[i]]++] = x[i];
		}
		return to;
	}
	
	public void game() {
		int n = in.nextInt();
		int a = in.nextInt() - 1;
		int b = in.nextInt() - 1;
		int da = in.nextInt();
		int db = in.nextInt();
		int[][] to = readGraph(n, n - 1);
		if (db <= 2 * da) {
			out.println("Alice");
			return;
		}
		int[] lenb = new int[n];
		for (int i = 0; i < lenb.length; i++) {
			lenb[i] = -1;
		}
		lenb[b] = 0;
		Queue<Integer> q = new ArrayDeque<>();
		q.add(b);
		while (!q.isEmpty()) {
			int v = q.poll();
			for (int x : to[v]) {
				if (lenb[x] < 0) {
					lenb[x] = lenb[v] + 1;
					q.add(x);
				}
			}
		}
		int[] lena = new int[n];
		for (int i = 0; i < lena.length; i++) {
			lena[i] = -1;
		}
		lena[a] = 0;
		q.add(a);
		while (!q.isEmpty()) {
			int v = q.poll();
			for (int x : to[v]) {
				if (lena[x] < 0) {
					lena[x] = lena[v] + 1;
					q.add(x);
				}
			}
		}
		if (lena[b] <= da) {
			out.println("Alice");
			return;
		}
		int x = b;
		int max = lena[b];
		for (int i = 0; i < lenb.length; i++) {
			if (lenb[i] <= db && lena[i] > max) {
				max = lena[i];
				x = i;
			}
		}
		if (max > 2 * da) {
			out.println("Bob");
			return;
		}
		int[] lenx = new int[n];
		for (int i = 0; i < lenx.length; i++) {
			lenx[i] = -1;
		}
		lenx[x] = 0;
		q.add(x);
		while (!q.isEmpty()) {
			int v = q.poll();
			for (int y : to[v]) {
				if (lenx[y] < 0 && lenb[y] <= db) {
					lenx[y] = lenx[v] + 1;
					q.add(y);
				}
			}
		}
		int mx = 0;
		for (int i = 0; i < lenx.length; i++) {
			if (lenx[i] > mx) {
				mx = lenx[i];
			}
		}
		if (mx > 2 * da) {
			out.println("Bob");
		} else {
			out.println("Alice");
		}
	}
	
	public void solve() {
		for (int qwerty = in.nextInt(); qwerty > 0; qwerty--) {
			game();
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
	public static void main(String[] arg) {
		new B().run();
	}
}