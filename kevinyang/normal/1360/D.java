import java.util.*;
import java.io.*;
public class D1360 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt(); int k = readInt();
			ArrayList<Integer>factors = new ArrayList<Integer>();
			for(int i = 1; i*i<=n; i++) {
				if(n%i==0) {
					factors.add(i);
					factors.add(n/i);
				}
			}
			Collections.sort(factors);
			for(int i = factors.size()-1; i>=0; i--) {
				if(factors.get(i)<=k) {
					System.out.println(n/factors.get(i));
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