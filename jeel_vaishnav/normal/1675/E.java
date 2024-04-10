import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main implements Runnable {
	int findSet(int i) {
		if(par[i] == i)
			return i;
		par[i] = findSet(par[i]);
		return par[i];
	}
	boolean union(int i, int j) {
		i = findSet(i);
		j = findSet(j);

		if(i == j)
			return false;

		if(i < j)
			par[j] = i;
		else
			par[i] = j;
		return true;
	}
	int par[];
	public void solve() {
		FastReader sc = new FastReader();
		PrintWriter out = new PrintWriter(System.out);

		int t = sc.nextInt();

		for(int x = 0; x < t; ++x) {
			int n = sc.nextInt();
			int k = sc.nextInt();

			String s = sc.next();

			par = new int[26];
			for(int i = 0; i < 26; ++i) {
				par[i] = i;
			}

			for(int i = 0; i < s.length(); ++i) {
				if(findSet((int)(s.charAt(i) - 'a')) != 0) {
					for(int j = (int)(s.charAt(i) - 'a'); j > 0; --j) {
						if(findSet(j) != findSet(j - 1) && k > 0) {
							k--;
							union(j, j - 1);
						}
					}
				}
			}

			for(int i = 0; i < s.length(); ++i) {
				out.print((char)('a' + findSet((int)(s.charAt(i) - 'a'))));
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