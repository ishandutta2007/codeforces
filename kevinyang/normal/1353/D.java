import java.io.*;
import java.util.*;
public class D1353 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		for(int cases = 0; cases<t; cases++) {
			int n = readInt();//base 10^6 first is sublength second is index
			PriorityQueue<Long>indices = new PriorityQueue<Long>(Collections.reverseOrder());
			indices.add((long)n*1000000+(-1)*1);
			int[]array = new int[n+1];
			for(int i = 1; i<=n; i++) {
				long num = indices.poll();
				int len = (int)(num/1000000+1);
				int l = (int)(1000000-num%1000000);
				long r = l+(len-1);
				if((r-l+1)%2==1)array[(int)(l+r)/2] = i;
				else array[(int)(l+r-1)/2] = i;
				if(len==1) {
					
				}
				else if(len%2==1) {
					int l1 = l;
					int l2 = l+((len+1)/2);
					indices.add((long)(len/2)*1000000 + (-1)*l1);
					indices.add((long)(len/2)*1000000 + (-1)*l2);
				}
				else if(len==2){
					indices.add((long)(len/2)*1000000 +(-1)*(l+1));
				}
				else {
					int l1 = l;
					int l2 = l+(len/2);
					indices.add((long)(len/2-1)*1000000 +(-1)*l1);
					indices.add((long)(len/2)*1000000 +(-1)*l2);
				}
			}
			for(int i = 1; i<=n; i++) {
				pr.print(array[i]);
				if(i!=n)pr.print(" ");
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
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}