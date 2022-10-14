//package cf590d3;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class E {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt(), m = sc.nextInt();
		TreeMap<Integer, TreeSet<Integer>> map = new TreeMap<Integer, TreeSet<Integer>>();
		for(int i = 1; i <= n; i++)
			map.put(i, new TreeSet<Integer>());
		int[] a = new int[m];
		for(int i = 0; i < m; i++) {
			a[i] = sc.nextInt();
			map.get(a[i]).add(i);
		}
		long curr = 0;
		for(int i = 0; i < m - 1; i++)
			curr += abs(pos(1, a[i]) - pos(1, a[i + 1]));
		out.print(curr + " ");
		for(int i = 2; i <= n; i++) {
			for(int j : map.get(i)) {
				if(j != m - 1) {
					curr -= abs(pos(i - 1, a[j]) - pos(i - 1, a[j + 1]));
					curr += abs(pos(i, a[j]) - pos(i, a[j + 1]));
				}
				if(j > 0 && a[j - 1] != i && a[j - 1] != i - 1) {
					curr -= abs(pos(i - 1, a[j]) - pos(i - 1, a[j - 1]));
					curr += abs(pos(i, a[j]) - pos(i, a[j - 1]));
				}
			}
			for(int j : map.get(i - 1)) {
				if(j != m - 1) {
					curr -= abs(pos(i - 1, a[j]) - pos(i - 1, a[j + 1]));
					curr += abs(pos(i, a[j]) - pos(i, a[j + 1]));
				}
				if(j > 0 && a[j - 1] != i && a[j - 1] != i - 1) {
					curr -= abs(pos(i - 1, a[j]) - pos(i - 1, a[j - 1]));
					curr += abs(pos(i, a[j]) - pos(i, a[j - 1]));
				}
			}
			out.print(curr + " ");
		}
		out.close();
	}
	public static int pos(int first, int x) {
		if(x == first)
			return 1;
		if(x < first)
			return x + 1;
		return x;
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