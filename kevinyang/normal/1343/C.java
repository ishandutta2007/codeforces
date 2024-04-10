import java.util.*;
import java.io.*;
public class C1343 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt();
			int[]array = new int[n];
			for(int i = 0; i<n; i++) {
				array[i] = readInt();
			}
			boolean positive = false;
			if(array[0]>0)positive = true;
			long total = 0;
			int max = Integer.MIN_VALUE;
			for(int i = 0; i<n; i++) {
				if(positive==array[i]>0) {
					max = Math.max(max, array[i]);
				}
				else {
					total+=max;
					if(array[i]<0)positive = false;
					else positive = true;
					max = array[i];
				}
			}
			total+=max;
			System.out.println(total);
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