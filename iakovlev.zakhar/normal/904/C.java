import java.util.*;

import java.io.*;
import java.lang.reflect.Array;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public static class Pair {
		int x;
		int y;

		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public void solve() {
		int n = in.nextInt();
		int[] type = new int[n - 1];
		String[] s = new String[n - 1];
		char ans = 0;
		for (int i = 0; i < s.length; i++) {
			String q = in.next();
			if (q.charAt(0) == '!') {
				type[i] = 2;
			} else if (q.charAt(0) == '.') {
				type[i] = 1;
			} else {
				type[i] = 0;
			}
			s[i] = in.next();
		}
		in.next();
		ans = in.next().charAt(0);
		int sh = 0;
		for (int i = 0; i < s.length; i++) {
			if (type[i] != 1) {
				sh++;
			}
		}
		int can = 0;
		boolean[] l = new boolean[26];
		for (int i = 0; i < l.length; i++) {
			l[i] = true;
		}
		for (int q = 0; q < s.length; q++) {
			if (type[q] == 2) {
				boolean[] b1 = new boolean[26];
				for (int j = 0; j < s[q].length(); j++) {
					b1[s[q].charAt(j) - 'a'] = true;
				}
				for (int j = 0; j < b1.length; j++) {
					l[j] = l[j] && b1[j];
				}
				can++;
			} else if (type[q] == 0) {
				l[s[q].charAt(0) - 'a'] = false;
				can++;
			} else {
				for (int i = 0; i < s[q].length(); i++) {
					l[s[q].charAt(i) - 'a'] = false;
				}
			}
			int count = 0;
			for (int j = 0; j < l.length; j++) {
				if (l[j]) {
					count++;
				}
			}
			if (count == 1) {
				out.print(sh - can);
				return;
			}
		}
		out.print(sh - can);
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
		new C().run();
	}
}