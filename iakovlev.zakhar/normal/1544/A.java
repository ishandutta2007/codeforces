import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class D {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;
	
	public class Tree {
		int pow = 1 << 19;
		int[] gcd = new int[2 * pow];
		
		public Tree(int[] a) {
			for (int i = 0; i < a.length; i++) {
				gcd[pow + i] = a[i];
			}
			for (int i = pow - 1; i > 0; i--) {
				update(i);
			}
		}
		
		public void update(int v) {
			gcd[v] = gcd(gcd[2 * v], gcd[2 * v + 1]);
		}
		
		public void set(int to, int x) {
			set(1, 0, pow - 1, to, x);
		}
		
		private void set(int v, int l, int r, int to, int x) {
			if (v >= pow) {
				gcd[v] = x;
			} else {
				int m = (l + r) / 2;
				if (to <= m) {
					set(2 * v, l, m, to, x);
				} else {
					set(2 * v + 1, m + 1, r, to, x);
				}
				update(v);
			}
		}
		
		public boolean get(int l, int r, int x) {
			int y = get(1, 0, 0, pow - 1, l, r, x);
			return y < 2;
		}
		
		private int get(int v, int n, int l, int r, int left, int right, int x) {
			if (r < left || l > right) {
				return n;
			}
			if (l >= left && r <= right) {
				if (gcd[v] % x == 0) {
					return n;
				}
				if (v >= pow) {
					n++;
					return n;
				}
			}
			int m = (l + r) / 2;
			n = get(2 * v, n, l, m, left, right, x);
			if (n > 1) {
				return n;
			}
			n = get(2 * v + 1, n, m + 1, r, left, right, x);
			return n;
		}
	}
	
//	public boolean share(int a, int b) {
//		return a < 0 || a % b == 0; 
//	}
	
	public int gcd(int a, int b) {
//		if (a < 0 || b < 0) {
//			return -1;
//		}
		if (a < b) {
			a = a + b;
			b = a - b;
			a = a - b;
		}
		if (b == 0) {
			return a;
		}
		return gcd(a % b, b);
	}

	public void solve() {
		for (int qwerty = in.nextInt(); qwerty > 0; qwerty--) {
			String s = in.next();
			int ans = 0;
			for (int i = 0; i < s.length(); i++) {
				ans = Math.max(ans, s.charAt(i) - '0');
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
		new D().run();
	}
}