import java.util.*;
import java.io.*;
public class B332 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int n = readInt(); int k = readInt();
		int[]array = new int[n];
		for(int i = 0; i<n; i++)array[i] = readInt();
		long sum1 = 0; long sum2 = 0;
		for(int i = 0; i<k; i++) {
			sum1+=array[i];sum2+=array[i+k];
		}
		long max = sum1+sum2;
		long max1 = sum1;
		long ind1 = 1; long ind2 = k+1; long update = 1;
		for(int i = 2*k; i<n; i++) {
			sum2+=(array[i]-array[i-k]); sum1+=(array[i-k]-array[i-2*k]);
			if(sum1>max1) {
				max1 = sum1; update= i-2*k+2;
			}
			if(sum2+max1>max) {
				max = sum2+max1;ind2=i-k+2;ind1= update;
			}
		}
		pr.println(ind1+" " + ind2);
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