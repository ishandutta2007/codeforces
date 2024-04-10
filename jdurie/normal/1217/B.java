//package cfed72;
import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int t = sc.nextInt();
		for(int w = 0; w < t; w++) {
			int n = sc.nextInt(), x = sc.nextInt();
			int maxD = sc.nextInt();
			int maxDiff = maxD - sc.nextInt();
			for(int i = 0; i < n - 1; i++) {
				int d = sc.nextInt(), h = sc.nextInt();
				maxD = Math.max(maxD, d);
				maxDiff = Math.max(maxDiff, d - h);
			}
			if(maxD >= x) {
				System.out.println(1);
				continue;
			}
			if(maxDiff <= 0) {
				System.out.println(-1);
				continue;
			}
			long ans = (x - maxD) / maxDiff;
			x -= ans * maxDiff;
			while(x > maxD) {
				x -= maxDiff;
				ans++;
			}
			if(ans > 0)
				ans++;
			System.out.println(ans);
		}
		
		
		out.close();
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