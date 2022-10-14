//package cfed72;
import java.io.*;
import java.util.*;

public class D {
	static ArrayList<HashSet<Integer>> graph = new ArrayList<HashSet<Integer>>();
	static int[] types;
	static int[] in;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt(), m = sc.nextInt();
		types = new int[m];
		in = new int[n];
		for(int i = 0; i < n; i++)
			graph.add(new HashSet<Integer>());
		for(int i = 0; i < m; i++) {
			int u = sc.nextInt() - 1, v = sc.nextInt() - 1;
			graph.get(u).add(v);
			in[v]++;
			types[i] = u > v ? 2 : 1;
		}
		boolean cycles = false;
		for(int i = 0; i < n; i++) {
			int source = -1;
			for(int j = 0; j < n; j++)
				if(in[j] == 0) {
					source = j;
					in[j] = 100000;
					break;
				}
			if(source == -1) {
				cycles = true;
				break;
			}
			else
				for(int k : graph.get(source))
					in[k] --;
		}
		out.println(cycles ? 2 : 1);
		if(cycles)	
			for(int x : types)
				out.print(x + " ");
		else
			for(int i = 0; i < m; i++)
				out.print("1 ");
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