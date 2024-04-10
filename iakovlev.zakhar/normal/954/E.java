import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class E {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public static class Pair implements Comparable<Pair> {
		int a;
		int t;
		
		public Pair(int a, int t) {
			this.a = a;
			this.t = t;
		}

		@Override
		public int compareTo(Pair o) {
			return t - o.t;
		}
	}
	
	public void solve() {
		int n = in.nextInt();
		double temp = in.nextDouble();
		double[] a = new double[n];
		double[] t = new double[n];
		double sum = 0;
		Pair[] p = new Pair[n];
		for (int i = 0; i < t.length; i++) {
			p[i] = new Pair(in.nextInt(), 0);
		}
		for (int i = 0; i < p.length; i++) {
			p[i].t = in.nextInt();
		}
		Random random = new Random();
		for (int i = 0; i < p.length; i++) {
			int j = random.nextInt(i + 1);
			Pair s = p[i];
			p[i] = p[j];
			p[j] = s;
		}
		Arrays.sort(p);
		if (temp < p[0].t || temp > p[n - 1].t) {
			out.println(0);
			return;
		}
		for (int i = 0; i < t.length; i++) {
			a[i] = p[i].a;
			sum += a[i];
			t[i] = p[i].t;
		}
		double l = 0;
		double r = sum;
		for (int i = 0; i < 100; i++) {
			double m = (l + r) / 2;
			double x = m;
			double q = 0;
			for (int j = 0; j < t.length; j++) {
				if (x < 1e-14) {
					break;
				}
				if (a[j] - 1e-14 * a[j] < x) {
					q += a[j] * t[j];
					x -= a[j];
				} else {
					q += x * t[j];
					x = 0;
				}
			}
			if (q - 1e-14 * q < m * temp) {
				l = m;
			} else {
				r = m;
			}
		}
		double ans1 = l;
		l = 0;
		r = sum;
		for (int i = 0; i < 100; i++) {
			double m = (l + r) / 2;
			double x = m;
			double q = 0;
			for (int j = t.length - 1; j >= 0; j--) {
				if (x < 1e-14) {
					break;
				}
				if (a[j] - 1e-14 * a[j] < x) {
					q += a[j] * t[j];
					x -= a[j];
				} else {
					q += x * t[j];
					x = 0;
				}
			}
			if (q > m * temp * (1 - 1e-14)) {
				l = m;
			} else {
				r = m;
			}
		}
		double ans2 = l;
		out.println(Math.min(ans1, ans2));
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