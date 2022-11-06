import java.util.*;
import java.io.*;
public class A1355 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args) throws IOException{
		int t = readInt();
		for(int i = 0; i<t; i++) {
			long a = readLong(); long k = readLong();
			loop:
			for(long j = 1; j<k; j++) {
				String s = ""+a;
				int min = 9;
				int max = 0;
				for(int l = 0; l<s.length(); l++) {
					int num = (int)s.charAt(l)-48;
					min = Math.min(min, num);
					max = Math.max(max, num);
					if(min==0)break loop;
				}
				a += max*min;
			}
			System.out.println(a);
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