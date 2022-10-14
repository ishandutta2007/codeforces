//package cf590d3;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class D {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		char[] s = sc.nextLine().toCharArray();
		int q = sc.nextInt();
		ArrayList<TreeSet<Integer>> map = new ArrayList<TreeSet<Integer>>();
		for(int i = 0; i < 26; i++)
			map.add(new TreeSet<Integer>());
		for(int i = 0; i < s.length; i++)
			map.get(s[i] -'a').add(i);
		for(int i = 0; i < q; i++)
			if(sc.nextInt() == 1) {
				int pos = sc.nextInt() - 1;
				char c = sc.next().charAt(0);
				map.get(s[pos] - 'a').remove(pos);
				s[pos] = c;
				map.get(s[pos] - 'a').add(pos);
			} else {
				int l = sc.nextInt() - 1, r = sc.nextInt() - 1;
				int dist = 0;
				for(int j = 0; j < 26; j++) {
					Integer ceil = map.get(j).ceiling(l);
					if(ceil != null && ceil <= r)
						dist++;
				}
				out.println(dist);
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