import java.util.*;
import java.io.*;

public class A {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	

	public void solve() {
		int n = in.nextInt();
		String s = in.next();
		ArrayList<Character> list = new ArrayList<>();
		int c = 0;
		int c1 = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != 'o' && s.charAt(i) != 'g') {
				if (c == 1) {
					list.add('o');
				} else if (c == 2) {
					list.add('o');
					list.add('g');
				} else if (c == 3) {
					list.add('*');
					list.add('*');
					list.add('*');
					if (c1 == 1) {
						list.add('g');
					}
				}
				list.add(s.charAt(i));
				c = 0;
				c1 = 0;
			} else if (s.charAt(i) == 'o') {
				if (c == 0) {
					c++;
				} else if (c == 1) {
					list.add('o');
				} else if (c == 2) {
					c = 3;
				} else if (c == 3) {
					if (c1 == 1) {
						c1 = 0;
					} else {
						for (int j = 0; j < 3; j++) {
							list.add('*');
						}
						c = 1;
						c1 = 0;
					}
				}
			} else {
				if (c == 0) {
					list.add('g');
				} else if (c == 1) {
					c++;
				} else if (c == 2) {
					c = 0;
					list.add('o');
					list.add('g');
					list.add('g');
				} else {
					if (c1 == 0) {
						c1++;
					} else {
						for (int j = 0; j < 3; j++) {
							list.add('*');
						}
						list.add('g');
						list.add('g');
						c = 0;
						c1 = 0;
					}
				}
			}
		}
		if (c == 0) {
			
		} else if (c == 1) {
			list.add('o');
		} else if (c == 2) {
			list.add('o');
			list.add('g');
		} else if (c == 3) {
			for (int j = 0; j < 3; j++) {
				list.add('*');
			}
			if (c1 == 1) {
				list.add('g');
			}
		}
		for (int j = 0; j < list.size(); j++) {
			out.print(list.get(j));
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
	public static void main(String[] args) {
		new A().run();
	}
}