import java.util.*;
import java.io.*;
public class B1354 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			String s = next();
			int low = 3;
			int high = s.length();
			int mid = (low+high)/2;
			while(low<high) {
				int ones = 0;
				int twos = 0;
				int threes = 0;
				for(int i = 0; i<mid; i++) {
					if(s.charAt(i)=='1')ones++;
					if(s.charAt(i)=='2')twos++;
					if(s.charAt(i)=='3')threes++;
				}
				boolean works = false;
				if(ones>0&twos>0&threes>0)works = true;
				for(int i = mid; i<s.length(); i++) {
					if(s.charAt(i)=='1')ones++;
					if(s.charAt(i)=='2')twos++;
					if(s.charAt(i)=='3')threes++;
					if(s.charAt(i-mid)=='1')ones--;
					if(s.charAt(i-mid)=='2')twos--;
					if(s.charAt(i-mid)=='3')threes--;
					if(ones>0&twos>0&threes>0)works = true;
				}
				if(works)high = mid;
				else low = mid+1;
				mid = (low+high)/2;
			}
			if(s.indexOf("1")==-1||s.indexOf("2")==-1||s.indexOf("3")==-1) {
				System.out.println(0);
			}
			else System.out.println(low);
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