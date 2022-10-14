//package cf577d2;
import java.io.*;
import java.util.*;

public class D {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n = sc.nextInt(), m = sc.nextInt(), k = sc.nextInt(), q = sc.nextInt();
		int[][] minMax = new int[n][2];
		for(int i = 0; i < n; i++) {
			minMax[i][0] = Integer.MAX_VALUE;
			minMax[i][1] = Integer.MIN_VALUE;
		}
		minMax[0][0] = 0;
		minMax[0][1] = 0;
		int maxRow = 0;
		for(int i = 0; i < k; i++) {
			int r = sc.nextInt() - 1, c = sc.nextInt() - 1;
			minMax[r][0] = Math.min(minMax[r][0], c);
			minMax[r][1] = Math.max(minMax[r][1], c);
			maxRow = Math.max(r, maxRow);
		}
		TreeSet<Integer> b = new TreeSet<Integer>();
		int[]nextRow = new int[n];
		for(int i = maxRow - 1; i >= 0; i--)
			nextRow[i] = (minMax[i + 1][0] == Integer.MAX_VALUE ? nextRow[i + 1] : i + 1);
		for(int i = 0; i < q; i++)
			b.add(sc.nextInt() - 1);
		long[][]dp = new long[n][2];
		dp[maxRow][0] = minMax[maxRow][1] - minMax[maxRow][0];
		dp[maxRow][1] = minMax[maxRow][1] - minMax[maxRow][0];
		for(int i = maxRow - 1; i >= 0; i--) 
			if(minMax[i][0] != Integer.MAX_VALUE) {
				for(int j = 0; j < 2; j++) {
						dp[i][j] = Long.MAX_VALUE;
						int st = minMax[i][j];
						int d = Math.abs(minMax[i][1 - j] - st);
						boolean okC = st <= b.last();
						boolean okF = st >= b.first();
						if(okC) {
							int ce = b.ceiling(st);
							int dC = Math.abs(st - ce);
							for(int l = 0; l < 2; l++) {
								int dC2 = Math.abs(minMax[nextRow[i]][l] - ce);
								//System.out.println(minMax[nextRow[i]][l] + " "+ce);
								dp[i][j] = Math.min(dp[i][j], d + dC + dC2 + dp[nextRow[i]][1 - l] + nextRow[i] - i);
								//System.out.println("dp["+i+"]["+j+"] = "+d+" + "+dC+" + "+dC2+" + "+dp[nextRow[i]][1 - l]+" + "+ (nextRow[i] - i) +" = "+dp[i][j]);
							}
						}
						if(okF) {
							int fl = b.floor(st);
							int dF = Math.abs(st - fl);
							for(int l = 0; l < 2; l++) {
								int dF2 = Math.abs(minMax[nextRow[i]][l] - fl);
								dp[i][j] = Math.min(dp[i][j], d + dF + dF2 + dp[nextRow[i]][1 - l] + nextRow[i] - i);
								//System.out.println("dp["+i+"]["+j+"] = "+d+" + "+dF+" + "+dF2+" + "+dp[nextRow[i]][1 - l]+" + "+ (nextRow[i] - i) +" = "+dp[i][j]);
							}	
						}
				}
		}
		//for(long[]i:dp)
			//out.println(i[0] + " "+i[1]);
		out.println(dp[0][1]);
		// ------------------------
		out.close();
	}
	//------------------------
	
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