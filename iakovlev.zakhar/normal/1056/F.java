import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class F {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Pair implements Comparable<Pair> {
		int a;
		int p;
		
		public Pair(int a, int p) {
			this.a = a;
			this.p = p;
		}

		@Override
		public int compareTo(Pair o) {
			return a - o.a;
		}
	}
	
	public void solve() {
		long l = System.currentTimeMillis();
		int tc = in.nextInt();
		f :
		for (int q = 0; q < tc; q++) {
			int n = in.nextInt();
			int maxp = 10 * n + 1;
			double c = in.nextDouble();
			double t = in.nextDouble();
			double s = 1.0;
			double m = 10.0 / 9;
			Pair[] p = new Pair[n];
			for (int j = 0; j < p.length; j++) {
				p[j] = new Pair(in.nextInt(), in.nextInt());
			}
			Arrays.sort(p);
			double[][] dp = new double[maxp][n + 1];
			boolean[][] used = new boolean[maxp][n + 1];
			used[0][0] = true;
			for (int i = 0; i < n; i++) {
				for (int number = i; number >= 0; number--) {
					for (int score = 0; score <= 10 * i; score++) {
						if (used[score][number]) {
							if (used[score + p[i].p][number + 1]) {
								dp[score + p[i].p][number + 1] = Math.min(dp[score + p[i].p][number + 1], (dp[score][number] + p[i].a) * m);
							} else {
								used[score + p[i].p][number + 1] = true;
								dp[score + p[i].p][number + 1] = (dp[score][number] + p[i].a) * m;
							}
						}
					}
				}
			}
			for (int sc = maxp - 1; sc >= 0; sc--) {
				for (int i = 0; i <= n; i++) {
					if (used[sc][i]) {
						double time = t - 10 * i;
						if (time >= dp[sc][i] || (Math.sqrt(c * dp[sc][i]) > 1 && 2 * Math.sqrt(dp[sc][i] / c) - s / c <= time)) {
							out.println(sc);
							continue f;
						}
					}
				}
			}
			out.println(0);
		}
		System.err.println(System.currentTimeMillis() - l);
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
		new F().run();
	}
}