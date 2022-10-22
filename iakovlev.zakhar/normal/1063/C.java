import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

//	public int dfs(int v, int father) {
//		int d = 0;
//		if (to[v].length == 1) {
//			return 0;
//		}
//		int n = 0;
//		for (int i : to[v]) {
//			if (i != father) {
//				int x = dfs(i, v) + 1;
//				if (x <= 0) {
//					continue;
//				}
//				if (x + d > k) {
//					ans++;
//					d = Math.min(d, x);
//				} else {
//					d = Math.max(d, x);
//					n++;
//				}
//			}
//		}
//		if (n == 0) {
//			return -1;
//		}
//		return d;
//	}
//	
//	public class Info {
//		int v;
//		int father;
//		int d;
//		int n;
//		int i;
//		
//		public Info(int v, int father, int d, int n, int i) {
//			this.v = v;
//			this.father = father;
//			this.d = d;
//			this.n = n;
//			this.i = i;
//		}
//		
//	}

//	public class Info {
//		long sum;
//		ArrayList<Long> 
//	}

	public class Pair {
		int v;
		int i;

		public Pair(int v, int i) {
			this.v = v;
			this.i = i;
		}
	}

	public void solve() {
		int n = in.nextInt();
		System.out.println("0 0");
		String s = in.next();
		n--;
		int y0 = 1;
		int y1 = 1 << 28;
		int d = y1 / 2;
		while (n > 0) {
			System.out.println("0 " + (y0 + 1));
			n--;
			if (in.next().equals(s)) {
				y0 += 2;
			} else {
				break;
			}
		}
		while (n > 0) {
			System.out.println("1 " + y1);
			n--;
			if (s.equals(in.next())) {
				y1 += d;
			} else {
				y1 -= d;
			}
			d /= 2;
		}
		System.out.println("0 " + y0 + " 1 " + y1);
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
		new C().run();
	}
}