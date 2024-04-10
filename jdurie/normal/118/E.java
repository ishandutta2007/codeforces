//package dfstree;
import java.util.*;
import static java.lang.Math.*;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class BertownRoads {
	static ArrayList<TreeSet<Integer>> graph = new ArrayList<TreeSet<Integer>>();
	static ArrayList<ArrayList<Integer>> dfsTree = new ArrayList<ArrayList<Integer>>();
	static int[] dep, backIn, backOut;
	static TreeSet<String> bridges = new TreeSet<String>(), roads = new TreeSet<String>();
	static PrintWriter out  = new PrintWriter(new BufferedOutputStream(System.out));
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt(), m = sc.nextInt();
		for(int i = 0; i < n; i++) {
			graph.add(new TreeSet<Integer>());
			dfsTree.add(new ArrayList<Integer>());
		}
		for(int i = 0; i < m; i++) {
			int u = sc.nextInt() - 1, v = sc.nextInt() - 1; //0-indexing
			graph.get(u).add(v);
			graph.get(v).add(u);
		}
		dep = new int[n];
		backIn = new int[n];
		backOut = new int[n];
		dfs(0, -1, 1);
		getBridges(0);
		if(bridges.isEmpty()) {
			for(String s : roads)
				out.println(s);
		} else
			out.println(0);
		out.close();
	}
	static int getBridges(int i) {
		int curr = 0;
		for(int j : dfsTree.get(i))
			if(curr == (curr += getBridges(j)))
				bridges.add((i + 1) + "-" + (j + 1)); //converting back to 1-indexing
		return curr - backIn[i] + backOut[i];
	}
	static void dfs(int i, int p, int d) {
		dep[i] = d;
		for(int j : graph.get(i))
			if(j != p && dep[j] < dep[i]) {
				roads.add((i + 1) + " " + (j + 1));
				if(dep[j] == 0) {
					dfsTree.get(i).add(j);
					dfs(j, i, d + 1);
				} else {
					backIn[j]++;
					backOut[i]++;
				}
			}
	}
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