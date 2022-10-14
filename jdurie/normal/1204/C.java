//package cf581d2;
import java.io.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		int n = sc.nextInt();
		int[][] dist = new int[n][n];
		for(int i = 0; i < n; i++) {
			char[] line = sc.nextLine().toCharArray();
			for(int j = 0; j < n; j++)
				dist[i][j] = line[j] == '1' ? 1 : Integer.MAX_VALUE;
		}
		for(int i = 0; i < n; i++)
			dist[i][i] = 0;
		for(int d = 2; d < n; d++) {
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					if(i != j && dist[i][j] == Integer.MAX_VALUE)
						for(int k = 0; k < n; k++)
							if(dist[i][k] == 1 && dist[k][j] == d - 1) {
								dist[i][j] = d;
								break;
							}
		}
		LinkedList<Integer> ll = new LinkedList<Integer>();
		int m  = sc.nextInt();
		int[] p = new int[m];
		for(int i = 0; i < m; i++)
			p[i] = sc.nextInt() - 1;
		ll.add(0);
		for(int i = 1; i < m - 1; i++) 
			if(dist[p[ll.getLast()]][p[i + 1]] < i + 1 - ll.getLast())
				ll.add(i);
		ll.add(m - 1);
		out.println(ll.size());
		for(int i : ll)
			out.print((p[i] + 1)+ " ");
		out.println();
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