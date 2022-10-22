import java.util.*;
import java.io.*;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;
	
	public void solve() throws IOException {
		String s1 = in.next();
		String s2 = in.next();
		TreeMap<Character, Integer> t11 = new TreeMap<>();
		TreeMap<Character, Integer> t22 = new TreeMap<>();
		TreeMap<Character, Integer> t1 = new TreeMap<>();
		TreeMap<Character, Integer> t2 = new TreeMap<>();
		for (int i = 0; i < s1.length(); i++) {
			if (t11.containsKey(s1.charAt(i))) {
				t11.put(s1.charAt(i), t11.get(s1.charAt(i)) + 1);
			} else {
				t11.put(s1.charAt(i), 1);
			}
		}
		for (int i = 0; i < s2.length(); i++) {
			if (t22.containsKey(s2.charAt(i))) {
				t22.put(s2.charAt(i), t22.get(s2.charAt(i)) + 1);
			} else {
				t22.put(s2.charAt(i), 1);
			}
		}
		int n = s1.length();
		char[] ans = new char[n];
		int begin = 0;
		int last = n - 1;
		int first = 0;
		int second = 0;
		for (char c : t11.keySet()) {
			if (first == (n + 1) / 2) {
				break;
			}
			if (first + t11.get(c) <= (n + 1) / 2) {
				first += t11.get(c);
				t1.put(c, t11.get(c));
			} else {
				t1.put(c, (n + 1) / 2 - first);
				break;
			}
		}
		for (char c : t22.keySet()) {
			if (second == (n + 1) / 2) {
				t2.put(c, t22.get(c));
			} else if (second + t22.get(c) <= (n + 1) / 2) {
				second += t22.get(c);
			} else {
				second += t22.get(c);
				t2.put(c, second - (n + 1) / 2);
				second = (n + 1) / 2;
			}
		}
//		for (char c : t2.keySet()) {
//			System.out.println(c + " " + t2.get(c));
//		}
		boolean flag = false;
		while (last - begin != -1) {
			if (t1.size() == 0) {
				break;
			}
			if (!flag && t1.size() > 0 && t2.size() > 0 && t1.firstKey() >= t2.lastKey()) {
				flag = true;
			}
			if (flag) {
				ans[last] = t1.lastKey();
				if (t1.get(t1.lastKey()) == 1) {
					t1.remove(t1.lastKey());
				} else {
					t1.put(t1.lastKey(), t1.get(t1.lastKey()) - 1);
				}
				last--;
			} else {
				ans[begin] = t1.firstKey();
				if (t1.get(t1.firstKey()) == 1) {
					t1.remove(t1.firstKey());
				} else {
					t1.put(t1.firstKey(), t1.get(t1.firstKey()) - 1);
				}
				begin++;
			}
			if (t2.size() == 0) {
				break;
			}
			if (!flag && t1.size() > 0 && t2.size() > 0 && t1.firstKey() >= t2.lastKey()) {
				flag = true;
			}
			if (flag) {
				ans[last] = t2.firstKey();
				if (t2.get(t2.firstKey()) == 1) {
					t2.remove(t2.firstKey());
				} else {
					t2.put(t2.firstKey(), t2.get(t2.firstKey()) - 1);
				}
				last--;
			} else {
				ans[begin] = t2.lastKey();
				if (t2.get(t2.lastKey()) == 1) {
					t2.remove(t2.lastKey());
				} else {
					t2.put(t2.lastKey(), t2.get(t2.lastKey()) - 1);
				}
				begin++;
			}
		}
		for (int i = 0; i < ans.length; i++) {
			out.print(ans[i]);
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