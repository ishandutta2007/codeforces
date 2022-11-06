import java.util.*;
import java.io.*;
public class A1364 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt(); int x = readInt();
			int[]array = new int[n];
			int total = 0;
			for(int i = 0; i<n; i++) {
				array[i] = readInt();
				total+=array[i];
			}
			if(total%x!=0) {
				pr.println(n); continue;
			}
			int front = 0;
			int back = 0;
			boolean works = false;
			for(int i = 0; i<n; i++) {
				front++;
				if(array[i]%x!=0) {
					works = true;
					break;
				}
			}
			for(int i = n-1; i>=0; i--) {
				back++;
				if(array[i]%x!=0) {
					works = true;
					break;
				}
			}
			if(!works) {
				pr.println(-1);
			}
			else {
				pr.println(n-Math.min(front, back));
			}
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