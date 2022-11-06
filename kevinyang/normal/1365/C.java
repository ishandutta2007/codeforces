import java.util.*;
import java.io.*;
public class C1365 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int n = readInt();
		int[]array = new int[n]; int[]indices2 = new int[n+1];
		int[]perms = new int[n];
		for(int i = 0; i<n; i++)array[i] = readInt();
		for(int i = 0; i<n; i++) {
			indices2[readInt()] = i;
		}
		for(int i = 0; i<n; i++) {
			int num = array[i];
			int ind2 = indices2[num];
			perms[(i-ind2+n)%n]++;
		}
		int max = 0;
		for(int i = 0; i<n; i++) {
			max = Math.max(perms[i], max);
		}
		pr.println(max);
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