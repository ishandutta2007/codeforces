import java.util.*;
import java.io.*;
public class C1367 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt(); int k = readInt();
			String s = next();
			boolean[]vis = new boolean[n]; int start = 0;
			for(int i = 0; i<n; i++) {
				if(s.charAt(i)=='1') {
					for(start = Math.max(start, i-k); start<=Math.min(i+k,n-1); start++) {
						vis[start] = true;
					}
				}
			}
			start = 0;
			int count = 0;
			for(int i = 0; i<n; i++) {
				if(!vis[i]) {
					count++;
					for(start = Math.max(start, i-k); start<=Math.min(i+k, n-1); start++) {
						vis[start] = true;
					}
				}
			}
			System.out.println(count);
		}
		pr.close();
	}
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}