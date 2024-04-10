//package cf580d1;
import java.io.*;
import java.util.*;

public class B {
	static int n;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		n = sc.nextInt();
		long[] a = new long[n];
		ArrayList<TreeSet<Integer>> bits = new ArrayList<TreeSet<Integer>>();
		for(int b = 0; b < 63; b++)
			bits.add(new TreeSet<Integer>());
		for(int i = 0; i < n; i++) {
			a[i] = sc.nextLong();
			for(int b = 0; b < 63; b++)
				if((a[i] & (1L << b)) > 0) {
					bits.get(b).add(i);
					if(bits.get(b).size() >= 3) {
						out.println(3);
						out.close();
						return;
					}
				}
		}
		for(int i = 0; i < n; i++)
			graph.add(new HashSet<Integer>());
		LinkedList<Integer>u = new LinkedList<Integer>();
		LinkedList<Integer>v = new LinkedList<Integer>();
		for(int b = 0; b < 63; b++)
			if(bits.get(b).size() == 2) {
				int f = bits.get(b).first(), l = bits.get(b).last();
				graph.get(f).add(l);
				graph.get(l).add(f);
				u.add(f);
				v.add(l);
			}
		int min = Integer.MAX_VALUE;
		while(!u.isEmpty())
			min = Math.min(min, dijk(u.pollFirst(), v.pollFirst()));
		out.println(min == Integer.MAX_VALUE ? -1 : min);
		out.close();
	}
	static ArrayList<HashSet<Integer>>graph = new ArrayList<HashSet<Integer>>();
	public static int dijk(int u, int v) {
		graph.get(u).remove(v);
		LinkedList<Integer> q = new LinkedList<Integer>();
		int[] dist = new int[n];
		int d = 1;
		q.add(u);
		while(!q.isEmpty()) {
			for(int i : q)
				dist[i] = d;
			HashSet<Integer> q2 = new HashSet<Integer>();
			while(!q.isEmpty()) {
				int f = q.pollFirst();
				for(int g : graph.get(f))
					if(dist[g] == 0)
						q2.add(g);
			}
			for(int x : q2)
				q.add(x);
			d++;
		}
		graph.get(u).add(v);
		return dist[v] == 0 ? Integer.MAX_VALUE : dist[v];
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