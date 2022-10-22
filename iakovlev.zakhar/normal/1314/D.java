import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

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

	public long[][] pow(long[][] x, long p) {
		if (p == 0) {
			long[][] ans = new long[x.length][x.length];
			for (int i = 0; i < ans.length; i++) {
				ans[i][i] = 1;
			}
			return ans;
		}
		long[][] t = pow(x, p / 2);
		t = multiply(t, t);
		if (p % 2 == 1) {
			t = multiply(t, x);
		}
		return t;
	}

	public long[][] multiply(long[][] a, long[][] b) {
		long[][] ans = new long[a.length][b[0].length];
		for (int i = 0; i < ans.length; i++) {
			for (int j = 0; j < ans[0].length; j++) {
				for (int k = 0; k < b.length; k++) {
					ans[i][j] += a[i][k] * b[k][j];
					ans[i][j] %= mod;
				}
			}
		}
		return ans;
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

	public long modInv(long x) {
		return pow(x, mod - 2);
	}

	long mod = 1000000007;

	Random random = new Random();

	public void solve() {
		int n = in.nextInt();
		int moves = in.nextInt() / 2;
		int[][] edge = new int[n][n];
		for (int i = 0; i < edge.length; i++) {
			for (int j = 0; j < edge.length; j++) {
				edge[i][j] = in.nextInt();
			}
		}
		int nmin = 5;
		int[][][] twoMove = new int[n][n][nmin];
		int[][][] through = new int[n][n][nmin];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int min = 0; min < nmin; min++) {
					twoMove[i][j][min] = Integer.MAX_VALUE / 2;
					through[i][j][min] = -1;
				}
				for (int th = 1; th < n; th++) {
					if (th == i || th == j) {
						continue;
					}
					int len = edge[i][th] + edge[th][j];
					for (int l = 0; l < nmin; l++) {
						if (len < twoMove[i][j][l]) {
							for (int k = nmin - 1; k > l; k--) {
								twoMove[i][j][k] = twoMove[i][j][k - 1];
								through[i][j][k] = through[i][j][k - 1];
							}
							twoMove[i][j][l] = len;
							through[i][j][l] = th;
							break;
						}
					}
				}
			}
		}
		if (moves == 1) {
			out.print(twoMove[0][0][0]);
			return;
		}
		if (moves == 5) {
			int ans = Integer.MAX_VALUE / 2;
			for (int b = 0; b < n; b++) {
				for (int d = 0; d < n; d++) {
					for (int f = 0; f < n; f++) {
						for (int h = 0; h < n; h++) {
							int th = 0;
							int[] route = { 0, b, d, f, h, 0 };
							for (int j = 0; j < moves; j++) {
								int from = route[j];
								int to = route[j + 1];
								for (int i = 0; i < nmin; i++) {
									if (through[from][to][i] == b || through[from][to][i] == d
											|| through[from][to][i] == f || through[from][to][i] == h) {
										continue;
									}
									th += twoMove[from][to][i];
									break;
								}
							}
							ans = Math.min(ans, th);
						}
					}
				}
			}
			out.print(ans);
			return;
		}
		if (moves == 4) {
			int ans = Integer.MAX_VALUE / 2;
			for (int b = 0; b < n; b++) {
				for (int d = 0; d < n; d++) {
					for (int f = 0; f < n; f++) {
						int th = 0;
						int[] route = { 0, b, d, f, 0 };
						for (int j = 0; j < moves; j++) {
							int from = route[j];
							int to = route[j + 1];
							for (int i = 0; i < nmin; i++) {
								if (through[from][to][i] == b || through[from][to][i] == d
										|| through[from][to][i] == f) {
									continue;
								}
								th += twoMove[from][to][i];
								break;
							}
						}
						ans = Math.min(ans, th);
					}
				}
			}
			out.print(ans);
			return;
		}
		if (moves == 3) {
			int ans = Integer.MAX_VALUE / 2;
			for (int b = 0; b < n; b++) {
				for (int d = 0; d < n; d++) {
					int th = 0;
					int[] route = { 0, b, d, 0 };
					for (int j = 0; j < moves; j++) {
						int from = route[j];
						int to = route[j + 1];
						for (int i = 0; i < nmin; i++) {
							if (through[from][to][i] == b || through[from][to][i] == d) {
								continue;
							}
							th += twoMove[from][to][i];
							break;
						}
					}
					ans = Math.min(ans, th);
				}
			}
			out.print(ans);
			return;
		}
		if (moves == 2) {
			int ans = Integer.MAX_VALUE / 2;
			for (int b = 0; b < n; b++) {
				int th = 0;
				int[] route = { 0, b, 0 };
				for (int j = 0; j < moves; j++) {
					int from = route[j];
					int to = route[j + 1];
					for (int i = 0; i < nmin; i++) {
						if (through[from][to][i] == b) {
							continue;
						}
						th += twoMove[from][to][i];
						break;
					}
				}
				ans = Math.min(ans, th);
			}
			out.print(ans);
			return;
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