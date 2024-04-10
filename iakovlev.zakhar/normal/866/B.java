import java.util.*;
import java.io.*;

public class B {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public void quickSort(int[] a, int from, int to) {
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

	public void quickSort(P[] a, int from, int to) {
		if (to - from <= 1) {
			return;
		}
		int i = from;
		int j = to - 1;
		P x = a[from + (new Random()).nextInt(to - from)];
		while (i <= j) {
			while (a[i].compareTo(x) < 0) {
				i++;
			}
			while (a[j].compareTo(x) > 0) {
				j--;
			}
			if (i <= j) {
				P t = a[i];
				a[i] = a[j];
				a[j] = t;
				i++;
				j--;
			}
		}
		quickSort(a, from, j + 1);
		quickSort(a, j + 1, to);
	}
	
	public class P implements Comparable<P> {
		long s;
		long a;
		long b;
		long base;
		long delta;
		
		public P(long s, long a, long b) {
			this.a = a;
			this.b = b;
			this.s = s;
		}

		@Override
		public int compareTo(P o) {
			if((a - b) - (o.a - o.b) > 0) {
				return 1;
			}
			if ((a - b) - (o.a - o.b) < 0) {
				return -1;
			}
			return 0;
		}
		
	}
	
	public long get(long b) {
		if (b < 0 || b > number) {
			return -1;
		}
		long h = 0;
		long s1 = b * s;
		long s2 = (number - b) * s;
		int last = -1;
		P free = new P(0, 0, 0);
		for (int i = 0; i < p.length; i++) {
			if (p[i].b > p[i].a) {
				if (p[i].s <= s1) {
					s1 -= p[i].s;
					h += p[i].s * p[i].b;
					last = i;
				} else {
					last = i;
					free = new P(p[i].s - s1, p[i].a, p[i].b);
					h += s1 * p[i].b;
					s1 = 0;
					break;
				}
			} else {
				break;
			}
		}
		int first = p.length;
		s2 -= free.s;
		h += free.s * free.a;
		free = new P(0, 0, 0);
		for (int i = p.length - 1; i > last; i--) {
			if (p[i].s <= s2) {
				s2 -= p[i].s;
				h += p[i].s * p[i].a;
				first = i;
			} else {
				first = i;
				free = new P(p[i].s - s2, p[i].a, p[i].b);
				h += s2 * p[i].a;
				s2 = 0;
				break;
			}
		}
		h += free.s * free.b;
		for (int i = last + 1; i < first; i++) {
			h += p[i].s * p[i].b;
		}
		return h;
	}
	
	P[] p;
	long number;
	long s;
	
	public void solve() {
		int n = in.nextInt();
		s = in.nextLong();
		p = new P[n];
		long sum = 0L;
		for (int i = 0; i < p.length; i++) {
			p[i] = new P(in.nextLong(), in.nextLong(), in.nextLong());
			sum += p[i].s;
		}
		number = 0;
		if (sum % s == 0) {
			number = sum / s;
		} else {
			number = sum / s + 1;
		}
		quickSort(p, 0, n);
		long l = -1;
		long r = number + 1;
		while (l + 2 < r) {
			long left = l + (r - l) / 3;
			long right = l + 2 * (r - l) / 3;
			if (get(left) < get(right)) {
				l = left;
			} else {
				r = right;
			}
		}
		System.out.println(Math.max(Math.max(get(l), get(l + 1)), get(l + 2)));
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
		new B().run();
	}
}