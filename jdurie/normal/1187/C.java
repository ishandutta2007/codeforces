//package cfed67;
import java.io.*;
import java.util.*;

public class C{
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),m=sc.nextInt();
		int[]a=new int[n];
		int[][]queries=new int[m][2];
		int ind=0;
		for(int i=0;i<m;i++)
			if(sc.nextInt()==0)
				queries[ind++]=new int[]{sc.nextInt()-1,sc.nextInt()-1};
			else{
				a[sc.nextInt()-1]++;
				a[sc.nextInt()-1]--;
			}
		for(int i=1;i<n;i++)
			a[i]+=a[i-1];
		boolean ok=true;
		for(int i=0;i<ind;i++){
			boolean b=false;
			for(int j=queries[i][0];j<queries[i][1];j++)
				if(a[j]==0){
					b=true;
					break;
				}
			if(!b)
				ok=false;
		}
		System.out.println(ok?"YES":"NO");
		int x=3*n;
		if(ok)
			for(int i:a)
				System.out.print(i==0?x--+" ":x+" ");
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