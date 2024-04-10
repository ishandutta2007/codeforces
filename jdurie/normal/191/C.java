//package a2oj;
import java.io.*;
import java.util.*;
 
public class FoolsAndRoads {
	// ------------------------
	private static ArrayList<LinkedList<Integer>> tree = new ArrayList<LinkedList<Integer>>();
	private static int[][] par;
	private static int[] dp;
	private static int[] dist;
	private static int n;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
        n = sc.nextInt();
		for(int i = 0; i < n; i++)
			tree.add(new LinkedList<Integer>());
		int[][] edges = new int[n - 1][2];
		for(int i = 0; i < n - 1; i++){
			int a = sc.nextInt() - 1, b = sc.nextInt() - 1;
			edges[i][0] = a;
			edges[i][1] = b;
			tree.get(a).add(b);
			tree.get(b).add(a);
		}
		par = new int[n][log(n)];
		dist = new int[n];
		fillPar(0, 0, 0);
		dp = new int[n];
		int k = sc.nextInt();
		for(int i = 0; i < k; i++){
			int a = sc.nextInt() - 1, b = sc.nextInt() - 1;
			dp[a]++;	
			dp[b]++;
			dp[lca(a, b)] -= 2;
		}
		sumChil(0);
		for(int i = 0; i < n - 1; i++){
			int a = edges[i][0], b = edges[i][1];
			out.print(dp[dist[a] > dist[b] ? a : b]+" ");
		}
		// ------------------------
		out.close();
	}
	//------------------------
	private static int log(int n) {
		return (int) Math.ceil(Math.log(n) / Math.log(2));
	}
	private static int lca(int a, int b) {
		int c = dist[a] > dist[b] ? a : b;
		int d = dist[a] > dist[b] ? b : a;
		for(int i = log(n) - 1; i >= 0; i--)
			if(dist[c] - dist[d] >= 1 << i)
				c = par[c][i];
		if(c == d)
			return c;
		for(int i = log(n) - 1; i >= 0; i--)
			if(par[c][i] != par[d][i]) {
				c = par[c][i];
				d = par[d][i];
			}
		return par[c][0];
	}
	private static void sumChil(int a) {
		for(int i : tree.get(a))
			if(i != par[a][0]){
				sumChil(i);
				dp[a] += dp[i];
			}
	}
	private static void fillPar(int a, int p, int d) {
		dist[a] = d;
		par[a][0] = p;
		for(int i = 1; i < log(n); i++)
			par[a][i] = par[par[a][i - 1]][i - 1];
		for(int i : tree.get(a))
			if(i != par[a][0])
				fillPar(i, a, d+1);
	}
	public static PrintWriter out;
	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
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