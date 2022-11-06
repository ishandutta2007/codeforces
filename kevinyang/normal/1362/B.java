import java.util.*;
import java.io.*;
public class B1362 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt();
			int[]array = new int[n];
			for(int i = 0; i<n; i++)array[i] = readInt();
			Arrays.sort(array);
			int[]newarray = new int[n];
			int ans = -1;
			
			for(int k = 1; k<=1500; k++) {
				boolean b = true;
				for(int i = 0; i<n; i++) {
					newarray[i] = array[i]^k;
				}
				Arrays.sort(newarray);
				for(int i = 0; i<n; i++) {
					if(newarray[i]!=array[i]) {
						b = false;
						break;
					}
				}
				if(b) {
					ans = k;
					break;
				}
			}
			pr.println(ans);
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