import java.util.*;
import java.io.*;

public class B {
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
	
	public void solve() throws IOException {
		int n = in.nextInt();
		int m = in.nextInt();
		int[][][] a = new int[n][m][2];
		HashMap<String, Integer> h = new HashMap<>();
		for (int i = 0; i < a.length; i++) {
			h.put(in.next(), i);
			in.next();
			String s = in.next();
			if (s.charAt(0) == '0' || s.charAt(0) == '1') {
				for (int j = 0; j < s.length(); j++) {
					a[i][j][0] = s.charAt(j) - '0';
					a[i][j][1] = s.charAt(j) - '0';
				}
			} else {
				int one = 0;
				if (s.charAt(0) == '?') {
					one = -1;
				} else {
					one = h.get(s);
				}
				int k = 0;
				String s1 = in.next();
				if (s1.charAt(0) == 'A') {
					k = 1;
				} else if (s1.charAt(0) == 'O') {
					k = 2;
				} else {
					k = 3;
				}
				String s2 = in.next();
				int two = 0;
				if (s2.charAt(0) == '?') {
					two = -1;
				} else {
					two = h.get(s2);
				}
				for (int j = 0; j < a[0].length; j++) {
					int o = 0;
					int t = 1;
					if (k == 1) {
						if (one == -1) {
							if (two == -1) {
								o = 0;
								t = 1;
							} else {
								o = 0;
								t = a[two][j][1];
							}
						} else {
							if (two == -1) {
								o = 0;
								t = a[one][j][1];
							} else {
								o = a[one][j][0] & a[two][j][0];
								t = a[one][j][1] & a[two][j][1];
							}
						}
					} else if (k == 2) {
						if (one == -1) {
							if (two == -1) {
								o = 0;
								t = 1;
							} else {
								o = a[two][j][0];
								t = 1;
							}
						} else {
							if (two == -1) {
								o = a[one][j][0];
								t = 1;
							} else {
								o = a[one][j][0] | a[two][j][0];
								t = a[one][j][1] | a[two][j][1];
							}
						}
					} else {
						if (one == -1) {
							if (two == -1) {
								o = 0;
								t = 0;
							} else {
								o = a[two][j][0];
								t = a[two][j][1] ^ 1;
							}
						} else {
							if (two == -1) {
								o = a[one][j][0];
								t = a[one][j][1] ^ 1;
							} else {
								o = a[one][j][0] ^ a[two][j][0];
								t = a[one][j][1] ^ a[two][j][1];
							}
						}
					}
					a[i][j][0] = o;
					a[i][j][1] = t;
				}
			}
		}
		int[] sum0 = new int[m];
		int[] sum1 = new int[m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				sum0[j] += a[i][j][0];
				sum1[j] += a[i][j][1];
			}
		}
		int[] min = new int[m];
		int[] max = new int[m];
		for (int i = 0; i < max.length; i++) {
			if (sum1[i] > sum0[i]) {
				max[i] = 1;
			}
			if (sum1[i] < sum0[i]) {
				min[i] = 1;
			}
		}
		for (int i = 0; i < min.length; i++) {
			out.print(min[i]);
		}
		out.println();
		for (int i = 0; i < max.length; i++) {
			out.print(max[i]);
		}
	}

	public void run() throws IOException {
		if (systemIO) {
			in = new FastScanner(System.in);
			out = new PrintWriter(System.out);
		} else {
			in = new FastScanner(new File("input.txt"));
			out = new PrintWriter(new File("output.txt"));
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
	public static void main(String[] arg) throws IOException {
		new B().run();
	}
}