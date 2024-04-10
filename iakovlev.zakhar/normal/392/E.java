import java.util.*;
import java.io.*;

public class Main {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	int mod = 1000000007;

	public int sum(int x, int y) {
		if (x + y >= mod) {
			return x + y - mod;
		}
		return x + y;
	}

	public int diff(int x, int y) {
		if (x < y) {
			return x + mod - y;
		}
		return x - y;
	}

	public int mult(int x, int y) {
		return (int) (x * 1L * y % mod);
	}

	public int pow(int x, long p) {
		int ans = 1;
		while (p > 0) {
			if ((p & 1) == 1) {
				ans = mult(ans, x);
			}
			x = mult(x, x);
			p >>= 1;
		}
		return ans;
	}

	public int inv(int x) {
		return pow(x, mod - 2);
	}

	public long gcd(long x, long y) {
		while (y > 0) {
			long c = y;
			y = x % y;
			x = c;
		}
		return x;
	}

	public double sum(double x, double y) {
		return x + y;
	}

	public double diff(double x, double y) {
		return x - y;
	}

	public double mult(double x, double y) {
		return x * y;
	}

	public double inv(double x) {
		return 1 / x;
	}

	public int[][] readGraph(int n, int m) {
		for (int i = 0; i < n; i++) {
			sz[i] = 0;
		}
		int[] x = new int[m];
		int[] y = new int[m];
		for (int i = 0; i < m; i++) {
			x[i] = in.nextInt() - 1;
			y[i] = in.nextInt() - 1;
//			x[i] = i + 1;
//			y[i] = i;
			sz[x[i]]++;
		}
		for (int i = 0; i < n; i++) {
			to[i] = new int[sz[i]];
			sz[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			to[x[i]][sz[x[i]]++] = y[i];
		}
		return to;
	}

	int MAX = 500000;

	int[][] to = new int[MAX][];
	int[] sz = new int[MAX];

	public int gcd(int x, int y) {
		while (y > 0) {
			int c = y;
			y = x % y;
			x = c;
		}
		return x;
	}

	public int[][][] pref(long[] a) {
		int n = a.length;
		int[][] pref2 = new int[n][2];
		int[][] pref1 = new int[n][2];
		int[][] pref0 = new int[n][2];
		int[][] prefLose = new int[n][2];
//		for (int m1 = 0; m1 < 2; m1++) {
//			for (int m2 = 0; m2 < 2; m2++) {
//				if ((m1 + 1) * a[0] > (m2 + 1) * a[1]) {
//					pref0[1][m2] = sum(pref0[1][m2], mult(inv2, inv2));
//					pref1[1][m2] = sum(pref1[1][m2], mult(inv2, inv2));
//					pref2[1][m2] = sum(pref2[1][m2], mult(inv2, inv2));
//				}
//			}
//		}
//		System.out.println(pref0[1][0] + " " + pref1[1][0] + " " + pref2[1][0]);
//		System.out.println(pref0[1][1] + " " + pref1[1][1] + " " + pref2[1][1]);
		prefLose[0][0] = inv2;
		prefLose[0][1] = inv2;
		for (int i = 1; i < pref0.length; i++) {
			for (int m1 = 0; m1 < 2; m1++) {
				for (int m2 = 0; m2 < 2; m2++) {
					if ((m1 + 1) * a[i - 1] > (m2 + 1) * a[i]) {
						pref2[i][m2] = sum(pref2[i][m2],
								mult(inv2, sum(sum(pref0[i - 1][m1], mult(2, pref1[i - 1][m1])),
										sum(pref2[i - 1][m1], prefLose[i - 1][m1]))));
						pref1[i][m2] = sum(pref1[i][m2],
								mult(inv2, sum(sum(pref0[i - 1][m1], pref1[i - 1][m1]), prefLose[i - 1][m1])));
						pref0[i][m2] = sum(pref0[i][m2], mult(inv2, sum(pref0[i - 1][m1], prefLose[i - 1][m1])));
					} else {
						prefLose[i][m2] = sum(prefLose[i][m2], mult(inv2, inv2));
					}
				}
			}
		}
		int[][][] ans = { pref0, pref1, pref2 };
		return ans;
	}

	Random random = new Random(566);

	int inv2 = inv(2);

	public int id(int x, int y, int n, int m) {
		return x * m + y;
	}

	public class State implements Comparable<State> {
		int mask;
		int x;
		int y;
		int len;
		int number;

		public State(int mask, int x, int y, int len, int number) {
			this.mask = mask;
			this.x = x;
			this.y = y;
			this.len = len;
			this.number = number;
		}

		@Override
		public int compareTo(State o) {
			if (len != o.len) {
				return len - o.len;
			}
			if (mask != o.mask) {
				return mask - o.mask;
			}
			if (x != o.x) {
				return x - o.x;
			}
			return y - o.y;
		}
	}

	public int ans(int n, int m) {
		TreeSet<State> set = new TreeSet<>();
		State last = new State(0, 0, 0, 0, 1);
		set.add(last);
		while (!set.isEmpty()) {
			State cur = set.pollFirst();
			if (cur.mask == (1 << n * m) - 1 && cur.x == 0 && cur.y == 0) {
				return cur.number;
			}
			last = cur;
			int x = cur.x;
			int y = cur.y;
			int mask = cur.mask;
			int x1 = (x + 1) % n;
			int y1 = y;
			int id1 = id(x1, y1, n, m);
			if (((mask >> id1) & 1) == 0) {
				int mask1 = mask + (1 << id1);
				State next = new State(mask1, x1, y1, cur.len + 1, cur.number);
				State st = set.ceiling(next);
				if (st == null || st.compareTo(next) != 0) {
					set.add(next);
				} else {
					st.number += cur.number;
				}
			}
			x1 = x;
			y1 = (y + 1) % m;
			id1 = id(x1, y1, n, m);
			if (((mask >> id1) & 1) == 0) {
				int mask1 = mask + (1 << id1);
				State next = new State(mask1, x1, y1, cur.len + 1, cur.number);
				State st = set.ceiling(next);
				if (st == null || st.compareTo(next) != 0) {
					set.add(next);
				} else {
					st.number += cur.number;
				}
			}
		}
		return 0;
	}

	public class Edge implements Comparable<Edge> {
		int d;
		int to;

		public Edge(int d, int to) {
			this.d = d;
			this.to = to;
		}

		@Override
		public int compareTo(Edge o) {
			if (d != o.d) {
				return d - o.d;
			}
			return to - o.to;
		}
	}

	public int[] dijkstra(ArrayList<Edge>[] g, int s) {
		int[] dist = new int[g.length];
		boolean[] used = new boolean[g.length];
		for (int i = 0; i < g.length; i += 1) {
			dist[i] = 1000000000;
		}
		dist[s] = 0;
		TreeSet<Edge> map = new TreeSet<>();
		map.add(new Edge(0, s));
		for (int i = 0; i < used.length; i += 1) {
			if (map.isEmpty()) {
				break;
			}
			Edge key = map.first();
			while (used[key.to]) {
				map.remove(key);
				if (map.isEmpty()) {
					break;
				}
				key = map.first();
			}
			if (map.isEmpty()) {
				break;
			}
			map.remove(key);
			int id = key.to;
			used[id] = true;
			for (int j = 0; j < g[id].size(); j += 1) {
				if (dist[g[id].get(j).to] > dist[id] + g[id].get(j).d) {
					dist[g[id].get(j).to] = dist[id] + g[id].get(j).d;
					Edge e = new Edge(dist[g[id].get(j).to], g[id].get(j).to);
					map.add(e);
				}
			}
		}

		return dist;
	}

//	public String my(String input) {
//		StringTokenizer lines = new StringTokenizer(input, "\n");
//	    StringTokenizer tokens = new StringTokenizer(lines.nextToken());
//	    int n = Integer.parseInt(tokens.nextToken());
//	    int t = Integer.parseInt(tokens.nextToken());
//	    int q = Integer.parseInt(tokens.nextToken()));
//	    
//	    StringBuilder res = new StringBuilder("");
//	    while (n != 0) {
//	    	int[] x = new int[n];
//	    	tokens = new StringTokenizer(lines.nextToken());
//	    	
//	    	let x = [from x in lines[curLine].split(" ") select int(x)];
//	        curLine += 1;
//	        let pref = [0];
//	        for (let i = 0; i < n; i += 1) {
//	            pref.push(pref[i] ^ x[i]);
//	        }
//	        
//	        let map : {int : bool} = {};
//	        for (let i = 0; i < t; i += 1) {
//	            tokens = [from y in lines[curLine].split(" ") select int(y)];
//	            let l = tokens[0] - 1;
//	            let r = tokens[1];
//	            curLine += 1;
//	            map[pref[r] ^ pref[l]] = true;
//	        }
//	        
//	        for (let i = 0; i < q; i += 1) {
//	            if (map.contains(int(lines[curLine]))) {
//	                res += "N\n";
//	            } else {
//	                res += "Y\n";
//	            }
//	            curLine += 1;
//	        }
//	        
//	        tokens = [from y in lines[curLine].split(" ") select int(y)];
//	        n = tokens[0];
//	        t = tokens[1];
//	        q = tokens[2];
//	        curLine += 1;
//	    }
//	    return res + "-\n";
//	}

//	public void solve() {
//		StringBuilder sb = new StringBuilder();
//		String s = in.nextLine();
//		while (s != null && !s.equals("")) {
//			sb.append(s + "\n");
//			s = in.nextLine();
//		}
//		out.println(my(sb.toString()));
//	}

	public double calc(int[] x, double x0) {
		double ans = 0;
		for (int i = 0; i < x.length; i++) {
			ans += (x0 - x[i]) * (x0 - x[i]);
		}
		return ans;
	}

	public int get(int[] v, int len) {
		if (len > v.length) {
			return Integer.MIN_VALUE / 4;
		}
		return v[len];
	}

	public void solve() throws IOException {
		int n = in.nextInt();
		int[] v = new int[n + 1];
		for (int i = 1; i < v.length; i++) {
			v[i] = in.nextInt();
		}
		int[] w = new int[n];
		for (int i = 0; i < w.length; i++) {
			w[i] = in.nextInt();
		}
		for (int i = 0; i < v.length; i++) {
			for (int j = 0; j < i; j++) {
				if (v[j] + v[i - j] > v[i]) {
					v[i] = v[j] + v[i - j];
				}
			}
		}
		int[][] dpMon = new int[n][n];
		int[][] dpAll = new int[n][n];
		int[][] dp = new int[n][n];
		for (int i = 0; i < dpMon.length; i++) {
			for (int j = 0; j < n; j++) {
				dpMon[i][j] = Integer.MIN_VALUE / 4;
				dpAll[i][j] = Integer.MIN_VALUE / 4;
			}
		}
		for (int len = 0; len < n; len++) {
			for (int l = 0; l + len < n; l++) {
				int r = l + len;
				if (l == r) {
					dpMon[l][r] = 0;
					dpAll[l][r] = v[1];
					if (r > 0) {
						dpAll[l][r - 1] = 0;
					}
				}
				for (int j = l; j < r; j++) {
					dpAll[l][r] = Math.max(dpAll[l][r], dpAll[l][j] + dpAll[j + 1][r]);
				}
				if (w[l] != w[r]) {
					if (Math.abs(w[r] - w[l]) == 1) {
						dpMon[l][r] = Math.max(dpMon[l][r], dpAll[l + 1][r - 1]);
					}
					for (int j = l + 1; j < r; j++) {
						if ((w[l] < w[j] && w[j] < w[r]) || (w[l] > w[j] && w[j] > w[r])) {
							dpMon[l][r] = Math.max(dpMon[l][r], dpMon[l][j] + dpMon[j][r]);
						}
					}
				}
				for (int j = l; j <= r; j++) {
					if (w[j] >= w[l] && w[j] >= w[r]) {
						int length = Math.abs(w[l] - w[j]) + Math.abs(w[j] - w[r]) + 1;
						dpAll[l][r] = Math.max(dpAll[l][r],
								dpMon[l][j] + dpMon[j][r] + get(v, Math.abs(w[l] - w[j]) + Math.abs(w[j] - w[r]) + 1));
//						if (length <= n && length > 0) {
//							System.out.println(l + " " + j + " " + r + " " + length + " " + dpMon[l][j] + " " + dpMon[j][r] + " " + dpAll[l][r]);
//						}
					}
				}
				dp[l][r] = Math.max(dp[l][r], dpAll[l][r]);
				for (int j = l; j < r; j++) {
					dp[l][r] = Math.max(dp[l][r], dp[l][j] + dp[j + 1][r]);
				}
			}
		}
		out.println(dp[0][n - 1]);
	}

	public String precision(double ans) {
		StringBuilder result = new StringBuilder();
		ans += 0.0005;
		result.append((int) (ans));
		result.append(".");
		double rem = ans - (int) (ans);
		for (int prec = 0; prec < 3; prec += 1) {
			rem *= 10;
			result.append((int) (rem));
			rem = rem - (int) (rem);
		}
		return result.toString();
	}

	public void run() {
		try {
			if (systemIO) {
				in = new FastScanner(System.in);
				out = new PrintWriter(System.out);
			} else {
				String fileName = "input";
				in = new FastScanner(new File(fileName + ".txt"));
				out = new PrintWriter(new File(fileName + ".out"));
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
			int ans = 0;
			String s = next();
			if (s.charAt(0) == '-') {
				for (int i = 1; i < s.length(); ++i) {
					ans = 10 * ans + (s.charAt(i) - '0');
				}
				return -ans;
			}
			for (int i = 0; i < s.length(); ++i) {
				ans = 10 * ans + (s.charAt(i) - '0');
			}
			return ans;
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
		long time = System.currentTimeMillis();
		new Main().run();
//		System.err.println(System.currentTimeMillis() - time);
	}
}