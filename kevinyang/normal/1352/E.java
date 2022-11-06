import java.util.*;
import java.io.*;
public class E1352 {
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
			int[]psa = new int[n+1];
			for(int i = 1; i<=n; i++) {
				psa[i] = psa[i-1]+array[i];
			}
			boolean[]choice = new boolean[n+1];
			for(int i = 0; i<=n-2; i++) {
				for(int j = i+2; j<=n; j++) {
					int sum = psa[j]-psa[i];
					if(sum<=n)
					choice[sum] = true;
				}
			}
			int count = 0;
			for(int i = 1; i<=n; i++) {
				if(choice[array[i]])count++;
			}
			pr.println(count);
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