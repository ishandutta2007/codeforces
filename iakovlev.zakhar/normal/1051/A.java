import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;

public class A {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public void solve() {
		int t = in.nextInt();
		for (int q = 0; q < t; q++) {
			String s = in.next();
			int[] x = new int[s.length()];
			int l = 0;
			int L = 0;
			int d = 0;
			for (int i = 0; i < x.length; i++) {
				if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
					x[i] = 2;
					d++;
				} else if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') {
					x[i] = 1;
					L++;
				} else {
					l++;
				}
			}
			if (l > 1) {
				if (L == 0) {
					for (int i = 0; i < x.length; i++) {
						if (x[i] == 0) {
							s = s.substring(0, i) + "A" + s.substring(i + 1);
							if (d == 0) {
								s = s.substring(0, i + 1) + 0 + s.substring(i + 2);
							}
							break;
						}
					}
				} else if (d == 0) {
					for (int i = 0; i < x.length; i++) {
						if (x[i] == 0) {
							s = s.substring(0, i) + "0" + s.substring(i + 1);
							break;
						}
					}
				}
			} else if (L > 1) {
				if (l == 0) {
					for (int i = 0; i < x.length; i++) {
						if (x[i] == 1) {
							s = s.substring(0, i) + "a" + s.substring(i + 1);
							if (d == 0) {
								s = s.substring(0, i + 1) + 0 + s.substring(i + 2);
							}
							break;
						}
					}
				} else if (d == 0) {
					for (int i = 0; i < x.length; i++) {
						if (x[i] == 1) {
							s = s.substring(0, i) + "0" + s.substring(i + 1);
							break;
						}
					}
				}
			} else if (d > 1) {
				if (l == 0) {
					for (int i = 0; i < x.length; i++) {
						if (x[i] == 2) {
							s = s.substring(0, i) + "a" + s.substring(i + 1);
							if (L == 0) {
								s = s.substring(0, i + 1) + "A" + s.substring(i + 2);
							}
							break;
						}
					}
				} else if (L == 0) {
					for (int i = 0; i < x.length; i++) {
						if (x[i] == 2) {
							s = s.substring(0, i) + "A" + s.substring(i + 1);
							break;
						}
					}
				}
			}
			out.println(s);
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
		new A().run();
	}
}