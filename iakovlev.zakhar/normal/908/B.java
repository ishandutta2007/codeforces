import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;

public class B {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public boolean check(int x, int y) {
		return x >= 0 && y >= 0 && x < n && y < m && f[x][y];
	}
	
	int n;
	int m;
	boolean[][] f;
	int[] dx = {1, 0, -1, 0};
	int[] dy = {0, 1, 0, -1};
	
	public void solve() {
		n = in.nextInt();
		m = in.nextInt();
		int x0 = 0;
		int y0 = 0;
		int x1 = 0;
		int y1 = 0;
		f = new boolean[n][m];
		for (int i = 0; i < f.length; i++) {
			for (int j = 0; j < f[0].length; j++) {
				f[i][j] = true;
			}
		}
		for (int i = 0; i < f.length; i++) {
			String s = in.next();
			for (int j = 0; j < f[0].length; j++) {
				if (s.charAt(j) == '#') {
					f[i][j] = false;
				} else if (s.charAt(j) == 'S') {
					x0 = i;
					y0 = j;
				} else if (s.charAt(j) == 'E') {
					x1 = i;
					y1 = j;
				}
			}
		}
		String s = in.next();
		int[] to = new int[4];
		int ans = 0;
		for (int q = 0; q < to.length; q++) {
			for (int w = 0; w < to.length; w++) {
				for (int e = 0; e < to.length; e++) {
					f:
					for (int r = 0; r < to.length; r++) {
						HashSet<Integer> set = new HashSet();
						set.add(q);
						set.add(w);
						set.add(e);
						set.add(r);
						if (set.size() != 4) {
							continue;
						}
						to[0] = q;
						to[1] = w;
						to[2] = e;
						to[3] = r;
						int x = x0;
						int y = y0;
						for (int i = 0; i < s.length(); i++) {
							x += dx[to[s.charAt(i) - '0']];
							y += dy[to[s.charAt(i) - '0']];
							if (check(x, y)) {
								if (x == x1 && y == y1) {
									ans++;
									continue f;
								}
							} else {
								continue f;
							}
						}
					}
				}
			}
		}
		out.print(ans);
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
		new B().run();
	}
}