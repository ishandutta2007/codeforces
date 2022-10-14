//package cf595d3;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class C {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int t = sc.nextInt();
		while(t-- > 0) {
			long n = sc.nextLong();
			long[] p3s = new long[40];
			for(int i = 39; i >= 0; i--)
				if(n >= pow(i)) {
					p3s[i] = n / pow(i);
					n %= pow(i);
				}
			//out.println(Arrays.toString(p3s));
			for(int i = 0; i < 39; i++)
				if(p3s[i] > 1) {
					for(int j = 0; j <= i; j++)
						p3s[j] = 0;
					p3s[i + 1]++;
				}
			long x = 0;
			for(int i = 0; i < 40; i++)
				if(p3s[i] == 1)
					x += pow(i);
			//out.println(Arrays.toString(p3s));
			out.println(x);
		}
		out.close();
	}
	static long pow(long x) {
		long ans = 1;
		for(int i = 0; i < x; i++)
			ans *= 3;
		return ans;
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