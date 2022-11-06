import java.util.*;
import java.io.*;
public class A1344 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt();
			int[]array = new int[n];
			for(int i = 0; i<n; i++)array[i] = readInt();
			boolean[]vis = new boolean[n];
			for(int i = 0; i<n; i++) {
				int a = array[i];
				a+=i;
				int rem = (a%n+n)%n;
				vis[rem] = true;
			}
			boolean works = true;
			for(int i = 0; i<n; i++) {
				works = works&vis[i];
			}
			if(works) {
				pr.println("YES");
			}
			else {
				pr.println("NO");
			}
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