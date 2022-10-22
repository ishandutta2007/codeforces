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
		int t = in.nextInt();
		f : for (int qwerty = 0; qwerty < t; qwerty++) {
			TreeMap<Vertex, Integer> map = new TreeMap<>();
			Vertex start = new Vertex(0, 0);
			Vertex finish = new Vertex(20, 0);
			map.put(start, 0);
			map.put(finish, 1);
			for (int r = 1; r < 20; r++) {
				for (int theta = 0; theta < 360; theta++) {
					map.put(new Vertex(r, theta), map.size());
				}
			}
			to = new ArrayList[map.size()];
			for (int i = 0; i < to.length; i++) {
				to[i] = new ArrayList<>();
			}
			for (int theta = 0; theta < 360; theta++) {
				int id1 = map.get(new Vertex(1, theta));
				to[0].add(id1);
				to[id1].add(0);
				int id2 = map.get(new Vertex(19, theta));
				to[1].add(id2);
				to[id2].add(1);
			}
			for (int r = 1; r < 20; r++) {
				for (int theta = 0; theta < 360; theta++) {
					int id1 = map.get(new Vertex(r, theta));
					int id2 = map.get(new Vertex(r, (theta + 1) % 360));
					to[id1].add(id2);
					to[id2].add(id1);
					if (r == 19) {
						continue;
					}
					id2 = map.get(new Vertex(r + 1, theta));
					to[id1].add(id2);
					to[id2].add(id1);
				}
			}
			int n = in.nextInt();
			for (int test = 0; test < n; test++) {
				if (in.next().charAt(0) == 'C') {
					int r = in.nextInt();
					int theta1 = in.nextInt();
					int theta2 = in.nextInt();
					for (int theta = theta1; theta != theta2; theta = (theta + 1) % 360) {
						int id1 = -1;
						int id2 = -1;
						if (r != 1 && r != 20) {
							id1 = map.get(new Vertex(r - 1, theta));
							id2 = map.get(new Vertex(r, theta));
						} else if (r == 1) {
							id1 = 0;
							id2 = map.get(new Vertex(r, theta));
						} else {
							id1 = map.get(new Vertex(r - 1, theta));
							id2 = 1;
						}
						for (int i = 0; i < to[id1].size(); i++) {
							if (to[id1].get(i) == id2) {
								to[id1].remove(i);
								break;
							}
						}
						for (int i = 0; i < to[id2].size(); i++) {
							if (to[id2].get(i) == id1) {
								to[id2].remove(i);
								break;
							}
						}
					}
				} else {
					int r1 = in.nextInt();
					int r2 = in.nextInt();
					int theta = in.nextInt();
					for (int r = r1; r < r2; r++) {
						int id1 = map.get(new Vertex(r, (theta + 359) % 360));
						int id2 = map.get(new Vertex(r, theta));
						for (int i = 0; i < to[id1].size(); i++) {
							if (to[id1].get(i) == id2) {
								to[id1].remove(i);
								break;
							}
						}
						for (int i = 0; i < to[id2].size(); i++) {
							if (to[id2].get(i) == id1) {
								to[id2].remove(i);
								break;
							}
						}
					}
				}
			}
			used = new boolean[map.size()];
			if (dfs(0)) {
				out.println("YES");
			} else {
				out.println("NO");
			}
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