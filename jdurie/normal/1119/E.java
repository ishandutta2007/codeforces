import java.io.*;
import java.util.*;

public class G {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		long[]a=new long[n];
		long[]b=new long[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		long done=0;
		for(int i=0;i<n;i++){
			int m=i==0?0:((int)Math.min(a[i]/2,b[i-1]));
			done+=m;
			a[i]-=2*m;
			if(i>0)
				b[i-1]-=m;
			done+=a[i]/3;
			b[i]=a[i]%3+(i==0?0:b[i-1]);
			a[i]=0;
		}
		System.out.println(done);
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