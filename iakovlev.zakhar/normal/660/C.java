import java.util.*;
import java.io.*;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	

	public void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = in.nextInt();
		}
		if (k == 0) {
			int ans = 0;
			int aNS = 0;
			for (int i = 0; i < a.length; i++) {
				if (a[i] == 0) {
					aNS = Math.max(aNS, ans);
					ans = 0;
				} else {
					ans++;
				}
			}
			aNS = Math.max(ans, aNS);
			out.println(aNS);
			for (int i = 0; i < a.length; i++) {
				out.print(a[i] + " ");
			}
			out.close();
			return;
		}
		int kThis = 0;
		int beginThis = 0;
		int lastThis = 0;
		while (kThis < k && lastThis < n) {
			if (a[lastThis] == 1) {
				lastThis++;
			} else {
				kThis++;
				lastThis++;
			}
		}
		while (lastThis < n && a[lastThis] == 1) {
			lastThis++;
		}
		lastThis--;
		int beginAns = 0;
		int endAns = lastThis;
		int fAns = lastThis + 1;
		int fThis = fAns;
		lastThis++;
		while (lastThis < n && beginThis < n) {
			if (a[beginThis] == 1) {
				beginThis++;
			} else {
				kThis--;
				beginThis++;
				while (kThis < k && lastThis < n) {
					if (a[lastThis] == 0) {
						kThis++;
					}
					lastThis++;
				}
				while (lastThis < n && a[lastThis] == 1) {
					lastThis++;
				}
			}
			lastThis --;
			fThis = lastThis - beginThis + 1;
			if (fThis > fAns) {
				fAns = fThis;
				endAns = lastThis;
				beginAns = beginThis;	
			}
			lastThis++;
		}
		out.println(fAns);
		int i = 0;
		while (i < beginAns) {
			out.print(a[i] + " ");
			i++;
		}
		while (i <= endAns) {
			out.print(1 + " ");
			i++;
		}
		while (i < n) {
			out.print(a[i] + " ");
			i++;
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