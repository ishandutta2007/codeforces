import java.util.*;
import java.io.*;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public void makeSet(int x) {
		p[x] = x;
		rank[x] = 0;
	}
    
    public int find(int x) {
    	if (x == p[x]) {
			return x;
		}
		return (p[x] = find(p[x]));
	}
    
    public boolean isUnite(int x, int y) {
    	x = find(x);
    	y = find(y);
		if (x == y) {
			return false;
		}
		if (rank[x] < rank[y]) {
			p[x] = y;
		} else {
			p[y] = x;
		}
		if (rank[x] == rank[y]) {
			rank[x]++;
		}
		return true;
	}
    
    int[] p;
    int[] rank;
	
	public void solve() throws IOException {
		int n = in.nextInt();
		int m = in.nextInt();
		long k = in.nextLong();
		int x = in.nextInt() - 1;
		int y = in.nextInt() - 1;
		if (n == 1) {
			long[] a = new long[m];
			for (int i = 0; i < a.length; i++) {
				a[i] = k / m;
			}
			k %= m;
			for (int i = 0; i < k; i++) {
				a[i]++;
			}
			System.out.println(a[0] + " " + a[m - 1] + " " + a[y]);
			return;
		}
		long[][] a = new long[n][m];
		for (int i = 0; i < a[0].length; i++) {
			a[0][i] = k / (2 * n * m - 2 * m);
			a[n - 1][i] = k / (2 * n * m - 2 * m);
		}
		for (int i = 1; i < a.length - 1; i++) {
			for (int j = 0; j < a[0].length; j++) {
				a[i][j] = k / (2 * n * m - 2 * m) * 2;
			}
		}
		k %= (2 * n * m - 2 * m);
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[0].length; j++) {
				if (k > 0) {
					k--;
					a[i][j]++;
				} else {
					break;
				}
			}
		}
		for (int i = a.length - 2; i > 0; i--) {
			for (int j = 0; j < a[0].length; j++) {
				if (k > 0) {
					k--;
					a[i][j]++;
				} else {
					break;
				}
			}
		}
		long min = Long.MAX_VALUE;
		long max = Long.MIN_VALUE;
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[0].length; j++) {
				if (a[i][j] > max) {
					max = a[i][j];
				}
				if (a[i][j] < min) {
					min = a[i][j];
				}
			}
		}
		System.out.println(max + " " + min + " " + a[x][y]);
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
		new C().run();
	}
}