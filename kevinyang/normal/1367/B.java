import java.util.*;
import java.io.*;
public class B1367 {
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
			int even = 0;
			int odd = 0;
			for(int i = 0; i<n; i++) {
				if(array[i]%2!=i%2) {
					if(i%2==0)even++;
					else odd++;
				}
			}
			if(even!=odd) {
				System.out.println(-1);
			}
			else {
				System.out.println(even);
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