import java.util.*;
import java.io.*;
public class C1358 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int x1 = readInt(); int y1 = readInt(); int x2 = readInt(); int y2 = readInt();
			if(x2==x1||y2==y1) {
				pr.println(1);
				continue;
			}
			if(x2-x1==1) {
				pr.println(y2-y1+1);
				continue;
			}
			if(y2-y1==1) {
				pr.println(x2-x1+1);
				continue;
			}
			int num1 = x2-x1;
			int num2 = y2-y1;
			int dif = Math.min(num1, num2)-1;
			long ans = (long)dif*(dif+1);
			
			int dif2 =Math.abs(num2-num1)+1;
			ans += (long)dif2*Math.min(num2, num1);
			pr.println(ans+1);
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