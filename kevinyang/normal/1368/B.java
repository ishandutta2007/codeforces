import java.util.*;
import java.io.*;
public class B1368 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		long k = readLong();
		int[]array = new int[10];
		Arrays.fill(array, 1);
		String s = "codeforces";
		int index = 0;
		if(k==1) {
			pr.println(s);
		}
		else {
			while(true) {
				array[index%10]++;
				index++;
				long p = 1;
				for(int i = 0; i<10; i++) {
					p*=array[i];
				}
				if(p>=k) {
					break;
				}
			}
			for(int i = 0; i<10; i++) {
				int num = array[i];
				for(int j = 0; j<num; j++) {
					pr.print(s.charAt(i));
				}
			}
			pr.println();
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