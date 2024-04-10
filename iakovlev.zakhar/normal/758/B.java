import java.util.*;
import java.io.*;

public class B {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;
	
	public static class word implements Comparable<word> {
		String s;
		int who;
		public word(String s, int who) {
			super();
			this.s = s;
			this.who = who;
		}
		@Override
		public int compareTo(word o) {
			// TODO Auto-generated method stub
			return s.compareTo(o.s);
		}
		
	}
	
	public void solve() throws IOException {
		String s = in.next();
		int[] ans = new int[4];
		char[] c = new char[4];
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != '!') {
				c[i % 4] = s.charAt(i);
			} else {
				ans[i % 4]++;
			}
		}
		for (int i = 0; i < c.length; i++) {
			if (c[i] == 'R') {
				System.out.print(ans[i] + " ");
			}
		}
		for (int i = 0; i < c.length; i++) {
			if (c[i] == 'B') {
				System.out.print(ans[i] + " ");
			}
		}
		for (int i = 0; i < c.length; i++) {
			if (c[i] == 'Y') {
				System.out.print(ans[i] + " ");
			}
		}
		for (int i = 0; i < c.length; i++) {
			if (c[i] == 'G') {
				System.out.print(ans[i] + " ");
			}
		}
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
		new B().run();
	}
}