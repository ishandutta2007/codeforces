//package cf571d2;
import java.io.*;
import java.util.*;

public class D{
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		double[]a=new double[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextDouble();
		int[]b=new int[n];
		long sum=0;
		for(int i=0;i<n;i++){
			b[i]=(int)Math.floor(a[i]);
			sum+=b[i];
		}
		for(int i=0;i<n;i++)
			if(sum<0&&a[i]%1!=0){
				b[i]++;
				sum++;
			}
		for(int i:b)
			out.println(i);
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