//REMEMBER TO COMMENT PACKAGE AND SAVEEEE YOU MONKEY lol 
//package cf;
import java.util.*;
import java.io.*;
public class AandB{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		//REMEMBER TO COMMENT PACKAGE AND SAVEEEE YOU MONKEY lol 
		int n = readInt();
		for(int i = 0; i<n; i++) {
			int a = readInt();
			int b = readInt();
			int c = Math.abs(a-b);
			long ll = 0;
			for(int j = 0; j<=100000; j++) {
				ll+=j;
				if(ll>=c) {
					if((ll-c)%2==0) {
						System.out.println(j);
						break;
					}
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