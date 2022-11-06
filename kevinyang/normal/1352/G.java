import java.io.*;
import java.util.*;
public class G1352 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int n = readInt();
		for(int i = 0; i<n; i++) {
			int m = readInt();
			if(m<=3)System.out.println(-1);
			else {
				int start = 0;
				if(m%2==1)start = m;
				else start = m-1;
				for(int j = start; j>0; j-=2) {
					System.out.print(j+ " ");
				}
				System.out.print("4 2 ");
				for(int j = 6; j<=m; j+=2) {
					System.out.print(j);
					if(j<m-1)System.out.print(" ");
				}
				System.out.println();
			}
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