import java.io.*;
import java.util.*;

public class A {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		HashMap<Integer,Long>map=new HashMap<Integer,Long>();
		int n=sc.nextInt();
		for(int i=0;i<26;i++)
			map.put(i, 0L);
		for(int i=0;i<n;i++){
			int x=sc.nextLine().charAt(0)-'a';
			map.put(x,map.get(x)+1);
		}
		long ans=0;
		for(int i=0;i<26;i++){
			ans+=f(map.get(i)/2)+f((map.get(i)+1)/2);
		}
		out.println(ans);
		// ------------------------
		out.close();
	}
	//------------------------
	private static long f(long l){
		return l*(l-1)/2;
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