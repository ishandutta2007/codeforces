import java.io.*;
import java.util.*;

public class E {
	// ------------------------
	private static int k;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		k=sc.nextInt();
		char[]sC=sc.nextLine().toCharArray();
		char[]tC=sc.nextLine().toCharArray();
		int[]s=new int[k];
		int[]t=new int[k];
		for(int i=0;i<k;i++){
			s[i]=sC[i]-'a';
			t[i]=tC[i]-'a';
		}
		stringify(add(s,half(subt(t,s))));
		// ------------------------
		out.close();
	}
	private static void stringify(int[]a){
		for(int i:a)
			out.print((char)(i+'a'));
	}
	private static int[] subt(int[]a,int[]b){
		int[]res=new int[k];
		int c=0;
		for(int i=k-1;i>=0;i--){
			res[i]=a[i]-c-b[i];
			if(res[i]<0){
				res[i]+=26;
				c=1;
			}else
				c=0;
		}
		return res;
	}
	private static int[] add(int[]a,int[]b){
		int[]res=new int[k];
		int c=0;
		for(int i=k-1;i>=0;i--){
			res[i]=(a[i]+b[i]+c)%26;
			c=(a[i]+b[i]+c)/26;
		}
		return res;
	}
	private static int[] half(int[]a){
		int[]res=new int[k];
		int c=0;
		for(int i=0;i<k;i++){
			res[i]=(a[i]+c*26)/2;
			c=a[i]%2;
		}
		return res;
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