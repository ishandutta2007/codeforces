import java.util.*;
import java.io.*;

public class Main {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	int mod = 1000000007;

	public int sum(int x, int y) {
		if (x + y >= mod) {
			return x + y - mod;
		}
		return x + y;
	}

	public int diff(int x, int y) {
		if (x < y) {
			return x + mod - y;
		}
		return x - y;
	}

	public int mult(int x, int y) {
		return (int) (x * 1L * y % mod);
	}

	public int pow(int x, long p) {
		int ans = 1;
		while (p > 0) {
			if ((p & 1) == 1) {
				ans = mult(ans, x);
			}
			x = mult(x, x);
			p >>= 1;
		}
		return ans;
	}

	public int inv(int x) {
		return pow(x, mod - 2);
	}

	public double sum(double x, double y) {
		return x + y;
	}

	public double diff(double x, double y) {
		return x - y;
	}

	public double mult(double x, double y) {
		return x * y;
	}

	public double inv(double x) {
		return 1 / x;
	}

	public int[][] readGraph(int n, int m) {
		for (int i = 0; i < n; i++) {
			sz[i] = 0;
		}
		int[] x = new int[m];
		int[] y = new int[m];
		for (int i = 0; i < m; i++) {
			x[i] = in.nextInt() - 1;
			y[i] = in.nextInt() - 1;
//			x[i] = i + 1;
//			y[i] = i;
			sz[x[i]]++;
		}
		for (int i = 0; i < n; i++) {
			to[i] = new int[sz[i]];
			sz[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			to[x[i]][sz[x[i]]++] = y[i];
		}
		return to;
	}

	int MAX = 500000;

	int[][] to = new int[MAX][];
	int[] sz = new int[MAX];

	public int gcd(int x, int y) {
		while (y > 0) {
			int c = y;
			y = x % y;
			x = c;
		}
		return x;
	}

	public int[][][] pref(long[] a) {
		int n = a.length;
		int[][] pref2 = new int[n][2];
		int[][] pref1 = new int[n][2];
		int[][] pref0 = new int[n][2];
		int[][] prefLose = new int[n][2];
//		for (int m1 = 0; m1 < 2; m1++) {
//			for (int m2 = 0; m2 < 2; m2++) {
//				if ((m1 + 1) * a[0] > (m2 + 1) * a[1]) {
//					pref0[1][m2] = sum(pref0[1][m2], mult(inv2, inv2));
//					pref1[1][m2] = sum(pref1[1][m2], mult(inv2, inv2));
//					pref2[1][m2] = sum(pref2[1][m2], mult(inv2, inv2));
//				}
//			}
//		}
//		System.out.println(pref0[1][0] + " " + pref1[1][0] + " " + pref2[1][0]);
//		System.out.println(pref0[1][1] + " " + pref1[1][1] + " " + pref2[1][1]);
		prefLose[0][0] = inv2;
		prefLose[0][1] = inv2;
		for (int i = 1; i < pref0.length; i++) {
			for (int m1 = 0; m1 < 2; m1++) {
				for (int m2 = 0; m2 < 2; m2++) {
					if ((m1 + 1) * a[i - 1] > (m2 + 1) * a[i]) {
						pref2[i][m2] = sum(pref2[i][m2],
								mult(inv2, sum(sum(pref0[i - 1][m1], mult(2, pref1[i - 1][m1])),
										sum(pref2[i - 1][m1], prefLose[i - 1][m1]))));
						pref1[i][m2] = sum(pref1[i][m2],
								mult(inv2, sum(sum(pref0[i - 1][m1], pref1[i - 1][m1]), prefLose[i - 1][m1])));
						pref0[i][m2] = sum(pref0[i][m2], mult(inv2, sum(pref0[i - 1][m1], prefLose[i - 1][m1])));
					} else {
						prefLose[i][m2] = sum(prefLose[i][m2], mult(inv2, inv2));
					}
				}
			}
		}
		int[][][] ans = { pref0, pref1, pref2 };
		return ans;
	}

	Random random = new Random(566);

	int inv2 = inv(2);

	public int id(int x, int y, int n, int m) {
		return x * m + y;
	}

	public class State implements Comparable<State> {
		int mask;
		int x;
		int y;
		int len;
		int number;

		public State(int mask, int x, int y, int len, int number) {
			this.mask = mask;
			this.x = x;
			this.y = y;
			this.len = len;
			this.number = number;
		}

		@Override
		public int compareTo(State o) {
			if (len != o.len) {
				return len - o.len;
			}
			if (mask != o.mask) {
				return mask - o.mask;
			}
			if (x != o.x) {
				return x - o.x;
			}
			return y - o.y;
		}
	}

	public int ans(int n, int m) {
		TreeSet<State> set = new TreeSet<>();
		State last = new State(0, 0, 0, 0, 1);
		set.add(last);
		while (!set.isEmpty()) {
			State cur = set.pollFirst();
			if (cur.mask == (1 << n * m) - 1 && cur.x == 0 && cur.y == 0) {
				return cur.number;
			}
			last = cur;
			int x = cur.x;
			int y = cur.y;
			int mask = cur.mask;
			int x1 = (x + 1) % n;
			int y1 = y;
			int id1 = id(x1, y1, n, m);
			if (((mask >> id1) & 1) == 0) {
				int mask1 = mask + (1 << id1);
				State next = new State(mask1, x1, y1, cur.len + 1, cur.number);
				State st = set.ceiling(next);
				if (st == null || st.compareTo(next) != 0) {
					set.add(next);
				} else {
					st.number += cur.number;
				}
			}
			x1 = x;
			y1 = (y + 1) % m;
			id1 = id(x1, y1, n, m);
			if (((mask >> id1) & 1) == 0) {
				int mask1 = mask + (1 << id1);
				State next = new State(mask1, x1, y1, cur.len + 1, cur.number);
				State st = set.ceiling(next);
				if (st == null || st.compareTo(next) != 0) {
					set.add(next);
				} else {
					st.number += cur.number;
				}
			}
		}
		return 0;
	}

	public void solve() {
		long[][] t = new long[3][3];
		for (int i = 0; i < 3; i += 1) {
			for (int j = 0; j < 3; j++) {
				t[i][j] = in.nextLong();
			}
		}
	    int n = in.nextInt();
	    long[][][] dp = new long[n][3][3];
	    for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) {
					continue;
				}
				dp[0][i][j] = t[i][j];
				int m = 3 - i - j;
				dp[0][i][j] = Math.min(dp[0][i][j], t[i][m] + t[m][j]);
			}
		}
	    for (int k = 1; k < n; k += 1) {
	        for (int i = 0; i < 3; i += 1) {
	            for (int j = 0; j < 3; j += 1) {
	            	dp[k][i][j] = 0;
	            	if (i == j) {
	                    continue;
	                }
	                int m = 3 - i - j;
	                dp[k][i][j] = t[i][j];
	                if (dp[k - 1][m][j] < dp[k - 1][m][i] + dp[k - 1][i][j]) {
	                    dp[k][i][j] += dp[k - 1][m][j];
	                } else {
	                    dp[k][i][j] += dp[k - 1][m][i] + dp[k - 1][i][j];
	                }
	                if (dp[k - 1][i][m] < dp[k - 1][i][j] + dp[k - 1][j][m]) {
	                    dp[k][i][j] += dp[k - 1][i][m];
	                } else {
	                    dp[k][i][j] += dp[k - 1][i][j] + dp[k - 1][j][m];
	                }
	                dp[k][i][j] = Math.min(dp[k][i][j], dp[k - 1][i][j] + t[i][m] + dp[k - 1][j][i] + t[m][j] + dp[k - 1][i][j]);
	            }
	        }
	    }
	    out.println(dp[n - 1][0][2]);
	}

	public void run() {
		try {
			if (systemIO) {
				in = new FastScanner(System.in);
				out = new PrintWriter(System.out);
			} else {
				String fileName = "input";
				in = new FastScanner(new File(fileName + ".txt"));
				out = new PrintWriter(new File(fileName + ".out"));
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
			int ans = 0;
			String s = next();
			if (s.charAt(0) == '-') {
				for (int i = 1; i < s.length(); ++i) {
					ans = 10 * ans + (s.charAt(i) - '0');
				}
				return -ans;
			}
			for (int i = 0; i < s.length(); ++i) {
				ans = 10 * ans + (s.charAt(i) - '0');
			}
			return ans;
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
		long time = System.currentTimeMillis();
		new Main().run();
		System.err.println(System.currentTimeMillis() - time);
	}
}