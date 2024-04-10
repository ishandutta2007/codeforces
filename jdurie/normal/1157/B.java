import java.io.*;
import java.util.*;

public class B{
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		char[]s=sc.nextLine().toCharArray();
		char[]f=new char[9];
		for(int i=0;i<9;i++)
			f[i]=(char)('0'+sc.nextInt());
		int ind=0;
		while(ind<n&&s[ind]>=f[s[ind]-'1'])
			ind++;
		if(ind<n)
			while(ind<n&&s[ind]<=f[s[ind]-'1']){
				s[ind]=f[s[ind]-'1'];
				ind++;
			}
		for(char c:s)
			out.print(c);
		out.println();
		// ------------------------
		out.close();
	}
	//------------------------

	public static PrintWriter out;
	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
}