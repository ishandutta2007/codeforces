import java.util.*;

import java.io.*;
import java.math.BigInteger;

public class D {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Pair implements Comparable<Pair> {
		long x;
		long y;

		public Pair(long x, long y) {
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

	public class Fenvik {
		int[] sum;

		public Fenvik(int n) {
			sum = new int[n];
		}

		public void add(int x, int d) {
			for (int i = x; i < sum.length; i = (i | (i + 1))) {
				sum[i] += d;
			}
		}

		public int sum(int r) {
			int ans = 0;
			for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
				ans += sum[i];
			}
			return ans;
		}

		public int sum(int l, int r) {
			if (l > r) {
				return 0;
			}
			return sum(r) - sum(l - 1);
		}
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

	public void solve() {
		int n = in.nextInt();
		int q = in.nextInt();
		int[] a = new int[n];
		String s = in.next();
		for (int i = 0; i < a.length; i++) {
			if (s.charAt(i) == 'R') {
				a[i] = 0;
			} else if (s.charAt(i) == 'P') {
				a[i] = 1;
			} else if (s.charAt(i) == 'S') {
				a[i] = 2;
			}
		}
		TreeSet<Integer>[] set = new TreeSet[3];
		Fenvik[] f = new Fenvik[3];
		for (int i = 0; i < set.length; i++) {
			set[i] = new TreeSet<>();
			f[i] = new Fenvik(n);
		}
		for (int i = 0; i < a.length; i++) {
			set[a[i]].add(i);
			f[a[i]].add(i, 1);
		}
		int ans = n;
		Integer[] l = new Integer[3];
		Integer[] r = new Integer[3];
		for (int i = 0; i < r.length; i++) {
			if (set[i].isEmpty()) {
				l[i] = null;
				r[i] = null;
			} else {
				l[i] = set[i].first();
				r[i] = set[i].last();
			}
		}
		for (int i = 0; i < l.length; i++) {
			if (l[i] == null) {
				l[i] = n;
			}
			if (r[i] == null) {
				r[i] = -1;
			}
		}
		for (int i = 0; i < r.length; i++) {
			if (!set[(i + 1) % 3].isEmpty()) {
				if (!set[(i + 2) % 3].isEmpty()) {
					ans -= f[i].sum(l[(i + 1) % 3] + 1, l[(i + 2) % 3] - 1);
					ans -= f[i].sum(r[(i + 2) % 3] + 1, r[(i + 1) % 3] - 1);
				} else {
					ans -= f[i].sum(0, n - 1);
				}
			}
		}
		out.println(ans);
		for (; q > 0; q--) {
			int x = in.nextInt() - 1;
			s = in.next();
			int type = 0;
			if (s.charAt(0) == 'R') {
				type = 0;
			} else if (s.charAt(0) == 'P') {
				type = 1;
			} else if (s.charAt(0) == 'S') {
				type = 2;
			}
			set[a[x]].remove(x);
			f[a[x]].add(x, -1);
			set[type].add(x);
			f[type].add(x, 1);
			a[x] = type;
			ans = n;
			l = new Integer[3];
			r = new Integer[3];
			for (int i = 0; i < r.length; i++) {
				if (set[i].isEmpty()) {
					l[i] = null;
					r[i] = null;
				} else {
					l[i] = set[i].first();
					r[i] = set[i].last();
				}
			}
			for (int i = 0; i < l.length; i++) {
				if (l[i] == null) {
					l[i] = n;
				}
				if (r[i] == null) {
					r[i] = -1;
				}
			}
//			System.out.println();
//			System.out.println(q);
//			System.out.println(set[0].isEmpty() + " " + set[1].isEmpty() + " " + set[2].isEmpty());
//			for (int j = 0; j < a.length; j++) {
//				System.out.println(a[j]);
//			}
			for (int i = 0; i < r.length; i++) {
				if (!set[(i + 1) % 3].isEmpty()) {
					if (!set[(i + 2) % 3].isEmpty()) {
						ans -= f[i].sum(l[(i + 1) % 3] + 1, l[(i + 2) % 3] - 1);
						ans -= f[i].sum(r[(i + 2) % 3] + 1, r[(i + 1) % 3] - 1);
					} else {
						ans -= f[i].sum(0, n - 1);
					}
				}
			}
			out.println(ans);
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
		new D().run();
	}
}