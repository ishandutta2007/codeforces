import java.util.*;
import java.io.*;
public class B1360 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt();
			int[]array = new int[n];
			for(int i = 0; i<n; i++) {
				array[i] = readInt();
			}
			Arrays.sort(array);
			int min = Integer.MAX_VALUE;
			for(int i = 0; i<n-1; i++) {
				int dif = array[i+1]-array[i];
				min = Math.min(min, dif);
			}
			System.out.println(min);
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