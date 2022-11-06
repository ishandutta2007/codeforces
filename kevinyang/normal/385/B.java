import java.util.*;
import java.io.*;
public class B385 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		String s = next();
		long ans = 0;
		Set<Integer>set = new HashSet<Integer>();
		int previous = 0;
		for(int i = 0; i<s.length()-3; i++) {
			if(s.substring(i,i+4).equals("bear")) {
				ans+=(i-previous+1)*(s.length()-3-i);
				previous = i+1;
			}
		}
		pr.println(ans);
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