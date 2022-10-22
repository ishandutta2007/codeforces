import java.io.*;
import java.util.*;

public class F1 {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public void solve() throws IOException {
		int n = in.nextInt();
		long k = in.nextLong();
		long[] max = new long[n];
		long[] used = new long[n];
		TreeSet<Long> set = new TreeSet();
		for (int i = 1; i < used.length; i++) {
			max[i] = max[i - 1];
			for (int j = 1; j * j <= i + 1; j++) {
				if ((i + 1) % j == 0) {
					used[j - 1]++;
					used[i]++;
					max[i]++;
					if (j != 1 && (i + 1) / j != j) {
						used[(i + 1) / j - 1]++;
						used[i]++;
						max[i]++;
					}
				}
			}
			// for (long j = 1; j <= max[i] - max[i - 1]; j++) {
			// set.add(j);
			// }
			// for (int j = 0; j < used.length; j++) {
			// set.remove(used[j]);
			// if (set.isEmpty()) {
			// break;
			// }
			// }
			// if (!set.isEmpty()) {
			// System.out.println(i + 1);
			// for (long j : set) {
			// System.out.println(j);
			// }
			// }
			// set.clear();
			if (k <= max[i]) {
				out.println("Yes");
				if (k == max[i]) {
					out.println(i + 1);
					for (int j = 0; j <= i; j++) {
						out.print(j + 1 + " ");
					}
				} else {
					int x = -1;
					for (int j = 0; j < used.length; j++) {
						if (used[j] + k == max[i]) {
							x = j;
							break;
						}
					}
					if (x != -1) {
						out.println(i);
						for (int j = 0; j <= i; j++) {
							if (j != x) {
								out.print(j + 1 + " ");
							}
						}
					} else {
//						TreeSet<Long> ans = new TreeSet<>();
						for (long j = 0; j <= i; j++) {
							set.add(j);
						}
						k = max[i] - k;
						for (long j = 0; j < i; j++) {
							if (used[(int)j] == 1) {
								set.remove(j);
								k--;
							}
							if (k == 0) {
								break;
							}
						}
						for (long j = 0; j < used.length; j++) {
							if (used[(int)j] == k) {
								set.remove(j);
								break;
							}
						}
						out.println(set.size());
						for (long j : set) {
							out.print(j + 1 + " ");
						}
					}
				}
				return;
			}
		}
		System.out.println("No");
		// for (int i = 1; i < used.length; i++) {
		// set.add(max[i] - max[i - 1]);
		// }
		// for (long j : set) {
		// System.out.println(j);
		// }
		// if (k > max[n - 1]) {
		// System.out.println("No");
		// return;
		// } else {
		// System.out.println("Yes");
		// int j = 0;
		// for (int i = 0; i < used.length; i++) {
		// if (max[i] >= k) {
		//
		// }
		// }
		// }
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

	public static void main(String[] arg) {
		new F1().run();
	}
}