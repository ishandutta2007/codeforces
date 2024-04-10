//package cf592d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class D {
	static ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
	static int[] pos;
	static long[][] c;
	static int n;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		n = sc.nextInt();
		c = new long[n][3];
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < n; j++)
				c[j][i] = sc.nextLong();
		for(int i = 0; i < n; i++)
			graph.add(new ArrayList<Integer>());
		for(int i = 0; i < n - 1; i++) {
			int u = sc.nextInt() - 1, v = sc.nextInt() - 1;
			graph.get(u).add(v);
			graph.get(v).add(u);
		}
		pos = new int[n];
		if(!dfs(1, -1, 0, false))
			out.println(-1);
		else {
			int[] pos2 = new int[n];
			for(int i = 0; i < n; i++)
				pos2[i] = (3 - pos[i]) % 3;
			long[] o = new long[6];
			for(int i = 0; i < 6; i++)
				o[i] = answer(i, i < 3 ? pos : pos2);
			int ind = 0;
			for(int i = 1; i < 6; i++)
				if(o[i] < o[ind])
					ind = i;
			out.println(o[ind]);
			for(int i = 0; i < n; i++)
				out.print((((ind < 3 ? pos[i] : pos2[i]) + ind) % 3 + 1) + " ");
		}
		out.close();
	}
	static long answer(int offset, int[] pos) {
		long ans = 0;
		for(int i = 0; i < n; i++)
			ans += c[i][(int)((offset + pos[i]) % 3)];
		return ans;
	}
	static boolean dfs(int i, int p, int c, boolean minus) {
		if(graph.get(i).size() > 2)
			return false;
		pos[i] = c;
		for(int j : graph.get(i)) 
			if(j != p) {
				if(!dfs(j, i, minus ? (c + 2) % 3 : (c + 1) % 3, minus))
					return false;
				minus = true;
			}
		return true;
	}
	static PrintWriter out  = new PrintWriter(new BufferedOutputStream(System.out));
	static class MyScanner {
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