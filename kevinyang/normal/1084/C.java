import java.util.*;
import java.io.*;
public class C1084 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static long mod = (long)1e9+7;
	public static void main(String[]args)throws IOException {
		String s = next();
		ArrayList<Integer>list = new ArrayList<Integer>();
		int count = 0;
		for(int i = 0; i<s.length(); i++) {
			if(s.charAt(i)=='a') {
				count++;
			}
			if(s.charAt(i)=='b') {
				if(count>0)
				list.add(count);
				count = 0;
			}
		}
		if(count>0) list.add(count);
		long[]array= new long[list.size()+1];
		for(int i = 0; i<list.size(); i++) {
			array[i+1] = list.get(i);
		}
		array[0] = 1;
		long prod = 1;
		for(int i = 1; i<=list.size(); i++) {
			prod = (prod*array[i]+prod)%mod;
		}
		prod--;
		pr.println(prod%mod);
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