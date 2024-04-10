import java.util.*;
import java.io.*;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public static class Edge {
		int to;
		int size;
		
		public Edge(int to, int size) {
			// TODO Auto-generated constructor stub
			this.size = size;
			this.to = to;
		}
	}
	
	public static class Edge1 {
		int from;
		int size;
		
		public Edge1(int from, int size) {
			// TODO Auto-generated constructor stub
			this.size = size;
			this.from = from;
		}
	}
	
	public static void dfs(int x) {
		used[x] = true;
		ans++;
		for (int i = 0; i < list[x].size(); i++) {
			dfs(list[x].get(i).to);
		}
	}
	
	public static void normal(int x) {
		if (x != 0) {
			if (maxThis[list1[x].get(0).from] > 0) {
				maxThis[x] = maxThis[list1[x].get(0).from] + list1[x].get(0).size;
			} else {
				maxThis[x] = list1[x].get(0).size;
			}
		}
		if (maxThis[x] > a[x]) {
			dfs(x);
		} else {
			for (int i = 0; i < list[x].size(); i++) {
				normal(list[x].get(i).to);
			}
		}
	}
	
	static boolean[] used;
	static int ans = 0;
	static ArrayList<Edge>[] list;
	static int[] a;
	static long[] maxThis;
	static ArrayList<Edge1>[] list1;
	
	public void solve() {
		int n = in.nextInt();
		used = new boolean[n];
		a = new int[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = in.nextInt();
		}
		maxThis = new long[n];
		list = new ArrayList[n];
		for (int i = 0; i < list.length; i++) {
			list[i] = new ArrayList<>();
		}
		list1 = new ArrayList[n];
		for (int i = 0; i < list.length; i++) {
			list1[i] = new ArrayList<>();
		}
		for (int i = 0; i < list.length - 1; i++) {
			int x = in.nextInt();
			int y = in.nextInt();
			list[x - 1].add(new Edge(i + 1, y));
			list1[i + 1].add(new Edge1(x - 1, y));
		}
		normal(0);
		System.out.println(ans);
	}

	public void run() {
		try {
			if (systemIO) {
				in = new FastScanner(System.in);
				out = new PrintWriter(System.out);
			} else {
				in = new FastScanner(new File("segments.in"));
				out = new PrintWriter(new File("segments.out"));
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