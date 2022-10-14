//package a2oj;
import java.io.*;
import java.util.*;

public class Civilization {
	private static int[]longPath;
	private static int[]set;
	private static ArrayList<LinkedList<Integer>>tree=new ArrayList<LinkedList<Integer>>();
	public static void main(String[]args) throws NumberFormatException, IOException{
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		int n=sc.nextInt(),m=sc.nextInt(),q=sc.nextInt();
		longPath=new int[n];
		set=new int[n];
		for(int i=0;i<n;i++){
			set[i]=i;
			tree.add(new LinkedList<Integer>());
		}
		for(int i=0;i<m;i++){
			int a=sc.nextInt()-1,b=sc.nextInt()-1;
			tree.get(a).add(b);
			tree.get(b).add(a);
		}
		for(int i=0;i<n;i++)
			if(set[i]==i)
				getLongPath(i,i,-1);
		for(int i=0;i<q;i++)
			if(sc.nextInt()==2)
				merge(sc.nextInt()-1,sc.nextInt()-1);
			else
				out.println(length(sc.nextInt()-1));
		out.close();
	}
	private static int getLongPath(int ind,int i,int p){
		set[i]=ind;
		int max=0,sMax=0;
		for(int j:tree.get(i))
			if(j!=p){
				int d=1+getLongPath(ind,j,i);
				if(d>=max){
					sMax=max;
					max=d;
				}else if(d>=sMax)
					sMax=d;
			}
		longPath[ind]=Math.max(longPath[ind],max+sMax);
		return max;
	}
	private static int setOf(int a) {
		while(set[a]!=a)
			a=set[a]=set[set[a]];
		return a;
	}
	private static void merge(int a,int b){
		a=setOf(a);
		b=setOf(b);
		if(a!=b){
			set[a]=b;
			longPath[b]=Math.max(Math.max(longPath[a],longPath[b]),
					(longPath[a]+1)/2+(longPath[b]+1)/2+1);
		}
	}
	private static long length(int a){
		return longPath[setOf(a)];
	}
	public static PrintWriter out;
	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		String next() throws IOException {
			while (st == null || !st.hasMoreElements())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}
		int nextInt() throws NumberFormatException, IOException {
			return Integer.parseInt(next());
		}
	}

}