import java.util.*;
import java.io.*;
public class B1350 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt();
			int[]array = new int[n+1];
			for(int i = 1; i<=n; i++) {
				array[i] = readInt();
			}
			int[]dp = new int[n+1];
			Arrays.fill(dp, 1);
			for(int i = 1; i<=n/2; i++) {
				int cur = array[i];
				for(int j = i; j<=n; j+=i) {
					if(array[j]>cur) {
						dp[j] = Math.max(dp[j], dp[i]+1);
					}
				}
			}
			int max = 0;
			for(int i = 1; i<=n; i++) {
				max = Math.max(max, dp[i]);
			}
			System.out.println(max);
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