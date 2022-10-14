//package cf592d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class C {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		long n = sc.nextLong(), p = sc.nextLong(), w = sc.nextLong(), d = sc.nextLong();
		long dPts = p % w, addDraws = -1;
		for(long i = 0; i < 300000; i++) {
			if(dPts % d == 0 && works(i, dPts, n, p, w, d)) {
				addDraws = i;
				break;
			}
			dPts = (dPts + w) % d;
		}
		if(addDraws == -1)
			out.println(-1);
		else {
			long draws = (addDraws * w + p % w) / d;
			long wins = (p - draws * d) / w, losses = n - draws - wins;
			out.println(wins + " " + draws + " " + losses);
		}
		out.close();
	}
	static boolean works(long i, long dPts, long n, long p, long w, long d) {
		long draws = (i * w + p % w) / d;
		long wins = (p - draws * d) / w, losses = n - draws - wins;
		return draws + wins <= n && wins >= 0 && losses >= 0 && wins * w + draws * d == p;
	}
	static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	static PrintWriter out  = new PrintWriter(new BufferedOutputStream(System.out));
	static class MyScanner {
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