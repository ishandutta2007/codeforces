//package cf566d2;
import java.io.*;
import java.util.*;

public class B{
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),m=sc.nextInt();
		boolean possible=true;
		int row=-1,col=-1;
		boolean rowDone=false,colDone=false;
		for(int i=0;i<n;i++){
			char[]s=sc.nextLine().toCharArray();
			for(int j=0;j<m;j++)
				if(s[j]=='*'){
					if(col==-1){
						if(j!=0&&j!=m-1)
							col=j;
						else
							possible=false;
					}
					else if(col!=j&&row==-1){
						if(j<col&&i!=0&&i!=n-1)
							row=i;
						else
							possible=false;
					}
					else if(col!=j&&row!=i)
						possible=false;
					if(col==j&&colDone)
						possible=false;
					if(row==i&&rowDone)
						possible=false;
				}else{
					if(row==i){
						if(j>col+1)
							rowDone=true;
						else
							possible=false;
					}
					if(col==j){
						if(row!=-1&&i>row+1)
							colDone=true;
						else
							possible=false;
					}
				}
		}
		out.println(possible&&row!=-1&&col!=-1?"YeS":"nO");
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