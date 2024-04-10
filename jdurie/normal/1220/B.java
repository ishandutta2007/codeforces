//package cf586d12;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		int[] guess = new int[n];
		sc.nextInt();
		int gcd = -1;
		for(int i = 1; i < n; i++) {
			guess[i] = sc.nextInt();
			gcd = gcd == -1 ? guess[i] : gcd(gcd, guess[i]);
		}
		guess[0] = gcd;
		for(int i = 1; i < n; i++)
			guess[i] /= gcd;
		sc.nextInt();
		sc.nextInt();
		int g23 = sc.nextInt();
		int abcdef = (int)sqrt(g23 / guess[1] / guess[2]);
		guess[0] /= abcdef;
		for(int i = 1; i < n; i++)
			guess[i] *= abcdef;
		for(int i : guess)
			out.print(i + " ");
		out.println();
		out.close();
	}
	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	public static PrintWriter out  = new PrintWriter(new BufferedOutputStream(System.out));
	public static class MyScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String next() {
			while (st == null || !st.hasMoreElements())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
}