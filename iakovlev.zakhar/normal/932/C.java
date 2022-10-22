import java.util.*;

import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Di {
		long x;
		long y;
		long g;
		
		public Di(long x, long y, long g) {
			this.x = x;
			this.y = y;
			this.g = g;
		}
	}
	
	public Di gcd(long a, long b) {
		if (a == 0) {
			return new Di(0, 1, b);
		}
		Di di = gcd(b % a, a);
		return new Di(di.y - (b / a) * di.x, di.x, di.g);
	}
	
	public void solve() {
		long n = in.nextInt();
		long a = in.nextInt();
		long b = in.nextInt();
		Di di = gcd(a, b);
		if (n % di.g != 0) {
			out.println(-1);
			return;
		}
		long x = di.x * (n / di.g);
		long y = di.y * (n / di.g);
		long dx = b / di.g;
		long dy = a / di.g;
		long nok = a * b / di.g;
		long l1 = - x;
		long r1 = -x + n / nok;
		long l2 = y;
		long r2 = y - (n / nok);
		long k = 0;
		if (x >= 0) {
			l1 = - (a * x / nok);
		} else {
			l1 = (- a * x + nok - 1) / nok;
		}
		if (y >= 0) {
			r2 = (b * y / nok);
		} else {
			r2 = - ((- b * y + nok - 1) / nok);
		}
		if (a * x >= n - nok + 1) {
			r1 = - (a * x - n + nok - 1) / nok;
		} else {
			r1 = (n - a * x) / nok;
		}
		if (b * y >= n - nok + 1) {
			l2 = (b * y - n + nok - 1) / nok;
		} else {
			l2 = - (n - b * y) / nok;
		}
		if (l1 >= l1 && l1 >= l2 && l1 <= r1 && l1 <= r2) {
			k = l1;
		} else if (l2 >= l1 && l2 >= l2 && l2 <= r1 && l2 <= r2) {
			k = l2;
		} else if (r1 >= l1 && r1 >= l2 && r1 <= r1 && r1 <= r2) {
			k = r1;
		} else if (r2 >= l1 && r2 >= l2 && r2 <= r1 && r2 <= r2) {
			k = r2;
		} else {
			out.print(-1);
			return;
		}
		x += k * dx;
		y -= k * dy;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < a; j++) {
				out.print(i * a + (j + 1) % a + 1 + " ");
			}
		}
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < b; j++) {
				out.print(x * a + i * b + (j + 1) % b + 1 + " ");
			}
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