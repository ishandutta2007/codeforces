//package cf584d12;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class C {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int tests = sc.nextInt();
		for(int wq = 0; wq < tests; wq++) {
			int n = sc.nextInt();
			char[] s = sc.nextLine().toCharArray();
			int[] fP = new int[n];
			TreeMap<Integer, TreeSet<Integer>> map = new TreeMap<Integer, TreeSet<Integer>>();
			for(int i = 0; i < 10; i++)
				map.put(i + '0', new TreeSet<Integer>());
			for(int i = 0; i < n; i++)
				map.get((int)s[i]).add(i);
			boolean poss = true, swap = false;
			int currI = -1;
			for(int i = '0'; i < '0' + 10; i++) 
				if(!map.get(i).isEmpty()){
					if(map.get(i).first() > currI) {
						currI = map.get(i).last();
						for(int x : map.get(i))
							fP[x] = swap ? 2 : 1;
					} else if(!swap) {
						swap = true;
						for(int x : map.get(i))
							fP[x] = x >= currI ? 1 : 2;
						currI = map.get(i).floor(currI - 1);
					} else
						poss = false;
				}
			if(poss) {
				for(int i : fP)
					out.print(i);
				out.println();
			} else
				out.println("-");
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