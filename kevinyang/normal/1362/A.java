import java.util.*;
import java.io.*;
public class A1362 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		long[]powers = new long[61];
		powers[0] = 1;
		for(int i = 1; i<=60; i++) {
			powers[i] = powers[i-1]*2;
		}
		while(t--!=0) {
			long c = readLong(); long d = readLong();
			long a = Math.min(c, d); long b = Math.max(c,d);
			if(a<b) {
				if(b%a==0) {
					long num = b/a;
					if(Arrays.binarySearch(powers,num)>=0) {
						long total = 0;
						while(num>=8) {
							total+=1;
							if(num%8!=0) {
								break;
							}
							num/=8;
						}
						if(num==2||num==4) {
							total+=1; num = 1;
						}
						pr.println(total);
					}
					else {
						pr.println(-1);
					}
				}
				else {
					pr.println(-1);
				}
			}
			else {
				pr.println(0);
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