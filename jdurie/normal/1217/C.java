//package cfed72;
import java.io.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int t = sc.nextInt();
		for(int w = 0; w < t; w++) {
			char[] s = sc.nextLine().toCharArray();
			int n = s.length;
			int[] leading0 = new int[n];
			long ans = 0;
			leading0[0] = s[0] == '0' ? 1 : 0;
			for(int i = 1; i < n; i++) {
				leading0[i] = s[i - 1] == '0' ? leading0[i - 1] : 0;
				if(s[i] == '0')
					leading0[i]++;
			}
			for(int i = 0; i < n; i++) {
				if(s[i] == '1') {
					int num = 0;
					for(int j = i; j < i + 20 && j < n; j++) {
						num = 2 * num + s[j] - '0';
						if(j - i + 1 + leading0[i] >= num)
							ans++;
					}
				}
			}
			out.println(ans);
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