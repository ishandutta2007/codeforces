import java.io.*;
import java.util.*;

public class B {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		char[]s=sc.nextLine().toCharArray();
		long ans=(long)s.length*(long)(s.length+1)/2L;
		for(int i=0;i<s.length;i++)
			ans-=bad(i,s);
		out.println(ans);
		// ------------------------
		out.close();
	}
	//------------------------
	public static long bad(int ind,char[]s){
		long ans=0;
		for(int i=ind;i<s.length;i++){
			if(works(s,ind,i))
				break;
			ans++;
		}
		return ans;
	}
	public static boolean works(char[]s,int st,int en){
		if(en-st<2)
			return false;
		for(int i=st+1;i<=en-1;i++)
			for(int j=1;j<=Math.min(i-st,en-i);j++)
				if(s[i]==s[i-j]&&s[i]==s[i+j])
					return true;
		return false;
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