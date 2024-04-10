import java.util.*;
import java.io.*;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;
	
	public static class Link {
		int timeUsed;
		int to;

		public Link(int timeUsed, int to) {
			this.timeUsed = timeUsed;
			this.to = to;
		}
		
	}
	
	public void solve() throws IOException {
		int pr = 1000000007;
		int n = in.nextInt();
		int m = in.nextInt();
		long[] fact = new long[m + 1];
		fact[0] = 1;
		for (int i = 1; i < fact.length; i++) {
			fact[i] = fact[i - 1] * i % pr;
		}
		int[] used = new int[m];
		//     
		int[] size = new int[m];
		//    ,     
		for (int i = 0; i < used.length; i++) {
			used[i] = -1;
		}
		int empty = 1;
		// 
		int[] type = new int[m];
		// 
		int[] col = new int[m];
		//-   
		int[] usedCol = new int[m];
		//    
		int[] numberColor = new int[m];
		//-   ,     
		int[] sizeColor = new int[m];
		//   ,   
		int[] usedSizeColor = new int[m];
		//       ,   
		HashMap<Integer, Link>[] hash = new HashMap[m];
		//         
		for (int i = 0; i < hash.length; i++) {
			hash[i] = new HashMap<>();
		}
		for (int i = 0; i < usedCol.length; i++) {
			usedCol[i] = -1;
			usedSizeColor[i] = -1;
		}
		col[0] = m;
		for (int i = 0; i < n; i++) {
			int g = in.nextInt();
			ArrayList<Integer> th = new ArrayList<>();
			for (int j = 0; j < g; j++) {
				int x = in.nextInt() - 1;
				if (used[x] != i) {
					th.add(x);
					used[x] = i;
					size[x] = 1;
					if (usedCol[type[x]] == i) {
						numberColor[type[x]]++;
					} else {
						usedCol[type[x]] = i;
						numberColor[type[x]] = 1;
					}
				} else {
					size[x]++;
				}
			}
			for (int j : th) {
				if (usedSizeColor[type[j]] != i) {
					usedSizeColor[type[j]] = i;
					if (numberColor[type[j]] == col[type[j]]) {
						sizeColor[type[j]] = size[j];
					} else {
						sizeColor[type[j]] = 0;
					}
				}
			}
			for (int j : th) {
				if (size[j] == sizeColor[type[j]]) {
					continue;
				}
				int was = type[j];
				col[was]--;
				if (hash[was].containsKey(size[j])) {
					Link l = hash[was].get(size[j]);
					if (l.timeUsed == i) {
						type[j] = l.to;
					} else {
						type[j] = empty;
						hash[was].put(size[j], new Link(i, empty));
						empty++;
					}
					col[type[j]]++;
				} else {
					type[j] = empty;
					hash[was].put(size[j], new Link(i, empty));
					empty++;
					col[type[j]]++;
				}
			}
		}
		long ans = 1;
		for (int i = 0; i < col.length; i++) {
			ans *= fact[col[i]];
			ans %= pr;
		}
		System.out.println(ans);
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
		new C().run();
	}
}