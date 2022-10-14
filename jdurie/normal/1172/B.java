//package cf564d1;
import java.io.*;
import java.util.*;

public class B{
	// ------------------------
	private static HashMap<Integer,HashSet<Integer>>tree=new HashMap<Integer,HashSet<Integer>>();
	private static int[]size;
	private static long MOD=998244353;
	private static long[]f;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		size=new int[n];
		f=new long[n];
		fillFact();
		for(int i=0;i<n;i++)
			tree.put(i,new HashSet<Integer>());
		for(int i=0;i<n-1;i++){
			int a=sc.nextInt()-1,b=sc.nextInt()-1;
			tree.get(a).add(b);
			tree.get(b).add(a);
		}
		fillSize(0,-1);
		out.println((size[0]*ans(0,-1))%MOD);
		// ------------------------
		out.close();
	}
	//------------------------
	private static void fillFact(){
		f[0]=1;
		for(int i=1;i<f.length;i++)
			f[i]=(i*f[i-1])%MOD;
	}
	private static long ans(int i,int p){
		long ans=f[tree.get(i).size()];
		for(int j:tree.get(i))
			if(j!=p)
				ans=(ans*ans(j,i))%MOD;
		return ans%MOD;
	}
	private static int fillSize(int i,int p){
		size[i]=1;
		for(int j:tree.get(i))
			if(j!=p)
				size[i]+=fillSize(j,i);
		return size[i];
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