import java.util.*;

import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;

public class C {
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

	public long gcd(long x, long y) {
		if (y == 0) {
			return x;
		}
		if (x == 0) {
			return y;
		}
		return gcd(y, x % y);
	}

	public boolean prime(long x) {
		for (int i = 2; i * i <= x; i++) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	}

	public long pow(long x, long p) {
		if (p == 0) {
			return 1;
		}
		long t = pow(x, p / 2);
		t *= t;
		t %= mod;
		if (p % 2 == 1) {
			t *= x;
			t %= mod;
		}
		return t;
	}

	public class Pair implements Comparable<Pair> {
		int x;
		long y;

		public Pair(int x, long y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(Pair o) {
			if (y > o.y) {
				return 1;
			}
			if (y < o.y) {
				return -1;
			}
			if (x > o.x) {
				return 1;
			}
			if (x < o.x) {
				return -1;
			}
			return 0;
		}
	}

	long mod = 1000000007;

	public class Func {
		ArrayList<Integer> types;
		ArrayList<Object> acts;

		public Func() {
			types = new ArrayList<>();
			acts = new ArrayList<>();
		}
	}

	public class Point implements Comparable<Point> {
		long x;
		int type;
		long cost;

		public Point(long x, int type, long cost) {
			this.x = x;
			this.type = type;
			this.cost = cost;
		}

		@Override
		public int compareTo(Point o) {
			if (x > o.x) {
				return 1;
			}
			if (x < o.x) {
				return -1;
			}
			if (type != o.type) {
				return type - o.type;
			}
			return 0;
		}
	}

	public class Block {
		boolean type;
		int number;

		public Block(boolean type, int number) {
			this.type = type;
			this.number = number;
		}
	}

	public void solve() {
		int n = in.nextInt();
		System.out.println("2 1 2 3");
		int min = -1;
		if (in.nextInt() == 1) {
			min = 2;
		} else {
			min = 3;
		}
		for (int i = 4; i <= n; i++) {
			System.out.println("2 1 " + min + " " + i);
			if (in.nextInt() < 0) {
				min = i;
			}
		}
		ArrayList<Pair> list = new ArrayList<>();
		long[] area = new long[n];
		for (int i = 2; i <= n; i++) {
			if (i == min) {
				continue;
			}
			System.out.println("1 1 " + min + " " + i);
			area[i - 1] = in.nextLong();
			list.add(new Pair(i, area[i - 1]));
		}
		Collections.sort(list);
		int dist = list.get(list.size() - 1).x;
		long smax = list.get(list.size() - 1).y + 1;
		ArrayList<Pair> ans = new ArrayList<>();
		ans.add(new Pair(dist, 0));
		for (int i = 2; i <= n; i++) {
			if (i == min || i == dist) {
				continue;
			}
			System.out.println("2 1 " + dist + " " + i);
			ans.add(new Pair(i, (smax - area[i - 1]) * in.nextInt()));
		}
		Collections.sort(ans);
		System.out.print("0 1 " + min + " ");
		for (Pair p : ans) {
			System.out.print(p.x + " ");
		}
		System.out.println();
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