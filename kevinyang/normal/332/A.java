import java.util.*;
import java.io.*;
public class A332 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int n = readInt(); String s = next();
		int m = s.length();
		if(m<4) {
			pr.println(0);
		}
		else {
			int count = 0;
			for(int i = 3; i<m; i++) {
				if(s.charAt(i-1)==s.charAt(i-2)&s.charAt(i-2)==s.charAt(i-3)&i%n==0) {
					count++;
				}
			}
			pr.println(count);
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