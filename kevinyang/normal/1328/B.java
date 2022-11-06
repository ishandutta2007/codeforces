//package cf;
import java.util.*;
import java.io.*;
public class KthBeautifulString {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		for(int tt = 0; tt<t; tt++) {
			int n = readInt();
			long num = readLong();
			char[]array = new char[n];
			Arrays.fill(array, 'a');
			long ll = 0;
			for(int i = 1; i<=n; i++) {
				ll+=i;
				if(ll-num<i & ll-num>=0) {
					array[n-1-i] = 'b';
					array[n-(i-(int)(ll-num))] = 'b';
					break;
				}
			}
			for(int i = 0; i<n; i++) {
				System.out.print(array[i]);
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