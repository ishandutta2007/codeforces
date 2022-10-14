//package manthan18;
import java.io.*;
import java.util.*;

public class D {
	// ------------------------
	static ArrayList<HashSet<Integer>> tree = new ArrayList<HashSet<Integer>>();
	static HashSet<Integer> used = new HashSet<Integer>();
	static LinkedList<Integer> queue = new LinkedList<Integer>();
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n = sc.nextInt();
		for(int i = 0; i < n; i++)
			tree.add(new HashSet<Integer>());
		for(int i = 0; i < n - 1; i++) {
			int a = sc.nextInt() - 1, b = sc.nextInt() - 1;
			tree.get(a).add(b);
			tree.get(b).add(a);
		}
		queue.add(sc.nextInt() - 1);
		int i = 1;
		boolean ok = true;
		while(ok && i < n) {
			if(queue.isEmpty()) { ok = false; break; }
			int x = queue.pollFirst(), sz = tree.get(x).size();
			if(x != 0) sz--;
			for(int j = 0; j < sz; j++) {
				int next = sc.nextInt() - 1;
				if(i >= n || !tree.get(x).contains(next))
					ok = false;
				queue.add(next);
				i++;
			}
		}
		out.println(ok ? "Yes" : "No");
		// ------------------------
		out.close();
	}
	//------------------------
	
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