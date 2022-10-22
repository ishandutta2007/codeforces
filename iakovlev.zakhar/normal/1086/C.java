import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public long gcd(long x, long y) {
		if (y == 0) {
			return x;
		}
		if (x == 0) {
			return y;
		}
		return gcd(y, x % y);
	}

	public class Pair implements Comparable<Pair> {
		long v;
		int i;

		public Pair(long v, int i) {
			this.v = v;
			this.i = i;
		}

		@Override
		public int compareTo(Pair o) {
			if (v > o.v) {
				return 1;
			}
			if (v < o.v) {
				return -1;
			}
			return i - o.i;
		}
	}

	public void solve() {
		int t = in.nextInt();
		f: for (; t > 0; t--) {
			int k = in.nextInt();
			String str = in.next();
			String aString = in.next();
			String bString = in.next();
			int n = str.length();
			int[] s = new int[n];
			int[] a = new int[n];
			int[] b = new int[n];
			for (int i = 0; i < n; i++) {
				s[i] = str.charAt(i) - 'a';
				a[i] = aString.charAt(i) - 'a';
				b[i] = bString.charAt(i) - 'a';
			}
			int[] ansa = new int[k];
			int[] wasa = new int[k];
			int[] ansb = new int[k];
			int[] wasb = new int[k];
			boolean cana = true;
			boolean canb = true;
			for (int i = 0; i < wasa.length; i++) {
				ansa[i] = -1;
				wasa[i] = -1;
				ansb[i] = -1;
				wasb[i] = -1;
			}
			boolean eq = true;
			f1: for (int i = 0; i < n; i++) {
				if (eq) {
					if (a[i] == b[i]) {
						if (ansa[s[i]] == -1) {
							if (wasa[a[i]] == -1) {
								ansa[s[i]] = a[i];
								ansb[s[i]] = b[i];
								wasa[a[i]] = s[i];
								wasb[b[i]] = s[i];
							} else {
								out.println("NO");
								continue f;
							}
						} else if (ansa[s[i]] == a[i]) {
							continue;
						} else {
							out.println("NO");
							continue f;
						}
					} else {
						eq = false;
						if (ansa[s[i]] == -1) {
							for (int j = a[i] + 1; j < b[i]; j++) {
								if (wasa[j] == -1) {
									ansa[s[i]] = j;
									wasa[j] = s[i];
									canb = false;
									break f1;
								}
							}
							if (wasa[a[i]] == -1) {
								wasa[a[i]] = s[i];
								ansa[s[i]] = a[i];
							} else {
								cana = false;
							}
							if (wasb[b[i]] == -1) {
								wasb[b[i]] = s[i];
								ansb[s[i]] = b[i];
							} else {
								canb = false;
							}
						} else {
							if (ansa[s[i]] == a[i]) {
								canb = false;
							} else if (ansb[s[i]] == b[i]) {
								cana = false;
							} else if (ansa[s[i]] > a[i] && ansb[s[i]] < b[i]) {
								canb = false;
								break;
							} else {
								out.println("NO");
								continue f;
							}
						}
					}
				} else {
					if (cana) {
						if (ansa[s[i]] == -1) {
							for (int j = a[i] + 1; j < k; j++) {
								if (wasa[j] == -1) {
									wasa[j] = s[i];
									ansa[s[i]] = j;
									canb = false;
									break f1;
								}
							}
							if (wasa[a[i]] == -1) {
								ansa[s[i]] = a[i];
								wasa[a[i]] = s[i];
							} else {
								cana = false;
							}
						} else {
							if (ansa[s[i]] > a[i]) {
								canb = false;
								break;
							} else if (ansa[s[i]] < a[i]) {
								cana = false;
							}
						}
					}
					if (canb) {
						if (ansb[s[i]] == -1) {
							for (int j = b[i] - 1; j >= 0; j--) {
								if (wasb[j] == -1) {
									wasb[j] = s[i];
									ansb[s[i]] = j;
									cana = false;
									break f1;
								}
							}
							if (wasb[b[i]] == -1) {
								wasb[b[i]] = s[i];
								ansb[s[i]] = b[i];
							} else {
								canb = false;
							}
						} else {
							if (ansb[s[i]] < b[i]) {
								cana = false;
								break;
							} else if (ansb[s[i]] > b[i]) {
								canb = false;
							}
						}
					}
				}
			}
			if (cana) {
				out.println("YES");
				int j = 0;
				for (int i = 0; i < wasa.length; i++) {
					if (ansa[i] == -1) {
						while (wasa[j] != -1) {
							j++;
						}
						ansa[i] = j;
						wasa[j] = i;
					}
				}
				for (int i = 0; i < wasa.length; i++) {
					out.print((char) ('a' + ansa[i]));
				}
				out.println();
			} else if (canb) {
				out.println("YES");
				int j = 0;
				for (int i = 0; i < wasb.length; i++) {
					if (ansb[i] == -1) {
						while (wasb[j] != -1) {
							j++;
						}
						ansb[i] = j;
						wasb[j] = i;
					}
				}
				for (int i = 0; i < wasb.length; i++) {
					out.print((char) ('a' + ansb[i]));
				}
				out.println();
			} else {
				out.println("NO");
			}
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
		new C().run();
	}
}