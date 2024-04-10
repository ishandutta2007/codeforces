//package a2oj;
import java.io.*;
import java.util.*;

public class PashmakAndGraph{
	static TreeMap<Integer,LinkedList<Edge>>edges=new TreeMap<Integer,LinkedList<Edge>>();
	static int[]dp;
	public static void main(String[]args){
		MyScanner sc=new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		int n=sc.nextInt(),m=sc.nextInt();
		dp=new int[n];
		for(int i=0;i<m;i++){
			Edge e=new Edge(sc.nextInt()-1,sc.nextInt()-1);
			int w=sc.nextInt();
			if(!edges.containsKey(w))
				edges.put(w,new LinkedList<Edge>());
			edges.get(w).add(e);
		}
		while(!edges.isEmpty()){
			LinkedList<Edge>ll=edges.pollLastEntry().getValue();
			HashMap<Integer,Integer>map=new HashMap<Integer,Integer>();
			for(Edge e:ll)
				if(!map.containsKey(e.a)||map.get(e.a)<dp[e.b]+1)
					map.put(e.a,dp[e.b]+1);
			for(int i:map.keySet())
				dp[i]=Math.max(dp[i],map.get(i));
		}
		int ans=0;
		for(int i:dp)
			ans=Math.max(ans,i);
		out.println(ans);
		out.close();
	}
	static class Edge{
		int a,b;
		public Edge(int A,int B){
			a=A;
			b=B;
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
	}
}