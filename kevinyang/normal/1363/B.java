import java.util.*;
import java.io.*;
public class B1363 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			char[]array = next().toCharArray();
			int[]psa = new int[array.length+1];
			for(int i = 0; i<array.length; i++) {
				if(array[i]=='1') {
					psa[i+1] = 1+psa[i];
				}
				else {
					psa[i+1] = psa[i];
				}
			}
			int max = Integer.MAX_VALUE;
			for(int i = 0; i<=array.length; i++) {
				int ones = psa[i];//left
				int zeroes = (array.length-i)-(psa[array.length]-psa[i]);//right
				max = Math.min(ones+zeroes, max);
				zeroes = i-psa[i];
				ones = psa[array.length]-psa[i];
				max = Math.min(zeroes+ones, max);
			}
			pr.println(max);
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