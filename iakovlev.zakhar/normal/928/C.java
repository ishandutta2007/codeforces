import java.util.*;

import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;

public class C {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public class Project {
		String s;
		int version;
		
		public Project(String s, int version) {
			this.s = s;
			this.version = version;
		}
		
	}
	
	public class V implements Comparable<V> {
		String s;
		int version;
		int len;
		
		public V(String s, int version, int len) {
			this.s = s;
			this.version = version;
			this.len = len;
		}

		@Override
		public int compareTo(V o) {
			if (len != o.len) {
				return o.len - len;
			}
			if (s.compareTo(o.s) != 0) {
				return s.compareTo(o.s);
			}
			return version - o.version;
		}
		
	}
	
	public void solve() {
		int n = in.nextInt();
		TreeMap<String, Integer> ans = new TreeMap<>();
		HashMap<String, HashMap<Integer, Project[]>> graph = new HashMap<>();
		TreeSet<V> queue = new TreeSet<>();
		String s0 = in.next();
		int version0 = in.nextInt();
		for (int i = 0; i < n; i++) {
			String s;
			int v;
			if (i == 0) {
				s = s0;
				v = version0;
			} else {
				s = in.next();
				v = in.nextInt();
			}
			int k = in.nextInt();
			Project[] p = new Project[k];
			for (int j = 0; j < p.length; j++) {
				p[j] = new Project(in.next(), in.nextInt());
			}
			if (graph.containsKey(s)) {
				graph.get(s).put(v, p);
			} else {
				HashMap<Integer, Project[]> map = new HashMap<>();
				map.put(v, p);
				graph.put(s, map);
			}
		}
		queue.add(new V(s0, version0, 0));
		while (!queue.isEmpty()) {
			V v = queue.pollLast();
			if (ans.containsKey(v.s)) {
				continue;
			} else {
				ans.put(v.s, v.version);
				Project[] p = graph.get(v.s).get(v.version);
				for (Project i : p) {
					queue.add(new V(i.s, i.version, v.len + 1));
				}
			}
		}
		out.println(ans.size() - 1);
		for (String s : ans.keySet()) {
			if (!s.equals(s0)) {
				out.println(s + " " + ans.get(s));
			}
		}
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