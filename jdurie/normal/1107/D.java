import java.io.*;
import java.util.*;

public class D {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		boolean[][]grid=new boolean[n][n];
		for(int i=0;i<n;i++){
			String s=sc.nextLine();
			for(int j=0;j<n/4;j++)
				fill(grid,i,4*j,s.charAt(j));
		}
		/*for(boolean[]a:grid){
			for(boolean b:a)
				System.out.print(b?1:0);
			System.out.println();
		}*/
		HashSet<Integer>factors=new HashSet<Integer>();
		for(int i=2;i<=n;i++)
			if(n%i==0)
				factors.add(i);
		int max=n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				if(j>0&&grid[i][j]!=grid[i][j-1]){
					max=gcd(max,j);
				}
				if(i>0&&grid[i][j]!=grid[i-1][j]){
					max=gcd(max,i);
				}
			}
		out.println(max);
		// ------------------------
		out.close();
	}
	//------------------------
	public static int gcd(int a,int b){
		if(a==1||b==1)
			return 1;
		int max=Math.max(a, b);
		int min=Math.min(a, b);
		if(max%min==0)
			return min;
		else
			return gcd(min,max-min);
	}
	public static void fill(boolean[][]grid,int i,int j,char c){
		int ind="0123456789ABCDEF".indexOf(c);
		for(int l=0;l<4;l++){
			int p=(int)Math.pow(2,3-l);
			grid[i][j+l]=ind>=p;
			if(ind>=p)
				ind-=p;
		}
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