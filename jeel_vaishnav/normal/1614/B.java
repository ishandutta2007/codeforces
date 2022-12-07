import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main implements Runnable {
	class Pair {
		int index;
		long val;
		Pair(int a, int b) {
			index = a;
			val = b;
		}
	}
	public void solve() {
		FastReader sc = new FastReader();
		PrintWriter out = new PrintWriter(System.out);

		int t = sc.nextInt();

		for(int x = 0; x < t; ++x) {
			int n = sc.nextInt();

			Pair pair[] = new Pair[n];
			for(int i = 0; i < n; ++i) {
				pair[i] = new Pair(i + 1, sc.nextInt());
			}

			Arrays.sort(pair, new Comparator<Pair>() {
				public int compare(Pair p1, Pair p2) {
					if(p1.val < p2.val)
						return 1;
					if(p1.val > p2.val)
						return -1;
					return 0;
				}
			});

			int flag = 0;
			int val = 1;
			int ans[] = new int[n + 1];
			long cost = 0;
			for(int i = 0; i < n; ++i) {
				cost += pair[i].val * val;
				if(flag == 0) {
					ans[pair[i].index] = val;
					flag = 1;
				} else {
					ans[pair[i].index] = -val;
					flag = 0;
					val++;
				}
			}

			out.println(2 * cost);
			for(int i = 0; i <= n; ++i) {
				out.print(ans[i] + " ");
			}
			out.println();
		}
		
		out.close();
	}
	public static void main(String[] args) {
		new Thread(null, new Main(), "Main", 1 << 26).start();	
	}

	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while(st == null || !st.hasMoreElements()) {
				try {
					String str = br.readLine();

					if(str == null)
						throw new InputMismatchException();

					st = new StringTokenizer(str);
				} catch(IOException e) {
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

		String nextLine() {
			String str = "";

			try {
				str = br.readLine();
			} catch(IOException e) {
				e.printStackTrace();
			}

			if(str == null) 
				throw new InputMismatchException();
			return str;
		}
	}

	public void run() {
		solve();
	}
}