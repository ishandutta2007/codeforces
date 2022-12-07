import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main implements Runnable {
	public void solve() {
		FastReader sc = new FastReader();
		PrintWriter out = new PrintWriter(System.out);

		int t = sc.nextInt();

		for(int z = 0; z < t; ++z) {
			int n = sc.nextInt();
			long x = sc.nextInt();

			long a[] = new long[n];
			for(int i = 0; i < n; ++i)
				a[i] = sc.nextLong();

			long dp[][] = new long[n][n + 1];
			dp[0][0] = max(0, a[0]);
			dp[0][1] = max(0, a[0] + x);
			for(int i = 0; i < n - 1; ++i) {
				for(int j = 0; j <= i + 1; ++j) {
					dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i + 1]);
					dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i + 1] + x);
				}	
			}

			long ans[] = new long[n + 1];
			long cans = 0;
			for(int i = 0; i <= n; ++i) {
				for(int j = 0; j < n; ++j) {
					cans = max(cans, dp[j][i]);
				}
				out.print(cans + " ");
			}
			out.println();
		}

		out.close();
	}
	public static void main(String[] args) {
		new Thread(null, new Main(), "Main", 1 << 26).start();	
	}

	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while(st == null || !st.hasMoreElements()) {
				try {
					String str = br.readLine();

					if(str == null)
						throw new InputMismatchException();

					st = new StringTokenizer(str);
				} catch(IOException e) {
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

		String nextLine() {
			String str = "";

			try {
				str = br.readLine();
			} catch(IOException e) {
				e.printStackTrace();
			}

			if(str == null) 
				throw new InputMismatchException();
			return str;
		}
	}

	public void run() {
		solve();
	}
}