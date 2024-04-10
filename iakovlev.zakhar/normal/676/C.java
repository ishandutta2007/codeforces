import java.util.*;
import java.io.*;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public static int f(int n, int k, String s) {
		ArrayList<Integer> a = new ArrayList<>();
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == 'b') {
				a.add(i);
			}
		}
//		for (int i = 0; i < a.size(); i++) {
//			System.out.println(a.get(i));
//		}
//		System.out.println(n - a.get(a.size() - k - 1) - 1);
		if (a.size() <= k) {
			return n;
		}
		int max = a.get(k);
		for (int i = k + 1; i < a.size(); i++) {
			if (a.get(i) - a.get(i - k - 1) - 1 > max) {
				max = a.get(i) - a.get(i - k - 1) - 1;
			}
//			System.out.println("\t " + a.get(i));
//			System.out.println(i + " " + max);
		}
		return Math.max(max, n - 1 - a.get(a.size() - k - 1));
	}
	
	public static int g(int n, int k, String s) {
		ArrayList<Integer> a = new ArrayList<>();
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == 'a') {
				a.add(i);
			}
		}
		if (a.size() <= k) {
			return n;
		}
		int max = a.get(k);
		for (int i = k + 1; i < a.size(); i++) {
			if (a.get(i) - a.get(i - k - 1) - 1 > max) {
				max = a.get(i) - a.get(i - k - 1) - 1;
			}
		}
		return Math.max(max, n - 1 - a.get(a.size() - k - 1));
	}

	public void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		String s = in.next();
//		System.out.println("f " + f(n, k, s));
//		System.out.println("g " + g(n, k, s));
		System.out.println(Math.max(f(n, k, s), g(n, k, s)));
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