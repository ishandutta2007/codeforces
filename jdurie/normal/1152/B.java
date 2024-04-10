import java.io.*;
import java.util.*;

public class B{
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
			int x=sc.nextInt();
			int t=0;
			ArrayList<Integer>list=new ArrayList<Integer>();
			while(x!=p2m1(x)){
				if(t%2==0){
					list.add(lg2(x));
					x=x^p2m1(x);
				}else
					x++;
				t++;
			}
			System.out.println(t);
			for(int i:list)
				System.out.print(i+" ");
		// ------------------------
		out.close();
	}
	//------------------------
	private static int p2m1(int x){
		return (int)Math.pow(2,lg2(x))-1;
	}
	private static int lg2(int x){
		int p=0;
		while(x>(1<<p))
			p++;
		return p;
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