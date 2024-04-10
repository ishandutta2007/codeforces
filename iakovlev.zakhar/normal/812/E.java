import java.util.*;
import java.io.*;

public class E {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;
	
	public static long pollMax(TreeMap<Long, Integer> t) {
		long x = t.lastKey();
		if (t.get(t.lastKey()) == 1) {
			t.remove(t.lastKey());
		} else {
			t.put(t.lastKey(), t.get(t.lastKey()) - 1);
		}
		return x;
	}
	
	public static long pollMin(TreeMap<Long, Integer> t) {
		long x = t.firstKey();
		if (t.get(t.firstKey()) == 1) {
			t.remove(t.firstKey());
		} else {
			t.put(t.firstKey(), t.get(t.firstKey()) - 1);
		}
		return x;
	}
	
	public static void add(TreeMap<Long, Integer> t, long x) {
		if (t.containsKey(x)) {
			t.put(x, t.get(x) + 1);
		} else {
			t.put(x, 1);
		}
	}
	
	public void dfsH(int v, int hi) {
		h[v] = hi;
		for (int i : a[v]) {
			dfsH(i, hi + 1);
		}
	}
	
	ArrayList<Integer>[] a;
	int[] h;
	
	public void solve() throws IOException {
		int n = in.nextInt();
		long[] x = new long[n];
		for (int i = 0; i < x.length; i++) {
			x[i] = in.nextLong();
		}
		a = new ArrayList[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = new ArrayList<>();
		}
		for (int i = 1; i < x.length; i++) {
			a[in.nextInt() - 1].add(i);
		}
		h = new int[n];
		dfsH(0, 0);
		long max = 0;
		for (int i = 0; i < h.length; i++) {
			max = Math.max(max, h[i]);
		}
		boolean[] ch = new boolean[n];
		for (int i = 0; i < ch.length; i++) {
			ch[i] = (h[i] % 2 == max % 2);
		}
		long xor = 0;
		for (int i = 0; i < ch.length; i++) {
			if (ch[i]) {
				xor = xor ^ x[i];
			}
		}
		HashMap<Long, Long> even = new HashMap<>();
		HashMap<Long, Long> odd = new HashMap<>();
		for (int i = 0; i < ch.length; i++) {
			if (ch[i]) {
				if (even.containsKey(x[i])) {
					even.put(x[i], even.get(x[i]) + 1);
				} else {
					even.put(x[i], 1L);
				}
			} else {
				if (odd.containsKey(x[i])) {
					odd.put(x[i], odd.get(x[i]) + 1);
				} else {
					odd.put(x[i], 1L);
				}
			}
		}
		long ans = 0;
		for (long i : odd.keySet()) {
			if (even.containsKey(i ^ xor)) {
				ans += odd.get(i) * even.get(i ^ xor);
			}
		}
		if (xor == 0) {
			long c = 0;
			for (long i : odd.keySet()) {
				c += odd.get(i);
			}
			ans += c * (c - 1) / 2;
			c = 0;
			for (long i : even.keySet()) {
				c += even.get(i);
			}
			ans += c * (c - 1) / 2;
		}
		System.out.println(ans);
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
		new E().run();
	}
}