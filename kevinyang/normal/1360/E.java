import java.util.*;
import java.io.*;
public class E1360 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt();
			int[][]array = new int[n][n];
			for(int i = 0; i<n; i++) {
				String s = next();
				for(int j = 0; j<n; j++) {
					int a = (int)s.charAt(j)-48;
					array[i][j] = a;
				}
			}
			int[][]array2 = new int[n][n];
			for(int i = n-1; i>=0; i--) {
				if(i==n-1) {
					for(int j = 0; j<n; j++) {
						if(array[j][i]==1) {
							array2[j][i] = 1;
						}
					}
					for(int j = 0; j<n; j++) {
						if(array[i][j]==1) {
							array2[i][j]=1;
						}
					}
				}
				else {
					for(int j = i; j>=0; j--) {
						if(array[j][i]==1) {
							if(array2[j+1][i]==1||array2[j][i+1]==1) {
								array2[j][i] = 1;
							}
						}
						if(array[i][j]==1) {
							if(array2[i][j+1]==1||array2[i+1][j]==1) {
								array2[i][j] = 1;
							}
						}
					}
				}
			}
			boolean works = true;
			for(int i = 0; i<n; i++) {
				for(int j = 0; j<n; j++) {
					if(array[i][j]!=array2[i][j])works = false;
				}
			}
			if(works)System.out.println("YES");
			else System.out.println("NO");
		}
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