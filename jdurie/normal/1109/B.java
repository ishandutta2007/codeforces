//package cf539d1;
import java.io.*;
import java.util.*;

public class B{
	// ------------------------
	static int x=1;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		char[]s=sc.nextLine().toCharArray();
		ans(s,0,s.length);
		out.println(!ok(s)?"Impossible":x);
		// ------------------------
		out.close();
	}
	//------------------------
	static void ans(char[]s, int start,int end){
		int mid=(end-start)/2;
		if(mid>0&&pal(s,start,mid-1))
			ans(s,start,mid);
		if((end-start)%2==1)
			x=2;
	}
	static boolean ok(char[]s){
		for(int i=1;i<s.length;i++)
			if(s[i]!=s[0]&&(s.length%2==0||i!=s.length/2))
				return true;
		return false;
	}
	static boolean pal(char[]s,int start,int end){
		while(start<end)
			if(s[start++]!=s[end--])
				return false;
		return true;
	}
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