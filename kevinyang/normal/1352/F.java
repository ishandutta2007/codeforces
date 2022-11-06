import java.util.*;
import java.io.*;
public class F1352 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int a = readInt(); int b = readInt(); int c = readInt();
			String ans = "";
			if(b%2==0&b>1) {
				System.out.print("1");
				b--;
			}
			if(a>0)
			for(int i = 0; i<=a; i++) {
				ans += "0";
			}
			if(a==0) {
				if(b>0)
				for(int i = 0; i<=b; i++) {
					if(i%2==1)ans+="1";
					else ans+="0";
				}
				
			}
			else {
				if(b%2==0&b>0) {
					b--;
					ans = "1"+ans;
				}
				for(int i = 0; i<b; i++) {
					if(i%2==0)ans+="1";
					else ans+="0";
				}
			}
			if(a==0&b==0) {
				if(c>0)
				for(int i = 0; i<=c; i++) {
					ans+="1";
				}
			}
			else {
				for(int i = 0; i<c; i++) {
					ans+="1";
				}
			}
			System.out.println(ans);
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