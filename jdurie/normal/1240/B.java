//package cf591d1;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int q = sc.nextInt();
		while(q-- > 0) {
			int n = sc.nextInt();
			int[] a = new int[n];
			TreeSet<Integer> set = new TreeSet<Integer>();
			for(int i = 0; i < n; i++) {
				a[i] = sc.nextInt();
				set.add(a[i]);
			}
			TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
			int gtr = 0;
			while(!set.isEmpty())
				map.put(set.pollLast(), gtr++);
			int[] lowestBad = new int[n + 1];
			for(int i = 0; i < n; i++) {
				set.add(a[i]);
				Integer ceil = set.ceiling(a[i] + 1);
				lowestBad[a[i]] = ceil == null ? 3 * n : ceil;
				//System.out.println(a[i] + " +" + ceil);
			}
			for(int i = n - 1; i >= 0; i--)
				if(map.ceilingKey(i + 1) != null)
					lowestBad[i] = min(lowestBad[i], lowestBad[map.ceilingKey(i + 1)]);
			/*for(int i : map.keySet())
				System.out.println(lowestBad[i]);
			set = new TreeSet<Integer>();
			int[] opsAft = new int[n + 1];
			for(int i = n - 1; i >= 0; i--){
				set.add(a[i]);
				Integer floor = set.floor(a[i] - 1);
				opsAft[a[i]] = floor == null ? 0 : map.keySet().size() - map.get(floor);
			}*/
			map.put(3 * n, -1);
			int ans = map.size() - 1;
			for(int i : map.keySet()) 
				if(i != 3 * n) {
					ans = min(ans, map.size() - 1 - (map.get(i) - map.get(lowestBad[i])));
					//System.out.println(i + " + " + map.get(i)+ " " + lowestBad[i] + " " + map.get(lowestBad[i]));
					//System.out.println(map.size() - 1 - (map.get(i) - map.get(lowestBad[i])));
				}
			/*LinkedList<Integer> ll = new LinkedList<Integer>();
			TreeMap<Integer, TreeSet<Integer>> currAvail = new TreeMap<Integer, TreeSet<Integer>>();
			for(int i = n; i > 0; i--)
				if(map.containsKey(i)) {
					ll.addFirst(i);
					insert(currAvail, opsAft[i], i);
					while(ll.peekLast() >= lowestBad[i])
						delete(currAvail, opsAft[ll.peekLast()], ll.pollLast());
					System.out.println(opsBef[i] + " " + currAvail.firstKey() + " " + opsAft[i]);
					ans = min(ans, currAvail.lastKey() + opsBef[i]);
				}*/
			out.println(ans);
		}
		out.close();
	}
	/*public static void delete(TreeMap<Integer, TreeSet<Integer>> map, int k, int v) {
		if(map.get(k).size() == 1)
			map.remove(k);
		else
			map.get(k).remove(v);
	}
	public static void insert(TreeMap<Integer, TreeSet<Integer>> map, int k, int v) {
		if(!map.containsKey(k))
			map.put(k, new TreeSet<Integer>());
		map.get(k).add(v);
	}*/
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