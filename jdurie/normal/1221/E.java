//package cfed73;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class E {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int q = sc.nextInt();
		for(int w = 0; w < q; w++) {
			int a = sc.nextInt(), b = sc.nextInt();
			char[] s = sc.nextLine().toCharArray();
			ArrayList<Integer> spots = new ArrayList<Integer>();
			int curr = 0;
			for(char c : s) {
				if(c == '.')
					curr++;
				else {
					if(curr > 0)
						spots.add(curr);
					curr = 0;
				}
			}
			if(curr > 0)
				spots.add(curr);
			Collections.sort(spots);
			int bSpots = 0, pbSpots = 0, aSpots = 0;
			for(int i : spots) {
				if(i >= b && i < a)
					bSpots++;
				if(i >= 2 * b)
					pbSpots++;
				if(i >= a)
					aSpots++;
			}
			if(aSpots == 0 || bSpots > 0 || pbSpots > 1)
				out.println("NO");
			else if(pbSpots == 1) {
				boolean canWin = false;
				int max = spots.get(spots.size() - 1);
				for(int i = 0; i <= max - a; i++) {
					int j = max - a - i;
					if(j >= 2 * b || i >= 2 * b)
						continue;
					int as = (j >= a ? 1 : 0) + (i >= a ? 1 : 0);
					int bs = (j >= b ? 1 : 0) + (i >= b ? 1 : 0);
					if(as == bs && (aSpots + as) % 2 == 1) {
						canWin = true;
						break;
					}
					continue;
				}
				out.println(canWin ? "YES" : "NO");
			} else
				out.println(aSpots % 2 == 1 ? "YES" : "NO");
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