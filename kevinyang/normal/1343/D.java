import java.util.*;
import java.io.*;
public class D1343 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt(); int k = readInt();
			int[]array = new int[n];
			for(int i = 0; i<n; i++) {
				array[i] = readInt();
			}
			int[]choices = new int[2*k+1];
			for(int i = 0; i<n/2; i++) {
				int min = Math.min(array[i], array[n-i-1])+1;
				int max = Math.max(array[i], array[n-i-1])+k;
				int sum = array[i] + array[n-i-1];
				if(sum<2*k)choices[sum]+=1;
				if(max<2*k)choices[max]+=1;
				choices[1]+=2; choices[min-1]-=1; choices[sum-1]-=1;
			}
			int max = n; 
			for(int i = 1;i<choices.length; i++) {
				int num = choices[i-1];
				max = Math.min(max, choices[i]+num);
				choices[i]+=num;
			}
			System.out.println(max);
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