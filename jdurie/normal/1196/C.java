//package cf575d3;
import java.io.*;
import java.util.*;

public class C {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int t=sc.nextInt();
		for(int w=0;w<t;w++){
			int n=sc.nextInt();
			int minX=-100000,maxX=100000;
			int minY=-100000,maxY=100000;
			for(int i=0;i<n;i++){
				int x=sc.nextInt(),y=sc.nextInt();
				if(sc.nextInt()==0)
					minX=Math.max(x,minX);
				if(sc.nextInt()==0)
					maxY=Math.min(y,maxY);
				if(sc.nextInt()==0)
					maxX=Math.min(x,maxX);
				if(sc.nextInt()==0)
					minY=Math.max(y,minY);
			}
			if(maxX<minX||maxY<minY)
				out.println(0);
			else
				out.println("1 "+minX+" "+minY);
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