import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public long number(String s, int allowed, boolean flag) {
		if (s.length() == 0) {
			return 1;
		}
		if (allowed == 0) {
			return 1;
		}
		long ans = 0;
		if (!flag) {
			if (s.charAt(0) != '0') {
				for (int i = 0; i <= allowed; i++) {
					ans += numb[s.length() - 1][i];
				}
			} else {
				return number(s.substring(1), allowed, false);
			}
		}
		for (int i = 1; i <= allowed; i++) {
			ans += (s.charAt(0) - '1') * numb[s.length() - 1][i - 1];
		}
		allowed--;
		return ans + number(s.substring(1), allowed, false);
	}

	long[][] numb = new long[19][4];

	public void solve() {
		int q = in.nextInt();
		numb[0][0] = 1;
		for (int i = 1; i < numb.length; i++) {
			numb[i][0] = 1;
			numb[i][1] = 9 * i;
			numb[i][2] = 9 * 9L * i * (i - 1) / 2;
			numb[i][3] = 9L * 9 * 9 * (i - 1) * (i - 2) * (i - 3) / 6;
		}
		for (int t = 0; t < q; t++) {
			long l = in.nextLong();
			long r = in.nextLong();
			int lenl = (l + "").length();
			int lenr = (r + "").length();
			long ans = 0;
			for (int i = lenl; i < lenr; i++) {
				ans += (numb[i - 1][2] + numb[i - 1][1] + numb[i - 1][0]) * 9;
			}
			String sl = l + "";
			String sr = r + "";
			int th = 0;
			for (int i = 0; i < sl.length(); i++) {
				if (sl.charAt(i) != '0') {
					th++;
				}
			}
			if (th <= 3) {
				ans++;
			}
//			System.out.println(ans + " " + number(sr, 3, true) + " " + number(sl, 3, true));
			ans += number(sr, 3, true) - number(sl, 3, true);
			out.println(ans);
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