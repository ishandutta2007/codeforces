//package cfglobal4;
import java.io.*;
import java.util.*;

public class B{
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		char[]s=sc.nextLine().toCharArray();
		long[]wF=new long[s.length];
		long[]wB=new long[s.length];
		for(int i=1;i<s.length;i++){
			wF[i]=wF[i-1];
			if(s[i]=='v'&&s[i-1]=='v')
				wF[i]++;
		}
		for(int i=s.length-2;i>=0;i--){
			wB[i]=wB[i+1];
			if(s[i]=='v'&&s[i+1]=='v')
				wB[i]++;
		}
		long ans=0;
		for(int i=0;i<s.length;i++)
			if(s[i]=='o')
			ans+=wF[i]*wB[i];
		out.println(ans);
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