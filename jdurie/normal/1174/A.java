//package cf563d2;
import java.io.*;
import java.util.*;

public class A{
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		Integer[]a=new Integer[2*n];
		for(int i=0;i<2*n;i++)
			a[i]=sc.nextInt();
		Arrays.sort(a);
		int[]pSum=new int[2*n];
		pSum[0]=a[0];
		for(int i=1;i<2*n;i++)
			pSum[i]=pSum[i-1]+a[i];
		if(2*pSum[n-1]==pSum[2*n-1])
			System.out.println(-1);
		else{
			for(int i:a)
				System.out.print(i+" ");
			System.out.println();
		}
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