import java.util.*;
import java.io.*;
public class C1362 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		long[]powers = new long[62];//2^n-1
		powers[0] = 1;
		for(int i = 1; i<=60; i++) {
			powers[i] = powers[i-1]*2;
		}
		while(t--!=0) {
			long n = readLong();
			long ans = 0;
			int index = 0;
			pr.println(a(n));
		}
		pr.close();
	}
	public static long a(long n) {
		if(n==0)return 0;
		return a(n/2)+n;
		
	}
	/*
	public static long choose(int n, int r) {
		long num = 1;
		long den = 1;
		for(int i = n; i>n-r; i--) {
			num*=i;
		}
		for(int i = r; i>1; i--) {
			den*=i;
		}
		return num/den;
	}
	*/
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