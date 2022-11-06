import java.util.*;
import java.io.*;
public class B1365 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt();
			int[]array = new int[n]; int[]sorted = new int[n]; int[]type = new int[n];
			for(int i = 0; i<n; i++) {
				array[i] = readInt(); sorted[i] = array[i];
			}
			int ones = 0; int zeroes = 0;
			for(int i = 0; i<n; i++) {
				type[i] = readInt();
				if(type[i]==0)zeroes++;
				else ones++;
			}
			Arrays.sort(sorted);
			if(ones!=n&zeroes!=n) {
				pr.println("Yes"); continue;
			}
			else {
				boolean works = true;
				for(int i = 0; i<n; i++) {
					if(array[i]!=sorted[i])works = false;
				}
				if(works)pr.println("Yes");
				else pr.println("No");
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