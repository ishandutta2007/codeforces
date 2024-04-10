//package cfglobal4;
import java.io.*;
import java.util.*;

public class A{
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		long sumI=0,sumO=0;
		HashSet<Integer>s=new HashSet<Integer>();
		int a=sc.nextInt();
		sumI+=a;
		for(int i=1;i<n;i++){
			int x=sc.nextInt();
			if(x<=a/2){
				sumI+=x;
				s.add(i+1);
			}else
				sumO+=x;
		}
		if(sumI>sumO){
			System.out.print((1+s.size())+"\n1");
			for(int i:s)
				System.out.print(" "+i);
			System.out.println();
		}else
			System.out.println(0);
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