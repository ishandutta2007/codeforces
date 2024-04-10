import java.io.*;
import java.util.*;

public class C {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),m=sc.nextInt();
		boolean[][]a=new boolean[n][m];
		boolean[][]b=new boolean[n][m];
		int[]sRow=new int[n];
		int[]sCol=new int[m];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				a[i][j]=sc.nextInt()==1;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				b[i][j]=sc.nextInt()==1;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(a[i][j]!=b[i][j]){
					sRow[i]++;
					sCol[j]++;
				}
		boolean good=true;
		for(int i:sRow)
			if(i%2==1)
				good=false;
		for(int i:sCol)
			if(i%2==1)
				good=false;
		System.out.println(good?"Yes":"No");
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