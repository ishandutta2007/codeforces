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

		int freq[][] = new int[200005][20];

		for(int i = 0; i <= 200004; ++i) {
			for(int j = 0; j < 20; ++j) {
				if(((i >> j) & 1) == 1) {
					freq[i][j] = 1;
				}
			}
		}

		for(int i = 1; i <= 200004; ++i) {
			for(int j = 0; j < 20; ++j) {
				freq[i][j] += freq[i - 1][j];
			}
		}

		int t = sc.nextInt();

		for(int x = 0; x < t; ++x) {
			int l = sc.nextInt();
			int r = sc.nextInt();

			int max_freq = 0;
			for(int i = 0; i < 20; ++i) {
				max_freq = max(max_freq, freq[r][i] - freq[l - 1][i]);
			}

			out.println((r - l + 1) - max_freq);
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