//package cf589d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class C {
	static long MOD = 1000000007L;
	static boolean prime(long x) {
		if(x == 1) return false;
		for(long i = 2; i * i <= x; i++)
			if(x % i == 0)
				return false;
		return true;
	}
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		long x = sc.nextLong(), n = sc.nextLong();
		TreeSet<Long> p = new TreeSet<Long>();
		for(long i = 1; i * i <= x; i++)
			if(x % i == 0) {
				if(prime(i))
					p.add(i);
				if(prime(x / i))
					p.add(x / i);
			}
		long ans = 1;
		for(long l : p) {
			long xx = 1;
			while((xx * l) > 0 && n / xx >= l) {
				xx *= l;
				ans = ans * pMod(l, n / xx) % MOD;
			}
		}
		out.println(ans);
		out.close();
	}
	public static long pMod(long x, long p) {
		if(p == 0)
			return 1;
		long l = pMod(x, p / 2);
		return l * l % MOD * (p % 2 == 1 ? x : 1) % MOD;
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