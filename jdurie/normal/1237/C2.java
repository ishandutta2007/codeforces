//package cfglobal5;
import java.io.*;
import java.util.*;

public class C{
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n = sc.nextInt();
		TreeMap<Integer, TreeMap<Integer, TreeMap<Integer, Integer>>> map = new TreeMap<Integer, TreeMap<Integer, TreeMap<Integer, Integer>>>();
		for(int i = 0; i < n; i++) {
			int x = sc.nextInt(), y = sc.nextInt(), z = sc.nextInt();
			if(!map.containsKey(x))
				map.put(x, new TreeMap<Integer, TreeMap<Integer, Integer>>());
			if(!map.get(x).containsKey(y))
				map.get(x).put(y, new TreeMap<Integer, Integer>());
			map.get(x).get(y).put(z, i + 1);
		}
		while(!map.isEmpty()) {
			P p = pollFirst(map);
			int x = bestX(p.x, map), y = bestY(p.y, x, map), z = bestZ(p.z, x, y, map), i = map.get(x).get(y).get(z);
			clear(map, x, y, z);
			out.println(p + " " + i);
		}
		// ------------------------
		out.close();
	}
	static int bestX(int x, TreeMap<Integer, TreeMap<Integer, TreeMap<Integer, Integer>>> map) {
		return map.ceilingKey(x) == null ? map.floorKey(x) : map.ceilingKey(x);
	}
	static int bestY(int y, int x, TreeMap<Integer, TreeMap<Integer, TreeMap<Integer, Integer>>> map) {
		return map.get(x).ceilingKey(y) == null ? map.get(x).floorKey(y) : map.get(x).ceilingKey(y);
	}
	static int bestZ(int z, int x, int y, TreeMap<Integer, TreeMap<Integer, TreeMap<Integer, Integer>>> map) {
		return map.get(x).get(y).ceilingKey(z) == null ? map.get(x).get(y).floorKey(z) : map.get(x).get(y).ceilingKey(z);
	}
	static void clear(TreeMap<Integer, TreeMap<Integer, TreeMap<Integer, Integer>>> map, int x, int y, int z) {
		map.get(x).get(y).remove(z);
		if(map.get(x).get(y).isEmpty())
			map.get(x).remove(y);
		if(map.get(x).isEmpty())
			map.remove(x);
	}
	static P pollFirst(TreeMap<Integer, TreeMap<Integer, TreeMap<Integer, Integer>>> map) {
		int x = map.firstKey(), y = map.get(x).firstKey(), z = map.get(x).get(y).firstKey();
		P p = new P(x, y, z, map.get(x).get(y).get(z));
		clear(map, x, y, z);
		return p;
	}
	//------------------------
	static class P implements Comparable<P>{
		int x, y, z, ind;
		public P(int X, int Y, int Z, int I) {
			x = X;
			y = Y;
			z = Z;
			ind = I;
		}
		public int compareTo(P p) {
			if(x == p.x && y == p.y)
				return z - p.z;
			if(x == p.x)
				return y - p.y;
			return x - p.x;
		}
		public String toString() {
			return ind + "";
		}
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