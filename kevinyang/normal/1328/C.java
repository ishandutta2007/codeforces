//REMEMBER TO COMMENT PACKAGE AND SAVEEEE YOU MONKEY lol 
//package cf;
import java.util.*;
import java.io.*;
public class TernaryXOR{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException{
		//REMEMBER TO COMMENT PACKAGE AND SAVEEEE YOU MONKEY lol 
		int cases = readInt();
		for(int cas = 0; cas<cases; cas++) {
			int n = readInt();
			String s = next();
			boolean greater = false;
			char[]array1 = new char[s.length()];
			char[]array2 = new char[s.length()];
			for(int i = 0; i<s.length(); i++) {
				if(!greater) {
					if(s.charAt(i)=='1') {
						array1[i] = '1';
						array2[i] = '0';
						greater = true;
					}
					else if(s.charAt(i)=='2') {
						array1[i] = '1';
						array2[i] = '1';
					}
					else {
						array1[i] = '0';
						array2[i] = '0';
					}
				}
				else {
					array1[i] = '0';
					array2[i] = s.charAt(i);
				}
			}
			for(int i = 0; i<s.length(); i++) {
				System.out.print(array1[i]);
			}
			System.out.println();
			for(int i = 0; i<s.length(); i++) {
				System.out.print(array2[i]);
			}
			System.out.println();
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