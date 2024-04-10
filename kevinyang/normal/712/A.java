import java.util.*;
import java.io.*;
public class A712 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int n = readInt();
		int[]array = new int[n];
		for(int i = 0; i<n; i++)array[i] = readInt();
		int[]array2 = new int[n];
		int cur = array[n-1];
		array2[n-1] = cur;
		for(int i = n-2; i>=0; i--) {
			cur*=-1;
			
			array2[i] = array[i]-cur;
			cur = array2[i]+cur;
		}
		for(int i = 0; i<n; i++) {
			if(i>0)pr.print(" ");
			pr.print(array2[i]);
		}
		pr.println();
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