import java.util.*;
import java.io.*;

public class B {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;
	
	public static class Number {
		int b;
		int c;
		
		public Number(int b, int c) {
			this.b = b;
			this.c = c;
		}
	}
	
	public static Number count(int w, int x, int y, int z, int a, int b, int c, int d) {
		int bi = 0;
		int co = 0;
		if (w == a) {
			bi++;
		}
		if (x == b) {
			bi++;
		}
		if (y == c) {
			bi++;
		}
		if (z == d) {
			bi++;
		}
		if (w == b || w == c || w == d) {
			co++;
		}
		if (x == a || x == c || x == d) {
			co++;
		}
		if (y == a || y == b || y == d) {
			co++;
		}
		if (z == a || z == b || z == c) {
			co++;
		}
		return new Number(bi, co);
	}
	
	public static void update(boolean[][][][] a, int b, int c, int w, int x, int y, int z) {
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length; j++) {
				for (int i2 = 0; i2 < a.length; i2++) {
					for (int j2 = 0; j2 < a.length; j2++) {
						if (a[i][j][i2][j2]) {
							Number n = count(w, x, y, z, i, j, i2, j2);
							if (n.b == b && n.c == c) {
								a[i][j][i2][j2] = true;
							} else {
								a[i][j][i2][j2] = false;
							}
						}
					}
				}
			}
		}
	}
	
	public void solve() throws IOException {
		boolean[][][][] a = new boolean[10][10][10][10];
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length; j++) {
				for (int i2 = 0; i2 < a.length; i2++) {
					for (int j2 = 0; j2 < a.length; j2++) {
						if (i != j && i != i2 && i != j2 && j != i2 && j != j2 && i2 != j2) {
							a[i][j][i2][j2] = true;
						}
					}
				}
			}
		}
		while (true) {
			for (int i = 0; i < a.length; i++) {
				for (int j = 0; j < a.length; j++) {
					for (int k = 0; k < a.length; k++) {
						for (int l = 0; l < a.length; l++) {
							if (a[i][j][k][l]) {
								System.out.println("" + i + j + k + l);
								int b = in.nextInt();
								int c = in.nextInt();
								if (b == 4) {
									return;
								}
								update(a, b, c, i, j, k, l);
							}
						}
					}
				}
			}
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