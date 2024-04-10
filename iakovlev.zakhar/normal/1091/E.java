import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;

public class E {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	long mod = 998244353;

	public class Fenvik {
		long[] x;

		public Fenvik(int n) {
			x = new long[n];
		}

		public int sum(int r) {
			int res = 0;
			for (; r >= 0; r = (r & (r + 1)) - 1) {
				res += x[r];
				res %= mod;
			}
			return res;
		}

		public int sum(int l, int r) {
			return sum(r) - sum(l - 1);
		}

		public void add(int i, long delta) {
			for (; i < x.length; i = (i | (i + 1))) {
				x[i] += delta;
				x[i] %= mod;
			}
		}
	}

	public class Pair implements Comparable<Pair> {
		long x;
		long y;
		long a;

		public Pair(int x, int y, long a) {
			this.x = x;
			this.y = y;
			this.a = a;
		}

		@Override
		public int compareTo(Pair o) {
			if (x > o.x) {
				return 1;
			}
			if (x < o.x) {
				return -1;
			}
			if (y < o.y) {
				return 1;
			}
			if (y > o.y) {
				return -1;
			}
			if (a < o.a) {
				return -1;
			}
			if (a > o.a) {
				return 1;
			}
			return 0;
		}
	}

//	public class Tree {
//		int pow;
//		int[][] sum;
//		int[][] delta;
//		boolean[] flag;
//		
//		public Tree(int[][] a) {
//			pow = 1;
//			while (pow < a.length) {
//				pow *= 2;
//			}
//			flag = new boolean[2 * pow];
//			sum = new int[2 * pow][24];
//			delta = new int[2 * pow][24];
//			for (int i = 0; i < a.length; i++) {
//				sum[pow + i] = a[i];
//			}
//			for (int i = pow - 1; i > 0; i--) {
//				sum[i] = f(sum[2 * i], sum[2 * i + 1]);
//			}
//		}
//		
//		public int[] get(int v, int tl, int tr, int l, int r) {
//			push(v, tl, tr);
//			if (l > r) {
//				return new int[24];
//			}
//			if (l == tl && r == tr) {
//				return sum[v];
//			}
//			int tm = (tl + tr) / 2;
//			return f(get(2 * v, tl, tm, l, Math.min(r, tm)), get(2 * v + 1, tm + 1, tr, Math.max(l, tm + 1), r));
//		}
//		
//		public void set(int v, int tl, int tr, int l, int r, int[] x) {
//			push(v, tl, tr);
//			if (l > tr || r < tl) {
//				return;
//			}
//			if (l <= tl && r >= tr) {
//				delta[v] = x.clone();
//				flag[v] = true;
//				push(v, tl, tr);
//				return;
//			}
//			int tm = (tl + tr) / 2;
//			set(2 * v, tl, tm, l, r, x);
//			set(2 * v + 1, tm + 1, tr, l, r, x);
//			sum[v] = f(sum[2 * v], sum[2 * v + 1]);
//		}
//		
//		public void push(int v, int tl, int tr) {
//			if (flag[v]) {
//				if (v < pow) {
//					flag[2 * v] = true;
//					flag[2 * v + 1] = true;
//					delta[2 * v] = delta[v].clone();
//					delta[2 * v + 1] = delta[v].clone();
//				}
//				flag[v] = false;
//				for (int i = 0; i < 24; i++) {
//					sum[v][i] = delta[v][i] * (tr - tl + 1);
//				}
//			}
//		}
//		
//		public int[] f(int[] a, int[] b) {
//			int[] ans = new int[24];
//			for (int i = 0; i < ans.length; i++) {
//				ans[i] = a[i] + b[i];
//			}
//			return ans;
//		}
//	}

	public void solve() {
		int n = in.nextInt();
		long[] a = new long[n];
		Random random = new Random();
		for (int i = 0; i < a.length; i++) {
			a[i] = in.nextLong();
			if (i > 0) {
				int x = random.nextInt(i);
				a[i] += a[x];
				a[x] = a[i] - a[x];
				a[i] = a[i] - a[x];
			}
		}
		Arrays.sort(a);
		long[] b = new long[n];
		for (int i = 0; i < a.length; i++) {
			b[i] = a[n - 1 - i];
		}
		long[] suml = new long[n + 1];
		for (int i = 1; i < suml.length; i++) {
			suml[i] = suml[i - 1] + b[i - 1];
		}
		long[] sr = new long[n + 1];
		sr[n] = b[n - 1];
		for (int i = n - 1; i >= 0; i--) {
			sr[i] = sr[i + 1] + b[i];
		}
		int r = n - 1;
		long[] sumr = new long[n + 1];
		for (int i = 0; i <= n; i++) {
			r = Math.max(i - 1, r);
			while (r + 1 > i && b[r] < i) {
				r--;
			}
			sumr[i] = suml[n] - suml[r + 1] + (r + 1L - i) * i;
		}
		r = n - 1;
		long[] sumr1 = new long[n + 1];
		for (int i = 0; i <= n; i++) {
			r = Math.max(i - 1, r);
			while (r + 1 > i && b[r] < i + 1) {
				r--;
			}
			sumr1[i] = suml[n] - suml[r + 1] + (r + 1L - i) * (i + 1);
		}
//		for (int i = 0; i < sumr.length; i++) {
//			System.out.println(sumr1[i]);
//		}
		long mod = 0;
		for (int i = 0; i < b.length; i++) {
			mod += b[i];
			mod %= 2;
		}
		int[] sum = new int[n + 2];
		for (int i = 0; i <= n; i++) {
			long left = suml[i];
			long right = i * (i - 1L) + sumr[i];
			long l1 = Math.max(0, left - right);
			long r1 = n;
			if (i != 0) {
				r1 = b[i - 1];
			}
			if (l1 <= r1) {
				sum[(int) l1]++;
				sum[(int) r1 + 1]--;
			}
			long l2 = 0;
			long r2 = 0;
			if (i != 0) {
				right = i * (i - 1L) + sumr1[i - 1];
				l2 = b[i - 1] + 1;
				r2 = right - suml[i - 1];
				r2 = Math.min(r2, n);
				if (l2 <= r2) {
					sum[(int) l2]++;
					sum[(int) r2 + 1]--;
				}
			}
		}
		int[] x = new int[n + 2];
		x[0] = sum[0];
		for (int i = 1; i < x.length; i++) {
			x[i] = x[i - 1] + sum[i];
		}
		ArrayList<Integer> ans = new ArrayList<>();
		for (int i = 0; i < x.length; i++) {
			if (x[i] >= n + 1 && i % 2 == mod) {
				ans.add(i);
			}
		}
		if (ans.size() == 0) {
			out.println(-1);
		} else {
			for (int i : ans) {
				out.print(i + " ");
			}
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
		new E().run();
	}
}