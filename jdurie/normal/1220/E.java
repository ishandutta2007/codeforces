//package cf586d12;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class E {
	static ArrayList<TreeSet<Integer>> graph = new ArrayList<TreeSet<Integer>>();
	static ArrayList<LinkedList<Integer>> g2 = new ArrayList<LinkedList<Integer>>();
	static long[] w;
	static long[] chil;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt(), m = sc.nextInt();
		w = new long[n];
		chil = new long[n];
		for(int i = 0; i < n; i++)
			w[i] = sc.nextInt();
		for(int i = 0; i < n; i++)
			graph.add(new TreeSet<Integer>());
		for(int i = 0; i < m; i++) {
			int u = sc.nextInt() - 1, v = sc.nextInt() - 1;
			graph.get(u).add(v);
			graph.get(v).add(u);
		}
		if(m == n - 1) {
			int s = sc.nextInt() - 1;
			out.println(dfs(s, -1));
		} else {
			LinkedList<Integer> ones = new LinkedList<Integer>();
			for(int i = 0; i < n; i++)
				g2.add(new LinkedList<Integer>());
			for(int i = 0; i < n; i++)
				if(graph.get(i).size() == 1)
					ones.add(i);
			int[] edge = new int[n];
			while(!ones.isEmpty()) {
				int i = ones.pollFirst();
				int j = graph.get(i).pollFirst();
				chil[j] = max(chil[j], w[i] + chil[i]);
				graph.get(j).remove(i);
				edge[i] = j;
				if(graph.get(j).size() == 1)
					ones.add(j);
				g2.get(j).add(i);
			}
			long sum = 0, ch = 0;
			int s = sc.nextInt() - 1, origS = s;
			while(graph.get(s).isEmpty()) {
				sum += w[s];
				w[s] = 0;
				s = edge[s];
			}
			chil[s] = 0;
			for(int i : g2.get(s))
				chil[s] = max(chil[s], dfs2(i));
			for(int i = 0; i < n; i++)
				if(graph.get(i).size() > 0) {
					sum += w[i];
					ch = max(chil[i], ch);
				}
			out.println(sum + ch);
		}
		out.close();
	}
	static long dfs(int i, int p) {
		long ans = 0;
		for(int j : graph.get(i))
			if(j != p)
				ans = max(ans, dfs(j, i));
		return ans + w[i];
	}
	static long dfs2(int i) {
		long ans = 0;
		for(int j : g2.get(i))
			ans = max(ans, dfs2(j));
		return ans + w[i];
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