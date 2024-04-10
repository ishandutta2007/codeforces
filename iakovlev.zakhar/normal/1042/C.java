import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Pause implements Comparable<Pause> {
		int time;
		int number;

		public Pause(int time, int number) {
			this.time = time;
			this.number = number;
		}

		@Override
		public int compareTo(Pause o) {
			if (this.time != o.time) {
				return this.time - o.time;
			}
			return this.number - o.number;
		}
	}
	
	public void solve() {
		int n = in.nextInt();
		ArrayList<Integer> neg = new ArrayList<>();
		ArrayList<Integer> x = new ArrayList<>();
		ArrayList<Integer> pos = new ArrayList<>();
		ArrayList<Integer> y = new ArrayList<>();
		ArrayList<Pause> p1 = new ArrayList<>();
		ArrayList<Pause> p2 = new ArrayList<>();
		Collections.sort(neg);
		Collections.sort(pos);
		ArrayList<Integer> zero = new ArrayList<>();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			int z = in.nextInt();
			a[i] = z;
			if (z > 0) {
				p2.add(new Pause(z, i));
				pos.add(z);
				y.add(i);
			} else if (z < 0) {
				p1.add(new Pause(z, i));
				neg.add(z);
				x.add(i);
			} else {
				zero.add(i);
			}
		}
		Collections.sort(p1);
		Collections.sort(p2);
		for (int i = 0; i < p1.size(); i++) {
			neg.set(i, p1.get(i).time);
			x.set(i, p1.get(i).number);
		}
		for (int i = 0; i < p2.size(); i++) {
			pos.set(i, p2.get(i).time);
			y.set(i, p2.get(i).number);
		}
		int del = Integer.MAX_VALUE;
		if (neg.size() % 2 == 0) {
			if (zero.size() > 0 && zero.size() < n) {
				for (int i = 0; i < zero.size() - 1; i++) {
					out.println("1 " + (zero.get(i) + 1) + " " + (zero.get(i + 1) + 1));
				}
				out.println("2 " + (zero.get(zero.size() - 1) + 1));
				for (int i = 0; i < x.size() - 1; i++) {
					out.println("1 " + (x.get(i) + 1) + " " + (x.get(i + 1) + 1));
				}
				if (y.size() > 0 && x.size() > 0) {
					out.println("1 " + (x.get(x.size() - 1) + 1) + " " + (y.get(0) + 1));
				}
				for (int i = 0; i < y.size() - 1; i++) {
					out.println("1 " + (y.get(i) + 1) + " " + (y.get(i + 1) + 1));
				}
				return;
			}
		} else {
			if (zero.size() > 0 && zero.size() < n - 1) {
				for (int i = 0; i < zero.size() - 1; i++) {
					out.println("1 " + (zero.get(i) + 1) + " " + (zero.get(i + 1) + 1));
				}
				out.println("1 " + (zero.get(zero.size() - 1) + 1) + " " + (x.get(x.size() - 1) + 1));
				out.println("2 " + (x.get(x.size() - 1) + 1));
				for (int i = 0; i < x.size() - 2; i++) {
					out.println("1 " + (x.get(i) + 1) + " " + (x.get(i + 1) + 1));
				}
				if (y.size() > 0 && x.size() > 1) {
					out.println("1 " + (x.get(x.size() - 2) + 1) + " " + (y.get(0) + 1));
				}
				for (int i = 0; i < y.size() - 1; i++) {
					out.println("1 " + (y.get(i) + 1) + " " + (y.get(i + 1) + 1));
				}
				return;
			}
			del = neg.get(neg.size() - 1);
		}
		if (del == Integer.MAX_VALUE) {
			for (int i = 1; i < a.length; i++) {
				out.println("1 " + i + " " + (i + 1));
			}
		} else {
			if (a[0] == del) {
				out.println("2 1");
				for (int i = 2; i < a.length; i++) {
					out.println("1 " + i + " " + (i + 1));
				}
			} else if (a[n - 1] == del) {
				out.println("2 " + (n));
				for (int i = 1; i < a.length - 1; i++) {
					out.println("1 " + i + " " + (i + 1));
				}
			} else {
				for (int i = 0; i < a.length - 1; i++) {
					if (a[i + 1] == del) {
						out.println("2 " + (i + 2));
						out.println("1 " + (i + 1) + " " + (i + 3));
						i++;
					} else {
						out.println("1 " + (i + 1) + " " + (i + 2));
					}
				}
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
	public static void main(String[] arg) {
		new C().run();
	}
}