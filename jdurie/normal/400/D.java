//package a2oj;
import java.io.*;
import java.util.*;

public class DimaAndBacteria {
	static int[] dsu;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt(), m = sc.nextInt(), k = sc.nextInt();
		dsu = new int[n];
		for(int i = 0; i < n; i++)
			dsu[i] = i;
		int[] c = new int[n];
		int x = 0, ind = 0;
		for(int i = 0; i < k; i++) {
			x += sc.nextInt();
			while(ind < x)
				c[ind++] = i;
		}
		LinkedList<Edge> ll = new LinkedList<Edge>();
		int[][] d = new int[k][];
		for(int i = 0; i < k; i++) {
			d[i] = new int[i + 1];
			for(int j = 0; j <= i; j++)
				d[i][j] = Integer.MAX_VALUE;
		}
		int[] set = new int[k];
		for(int i = 0; i < k; i++)
			set[i] = -1;
		for(int i = 0; i < m; i++) {
			int u = sc.nextInt() - 1, v = sc.nextInt() - 1, w = sc.nextInt();
			if(w == 0)
				dsu[dsu(u)] = dsu(v);
			else
				ll.add(new Edge(u, v, w));
		}
		int s = -1;
		boolean possible = true;
		for(int i = 0; i < n; i++)
			if(i == 0 || c[i] != c[i - 1])
				set[++s] = dsu(i);
			else if(dsu(i) != set[s])
				possible = false;
		out.println(possible ? "Yes" : "No");
		if(possible) {
			for(int i = 0; i < k; i++)
				for(int j = 0; j <= i; j++)
					if(set[i] == set[j])
						d[i][j] = 0;
			for(Edge e : ll) {
				int u = Math.max(c[e.u], c[e.v]);
				int v = Math.min(c[e.u], c[e.v]);
				d[u][v] = Math.min(d[u][v], e.w);
			}
			for(int l = 0; l < k; l++)
				for(int i = 0; i < k; i++)
					for(int j = 0; j < i; j++) {
						int d1 = i >= l ? d[i][l] : d[l][i];
						int d2 = j >= l ? d[j][l] : d[l][j];
						if(d1 != Integer.MAX_VALUE && d2 != Integer.MAX_VALUE)
							d[i][j] = Math.min(d[i][j], d1 + d2);
					}
			for(int i = 0; i < k; i++) {
				for(int j = 0; j < k; j++) {
					int num = i < j ? d[j][i] : d[i][j];
					out.print((num == Integer.MAX_VALUE ? -1 : num) + " ");
				}
				out.println();
			}
		}
		out.close();
	}
 	static class Edge {
		int u, v, w;
		public Edge(int U, int V, int W) {
			u = U;
			v = V;
			w = W;
		}
	}
	static int dsu(int u) {
		return dsu[u] = (u == dsu[u] ? u : dsu(dsu[u]));
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