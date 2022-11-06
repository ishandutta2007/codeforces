import java.util.*;
import java.io.*;
public class G1360 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt(); int m = readInt(); int a = readInt(); int b = readInt();
			if(n*a==m*b) {
				boolean works = true;
				int[][]array = new int[n][m];
				int mod = m;
				int rem = a;
				for(int i = 2; i<=49; i++) {
					while(true) {
						if(mod%i==0&rem%i==0) {
							mod/=i;
							rem/=i;
						}
						else {
							break;
						}
					}
				}
				for(int i = 0; i<n; i++) {
					for(int j = 0; j<m; j++) {
						if((i+j)%mod<rem) {
							array[i][j] = 1;
						}
					}
				}
				for(int i = 0; i<n; i++) {
					int count = 0;
					for(int j = 0; j<m; j++) {
						count+=array[i][j];
					}
					if(count!=a)works = false;
				}
				for(int j = 0; j<m; j++){
					int count = 0;
					for(int i = 0; i<n; i++) {
						count+=array[i][j];
					}
					if(count!=b)works = false;
				}
				if(works) {
					pr.println("YES");
					for(int i = 0; i<n; i++) {
						for(int j = 0; j<m; j++) {
							pr.print(array[i][j]);
						}
						pr.println();
					}
				}
				else {
					pr.println("NO");
				}
			}
			else {
				pr.println("NO");
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