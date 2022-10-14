import java.io.*;
import java.util.*;

public class Main {
	// ------------------------
	private static long[]sum;
	private static long[]a;
	private static long[]cost;
	private static HashMap<Integer,HashSet<Integer>>tree=new HashMap<Integer,HashSet<Integer>>();
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		sum=new long[n];
		a=new long[n];
		cost=new long[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextLong();
		for(int i=0;i<n;i++)
			tree.put(i,new HashSet<Integer>());
		for(int i=0;i<n-1;i++){
			int a=sc.nextInt()-1,b=sc.nextInt()-1;
			tree.get(a).add(b);
			tree.get(b).add(a);
		}
		getSum(0,-1);
		addToCost0(0,-1,0);
		for(int i:tree.get(0))
			fillCost(i,0);
		long max=0;
		for(long c:cost)
			max=Math.max(c,max);
		out.println(max);
		// ------------------------
		out.close();
	}
	//------------------------
	private static void fillCost(int i,int p){
		cost[i]=cost[p]+sum[0]-2*sum[i];
		for(int j:tree.get(i))
			if(j!=p)
				fillCost(j,i);
	}
	private static void addToCost0(int i,int p,int d){
		cost[0]+=d*a[i];
		for(int j:tree.get(i))
			if(j!=p)
				addToCost0(j,i,d+1);
	}
	private static long getSum(int i,int p){
		sum[i]=a[i];
		for(int j:tree.get(i))
			if(j!=p)
				sum[i]+=getSum(j,i);
		return sum[i];
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