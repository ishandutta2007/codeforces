
import java.io.*;
import java.util.*;

public class D {
	// ------------------------
	static HashMap<Integer,HashSet<Integer>>tree=new HashMap<Integer,HashSet<Integer>>();
	static boolean[]max;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		max=new boolean[n];
		for(int i=0;i<n;i++){
			tree.put(i,new HashSet<Integer>());
			max[i]=sc.nextInt()==1;
		}
		for(int i=1;i<=n-1;i++)
			tree.get(sc.nextInt()-1).add(i);
		System.out.println((numLs(0)-usedLs(0)+1));
		// ------------------------
		out.close();
	}
	//------------------------
	private static int usedLs(int i){
		if(tree.get(i).isEmpty())
			return 1;
		if(max[i]){
			int ans=Integer.MAX_VALUE;
			for(int j:tree.get(i))
				ans=Math.min(ans, usedLs(j));
			return ans;
		}else{
			int ans=0;
			for(int j:tree.get(i))
				ans+=usedLs(j);
			return ans;
		}
	}
	private static int numLs(int i){
		if(tree.get(i).isEmpty())
			return 1;
		int ans=0;
		for(int j:tree.get(i))
			ans+=numLs(j);
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