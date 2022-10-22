import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class D {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;
	
	public class Segment {
		int val;
		int x;
		int y;

		public Segment(int val, int x, int y) {
			this.val = val;
			this.x = x;
			this.y = y;
		}
	}
	
	public void solve() {
		int n = in.nextInt();
		int q = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = in.nextInt();
		}
		int[] x = new int[q + 1];
		for (int i = 0; i < x.length; i++) {
			x[i] = n;
		}
		int[] y = new int[q + 1];
		for (int i = 0; i < a.length; i++) {
			x[a[i]] = Math.min(x[a[i]], i);
			y[a[i]] = i;
		}
		for (int i = 0; i < y.length; i++) {
			y[i] = Math.max(y[i], x[i]);
		}
		Segment[] ans = new Segment[q + 1];
		boolean flag = true;
		if (x[0] == n) {
			flag = false;
			if (x[q] == n) {
				out.println("NO");
				return;
			}
		}
		ans[1] = new Segment(1, 0, n - 1);
		for (int i = 2; i < ans.length; i++) {
			if (x[i] == n) {
				if (flag) {
					ans[i] = new Segment(i, x[0], x[0]);
				} else {
					ans[i] = new Segment(i, x[q], x[q]);
				}
			} else {
				ans[i] = new Segment(i, x[i], y[i]);
			}
		}
		int[] answer = new int[n];
		TreeSet<Integer> set = new TreeSet<>();
		for (int i = 0; i < answer.length; i++) {
			set.add(i);
		}
		for (int i = q; i > 0; i--) {
			int b = ans[i].x;
			int e = ans[i].y;
//			System.out.println(ans[i].val + " " + b + " " + e);
			while (set.higher(b - 1) != null && set.higher(b - 1) <= e) {
				answer[set.higher(b - 1)] = i;
				set.remove(set.higher(b - 1));
			}
		}
		for (int i = 0; i < answer.length; i++) {
			if (a[i] != 0 && a[i] != answer[i]) {
				out.println("NO");
				return;
			}
		}
		out.println("YES");
		for (int i = 0; i < answer.length; i++) {
			out.print(answer[i] + " ");
		}
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
		new D().run();
	}
}