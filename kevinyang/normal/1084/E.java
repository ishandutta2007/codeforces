import java.util.*;
import java.io.*;
public class E1084 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int n = readInt(); long k = readLong();
		String s1 = next(); String s2 = next();
		boolean larger = false;
		long bin = 1;
		int i = 0;
		long ans = 0;
		for(i = 0; i<n; i++) {
			bin*=2;
			if(s1.charAt(i)==s2.charAt(i))bin--;
			if(s2.charAt(i)=='a'&s1.charAt(i)=='b')bin-=2;
			
			if(bin>k) {
				larger= true; break;
			}
			ans+=bin;
		}
		ans+=(long)(n-i)*k;
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