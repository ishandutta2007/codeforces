import java.util.*;
import java.io.*;
public class F1360 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		loop:
		while(t--!=0) {
			int n = readInt(); int m = readInt();
			String[]array = new String[n-1];
			for(int i = 0; i<n-1; i++) {
				array[i] = next();
			}
			String s = next();
			if(n==1) {
				System.out.println(s);
				continue;
			}
			for(int i = 0; i<m; i++) {
				for(int j = 0; j<26; j++) {
					String c = s.substring(0,i)+(char)(j+97)+s.substring(i+1);
					boolean works = true;
					for(int k = 0; k<n-1; k++) {
						int dif = 0;
						for(int l = 0; l<m; l++) {
							if(c.charAt(l)!=array[k].charAt(l))dif++;
						}
						if(dif>1) {
							works = false; 
						}
					}
					if(works) {
						System.out.println(c);
						continue loop;
					}
				}
			}
			System.out.println(-1);
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