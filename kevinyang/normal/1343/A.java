import java.util.*;
import java.io.*;
public class A1343 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		long[]powers = new long[32];
		for(int i = 1; i<32; i++) {
			powers[i] = (long)Math.pow(2, i)-1;
		}
		for(int tt = 0; tt<t; tt++) {
			int n = readInt();
			for(int i = 31; i>=1; i--) {
				if(n%powers[i]==0) {
					System.out.println(n/powers[i]);
					break;
				}
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