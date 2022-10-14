
import java.io.*;
import java.util.*;

public class C {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		long f=sc.nextLong(),r=sc.nextLong(),c=sc.nextLong();
		long weeks=Math.min(f/3,Math.min(r/2,c/2));
		f-=3*weeks;
		r-=2*weeks;
		c-=2*weeks;
		long max=0;
		int[]bs={0,1,2,0,2,1,0};
		for(int i=0;i<7;i++){
			long[]food={f,r,c};
			int j=0;
			boolean good=true;
			while(good){
				food[bs[(i+j)%7]]--;
				if(food[bs[(i+j)%7]]<0){
					good=false;
					j--;
				}
				j++;
			}
			max=Math.max(j,max);
		}
		System.out.println(7*weeks+max);
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