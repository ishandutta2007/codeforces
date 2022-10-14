
import java.io.*;
import java.util.*;

public class B {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),m=sc.nextInt();
		HashMap<Integer,TreeSet<Integer>>aaa=new HashMap<Integer,TreeSet<Integer>>();
		int[][]grid=new int[n][m];
		for(int i=0;i<n;i++){
			aaa.put(i,new TreeSet<Integer>());
			for(int j=0;j<m;j++){
				grid[i][j]=sc.nextInt();
				aaa.get(i).add(grid[i][j]);
			}
		}
		int iii=-1;
		for(int i=0;i<n;i++)
			if(aaa.get(i).size()>1)
				iii=i;
		if(iii==-1){
			int a=0;
			for(int i=0;i<n;i++)
				a=a^aaa.get(i).first();
			System.out.println(a==0?"NIE":"TAK");
			if(a!=0)
				for(int i=0;i<n;i++)
					System.out.print("1 ");
			System.out.println();
		}else{
			int a=0;
			for(int i=0;i<n;i++)
				if(i!=iii)
					a=a^grid[i][0];
			int f=-1;
			for(int i:aaa.get(iii))
				if((a^i)!=0)
					f=i;
			int ii=-1;
			for(int j=0;j<m;j++)
				if(grid[iii][j]==f)
					ii=j;
			System.out.println("TAK");
			for(int i=0;i<n;i++)
				if(i==iii)
					System.out.print((ii+1)+" ");
				else
					System.out.print("1 ");
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