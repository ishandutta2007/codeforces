
import java.util.*;
import java.io.*;
public class A1353 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		for(int cases = 0; cases<t; cases++) {
			int n = readInt();
			int m = readInt();
			if(n==1) {
				System.out.println(0);
			}
			else if(n==2) {
				System.out.println(m);
			}
			else {
				if(n%2==1) {
					long num1 = m/(n/2);
					long rem1 = m%(n/2);
					long total = num1*(n-1);
					total+=rem1*2;
					System.out.println(total);
				}
				else {
					long num1 = m/(n/2);
					long rem1 = m%(n/2);
					long total = num1*(n);
					total+=rem1*2;
					System.out.println(total);
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