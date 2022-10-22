import java.util.*;
import java.io.*;

public class B {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public void solve() {
		int n = in.nextInt();
		int[][] a = new int[n][n];
		if (n == 1) {
			out.println(1);
			return;
		}
		int x = 0;
		int y = 0;
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length; j++) {
				a[i][j] = in.nextInt();
				if (a[i][j] == 0) {
					x = i;
					y = j;
				}
			}
		}
		long sum = 0;
		for (int i = 0; i < a.length; i++) {
			if (x == 0) {
				sum += a[1][i];
			} else {
				sum += a[0][i];
			}
		}
		for (int i = 0; i < a.length; i++) {
			if (x != i) {
				long s = 0;
				for (int j = 0; j < a.length; j++) {
					s += a[i][j];
				}
				if (s != sum) {
					out.print("-1");
					return;
				}
			}
			if (y != i) {
				long s = 0;
				for (int j = 0; j < a.length; j++) {
					s += a[j][i];
				}
				if (s != sum) {
					out.println(-1);
					return;
				}
			}
		}
		long d1 = 0;
		long d2 = 0;
		for (int i = 0; i < a.length; i++) {
			d1 += a[i][i];
			d2 += a[i][n - 1 - i];
		}
		boolean isD1 = x == y;
		boolean isD2 = x + y == n - 1;
		if (!isD1 && d1 != sum || !isD2 && d2 != sum) {
			out.println(-1);
			return;
		}
		long sumX = 0;
		long sumY = 0;
		for (int i = 0; i < a.length; i++) {
			sumX += a[x][i];
			sumY += a[i][y];
		}
		if (sumX == sumY && (!isD1 || isD1 && d1 == sumX) && (!isD2 || isD2 && d2 == sumX)) {
			if (sum - sumX > 0) {
				out.println(sum - sumX);
			} else {
				out.println(-1);
			}
		} else {
			out.println(-1);
		}
	}

	public void run() {
		if (systemIO) {
			in = new FastScanner(System.in);
			out = new PrintWriter(System.out);
		} else {
			in = new FastScanner(new File("test.out"));
			out = new PrintWriter(System.out);
		}
		solve();

		out.close();
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
		new B().run();
	}
}