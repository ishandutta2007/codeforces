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

	int time = 0;
	
	public void solve() {
		f : for (int qwerty = in.nextInt(); qwerty > 0; qwerty--) {
			int n = in.nextInt();
			int k = in.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = in.nextInt() - 1;
			}
			int number = k + (n - k + 1) / 2;
			int[] b = new int[n];
			for (int i = 0; i < a.length; i++) {
				b[a[i]]++;
			}
			int[] prefsum = new int[n + 1];
			for (int i = 0; i < b.length; i++) {
				prefsum[i + 1] = prefsum[i] + b[i];
			}
			int x = 0;
			int y = n;
			for (int i = 0; i < n; i++) {
				if (prefsum[n] - prefsum[i] < number) {
					break;
				}
				int l = i;
				int r = n;
				while (l + 1 < r) {
					int m = (l + r) >> 1;
					if (prefsum[m] - prefsum[i] >= number) {
						r = m;
					} else {
						l = m;
					}
				}
				if (r - i < y - x) {
					x = i;
					y = r;
				}
			}
			out.println(x + 1 + " " + y);
			int i = 0;
			for (int j = 0; j < k - 1; j++) {
				int bal = 0;
				int left = i;
				while (bal <= 0) {
					if (x <= a[i] && a[i] < y) {
						bal++;
					} else {
						bal--;
					}
					i++;
				}
				out.println(left + 1 + " " + i);
			}
			out.println(i + 1 + " " + n);
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