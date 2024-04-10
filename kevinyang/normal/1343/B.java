import java.util.*;
import java.io.*;
public class B1343 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int n = readInt();
		for(int i = 0; i<n; i++) {
			int m = readInt();
			if(m%4!=0) {
				System.out.println("NO");
			}
			else {
				System.out.println("YES");
				for(int j = 2; j<=m; j+=2) {
					System.out.print(j+ " ");
				}
				for(int j = 1; j<m-2; j+=2) {
					System.out.print(j+ " ");
				}
				int last = (m/2-1+m);
				System.out.println(last);
			}
		}
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