//package cf576d1;
import java.io.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		int t  = sc.nextInt();
		for(int w = 0; w < t; w++) {
			int n = sc.nextInt(), m = sc.nextInt();
			TreeSet<Integer> indSet = new TreeSet<Integer>();
			TreeSet<Integer> matching = new TreeSet<Integer>();
			for(int i = 1; i <= 3 * n; i++)
				indSet.add(i);
			for(int i = 1; i <= m; i++) {
				int a = sc.nextInt(), b = sc.nextInt();
				if(indSet.contains(a) && indSet.contains(b)) {
					indSet.remove(a);
					indSet.remove(b);
					matching.add(i);
				}
			}
			out.println(indSet.size() >= n ? "IndSet" : "Matching");
			if(indSet.size() >= n) {
				for(int i = 0; i < n; i++)
					out.print(indSet.pollFirst() + " ");
				out.println();
			} else {
				for(int i = 0; i < n; i++)
					out.print(matching.pollFirst() + " ");
				out.println();
			}
		}
		out.close();
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