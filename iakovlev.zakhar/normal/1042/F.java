import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class F {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public int dfs(int v, int father) {
		int d = 0;
		if (to[v].length == 1) {
			return 0;
		}
		int n = 0;
		for (int i : to[v]) {
			if (i != father) {
				int x = dfs(i, v) + 1;
				if (x <= 0) {
					continue;
				}
				if (x + d > k) {
					ans++;
					d = Math.min(d, x);
				} else {
					d = Math.max(d, x);
					n++;
				}
			}
		}
		if (n == 0) {
			return -1;
		}
		return d;
	}
	
	public class Info {
		int v;
		int father;
		int d;
		int n;
		int i;
		
		public Info(int v, int father, int d, int n, int i) {
			this.v = v;
			this.father = father;
			this.d = d;
			this.n = n;
			this.i = i;
		}
		
	}
	
	int[][] to;
	int ans = 0;
	int k;
	
	public void solve() {
		int n = in.nextInt();
		k = in.nextInt();
		to = new int[n][];
		int[] x = new int[n - 1];
		int[] y = new int[n - 1];
		int[] sz = new int[n];
		for (int i = 0; i < to.length - 1; i++) {
			x[i] = in.nextInt() - 1;
			y[i] = in.nextInt() - 1;
			sz[x[i]]++;
			sz[y[i]]++;
		}
		for (int i = 0; i < to.length; i++) {
			to[i] = new int[sz[i]];
		}
		int[] free = new int[n];
		for (int i = 0; i < x.length; i++) {
			to[x[i]][free[x[i]]] = y[i];
			free[x[i]]++;
			to[y[i]][free[y[i]]] = x[i];
			free[y[i]]++;
		}
		int root = -1;
		for (int i = 0; i < to.length; i++) {
			if (to[i].length > 1) {
				root = i;
				break;
			}
		}
//		if (dfs(root, -1) >= 0) {
//			ans++;
//		}
//		int[] father = new int[n];
//		int v = root;
//		father[v] = -1;
		Stack<Info> stack = new Stack<>();
		int answer = 0;
		stack.add(new Info(root, -1, 0, 0, -1));
		w :
		while (!stack.isEmpty()) {
			Info inf = stack.pop();
//			System.out.println(answer + " " + inf.v + " " + inf.father + " " + inf.d + " " + inf.n + " " + inf.i + " " + ans + " " + stack.size());
			if (inf.i < 0) {
				if (to[inf.v].length == 1) {
					answer = 0;
					continue;
				}
				for (int i = 0; i < to[inf.v].length; i++) {
					if (to[inf.v][i] != inf.father) {
						stack.add(new Info(inf.v, inf.father, inf.d, inf.n, i));
						stack.add(new Info(to[inf.v][i], inf.v, 0, 0, -1));
						continue w;
					}
				}
			} else {
				int q = answer + 1;
				if (q > 0) {
					if (q + inf.d > k) {
						ans++;
						inf.d = Math.min(inf.d, q);
					} else {
						inf.d = Math.max(inf.d, q);
						inf.n++;
					}
				}
				for (int i = inf.i + 1; i < to[inf.v].length; i++) {
					if (to[inf.v][i] != inf.father) {
						stack.add(new Info(inf.v, inf.father, inf.d, inf.n, i));
						stack.add(new Info(to[inf.v][i], inf.v, 0, 0, -1));
						continue w;
					}
				}
				if (inf.n == 0) {
					answer = -1;
				} else {
					answer = inf.d;
				}
			}
		}
		if (answer >= 0) {
			ans++;
		}
		out.println(ans);
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
		new F().run();
	}
}