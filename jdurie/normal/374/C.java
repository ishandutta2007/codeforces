//package a2oj;
import java.io.*;
import java.util.*;
 
public class InnaAndDima {
	// ------------------------
    private static int[]dx={0,0,1,-1};
	private static int[]dy={1,-1,0,0};
	private static char[][]grid;
	private static int n,m;
	private static HashSet<Integer>used=new HashSet<Integer>();
	private static int[][]dfs;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
        n=sc.nextInt();
		m=sc.nextInt();
		grid=new char[n][m];
		for(int i=0;i<n;i++){
			String s=sc.nextLine();
			for(int j=0;j<m;j++)
				grid[i][j]=s.charAt(j);
		}
		dfs=new int[n][m];
		int max=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(grid[i][j]=='D')
					max=Math.max(max,dfs(i,j)/4);
		out.println(max==0?"Poor Dima!":(max==Integer.MAX_VALUE/4?"Poor Inna!":max));
		// ------------------------
		out.close();
	}
	//------------------------
    public static int dfs(int i,int j){
		if(dfs[i][j]>0)
			return dfs[i][j];
		int max=1;
		used.add(i*m+j);
		for(int k=0;k<4;k++){
			int i2=i+dx[k], j2=j+dy[k];
			if(valid(i2,j2)&&"DIMA".indexOf(grid[i][j])=="IMAD".indexOf(grid[i2][j2])){
				if(used.contains(i2*m+j2)||dfs(i2,j2)==Integer.MAX_VALUE)
					return dfs[i][j]=Integer.MAX_VALUE;
				else
					max=Math.max(max,dfs[i2][j2]+1);
			}
		}
		used.remove(i*m+j);
		return dfs[i][j]=max;
	}
    public static boolean valid(int i,int j){
    	return i>=0&&i<n&&j>=0&&j<m;
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