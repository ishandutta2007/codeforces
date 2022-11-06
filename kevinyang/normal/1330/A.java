//package cf;
import java.util.*;
import java.io.*;
public class DreammoonAndRankingCollection{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException{
		int cases = readInt();
		for(int cas = 0; cas<cases; cas++) {
			int n = readInt();
			int x = readInt();
			boolean[]array = new boolean[204];
			for(int i = 0; i<n; i++) {
				array[readInt()] = true;
			}
			for(int i = 1; i<array.length; i++) {
				if(x==0)break;
				if(!array[i]) {
					x--;
					array[i] = true;
				}
			}
			for(int i = 1; i<array.length; i++) {
				if(!array[i]) {
					System.out.println(i-1);
					break;
				}
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