import java.util.*;
import java.io.*;
public class A199 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int a = 0;
		int b = 1;
		int c = 1;
		int d = 2;
		int n = readInt();
		if(n==0) {
			System.out.println("0 0 0");
		}
		else if(n==1) {
			System.out.println("0 0 1");
		}
		else if(n==2) {
			System.out.println("0 0 2");
		}
		else {
		while(true) {
			if(c+d==n) {
				System.out.println(a+" " + b+ " " + d);
				break;
			}
			if(c+d>n) {
				System.out.println("I'm too stupid to solve this problem");
				break;
			}
			a = b;
			b = c;
			int temp = c+d;
			c = d;
			d = temp;
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