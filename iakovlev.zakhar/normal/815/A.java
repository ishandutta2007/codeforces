import java.util.*;
import java.io.*;

public class A {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;
	
	public static void quickSort(int[] a, int from, int to) {
		if (to - from <= 1) {
			return;
		}
		int i = from;
		int j = to - 1;
		int x = a[from + (new Random()).nextInt(to - from)];
		while (i <= j) {
			while (a[i] < x) {
				i++;
			}
			while (a[j] > x) {
				j--;
			}
			if (i <= j) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
				i++;
				j--;
			}
		}
		quickSort(a, from, j + 1);
		quickSort(a, j + 1, to);
	}
	
	public static class Delete {
		boolean row;
		int x;
		public Delete(boolean row, int x) {
			super();
			this.row = row;
			this.x = x;
		}
		
	}
	
	public void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
//		boolean flag = n <= m;
		int[][] a = new int[n][m];
//		if (flag) {
//			a = new int[n][m];
//		} else {
//			a = new int[m][n];
//		}
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[0].length; j++) {
//				if (flag) {
//					a[i][j] = in.nextInt();
//				} else {
//					a[i][j] = in.nextInt();
//				}
				a[i][j] = in.nextInt();
			}
		}
		int[][] b = new int[a.length][a[0].length];
		for (int i = 0; i < b.length; i++) {
			for (int j = 0; j < b[0].length; j++) {
				b[i][j] = a[i][j];
			}
		}
		int min = 10000;
		for (int i = 0; i < a.length; i++) {
			if (a[i][0] < min) {
				min = a[i][0];
			}
		}
		ArrayList<Delete> ans1 = new ArrayList<>();
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i][0] - min; j++) {
				ans1.add(new Delete(true, i + 1));
			}
			for (int j = 1; j < a[0].length; j++) {
				a[i][j] -= a[i][0] - min;
			}
			a[i][0] = min;
		}
		for (int j = 0; j < a[0].length; j++) {
			for (int i = 0; i < a.length; i++) {
				if (a[i][j] != a[0][j]) {
					System.out.println(-1);
					return;
				}
			}
			if (a[0][j] < 0) {
				System.out.println(-1);
				return;
			}
			for (int i = 0; i < a[0][j]; i++) {
				ans1.add(new Delete(false, j + 1));
			}
		}
		int min1 = 10000;
		for (int i = 0; i < b[0].length; i++) {
			if (b[0][i] < min1) {
				min1 = b[0][i];
			}
		}
		ArrayList<Delete> ans2 = new ArrayList<>();
		for (int i = 0; i < b[0].length; i++) {
			for (int j = 0; j < b[0][i] - min1; j++) {
				ans2.add(new Delete(false, i + 1));
			}
			for (int j = 1; j < b.length; j++) {
				b[j][i] -= b[0][i] - min1;
			}
			b[0][i] = min1;
		}
		for (int j = 0; j < b.length; j++) {
			for (int i = 0; i < b[0].length; i++) {
				if (b[j][i] != b[j][0]) {
					System.out.println(-1);
					return;
				}
			}
			if (b[j][0] < 0) {
				System.out.println(-1);
				return;
			}
			for (int i = 0; i < b[j][0]; i++) {
				ans2.add(new Delete(true, j + 1));
			}
		}
		if (ans1.size() < ans2.size()) {
			out.println(ans1.size());
			for (Delete i : ans1) {
				if (!i.row) {
					out.println("col " + i.x);
				} else {
					out.println("row " + i.x);
				}
			}
		} else {
			out.println(ans2.size());
			for (Delete i : ans2) {
				if (!i.row) {
					out.println("col " + i.x);
				} else {
					out.println("row " + i.x);
				}
			}
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
	public static void main(String[] args) {
		new A().run();
	}
}