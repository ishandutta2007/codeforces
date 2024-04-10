import java.util.*;
import java.io.*;
public class C1335 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt();
			int[]freq = new int[n+1];
			for(int i = 0; i<n; i++)freq[readInt()]++;
			int low = 0;
			int high = n;
			int mid = (low+high)/2;
			while(low<high) {
				boolean works = true;
				int[]freq2 = new int[n+1];
				for(int i = 0; i<=n; i++) {
					freq2[i] = freq[i];
				}
				int index = 0;
				int max = 0;
				for(int i = 0; i<=n; i++) {
					if(freq[i]>max) {
						max = freq[i];
						index = i;
					}
				}
				freq2[index]-=mid;
				if(freq2[index]<0)works = false;
				int count = 0;
				for(int i = 0; i<=n; i++) {
					if(freq2[i]>=1)count++;
				}
				if(count<mid)works = false;
				if(works) {
					low = mid;
				}
				else {
					high = mid-1;
				}
				mid = (low+high+1)/2;
			}
			pr.println(low);
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