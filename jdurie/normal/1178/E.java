//package cfglobal4;
import java.io.*;
import java.util.*;

public class E{
	// ------------------------
	class Pair{
		int i,j;
		public Pair(int I,int J){
			i=I;
			j=J;
		}
	}
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		char[]s=sc.nextLine().toCharArray();
		int n=s.length;
		int[][]floor=new int[n][3];
		int[][]ceil=new int[n][3];
		for(int i=0;i<n;i++)
			for(int j=0;j<3;j++)
				floor[i][j]=s[i]-'a'==j?i:(i==0?-1:floor[i-1][j]);
		for(int i=n-1;i>=0;i--)
			for(int j=0;j<3;j++)
				ceil[i][j]=s[i]-'a'==j?i:(i==n-1?-1:ceil[i+1][j]);
		X[][]dp=new X[s.length/2][3];
		for(int k=0;k<3;k++)
		dp[0][k]=new X(ceil[0][k],floor[n-1][k],-1);
		//System.out.println(dp[0][0]);
		for(int i=1;i<s.length/2;i++)
			for(int j=0;j<3;j++){
				dp[i][j]=new X(-1,-1,40000);
				for(int k=0;k<3;k++){
						X last = dp[i-1][k];
						int left=last.i!=-1?ceil[last.i+1][j]:-1,right=last.j!=-1?floor[last.j-1][j]:-1;
						//System.out.println(i+" "+(char)('a'+j)+" "+(char)(k+'a')+" ("+last+") "+left+" "+right);
						if(left!=-1 && right!=-1 &&left<=right){
							if(dp[i][j].i==-1||dp[i][j].j-dp[i][j].i<right-left)
								dp[i][j]=new X(left, right,k);
						}else
							dp[i][j]=new X(-1,-1,-1);
				}
			}
		//System.out.println(ceil[1][1]);
		//System.out.println(dp[1][1]);
		outer:
		for(int d=s.length/2-1;d>=0;d--){
			for(int i=0;i<3;i++){
				int length=(d+1)*2-(dp[d][i].i==dp[d][i].j?1:0);
				if(length>=n/2&&dp[d][i].i!=-1){
					LinkedList<Character>ll=print(dp,d,i);
					for(char c:ll)
						out.print(c);
					if(dp[d][i].i==dp[d][i].j)
						ll.removeLast();
					while(!ll.isEmpty())
						out.print(ll.removeLast());
					out.println();
					break outer;
				}
			}
		}
		// ------------------------
		out.close();
	}
	//------------------------
	static LinkedList<Character> print(X[][]dp,int ind,int c){
		if(c==-1)
			return new LinkedList<Character>();
		//System.out.println(c);
		LinkedList<Character> aaa=print(dp,ind-1,dp[ind][c].l);
		aaa.add((char)('a'+c));
		return aaa;
	}
	static class X{
		int i,j,l;
		public X(int I,int J,int L){
			i=I;
			j=J;
			l=L;
		}
		public String toString(){
			return i+" "+j+" "+(char)(l+'a');
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