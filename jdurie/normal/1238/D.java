//package cfed74;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class G {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		char[] s = sc.nextLine().toCharArray();
		long ans = (long) n * (long) (n + 1) / 2;
		int[] last = new int[]{-1, -1};
		long[] max = new long[n], min = new long[n];
		for(int i = 0; i < n; i++) {
			if(last[1 - s[i] + 'A'] != -1)
				max[last[1 - s[i] + 'A']] = i - last[1 - s[i] + 'A'];
			last[s[i] - 'A'] = i;
		}
		last = new int[]{-1, -1};
		for(int i = n - 1; i >= 0; i--) {
			if(last[1 - s[i] + 'A'] != -1)
				min[last[1 - s[i] + 'A']] = last[1 - s[i] + 'A'] - i;
			last[s[i] - 'A'] = i;
		}
		for(int i = 0; i < n; i++) {
			ans -= min[i] + max[i] + 1;
			if(max[i] > 0)
				ans++;
		}
		out.println(ans);
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