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
		int n = in.nextInt();
		int k1 = in.nextInt();
		int[] s1 = new int[k1];
		for (int i = 0; i < s1.length; i++) {
			s1[i] = in.nextInt();
		}
		int k2 = in.nextInt();
		int[] s2 = new int[k2];
		for (int i = 0; i < s2.length; i++) {
			s2[i] = in.nextInt();
		}
		int[] win1 = new int[n];
		int[] win2 = new int[n];
		quickSort(s1, 0, k1);
		quickSort(s2, 0, k2);
		win1[0] = -1;
		win2[0] = -1;
		Queue<Integer> d1 = new ArrayDeque<>();
		HashSet<Integer> h1 = new HashSet<>();
		Queue<Integer> d2 = new ArrayDeque<>();
		HashSet<Integer> h2 = new HashSet<>();
		Queue<Integer> q1 = new ArrayDeque<>();
		HashSet<Integer> h3 = new HashSet<>();
		Queue<Integer> q2 = new ArrayDeque<>();
		HashSet<Integer> h4 = new HashSet<>();
		d1.add(0);
		h1.add(0);
		d2.add(0);
		h2.add(0);
		while (true) {
			boolean flag = false;
//			for (int i : d1) {
//				System.out.print(i + " ");
//			}
//			System.out.println("d1");
//			for (int i : d2) {
//				System.out.print(i + " ");
//			}
//			System.out.println("d2");
//			for (int i : q1) {
//				System.out.print(i + " ");
//			}
//			System.out.println("q1");
//			for (int i : q2) {
//				System.out.print(i + " ");
//			}
//			System.out.println("q2");
			while (!d1.isEmpty()) {
				int x = d1.poll();
				for (int j = 0; j < s1.length; j++) {
					int y = (x - s1[j] + n) % n;
					if (win1[(x - s1[j] + n) % n] != 1) {
						win1[(x - s1[j] + n) % n] = 1;
						for (int i = 0; i < s2.length; i++) {
							int z = (y - s2[i] + n) % n;
							if (win2[(y - s2[i] + n) % n] == 0 && !h4.contains(z)) {
								h4.add(z);
								q2.add(z);
							}
						}
						flag = true;
					}
				}
			}
			while (!d2.isEmpty()) {
				int x = d2.poll();
				for (int i = 0; i < s2.length; i++) {
					int y =(x - s2[i] + n) % n;
					if (win2[(x - s2[i] + n) % n] != 1) {
						win2[(x - s2[i] + n) % n] = 1;
						for (int j = 0; j < s1.length; j++) {
							int z = (y - s1[j] + n) % n;
							if (win1[(y - s1[j] + n) % n] == 0 && !h3.contains(z)) {
								h3.add(z);
								q1.add(z);
							}
						}
						flag = true;
					}
				}
			}
//			for (int i : d1) {
//				System.out.print(i + " ");
//			}
//			System.out.println("d1");
//			for (int i : d2) {
//				System.out.print(i + " ");
//			}
//			System.out.println("d2");
//			for (int i : q1) {
//				System.out.print(i + " ");
//			}
//			System.out.println("q1");
//			for (int i : q2) {
//				System.out.print(i + " ");
//			}
//			System.out.println("q2");
			while (!q1.isEmpty()) {
				int x = q1.poll();
				if (win1[x] != 0) {
					continue;
				}
				boolean fl = true;
				for (int i = 0; i < s1.length; i++) {
					if (win2[(x + s1[i]) % n] != 1) {
						fl = false;
						break;
					}
				}
				if (fl) {
					win1[x] = -1;
					flag = true;
					if (!h2.contains(x)) {
						h2.add(x);
						d2.add(x);
					}
				} else {
					h3.remove(x);
				}
			}
			while (!q2.isEmpty()) {
				int x = q2.poll();
				if (win2[x] != 0) {
					continue;
				}
				boolean fl = true;
				for (int i = 0; i < s2.length; i++) {
					if (win1[(x + s2[i]) % n] != 1) {
						fl = false;
						break;
					}
				}
				if (fl) {
					win2[x] = -1;
					flag = true;
					if (!h1.contains(x)) {
						h1.add(x);
						d1.add(x);
					}
				} else {
					h4.remove(x);
				}
			}
			if (!flag) {
				break;
			}
		}
		for (int i = 1; i < win1.length; i++) {
			if (win1[i] == 1) {
				System.out.print("Win ");
			} else if (win1[i] == 0) {
				System.out.print("Loop ");
			} else {
				System.out.print("Lose ");
			}
		}
		System.out.println();
		for (int i = 1; i < win2.length; i++) {
			if (win2[i] == 1) {
				System.out.print("Win ");
			} else if (win2[i] == 0) {
				System.out.print("Loop ");
			} else {
				System.out.print("Lose ");
			}
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