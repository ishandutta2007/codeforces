import java.util.*;
import java.io.*;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;


	
	public void solve() throws IOException {
		String s = in.next();
		int med = 0;
		int[] ch = new int['z' - 'a' + 1];
		for (int i = 0; i < s.length(); i++) {
			ch[s.charAt(i) - 'a']++;
		}
		int[] ans = new int['z' - 'a' + 1];
		int j = 0;
		for (int i = 0; i < ans.length; i++) {
			while (j < s.length() / 2 && ch[i] >= 2) {
				ch[i] -= 2;
				j++;
				ans[i]++;
			}
		}
		for (int i = 0; i < ans.length; i++) {
			if (j < s.length() / 2 && ch[i] == 1) {
				ch[i]--;
				j++;
				ans[i]++;
			}
		}
		if (s.length() % 2 == 1) {
			for (int i = 0; i < ans.length; i++) {
				if (ch[i] == 1) {
					med = i;
					break;
				}
			}
		}
		char[] ans1 = new char[s.length()];
		j = 0;
		for (int i = 0; i < ans.length; i++) {
			while (ans[i] > 0) {
				ans[i]--;
				ans1[j] = (char) (i + 'a');
				ans1[s.length() - 1 - j] = (char) (i + 'a');
				j++;
			}
		}
		if (s.length() % 2 == 1) {
			ans1[s.length() / 2] = (char) (med + 'a');
		}
		for (int i = 0; i < ans1.length; i++) {
			System.out.print(ans1[i]);
		}
	}

	public void run() throws IOException {
		if (systemIO) {
			in = new FastScanner(System.in);
			out = new PrintWriter(System.out);
		} else {
			in = new FastScanner(new File("input.txt"));
			out = new PrintWriter(new File("output.txt"));
		}
		solve();

		out.close();
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
	public static void main(String[] arg) throws IOException {
		new C().run();
	}
}