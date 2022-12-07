import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main implements Runnable {
	long gcd(long a, long b) {
		if(b == 0)
			return a;
		return gcd(b, a % b);
	}
	String reverse(String a) {
		char[] ans = new char[a.length()];
		for(int i = 0; i < a.length(); ++i) {
			ans[a.length() - 1 - i] = a.charAt(i); 
		}
		return new String(ans);
	}
	public void solve() {
		FastReader sc = new FastReader();
		PrintWriter out = new PrintWriter(System.out);

		int t = sc.nextInt();

		for(int x = 0; x < t; ++x) {
			int n = sc.nextInt();

			long h = sc.nextLong();

			long a[] = new long[n];
			for(int i = 0; i < n; ++i)
				a[i] = sc.nextLong();



			long start = 1, end = (long)1e18, ans = (long)1e18;

			while(start <= end) {
				long mid = (start + end) >> 1;

				long req = h;
				long cur = a[0] + mid;
				req -= mid;

				for(int i = 1; i < n && req > 0; ++i) {
					long ccur = a[i] + mid;
					long dmg = ccur - max(a[i], cur);
					cur = a[i] + mid;
					req -= dmg;
				}

				if(req <= 0) {
					ans = mid;
					end = mid - 1;
				} else {
					start = mid + 1;
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