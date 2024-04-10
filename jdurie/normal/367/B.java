//package a2oj;
import java.io.*;
import java.util.*;

public class SerejaAndAnagrams {
	public static void main(String[] args) { 
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		int n = sc.nextInt(), m = sc.nextInt(), p = sc.nextInt();
		if(((long)m - 1) * (long)p >= (long)n)
			out.println(0);
		else {
			int[][] a = new int[p][(n + p - 1) / p];
			for(int i = 0; i < n; i++)
				a[i % p][i / p] = sc.nextInt();
			int[] b = new int[m];
			for(int i = 0; i < m; i++)
				b[i] = sc.nextInt();
			TreeSet<Integer> ans = new TreeSet<Integer>();
			for(int i = 0; i < p; i++) {
				HashMap<Integer, Integer> need = new HashMap<Integer, Integer>();
				HashMap<Integer, Integer> extra = new HashMap<Integer, Integer>();
				for(int x : b)
					add(need, x);
				for(int j = 0; j < a[i].length; j++) {
					if(j >= m && extra.containsKey(a[i][j - m]))
						remove(extra, a[i][j - m]);
					else if(j >= m)
						add(need, a[i][j - m]);
					if(need.containsKey(a[i][j]))
						remove(need, a[i][j]);
					else
						add(extra, a[i][j]);
					if(extra.isEmpty() && need.isEmpty())
						ans.add((j + 1 - m) * p + i + 1);
				}
			}
			out.println(ans.size());
			for(int i : ans)
				out.print(i + " ");
		}
		out.close();
	}
	public static void add(HashMap<Integer, Integer> map, int x) {
		map.put(x, map.containsKey(x) ? map.get(x) + 1 : 1);
	}
	public static void remove(HashMap<Integer,Integer> map, int x) {
		map.put(x, map.get(x) - 1);
		if(map.get(x) == 0)
			map.remove(x);
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