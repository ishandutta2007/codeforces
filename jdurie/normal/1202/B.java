//package cfed70;
import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		char[] s = sc.nextLine().toCharArray();
		for(int i = 0; i <= 9; i++) {
			for(int j = 0; j <= 9; j++) {
				int[][]dist = new int[10][10];
				for(int x = 0; x < 10; x++)
					for(int y = 0; y < 10; y++)
						dist[x][y] = 100;
				for(int a = 0; a < 10; a++)
					for(int b = 0; b < 10; b++)
						if(a + b != 0)
							for(int x = 0; x < 10; x++) {
								int y = (x + a * i + b * j) % 10;
								dist[x][y] = Math.min(dist[x][y], a + b);
							}
				long ans = 0;
				for(int c = 1; c < s.length; c++)
					if(ans == -1 || dist[s[c - 1] - '0'][s[c] - '0'] == 100)
						ans = -1;
					else
						ans += (dist[s[c - 1] - '0'][s[c] - '0'] - 1);
				out.print(ans +" ");
			}
			out.println();
		}
		out.close();
	}
	public static PrintWriter out;
	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				} 
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