import java.util.*;
import java.io.*;
public class A1354 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int a = readInt(); int b = readInt(); int c = readInt(); int d = readInt();
			a-=b;
			if(a<=0) {
				System.out.println(b);
				continue;
			}
			long ans = b;
			int subtract = c-d;
			int total = 0;
			if(subtract<=0) {
				System.out.println(-1);
				continue;
			}
			else {
				total+=a/subtract;
				if(a%subtract!=0)total++;
				ans +=(long)total*c;
			}
			System.out.println(ans);
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