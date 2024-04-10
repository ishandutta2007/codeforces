import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	int mod = 1000000007;

	public int mult(int x, int y) {
		return (int) (x * 1L * y % mod);
	}

	public int sum(int x, int y) {
		if (x + y >= mod) {
			return x + y - mod;
		}
		return x + y;
	}

	public int diff(int x, int y) {
		if (x >= y) {
			return x - y;
		}
		return x - y + mod;
	}

	public int div(int x, int y) {
		return mult(x, modInv(y));
	}

	int[][] res = new int[2][2];

	public void mult(int[][] a, int[][] b) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				res[i][j] = 0;
				for (int k = 0; k < 2; k++) {
					res[i][j] = sum(res[i][j], mult(a[i][k], b[k][j]));
				}
			}
		}
	}

	public int pow(int x, long p) {
		if (p == 0) {
			return 1;
		}
		int ans = pow(x, p / 2);
		ans = mult(ans, ans);
		if ((p & 1) > 0) {
			ans = mult(ans, x);
		}
		return ans;
	}

	int[][] ans = { { 1, 0 }, { 0, 1 } };

	public void pow(int[][] x, long p) {
		if (p == 0) {
			ans[0][0] = ans[1][1] = 1;
			ans[0][1] = ans[1][0] = 0;
			return;
		}
		pow(x, p / 2);
		mult(ans, ans);
		for (int i = 0; i < ans.length; i++) {
			for (int j = 0; j < ans.length; j++) {
				ans[i][j] = res[i][j];
			}
		}
		if ((p & 1) > 0) {
			mult(ans, x);
			for (int i = 0; i < ans.length; i++) {
				for (int j = 0; j < ans.length; j++) {
					ans[i][j] = res[i][j];
				}
			}
		}
	}

	public int modInv(int x) {
		return pow(x, mod - 2);
	}

	public long calc(int[] a, int x) {
		long ans = 0;
		long prev = 0;
		for (int i = x + 1; i < a.length; i++) {
			ans += (prev + a[i]) / a[i];
			prev = (prev + a[i]) / a[i] * a[i];
		}
		prev = 0;
		for (int i = x - 1; i >= 0; --i) {
			ans += (prev + a[i]) / a[i];
			prev = (prev + a[i]) / a[i] * a[i];
		}
		return ans;
	}

	public class Vertex implements Comparable<Vertex> {
		int r;
		int theta;
		
		public Vertex(int r, int theta) {
			this.r = r;
			this.theta = theta;
		}

		@Override
		public int compareTo(A.Vertex o) {
			if (r != o.r) {
				return r - o.r;
			}
			return theta - o.theta;
		}
	}
	
	public boolean dfs(int v) {
		if (v == 1) {
			return true;
		}
		used[v] = true;
		for (int i : to[v]) {
			if (!used[i] && dfs(i)) {
				return true;
			}
		}
		return false;
	}
	
	boolean[] used;
	ArrayList<Integer>[] to;
	
	public void solve() {
		f : for (int qwerty = in.nextInt(); qwerty > 0; --qwerty) {
			int n = in.nextInt();
			int z = in.nextInt();
			int ans = z;
			for (int i = 0; i < n; i++) {
				ans = Math.max(ans, in.nextInt() | z);
			}
			out.println(ans);
		}
	}

	public void add(HashMap<Integer, Integer> map, int x) {
		if (map.containsKey(x)) {
			map.put(x, map.get(x) + 1);
		} else {
			map.put(x, 1);
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