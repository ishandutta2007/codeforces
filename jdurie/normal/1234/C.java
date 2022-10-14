//package cf590d3;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class C {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int q = sc.nextInt();
		for(int w = 0; w < q; w++) {
			int n = sc.nextInt();
			char[]top = sc.nextLine().toCharArray();
			char[]bot = sc.nextLine().toCharArray();
			boolean[]dpTop = new boolean[n];
			boolean[]dpBot = new boolean[n];
			for(int i = 0; i < n; i++) {
				boolean bothTurns = top[i] - '0' > 2 && bot[i] - '0' > 2;
				if((top[i] - '0' <= 2 && (i == 0 || dpTop[i - 1]))
						|| (bothTurns && i > 0 && dpBot[i - 1]))
					dpTop[i] = true;
				if((bot[i] - '0' <= 2 && i > 0 && dpBot[i - 1]) 
						|| (bothTurns && (i == 0 || dpTop[i - 1])))
					dpBot[i] = true;
			}
			out.println(dpBot[n - 1] ? "YES" : "NO");
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