import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class D {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		if (n <= 3 && m <= 3) {
			if (n == 1 && m == 1) {
				System.out.println("YES");
				System.out.println(1);
				return;
			} else if (n == 3 && m == 3) {
				System.out.println("YES");
				System.out.println("2 9 4");
				System.out.println("8 1 3");
				System.out.println("6 7 5");
				return;
			}
			System.out.println("NO");
			return;
		}
		out.println("YES");
		boolean reverse = false;
		if (n > m) {
			reverse = true;
			int x = n;
			n = m;
			m = x;
		}
		int[][] ans = new int[n][m];
		for (int i = 0; i < ans.length; i++) {
			if (i % 2 == 0) {
				int th = 0;
				for (int j = 1; j < ans[0].length; j += 2) {
					ans[i][th] = m * i + j + 1;
					th++;
				}
				for (int j = 0; j < ans[0].length; j += 2) {
					ans[i][th] = m * i + j + 1;
					th++;
				}
			} else {
				if (m % 2 == 0) {
					int th = 0;
					for (int j = 1; j < ans[0].length; j += 2) {
						ans[i][m - th - 1] = m * i + j + 1;
						th++;
					}
					for (int j = 0; j < ans[0].length; j += 2) {
						ans[i][m - th - 1] = m * i + j + 1;
						th++;
					}
				} else {
					int th = 0;
					for (int j = 0; j < ans[0].length; j += 2) {
						ans[i][th] = m * i + j + 1;
						th++;
					}
					for (int j = 1; j < ans[0].length; j += 2) {
						ans[i][th] = m * i + j + 1;
						th++;
					}
				}
			}
		}
		if (!reverse) {
			for (int i = 0; i < ans.length; i++) {
				for (int j = 0; j < ans[0].length; j++) {
					out.print(ans[i][j] + " ");
				}
				out.println();
			}
		} else {
			int[][] was = new int[n][m];
			int[] ne = new int[n * m];
			for (int i = 0; i < was.length; i++) {
				for (int j = 0; j < was[0].length; j++) {
					ne[j + m * i] = j * n + i + 1;
				}
			}
			for (int j = 0; j < ans[0].length; j++) {
				for (int i = 0; i < ans.length; i++) {
					out.print(ne[ans[i][j] - 1] + " ");
				}
				out.println();
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
		new D().run();
	}
}