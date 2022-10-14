//package cfed67;
import java.io.*;
import java.util.*;

public class E{
	// ------------------------
	private static HashMap<Integer,HashSet<Integer>>tree=new HashMap<Integer,HashSet<Integer>>();
	static long points=0;
	static long[]size;
	static long[]pts;
	static int n;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		n=sc.nextInt();
		size=new long[n];
		pts=new long[n];
		for(int i=0;i<n;i++)
			tree.put(i,new HashSet<Integer>());
		for(int i=0;i<n-1;i++){
			int a=sc.nextInt()-1,b=sc.nextInt()-1;
			tree.get(a).add(b);
			tree.get(b).add(a);
		}
		points=points(0,-1);
		pts[0]=points;
		getPts(0,-1);
		out.println(points);
		// ------------------------
		out.close();
	}
	//------------------------
	private static void getPts(int i,int p){
		if(i!=0){
			pts[i]=pts[p]+n-2*size[i];
			points=Math.max(points,pts[i]);
		}
		for(int j:tree.get(i))
			if(j!=p)
				getPts(j,i);
	}
	private static long points(int i,int p){
		long pts=0;
		size[i]=1;
		for(int j:tree.get(i))
			if(j!=p){
				pts+=points(j,i);
				size[i]+=size[j];
			}
		return pts+size[i];
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