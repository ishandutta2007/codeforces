import java.io.*;
import java.util.*;

public class Main {
	// ------------------------
    private static HashMap<Integer,HashSet<Integer>>tree=new HashMap<Integer,HashSet<Integer>>();
	private static int badCt=0;
	private static int max=0;
	private static TreeSet<Integer>ans=new TreeSet<Integer>();
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
        int n=sc.nextInt();
		for(int i=1;i<=n;i++)
			tree.put(i,new HashSet<Integer>());
		for(int i=0;i<n-1;i++){
			int a=sc.nextInt(),b=sc.nextInt();
			tree.get(a).add(b);
			tree.get(b).add(-a);
		}
		fillBad(1,-1,0);
		System.out.println(badCt-max);
		while(!ans.isEmpty())
			out.print(ans.pollFirst()+" ");
		// ------------------------
		out.close();
	}
	//------------------------
	private static void fillBad(int a,int p,int b){
		if(b==max)
			ans.add(a);
		else if(b>max){
			max=b;
			ans=new TreeSet<Integer>();
			ans.add(a);
		}
		for(int i:tree.get(a)){
			int j=Math.abs(i);
			if(j!=p){
				if(j!=i)
					badCt++;
				fillBad(j,a,b+(i==j?-1:1));
			}
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