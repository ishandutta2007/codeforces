//package cfed74;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int q = sc.nextInt();
		for(int qq = 0; qq < q; qq++) {
			int n = sc.nextInt(), r = sc.nextInt();
			ArrayList<Integer> monsters = new ArrayList<Integer>();
			for(int i = 0; i < n; i++)
				monsters.add(sc.nextInt());
			Collections.sort(monsters);
			TreeSet<Integer> moves = new TreeSet<Integer>();
			while(!monsters.isEmpty()) {
				if(monsters.get(monsters.size() - 1) - moves.size() * r > 0)
					moves.add(monsters.get(monsters.size() - 1));
				monsters.remove(monsters.size() - 1);
			}
			out.println(moves.size());
		}
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