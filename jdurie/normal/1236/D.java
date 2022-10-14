//package cf593d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class D {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt(), m = sc.nextInt();
		long seen = 1, k = sc.nextInt();
		int minRow = 1, maxRow = n;
		int minCol = 1, maxCol = m;
		TreeMap<Integer, TreeSet<Integer>> obsRows = new TreeMap<Integer, TreeSet<Integer>>();
		TreeMap<Integer, TreeSet<Integer>> obsCols = new TreeMap<Integer, TreeSet<Integer>>();
		for(int i = 1; i <= n; i++)
			obsRows.put(i, new TreeSet<Integer>());
		for(int i = 1; i <= m; i++)
			obsCols.put(i, new TreeSet<Integer>());
		for(int i = 0; i < k; i++) {
			int x = sc.nextInt(), y = sc.nextInt();
			obsRows.get(x).add(y);
			obsCols.get(y).add(x);
		}
		int dir = m == 1 || obsRows.get(1).contains(2) ? 1 : 0, x = 1, y = 1;
		boolean notStuck = true;
		while(notStuck) {
			if(dir == 0) {
				int newY = maxCol;
				if(obsRows.get(x).ceiling(y) != null)
					newY = min(newY, obsRows.get(x).ceiling(y) - 1);
				if(y >= newY)
					notStuck = false;
				else {
					minRow = x + 1;
					seen += (long)newY - (long)y;
					y = newY;
				}
			} else if(dir == 1) {
				int newX = maxRow;
				if(obsCols.get(y).ceiling(x) != null)
					newX = min(newX, obsCols.get(y).ceiling(x) - 1);
				if(x >= newX)
					notStuck = false;
				else {
					maxCol = y - 1;
					seen += (long)newX - (long)x;
					x = newX;
				}
			} else if(dir == 2) {
				int newY = minCol;
				if(obsRows.get(x).floor(y) != null)
					newY = max(newY, obsRows.get(x).floor(y) + 1);
				if(y <= newY)
					notStuck = false;
				else {
					maxRow = x - 1; 
					seen += (long)y - (long)newY;
					y = newY;
				}
			} else {
				int newX = minRow;
				if(obsCols.get(y).floor(x) != null)
					newX = max(newX, obsCols.get(y).floor(x) + 1);
				if(x <= newX)
					notStuck = false;
				else {
					minCol = y + 1;
					seen += (long)x - (long)newX;
					x = newX;
				}
			}
			dir = (dir + 1) % 4;
		}
		long area = (long)n * (long)m;
		out.println(seen == area - k ? "Yes" : "No");
		out.close();
	}
	static PrintWriter out  = new PrintWriter(new BufferedOutputStream(System.out));
	static class MyScanner {
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