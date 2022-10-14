
import java.io.*;
import java.util.*;

public class C{
	// ------------------------
	static HashMap<Integer,HashSet<Integer>>tree=new HashMap<Integer,HashSet<Integer>>();
	static boolean[] used;
	static final long MOD=1000000007;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),k=sc.nextInt();
		for(int i=0;i<n;i++)
			tree.put(i,new HashSet<Integer>());
		used=new boolean[n];
		for(int i=0;i<n-1;i++){
			int u=sc.nextInt()-1,v=sc.nextInt()-1,x=sc.nextInt();
			if(x==0){
				tree.get(u).add(v);
				tree.get(v).add(u);
			}
		}
		long bad=0;
		for(int i=0;i<n;i++)
			if(!used[i])
				bad+=pow(dfs(i),k);
		long ans=pow(n,k)-bad;
		while(ans<0)
			ans+=MOD;
		System.out.println(ans%MOD);
		// ------------------------
		out.close();
	}
	//------------------------
	private static long pow(long x,long p){
		if(p==0)
			return 1;
		long a=pow(x,p/2);
		return (((a*a)%MOD)*(p%2==1?x:1))%MOD;
	}
	private static long dfs(int i){
		used[i]=true;
		int ans=1;
		for(int j:tree.get(i))
			if(!used[j])
				ans+=dfs(j);
		return ans;
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