import java.io.*;
import java.util.*;

public class F {
	// ------------------------
	static HashMap<Integer,HashSet<Integer>>graph=new HashMap<Integer,HashSet<Integer>>();
	static int[]group;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),m=sc.nextInt();
		int[]edges0=new int[m];
		group=new int[n];
		for(int i=0;i<n;i++)
			graph.put(i,new HashSet<Integer>());
		for(int i=0;i<m;i++){
			int a=sc.nextInt()-1,b=sc.nextInt()-1;
			edges0[i]=a;
			graph.get(a).add(b);
			graph.get(b).add(a);
		}
		if(dfsify(0,1)){
			System.out.println("YES");
			for(int i=0;i<m;i++)
				System.out.print(group[edges0[i]]-1);
		}else
			System.out.println("NO");
		// ------------------------
		out.close();
	}
	private static boolean dfsify(int i,int val){
		group[i]=val;
		boolean b=true;
		for(int j:graph.get(i))
			if(group[j]==0)
				b=b&&dfsify(j,3-val);
			else if(group[j]==val)
				return false;
		return b;
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