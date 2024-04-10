import java.util.*;
import java.io.*;

public class A {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;
	
	public static void quickSort(int[] a, int from, int to) {
		if (to - from <= 1) {
			return;
		}
		int i = from;
		int j = to - 1;
		int x = a[from + (new Random()).nextInt(to - from)];
		while (i <= j) {
			while (a[i] < x) {
				i++;
			}
			while (a[j] > x) {
				j--;
			}
			if (i <= j) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
				i++;
				j--;
			}
		}
		quickSort(a, from, j + 1);
		quickSort(a, j + 1, to);
	}
	
	public void solve() {
		String s = in.next();
		ArrayList<String> number = new ArrayList<>();
		ArrayList<String> not = new ArrayList<>();
		int begin = 0;
		f:
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == ';' || s.charAt(i) == ',') {
				String s1 = s.substring(begin, i);
				begin = i + 1;
				if (s1.equals("0")) {
					number.add(s1);
				} else if (s1.equals("")) {
					not.add(s1);
				} else if (s1.charAt(0) == '0') {
					not.add(s1);
				} else {
					for (int j = 0; j < s1.length(); j++) {
						if (!Character.isDigit(s1.charAt(j))) {
							not.add(s1);
							continue f;
						}
					}
					number.add(s1);
				}
			}
		}
		String s1 = s.substring(begin, s.length());
		if (s1.equals("0")) {
			number.add(s1);
		} else if (s1.equals("")) {
			not.add(s1);
		} else if (s1.charAt(0) == '0') {
			not.add(s1);
		} else {
			boolean flag = true;
			for (int j = 0; j < s1.length(); j++) {
				if (!Character.isDigit(s1.charAt(j))) {
					not.add(s1);
					flag = false;
					break;
				}
			}
			if (flag) {
				number.add(s1);
			}
		}
		if (number.size() == 0) {
			out.println("-");
		} else {
			out.print("\"");
			for (int i = 0; i < number.size() - 1; i++) {
				out.print(number.get(i) + ",");
			}
			out.print(number.get(number.size() - 1));
			out.println("\"");
		}
		if (not.size() == 0) {
			out.println("-");
		} else {
			out.print("\"");
			for (int i = 0; i < not.size() - 1; i++) {
				out.print(not.get(i) + ",");
			}
			out.print(not.get(not.size() - 1));
			out.println("\"");
		}
	}

	public void run() {
		try {
			if (systemIO) {
				in = new FastScanner(System.in);
				out = new PrintWriter(System.out);
			} else {
				in = new FastScanner(new File("input.txt"));
				out = new PrintWriter(new File("output.txt"));
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
	public static void main(String[] args) {
		new A().run();
	}
}