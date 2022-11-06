import java.io.*;
import java.util.*;
public class B1353 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		for(int cases = 0; cases<t; cases++) {
			int n = readInt();
			int k = readInt();
			int[]array1 = new int[n];
			int[]array2 = new int[n];
			for(int i = 0; i<n; i++) {
				array1[i] = readInt();
			}
			for(int i = 0; i<n; i++) {
				array2[i] = readInt();
			}
			for(int i = 0; i<k; i++) {
				int min1 = Integer.MAX_VALUE;
				int ind1 = 0;
				for(int j = 0; j<n; j++) {
					if(min1>array1[j]) {
						min1 = array1[j];
						ind1 = j;
					}
				}
				int max2 = 0;
				int ind2 = 0;
				for(int j = 0; j<n; j++) {
					if(max2<array2[j]) {
						max2 = array2[j];
						ind2 = j;
					}
				}
				if(min1<max2) {
					int temp = min1;
					array1[ind1] = max2;
					array2[ind2] = min1;
				}
				else {
					break;
				}
			}
			int sum = 0;
			for(int j = 0; j<n; j++) {
				sum+=array1[j];
			}
			System.out.println(sum);
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