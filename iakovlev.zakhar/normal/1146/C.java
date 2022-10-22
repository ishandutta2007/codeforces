import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;
	
	public class Side implements Comparable<Side> {
		long sq;
		int n;
		
		public Side(long sq, int n) {
			this.sq = sq;
			this.n = n;
		}

		@Override
		public int compareTo(Side o) {
			if (sq > o.sq) {
				return 1;
			}
			if (sq < o.sq) {
				return -1;
			}
			return n - o.n;
		}
	}
	
	public class Fract {
		long p;
		long q;
		
		public Fract(long p, long q) {
			this.p = p;
			this.q = q;
			long gcd = gcd(Math.abs(p), q);
			p /= gcd;
			q /= gcd;
		}
	}
	
	public long gcd(long a, long b) {
		if (a == 0) {
			return b;
		}
		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}
	
	public Fract sum(Fract a, Fract b) {
		return new Fract(a.p * b.q + a.q * b.p, a.q * b.q);
	}
	
	public Fract neg(Fract a) {
		return new Fract(-a.p, a.q);
	}
	
	public Fract subtr(Fract a, Fract b) {
		return sum(a, neg(b)); 
	}
	
	public class Triangle implements Comparable<Triangle> {
		int x;
		int y;
		int z;
		Fract d;
		
		public Triangle(int x, int y, int z, Fract d) {
			this.x = x;
			this.y = y;
			this.z = z;
			this.d = d;
		}

		@Override
		public int compareTo(Triangle o) {
			if (o == null) {
				return -1;
			}
			Fract f = subtr(d, o.d);
			if (f.p > 0) {
				return 1;
			}
			if (f.p < 0) {
				return -1;
			}
			return 0;
		}
		
	}
	
	public void solve() {
		Random random = new Random();
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			int n = in.nextInt();
			ArrayList<Integer> ans = new ArrayList<>();
			for (int j = 0; j < 9; j++) {
				ArrayList<Integer> list = new ArrayList<>();
				TreeSet<Integer> set = new TreeSet<>();
				for (int x = 0; x < n; x++) {
					if (x % (1 << (j + 1)) < (1 << j)) {
						list.add(x);
					} else {
						set.add(x);
					}
				}
				if (set.size() == 0) {
					break;
				}
				System.out.print(list.size() + " " + set.size() + " ");
				for (int k : list) {
					System.out.print(k + 1 + " ");
				}
				for (int k : set) {
					System.out.print(k + 1 + " ");
				}
				System.out.println();
				ans.add(in.nextInt());
			}
			Collections.sort(ans);
			System.out.println("-1 " + ans.get(ans.size() - 1));
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