import java.util.*;
import java.io.*;

public class E {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

//	public static class Nout {
//		int p;
//		int number;
//		
//		public Nout(int p, int number) {
//			
//		}
//	}
	
	
	public void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		HashMap<Integer, ArrayList<Integer>> h = new HashMap<>();
		for (int i = 0; i < n; i++) {
			int p = in.nextInt();
			if (h.containsKey(p)) {
				ArrayList<Integer> a = h.get(p);
				a.add(i);
				h.put(p, a);
			} else {
				ArrayList<Integer> a = new ArrayList<>();
				a.add(i);
				h.put(p, a);
			}
		}
		int[] s = new int[m];
		boolean[] used = new boolean[m];
		for (int i = 0; i < m; i++) {
			s[i] = in.nextInt();
		}
		int c = 0;
		int u = 0;
		int[] a = new int[m];
		int[] b = new int[n];
		for (int i = 0; i < 32; i++) {
			for (int j = 0; j < s.length; j++) {
				if (used[j]) {
					continue;
				}
				if (h.containsKey(s[j])) {
					ArrayList<Integer> list = h.get(s[j]);
					int x = list.get(list.size() - 1);
					list.remove(list.size() - 1);
					if (list.size() == 0) {
						h.remove(s[j]);
					}
					b[x] = j + 1;
					used[j] = true;
					c++;
					a[j] = i;
					u += i;
				}
				s[j] = (s[j] + 1) / 2;
			}
		}
		out.println(c + " " + u);
		for (int i = 0; i < a.length; i++) {
			out.print(a[i] + " ");
		}
		out.println();
		for (int i = 0; i < b.length; i++) {
			out.print(b[i] + " ");
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
		new E().run();
	}
}