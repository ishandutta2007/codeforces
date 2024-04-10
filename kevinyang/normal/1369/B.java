import java.util.*;
import java.io.*;
public class B1369 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt();
			String s = next();
			int start = 0;
			int end = 0;
			if(s.indexOf('0')==-1||s.indexOf('1')==-1) {
				System.out.println(s); continue;
			}
			for(int i = 0; i<n; i++) {
				if(s.charAt(i)=='1') {
					start = i; break;
				}
			}
			for(int i = n-1; i>=0; i--) {
				if(s.charAt(i)=='0') {
					end = i;
					break;
				}
			}
			boolean contains1 = false;
			boolean contains0 = false;
			for(int i = start; i<=end; i++) {
				if(s.charAt(i)=='1') {
					contains1 = true;
				}
				else {
					contains0 = true;
				}
			}
			System.out.print(s.substring(0,start));
			if(contains0)System.out.print(0);
			else if(contains1) System.out.print(1);
			System.out.println(s.substring(end+1));
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
	static char readChar () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}