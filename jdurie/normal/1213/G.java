//package cf582d3;
import java.io.*;
import java.util.*;

public class G {
	static ArrayList<LinkedList<Edge>> tree = new ArrayList<LinkedList<Edge>>();
	static long[] a = new long[200001];
	static long[] sz;
	static int[] dsu;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt(), m = sc.nextInt();
		sz = new long[n];
		dsu = new int[n];
		for(int i = 0; i < n; i++) {
			tree.add(new LinkedList<Edge>());
			sz[i] = 1;
			dsu[i] = i;
		}
		TreeSet<Edge> edges = new TreeSet<Edge>();
		for(int i = 0; i < n - 1; i++)
			edges.add(new Edge(sc.nextInt() - 1, sc.nextInt() - 1, sc.nextInt()));
		while(!edges.isEmpty()) {
			Edge e = edges.pollFirst();
			int u = dsu(e.u), v = dsu(e.v);
			dsu[v] = u;
			a[e.w] += sz[u] * sz[v];
			sz[u] += sz[v];
		}
		for(int i = 1; i <= 200000; i++)
			a[i] += a[i - 1];
		for(int i = 0; i < m; i++)
			out.print(a[sc.nextInt()] + " ");
		out.println();
		out.close();
	}
	static int dsu(int u) {
		return dsu[u] = (u == dsu[u] ? u : dsu(dsu[u]));
	}
	static class Edge implements Comparable<Edge> {
		int u, v, w;
		public Edge(int U, int V, int W) {
			u = U;
			v = V;
			w = W;
		}
		public int compareTo(Edge e) {
			if(e.w == w && e.u == u)
				return v - e.v;
			if(e.w == w)
				return u - e.u;
			return w - e.w;
		}
	}
	public static PrintWriter out  = new PrintWriter(new BufferedOutputStream(System.out));
	public static class MyScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String next() {
			while (st == null || !st.hasMoreElements())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
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
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
}