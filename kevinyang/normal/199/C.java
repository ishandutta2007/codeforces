import java.util.*;
import java.io.*;
public class C199 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int k = readInt(); int b = readInt(); int n = readInt(); int t = readInt();
		long z = 1;
		if(t==1) {
			System.out.println(n);
		}
		
		else {
			int i = 1;
			for(i = 1; i<=n; i++) {
				z = z*k+b;
				if(z>t)break;
			}
			System.out.println(n-i+1);
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