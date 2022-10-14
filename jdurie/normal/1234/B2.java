//package cf590d3;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt(), k = sc.nextInt();
		LinkedList<Integer> ll = new LinkedList<Integer>();
		TreeSet<Integer> set = new TreeSet<Integer>();
		for(int i = 0; i < n; i++) {
			int nx = sc.nextInt();
			if(!set.contains(nx)) {
				if(set.size() == k)
					set.remove(ll.pollLast());
				ll.addFirst(nx);
				set.add(nx);
			}
		}
		out.println(ll.size());
		for(int i : ll)
			out.print(i + " ");
		out.println();
		out.close();
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