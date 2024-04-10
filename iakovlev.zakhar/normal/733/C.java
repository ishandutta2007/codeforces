import java.util.*;
import java.io.*;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;
	
	

	public void solve() {
		int n = in.nextInt();
		long[] a = new long[n];
		long[] sum = new long[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = in.nextInt();
			if (i == 0) {
				sum[i] = a[i];
			} else {
				sum[i] = sum[i - 1] + a[i];
			}
		}
		int k = in.nextInt();
		long[] b = new long[k];
		for (int i = 0; i < b.length; i++) {
			b[i] = in.nextInt();
		}
		int wereEaten = 0;
		int last = 0;
		ArrayList<Integer> list = new ArrayList<>();
		ArrayList<Character> list1 = new ArrayList<>();
		for (int i = 0; i < b.length; i++) {
			if (i == 0) {
				int l = -1;
				int r = n;
				while (l + 1 < r) {
					int m = (l + r) / 2;
					if (sum[m] >= b[0]) {
						r = m;
					} else {
						l = m;
					}
				}
				if (r >= 0 && r < n && sum[r] == b[0]) {
					if (r == 0) {
						last = r;
						continue;
					} else {
						long max = 0;
						int number = 0;
						for (int j = 0; j <= r; j++) {
							if (a[j] > max) {
								max = a[j];
								number = 1;
							} else if (a[j] == max) {
								number++;
							}
						}
						if (number == r + 1) {
							out.println("NO");
							out.close();
							return;
						} else {
							for (int j = 0; j <= r; j++) {
								if (a[j] == max) {
									if (j > 0 && a[j - 1] < max) {
										for (int j2 = 0; j2 < j; j2++) {
											wereEaten++;
											list.add(j + 1 - j2);
											list1.add('L');
										}
										for (int j2 = j; j2 < r; j2++) {
											wereEaten++;
											list.add(1);
											list1.add('R');
										}
										break;
									} else if (j < r && a[j + 1] < max) {
										while (wereEaten + j < r) {
											wereEaten++;
											list.add(j + 1);
											list1.add('R');
										}
										for (int j2 = j; j2 > 0; j2--) {
											wereEaten++;
											list.add(j2 + 1);
											list1.add('L');
										}
										break;
									}
								}
							}
						}
					}
					last = r;
				} else {
					out.println("NO");
					out.close();
					return;
				}
			} else {
				int l = last - 1;
				int r = n;
				while (l + 1 < r) {
					int m = (l + r) / 2;
					if (sum[m] - sum[last] >= b[i]) {
						r = m;
					} else {
						l = m;
					}
				}
				if (r > last && r < n && sum[r] - sum[last] == b[i]) {
					if (r == last + 1) {
						last = r;
						continue;
					} else {
						long max = 0;
						int number = 0;
						for (int j = last + 1; j <= r; j++) {
							if (a[j] > max) {
								max = a[j];
								number = 1;
							} else if (a[j] == max) {
								number++;
							}
						}
						if (number == r - last) {
							out.println("NO");
							out.close();
							return;
						} else {
							for (int j = last + 1; j <= r; j++) {
								if (a[j] == max) {
									if (j > last + 1 && a[j - 1] < max) {
										for (int j2 = last + 1; j2 < j; j2++) {
											list.add(- wereEaten + j + 1);
											wereEaten++;
											list1.add('L');
										}
										for (int j2 = 0; j2 < - j + r; j2++) {
											wereEaten++;
											list.add(1 + i);
											list1.add('R');
										}
										break;
									} else if (j < r && a[j + 1] < max) {
										for (int j2 = j; j2 < r; j2++) {
											wereEaten++;
											list.add(i + j - last);
											list1.add('R');
										}
										for (int j2 = j; j2 > last + 1; j2--) {
											wereEaten++;
											list.add(j2 + i - last);
											list1.add('L');
										}
										break;
									}
								}
							}
						}
					}
					last = r;
				} else {
					out.println("NO");
					out.close();
					return;
				}
			}
		}
		if (last != n - 1) {
			out.print("NO");
			out.close();
			return;
		}
		out.println("YES");
		for (int j = 0; j < list.size(); j++) {
			out.println(list.get(j) + " " + list1.get(j));
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