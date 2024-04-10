//package a2oj;
import java.util.*;
import java.io.*;

public class JzzhuAndCities {
	private static ArrayList<LinkedList<Pair>>graph = new ArrayList<LinkedList<Pair>>();
	private static long[] dist;
	private static boolean[] trainAvail;
	private static TreeMap<Long,TreeSet<Integer>>queue=new TreeMap<Long,TreeSet<Integer>>();
	public static void main(String[]args){
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		int n=sc.nextInt(), m=sc.nextInt(), k=sc.nextInt();
		for(int i=0;i<n;i++)
			graph.add(new LinkedList<Pair>());
		for(int i=0;i<m;i++){
			int a=sc.nextInt()-1, b=sc.nextInt()-1;
			long d=sc.nextLong();
			graph.get(a).add(new Pair(d,b));
			graph.get(b).add(new Pair(d,a));
		}
		dist=new long[n];
		trainAvail=new boolean[n];
		for(int i=1;i<n;i++)
			dist[i]=Long.MAX_VALUE;
		for(int i=0;i<k;i++){
			int c=sc.nextInt()-1;
			add(dist[c],sc.nextLong(),c,true);
		}
		queue.put(0L,new TreeSet<Integer>());
		queue.get(0L).add(0);
		while(!queue.isEmpty())
			dijkstra(pollFirst());
		int ct=0;
		for(int i=0;i<n;i++)
			if(trainAvail[i])
				ct++;
		System.out.println(k-ct);
		out.close();
	}
	private static void add(long oldD, long d, int c, boolean train){
		if(d<=oldD){
			if(oldD != Long.MAX_VALUE){
				queue.get(oldD).remove(c);
				if(queue.get(oldD).isEmpty())
					queue.remove(oldD);
			}
			if(!queue.containsKey(d))
				queue.put(d,new TreeSet<Integer>());
			queue.get(d).add(c);
			dist[c] = d;
			trainAvail[c]=train;
		}
	}
	private static int pollFirst(){
		int x=queue.firstEntry().getValue().pollFirst();
		if(queue.firstEntry().getValue().isEmpty())
			queue.pollFirstEntry();
		return x;
	}
	private static void dijkstra(int a){
		for(Pair p:graph.get(a))
			add(dist[p.city], dist[a]+p.dist,p.city,false);
	}
	public static class Pair{
		public long dist;
		public int city;
		public Pair(long d,int c){
			dist=d;
			city=c;
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