import java.util.*;
import java.io.*;
public class A1365 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt(); int m = readInt();
			int maxr = 0; int maxc = 0;
			int[][]array = new int[n][m];
			for(int i = 0; i<n; i++) {
				for(int j = 0; j<m; j++) {
					array[i][j] = readInt();
				}
			}
			for(int i = 0; i<n; i++) {
				boolean works = true;
				for(int j = 0; j<m; j++) {
					if(array[i][j]==1)works = false;
				}
				if(works)maxr++;
			}
			for(int i = 0; i<m; i++) {
				boolean works = true;
				for(int j = 0; j<n; j++) {
					if(array[j][i]==1)works = false;
				}
				if(works)maxc++;
			}
			int low = Math.min(maxc, maxr);
			if(low%2==0) {
				pr.println("Vivek");
			}
			else {
				pr.println("Ashish");
			}
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