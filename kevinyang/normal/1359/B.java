import java.util.*;
import java.io.*;
public class B1359 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt(); int m = readInt(); int x = readInt(); int y = readInt();
			char[][]array = new char[n][m];
			for(int i = 0; i<n; i++) {
				String s = next();
				for(int j = 0; j<m; j++) {
					array[i][j] = s.charAt(j);
				}
			}
			boolean cheaper = false;
			if(x*2>y) {
				cheaper = true;
			}
			if(!cheaper) {
				int count = 0;
				for(int i = 0; i<n; i++) {
					for(int j = 0; j<m; j++) {
						if(array[i][j] =='.')count++;
					}
				}
				pr.println(count*x);
			}
			else {
				int count = 0;
				for(int i = 0; i<n; i++) {
					for(int j = 0; j<m-1; j++) {
						if(array[i][j]=='.'&array[i][j+1]=='.') {
							array[i][j] = '*'; array[i][j+1] = '*';
							count++;
						}
					}
				}
				int count2 = 0;
				for(int i = 0; i<n; i++) {
					for(int j = 0; j<m; j++) {
						if(array[i][j] =='.')count2++;
					}
				}
				pr.println(count*y+count2*x);
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