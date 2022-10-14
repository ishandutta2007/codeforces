//package cf603d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int t = sc.nextInt();
		while(t-- > 0) {
			int n = sc.nextInt();
			int[] ans = new int[n];
			TreeMap<Integer, TreeSet<Integer>> map = new TreeMap<Integer, TreeSet<Integer>>();
			for(int i = 0; i < n; i++) {
				int p = sc.nextInt();
				if(!map.containsKey(p)) map.put(p, new TreeSet<Integer>());
				map.get(p).add(i);
				ans[i] = p;
			}
			TreeSet<Integer> set = new TreeSet<Integer>();
			int changes = 0;
			for(int p : map.keySet()) {
				for(int j : map.get(p)) 
					if(j != map.get(p).first()) {
						for(int k = 0; k <= 9; k++) {
							int key = 10 * (p / 10) + k;
							if(!map.containsKey(key) && !set.contains(key)) {
								set.add(key);
								ans[j] = key;
								break;
							}
						}
						changes++;
					}
			}
			System.out.println(changes);
			for(int i : ans)
				System.out.printf("%04d\n", i);
		}
		out.close();
	}
	static String repl(String s, int j, char c) {
		return s.substring(0, j) + c + s.substring(j + 1);
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