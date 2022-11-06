import java.util.*;
import java.io.*;
public class B1345 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		long[]dp = new long[30000];
		for(int i = 1; i<30000; i++) {
			dp[i] = (long)i*(3*i+1)/2;
		}
		while(t--!=0) {
			long n = readLong();
			int count = 0;
			while(n>1) {
				int index = Arrays.binarySearch(dp, n);
				if(index>=0) {
					count++;
					break;
				}
				index+=1;
				index*=-1;
				index--;
				n-=dp[index];
				count++;
			}
			System.out.println(count);
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