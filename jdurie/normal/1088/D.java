//package cf525d2;
import java.io.*;
import java.util.*;

public class D {
	// ------------------------
	static MyScanner sc;
	public static void main(String[] args) {
		sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int c=0,d=0;
		System.out.println("? 0 0");
		System.out.flush();
		int aGb=sc.nextInt();
		for(int i=29;i>=0;i--){
			int r1 = ask(c|(1<<i), d|(1<<i));
			if(r1 != aGb){
				if(aGb==1)
					c|=1<<i;
				else
					d|=1<<i;
				aGb=ask(c,d);
			}else{
				int x=ask(c|(1<<i),d);
				if(x==-1){
					c|=1<<i;
					d|=1<<i;
				}
			}
		}
		System.out.println("! "+c+" "+d);
		System.out.flush();
		// ------------------------
		out.close();
	}
	//------------------------
	static int ask(int c,int d){
		System.out.println("? "+c+" "+d);
		System.out.flush();
		return sc.nextInt();
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