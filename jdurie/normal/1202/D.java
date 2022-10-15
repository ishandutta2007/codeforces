//package cfed70;
import java.io.*;
import java.util.*;

public class D {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		int t = sc.nextInt();
		for(int w = 0; w < t; w++) {
			long n = sc.nextLong();
			LinkedList<Integer> ll = new LinkedList<Integer>();
			while(n > 0) {
				int a = (int)Math.floor((1 + Math.sqrt(1 + 8 * n)) / 2.0);
				n -= a * (a - 1) / 2;
				ll.add(a);
				//System.out.println(a+" "+n);
			}
			//out.println(ll.size());
			int[] threes = new int[ll.size()];
			int x = ll.size();
			for(int i = 0; i < x; i++)
				threes[i] = ll.pollFirst();
			for(int i = 0; i < x - 1; i++)
				threes[i] -= threes[i + 1];
			for(int i:threes) {
					out.print(1);
					for(int j = 0; j < i; j++)
						out.print("3");
			}
			out.println(7);
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