//package cf584d12;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class D {
	static boolean[] used;
	static ArrayList<TreeSet<Integer>> graph = new ArrayList<TreeSet<Integer>>();
	static int ans = 0;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt(),  m = sc.nextInt();
		used = new boolean[n];
		for(int i = 0; i < n; i++)
			graph.add(new TreeSet<Integer>());
		for(int i = 0; i < m; i++) {
			int u = sc.nextInt() - 1, v = sc.nextInt() - 1;
			if(graph.get(u).contains(v))
				ans += 2;
			else {
				graph.get(u).add(v);
				graph.get(v).add(u);
			}
		}
		for(int i = 0; i < n; i++)
			if(!used[i])
				dfs(i, -1);
		out.println(ans / 2);
		out.close();
	}
	static void dfs(int i, int p) {
		if(used[i])
			ans++;
		else {
			used[i] = true;
			for(int j : graph.get(i))
				if(j != p)
					dfs(j, i);
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