import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public long gcd(long x, long y) {
		if (y == 0) {
			return x;
		}
		if (x == 0) {
			return y;
		}
		return gcd(y, x % y);
	}
	
	public class Hero implements Comparable<Hero> {
		int n;
		int pow;
		
		public Hero(int n, int pow) {
			this.n = n;
			this.pow = pow;
		}

		@Override
		public int compareTo(Hero o) {
			if (pow != o.pow) {
				return pow - o.pow;
			}
			return n - o.n;
		}
	}
	
	public void solve() {
		int n = 2 * in.nextInt();
		int m = in.nextInt();
		int[] power = new int[n];
		TreeSet<Hero> set = new TreeSet<>();
		for (int i = 0; i < power.length; i++) {
			power[i] = in.nextInt();
			set.add(new Hero(i + 1, power[i]));
		}
		TreeMap<Integer, Integer> pair = new TreeMap<>();
		for (int i = 0; i < m; i++) {
			int x = in.nextInt();
			int y = in.nextInt();
			pair.put(x, y);
			pair.put(y, x);
		}
		int t = in.nextInt();
		if (t == 1) {
			while (!pair.isEmpty()) {
				int x = pair.firstKey();
				int y = pair.get(x);
				if (power[x - 1] >= power[y - 1]) {
					System.out.println(x);
					set.remove(new Hero(x, power[x - 1]));
					pair.remove(x);
				} else {
					System.out.println(y);
					set.remove(new Hero(y, power[y - 1]));
					pair.remove(y);
				}
				int z = in.nextInt();
				set.remove(new Hero(z, power[z - 1]));
				pair.remove(z);
			}
			while (!set.isEmpty()) {
				System.out.println(set.pollLast().n);
				int z = in.nextInt();
				set.remove(new Hero(z, power[z - 1]));
			}
		} else {
			while (!set.isEmpty()) {
				int z = in.nextInt();
				set.remove(new Hero(z, power[z - 1]));
				boolean nec = false;
				int x = set.last().n;
				if (pair.containsKey(z) && pair.containsKey(pair.get(z))) {
					 x = pair.get(z);
					 nec = true;
				}
				pair.remove(z);
				if (!nec && !pair.isEmpty()) {
					x = pair.firstKey();
					int y = pair.get(x);
					if (power[x - 1] <= power[y - 1]) {
						x = y;
					}
				}
				System.out.println(x);
				pair.remove(x);
				set.remove(new Hero(x, power[x - 1]));
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