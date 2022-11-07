import java.util.*;
import java.io.*;
public class B1352 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt();
			int k = readInt();
			if(k%2==0&n%2==1) {
				System.out.println("NO");
				continue;
			}
			if(k%2==0&n<k) {
				System.out.println("NO");
				continue;
			}
			else if(k%2==0) {
				System.out.println("YES");
				for(int i = 0; i<k-1; i++) {
					System.out.print("1 ");
				}
				System.out.println(n-(k-1));
				continue;
			}
			if(n%2==1) {
				if(n<k) {
					System.out.println("NO");
					continue;
				}
				System.out.println("YES");
				for(int i = 0; i<k-1; i++) {
					System.out.print("1 ");
				}
				System.out.println(n-(k-1));
				continue;
			}
			if(n<2*k) {
				System.out.println("NO");
				continue;
			}
			System.out.println("YES");
			for(int i = 0; i<k-1; i++) {
				System.out.print("2 ");
			}
			System.out.println(n-(2*k-2));
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