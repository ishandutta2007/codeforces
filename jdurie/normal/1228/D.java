//package cf589d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class D {
	static ArrayList<TreeSet<Integer>> graph = new ArrayList<TreeSet<Integer>>();
	static int[] set;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt(), m = sc.nextInt();
		for(int i = 0; i < n; i++)
			graph.add(new TreeSet<Integer>());
		for(int i = 0; i < m; i++) {
			int u = sc.nextInt() - 1, v = sc.nextInt() - 1;
			graph.get(u).add(v);
			graph.get(v).add(u);
		}
		set = new int[n];
		set[0] = 1;
		boolean b = graph.get(0).isEmpty() ? false : dfs(graph.get(0).first(), 0, 2);
		long[] size = new long[3];
		for(int i = 0; i < n; i++)
			if(set[i] == 0)
				b = false;
			else
				size[set[i] - 1]++;
		long edges = size[0] * size[1] + size[0] * size[2] + size[1] * size[2];
		if(edges != m)
			b = false;
		for(int i = 0; i < 3; i++)
			if(size[i] == 0)
				b = false;
		if(b) {
			for(int i : set)
				out.print(i + " ");
			out.println();
		} else
			out.println(-1);
		out.close();
	}
	static boolean dfs(int i, int p, int s) {
		set[i] = s;
		for(int j : graph.get(i))
			if(j != p) {
				if(set[j] == set[i])
					return false;
				else if(set[j] == 0 && !dfs(j, i, 
						graph.get(p).contains(j) ? 6 - set[i] - set[p] : set[p]))
							return false;
			}
		return true;
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