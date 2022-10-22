import java.util.*;
import java.io.*;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Pair {
		int type;
		int number;
		
		public Pair(int type, int number) {
			// TODO Auto-generated constructor stub
			this.number = number;
			this.type = type;
		}
	}

	public void solve() {
		int n = in.nextInt();
		TreeMap<Integer, Integer> tree = new TreeMap<>();
		ArrayList<Pair> a = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			String s = in.next();
			if (s.charAt(0) == 'i') {
				int x = in.nextInt();
				if (tree.containsKey(x)) {
					tree.put(x, tree.get(x) + 1);
				} else {
					tree.put(x, 1);
				}
				a.add(new Pair(1, x));
			} else if (s.charAt(0) == 'r') {
				if (tree.size() == 0) {
					a.add(new Pair(1, 0));
				} else {
					if (tree.get(tree.firstKey()) == 1) {
						tree.remove(tree.firstKey());
					} else {
						tree.put(tree.firstKey(), tree.get(tree.firstKey()) - 1);
					}
				}
				a.add(new Pair(2, 0));
			} else {
				int x = in.nextInt();
				if (tree.size() == 0) {
					a.add(new Pair(1, x));
					tree.put(x, 1);
					a.add(new Pair(3, x));
				} else {
					if (tree.firstKey() == x) {
						a.add(new Pair(3, x));
					} else if (tree.firstKey() > x) {
						a.add(new Pair(1, x));
						tree.put(x, 1);
						a.add(new Pair(3, x));
					} else {
						while (tree.size() > 0 && tree.firstKey() < x) {
							a.add(new Pair(2, 0));
							if (tree.get(tree.firstKey()) == 1) {
								tree.remove(tree.firstKey());
							} else {
								tree.put(tree.firstKey(), tree.get(tree.firstKey()) - 1);
							}
						}
						if (tree.size() == 0) {
							a.add(new Pair(1, x));
							tree.put(x, 1);
							a.add(new Pair(3, x));
						} else if (tree.firstKey() == x) {
							a.add(new Pair(3, x));
						} else {
							a.add(new Pair(1, x));
							tree.put(x, 1);
							a.add(new Pair(3, x));
						}
					}
				}
			}
		}
		out.println(a.size());
		for (int i = 0; i < a.size(); i++) {
			if (a.get(i).type == 1) {
				out.println("insert " + a.get(i).number);
			} else if (a.get(i).type == 2) {
				out.println("removeMin");
			} else {
				out.println("getMin " + a.get(i).number);
			}
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
		new C().run();
	}
}