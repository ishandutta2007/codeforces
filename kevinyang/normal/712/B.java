import java.util.*;
import java.io.*;
public class B712 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		String s = next();
		int up = 0;
		int right = 0;
		for(int i = 0; i<s.length(); i++) {
			if(s.charAt(i)=='U') {
				up++;
			}
			else if(s.charAt(i)=='D') {
				up--;
			}
			else if(s.charAt(i)=='L') {
				right--;
			}
			else {
				right++;
			}
		}
		up = Math.abs(up);
		right = Math.abs(right);
		if((up+right)%2==0) {
			pr.println((up+right)/2);
		}
		else {
			pr.println(-1);
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