import java.util.*;
import java.io.*;
public class A1352 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			String n = next();
			int count = 0;
			for(int i = 0; i<n.length(); i++) {
				if(n.charAt(i)!='0')count++;
			}
			System.out.println(count);
			boolean already = false;
			for(int i = 0; i<n.length(); i++) {
				if(n.charAt(i)!='0') {
					if(already)System.out.print(" ");
					System.out.print(n.charAt(i));
					for(int j = 0; j<n.length()-i-1; j++) {
						System.out.print(0);
					}
					already = true;
				}
			}
			System.out.println();
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