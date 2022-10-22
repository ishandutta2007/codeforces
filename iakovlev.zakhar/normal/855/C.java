import java.util.*;
import java.io.*;

public class C {
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

	public long[][] dfs(int v) {
		used[v] = true;
		ArrayList<long[][]> a = new ArrayList<>();
		for (int i : to[v]) {
			if (!used[i]) {
				a.add(dfs(i));
//				System.out.println(v + " " + i);
//				long[][] dp = a.get(a.size() - 1);
//				for (int j = 0; j < dp.length; j++) {
//					for (int j2 = 0; j2 < dp[0].length; j2++) {
//						System.out.print(dp[j][j2] + " ");
//					}
//					System.out.println();
//				}
			}
		}
		long[][] dp = new long[x + 1][3];
		dp[0][0] = k - 1;
		dp[1][1] = 1;
		dp[0][2] = m - k;
		for (long[][] dp1 : a) {
			long[][] dp2 = new long[x + 1][3];
			for (int i = 0; i < dp1.length; i++) {
				for (int j = 0; j <= i; j++) {
					dp2[i][0] += dp[i - j][0] * (dp1[j][0] + dp1[j][1] + dp1[j][2]);
					dp2[i][0] %= mod;
					// dp[i][0] *= (k - 1);
					// dp[i][0] %= mod;
					dp2[i][2] += dp[i - j][2] * (dp1[j][0] + dp1[j][2]);
					dp2[i][2] %= mod;
					// dp[i][2] *= (m - k);
					// dp[i][2] %= mod;
					dp2[i][1] += dp[i - j][1] * dp1[j][0];
					dp2[i][1] %= mod;
				}
			}
			dp = dp2;
		}
		return dp;
		// long[][] dp1 = new long[x + 1][3];
		// for (int j = 0; j < dp.length; j++) {
		// dp1[j][0] += (dp[j][0] + dp[j][1] + dp[j][2]) * (k - 1);
		// if (j > 0) {
		// dp1[j][1] += dp1[j - 1][0];
		// }
		// dp[j][2] += (dp[j][0] + dp[j][2]) * (m - k);
		// }
		// for (int i = 0; i < dp1.length; i++) {
		// dp[i][0] = dp1[i][0] + dp1[i][1] + dp1[i][2];
		// dp[i][1] = dp1[i][0];
		// dp[i][2] = dp1[]
		// }
	}

	ArrayList<Integer>[] to;
	long m;
	long k;
	int x;
	boolean[] used;
	long mod = 1000000007L;

	@SuppressWarnings("unchecked")
	public void solve() {
		int n = in.nextInt();
		used = new boolean[n];
		m = in.nextLong();
		to = new ArrayList[n];
		for (int i = 0; i < to.length; i++) {
			to[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			int x = in.nextInt() - 1;
			int y = in.nextInt() - 1;
			to[x].add(y);
			to[y].add(x);
		}
		k = in.nextLong();
		x = in.nextInt();
		if (n == 1) {
			System.out.println(m);
			return;
		}
		long[][] dp = dfs(0);
		long sum = 0;
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[0].length; j++) {
//				System.out.print(dp[i][j] + " ");
				sum += dp[i][j];
				sum %= mod;
			}
//			System.out.println();
		}
		System.out.println(sum);
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
		new C().run();
	}
}