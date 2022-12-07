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

		int q = sc.nextInt();

		for(int z = 0; z < q; ++z) {
			int n = sc.nextInt();	
			int k = sc.nextInt();

			long a[] = new long[n];
			for(int i = 0; i < n; ++i)
				a[i] = sc.nextInt();

			long sum = 0;
			for(int i = 0; i < n; ++i) {
				sum += a[i];
			}

			if(sum % 2 != k % 2) {
				out.println("NO");
			} else {
				ArrayList<Integer> indices = new ArrayList<>();
				long curSum = 0;
				for(int i = 0; i < n; ++i) {
					curSum += a[i];
					if(curSum % 2 == 1) {
						indices.add(i);
						curSum = 0;
					}
				}

				if(indices.size() >= k) {
					out.println("YES");
					for(int i = 0; i < k - 1; ++i) {
						out.print((indices.get(i) + 1) + " ");
					}
					out.print(n);
					out.println();
				} else {
					out.println("NO");
				}
			}
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