import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main implements Runnable {
	public void solve() {
		FastReader sc = new FastReader();
		PrintWriter out = new PrintWriter(System.out);

		int t = sc.nextInt();

		for(int z = 0; z < t; ++z) {
			int n = sc.nextInt();

			int a[] = new int[n];
			for(int i = 0; i < n; ++i)
				a[i] = sc.nextInt() * 2;

			if(n == 1) {
				out.println("0");
				continue;
			}

			int ans = n;
			double epsilon = 1e-7;
			for(int i = 0; i < n; ++i) {
				for(int j = i + 1; j < n; ++j) {
					int diff = a[j] - a[i]; 
					double reqD = (double)diff / (j - i);
					double startVal = a[i] - i * reqD;
					int cost = 0;
					for(int k = 0; k < n; ++k) {
						if(abs((double)a[k] - startVal) > epsilon)
							cost++;
						startVal += reqD;
					}
					ans = min(ans, cost);
				}
			}

			out.println(ans);
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