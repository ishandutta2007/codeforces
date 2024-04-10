import java.util.*;

import javax.swing.Painter;

import java.io.*;

public class B {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;
	
	
	public static void quickSort(long[] a, int from, int to) {
		if (to - from <= 1) {
			return;
		}
		int i = from;
		int j = to - 1;
		long x = a[from + (new Random()).nextInt(to - from)];
		while (i <= j) {
			while (a[i] < x) {
				i++;
			}
			while (a[j] > x) {
				j--;
			}
			if (i <= j) {
				long t = a[i];
				a[i] = a[j];
				a[j] = t;
				i++;
				j--;
			}
		}
		quickSort(a, from, j + 1);
		quickSort(a, j + 1, to);
	}
	
	
	public void solve() throws IOException {
		int n = in.nextInt();
		int k = in.nextInt();
		TreeMap<Integer, Integer> map = new TreeMap<>();
		for (int i = 0; i < k; i++) {
			int x = in.nextInt();
			if (map.containsKey(x)) {
				map.put(x, map.get(x) + 1);
			} else {
				map.put(x, 1);
			}
		}
		int four = n;
		int two = 2 * n;
		int one = 0;
		while (!map.isEmpty() && four > 0) {
			int x = map.lastKey();
			if (map.get(x) == 1) {
				map.remove(map.lastKey());
			} else {
				map.put(x, map.get(map.lastKey()) - 1);
			}
			if (x > 4) {
				four--;
				x -= 4;
				if (map.containsKey(x)) {
					map.put(x, map.get(x) + 1);
				} else {
					map.put(x, 1);
				}
			} else if (x > 2) {
				four--;
			} else if (x == 2) {
				four--;
				one++;
			} else if (x == 1) {
				four--;
				two++;
			}
		}
		while (!map.isEmpty() && two > 0) {
			int x = map.lastKey();
			if (map.get(x) == 1) {
				map.remove(map.lastKey());
			} else {
				map.put(x, map.get(map.lastKey()) - 1);
			}
			if (x > 2) {
				x -= 2;
				two--;
				if (map.containsKey(x)) {
					map.put(x, map.get(x) + 1);
				} else {
					map.put(x, 1);
				}
			} else {
				two--;
			}
		}
		while (!map.isEmpty() && one > 0) {
			int x = map.lastKey();
			if (map.get(x) == 1) {
				map.remove(map.lastKey());
			} else {
				map.put(x, map.get(map.lastKey()) - 1);
			}
			one--;
			if (x > 1) {
				x--;
				if (map.containsKey(x)) {
					map.put(x, map.get(x) + 1);
				} else {
					map.put(x, 1);
				}
			}
		}
		if (map.size() == 0) {
			out.println("YES");
		} else {
			out.print("NO");
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