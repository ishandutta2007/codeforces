import java.util.*;
import java.io.*;

public class D {
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

	public class Pair {
		int x;
		int y;
		int time;
		
		public Pair(int x, int y, int time) {
			super();
			this.x = x;
			this.y = y;
			this.time = time;
		}
		
	}
	
	

	public void solve() {
		String s = in.next();
		String t = in.next();
		int[] a1 = new int[s.length() + 1];
		int[] c1 = new int[s.length() + 1];
		int[] a2 = new int[t.length() + 1];
		int[] c2 = new int[t.length() + 1];
		for (int i = 0; i < s.length(); i++) {
			c1[i + 1] = c1[i];
			if (s.charAt(i) == 'A') {
				a1[i + 1] = a1[i] + 1;
			} else {
				c1[i + 1]++;
			}
		}
		for (int i = 0; i < t.length(); i++) {
			c2[i + 1] = c2[i];
			if (t.charAt(i) == 'A') {
				a2[i + 1] = a2[i] + 1;
			} else {
				c2[i + 1]++;
			}
		}
		int q = in.nextInt();
		for (int i = 0; i < q; i++) {
			int l1 = in.nextInt() - 1;
			int r1 = in.nextInt() - 1;
			int l2 = in.nextInt() - 1;
			int r2 = in.nextInt() - 1;
			int n1 = Math.min(r1 - l1 + 1, a1[r1 + 1]);
			int n2 = Math.min(r2 - l2 + 1, a2[r2 + 1]);
			int b1 = c1[r1 + 1] - c1[l1];
			int b2 = c2[r2 + 1] - c2[l2];
			if (n2 > n1) {
				out.print(0);
				continue;
			}
			n1 -= n2;
			if (b1 == 0) {
				if (b2 == 0) {
					if (n1 % 3 == 0) {
						out.print(1);
					} else {
						out.print(0);
					}
					continue;
				} else {
					if (n1 == 0) {
						out.print(0);
						continue;
					}
					b1 = 2;
					n1 = 0;
					if (b2 >= b1 && (b2 - b1) % 2 == 0) {
						out.print(1);
					} else {
						out.print(0);
					}
					continue;
				}
			} else {
				if (n1 % 3 != 0) {
					b1 += 2;
				}
				if (b2 >= b1 && (b2 - b1) % 2 == 0) {
					out.print(1);
				} else {
					out.print(0);
				}
				continue;
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
	public static void main(String[] args) {
		new D().run();
	}
}