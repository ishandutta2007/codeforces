//package cf579d3;
import java.io.*;
import java.util.*;

public class E {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n = sc.nextInt();
		Integer[] a = new Integer[n];
		for(int i = 0; i < n; i++)
			a[i] = sc.nextInt();
		Arrays.sort(a);
		HashSet<Integer> covered = new HashSet<Integer>();
		for(int i : a) {
			if(i > 1 && !covered.contains(i - 1))
				covered.add(i - 1);
			else if(!covered.contains(i))
				covered.add(i);
			else if(!covered.contains(i + 1))
				covered.add(i + 1);
		}
		out.println(covered.size());
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