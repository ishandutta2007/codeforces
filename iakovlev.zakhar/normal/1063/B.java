import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;

public class B {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Pair implements Comparable<Pair> {
		int sc;
		int n;

		public Pair(int sc, int n) {
			this.sc = sc;
			this.n = n;
		}

		@Override
		public int compareTo(Pair o) {
			if (sc != o.sc) {
				return o.sc - sc;

			}
			return n - o.n;
		}

	}
	
	public class Vertex implements Comparable<Vertex> {
		int x;
		int y;
		int l;
		int r;
		int d;
		
		public Vertex(int x, int y, int l, int r) {
			this.x = x;
			this.y = y;
			this.l = l;
			this.r = r;
			d = Math.min(l, r);
		}

		@Override
		public int compareTo(Vertex o) {
			int d = Math.min(r, l);
			int od = Math.min(r, l);
			if (d != od) {
				return d - od;
			}
			if (x != o.x) {
				return x - o.x;
			}
			return y - o.y;
		}
	}
	
	public boolean check(int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < m && field[x][y] && !used[x][y];
	}
	
	boolean[][] used;
	boolean[][] field;
	int n;
	int m;

	public void solve() {
		n = in.nextInt();
		m = in.nextInt();
		used = new boolean[n][m];
		field = new boolean[n][m];
		int x = in.nextInt() - 1;
		int y = in.nextInt() - 1;
		int left = in.nextInt();
		int right = in.nextInt();
		for (int i = 0; i < field.length; i++) {
			String s = in.next();
			for (int j = 0; j < m; j++) {
				if (s.charAt(j) == '.') {
					field[i][j] = true;
				}
			}
		}
		Queue<Vertex>[] q = new Queue[2];
		for (int i = 0; i < q.length; i++) {
			q[i] = new ArrayDeque<>();
		}
		q[0].add(new Vertex(x, y, 0, 0));
		while (!q[0].isEmpty() || !q[1].isEmpty()) {
			if (q[0].isEmpty()) {
				while (!q[1].isEmpty()) {
					q[0].add(q[1].poll());
				}
				q[1] = new ArrayDeque<>();
			}
			
			Vertex v = q[0].poll();
//			System.out.println(v.x + " " + v.y + " " + v.d + " " + v.l + " " + v.r);
			if (used[v.x][v.y]) {
				continue;
			}
			used[v.x][v.y] = true;
			if (check(v.x + 1, v.y)) {
				q[0].add(new Vertex(v.x + 1, v.y, v.l, v.r));
			}
			if (check(v.x - 1, v.y)) {
				q[0].add(new Vertex(v.x - 1, v.y, v.l, v.r));
			}
			if (v.l + 1 <= left && check(v.x, v.y - 1)) {
				Vertex v1 = new Vertex(v.x, v.y - 1, v.l + 1, v.r);
				if (v1.d > v.d) {
					q[1].add(v1);
				} else {
					q[0].add(v1);
				}
			}
			if (v.r + 1 <= right && check(v.x, v.y + 1)) {
				Vertex v1 = new Vertex(v.x, v.y + 1, v.l, v.r + 1);
				if (v1.d > v.d) {
					q[1].add(v1);
				} else {
					q[0].add(v1);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < used.length; i++) {
			for (int j = 0; j < used[0].length; j++) {
				if (used[i][j]) {
					ans++;
				}
			}
		}
		out.println(ans);
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