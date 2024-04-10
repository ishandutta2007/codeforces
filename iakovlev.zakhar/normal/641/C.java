import java.util.*;
import java.io.*;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	

	public void solve() {
		int n = in.nextInt();
		int q = in.nextInt();
		int[] a = new int[n];
		if (n == 2) {
			int one = 0;
			for (int i = 0; i < q; i++) {
				if (in.nextInt() == 1) {
					int x = in.nextInt();
					one = (one + 2 * n + x) % n;
				} else {
					if (one % 2 == 0) {
						one++;
					} else {
						one--;
					}
				}
			}
			if (one == 1) {
				out.print("2 1");
			} else {
				out.println("1 2");
			}
			return;
		}
		int one = 0;
		int two = 1;
		int tree = 2;
		for (int i = 0; i < q; i++) {
			if (in.nextInt() == 1) {
				int x = in.nextInt();
				one = (one + 2 * n + x) % n;
				two = (two + 2 * n + x) % n;
				tree = (tree + 2 * n + x) % n;
			} else {
				if (one % 2 == 0) {
					one++;
				} else {
					one--;
				}
				if (two % 2 == 0) {
					two++;
				} else {
					two--;
				}
				if (tree % 2 == 0) {
					tree++;
				} else {
					tree--;
				}
			}
		}
		a[one] = 1;
		a[two] = 2;
		a[tree] = 3;
		int dx = two - one;
		int dy = tree - one;
		one = tree;
		a[(tree + dx + 2 * n) % n] = 4;
		two = (tree + dx + 2 * n) % n;
		for (int i = 5; i <= a.length; i += 2) {
			one = (one + dy + 2 * n) % n;
			a[one] = i;
			two = (two + dy + 2 * n) % n;
			a[two] = i + 1;
		}
		for (int i = 0; i < a.length; i++) {
			out.print(a[i] + " ");
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
		new C().run();
	}
}