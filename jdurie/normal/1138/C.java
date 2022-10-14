import java.io.*;
import java.util.*;

public class C {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),m=sc.nextInt();
		int[][]grid=new int[n][m];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				grid[i][j]=sc.nextInt();
		
		
		int[][]indHor=new int[n][m];
		int[]sHor=new int[n];
		for(int i=0;i<n;i++){
			TreeSet<Integer>nums=new TreeSet<Integer>();
			for(int j=0;j<m;j++)
				nums.add(grid[i][j]);
			sHor[i]=nums.size();
			ArrayList<Integer>a=new ArrayList<Integer>();
			while(!nums.isEmpty())
				a.add(nums.pollFirst());
			for(int j=0;j<m;j++)
				indHor[i][j]=Collections.binarySearch(a,grid[i][j]);
		}
		
		
		int[][]indVer=new int[n][m];
		int[]sVer=new int[m];
		for(int j=0;j<m;j++){
			TreeSet<Integer>nums=new TreeSet<Integer>();
			for(int i=0;i<n;i++)
				nums.add(grid[i][j]);
			sVer[j]=nums.size();
			ArrayList<Integer>a=new ArrayList<Integer>();
			while(!nums.isEmpty())
				a.add(nums.pollFirst());
			for(int i=0;i<n;i++)
				indVer[i][j]=Collections.binarySearch(a,grid[i][j]);
		}
		
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int ind=Math.max(indVer[i][j],indHor[i][j]);
				out.print(Math.max(sHor[i]+ind-indHor[i][j],sVer[j]+ind-indVer[i][j])+" ");
			}
			out.println();
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