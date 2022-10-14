import java.util.*;
public class BookOfEvil {
	private static HashMap<Integer,HashSet<Integer>>tree=new HashMap<Integer,HashSet<Integer>>();
	private static int[]dist;
	private static int[]distSec;
	private static int[]maxChild;
	private static boolean[]evil;
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt(),d=sc.nextInt();
		dist=new int[n];
		distSec=new int[n];
		maxChild=new int[n];
		evil=new boolean[n];
		for(int i=0;i<m;i++)
			evil[sc.nextInt()-1]=true;
		for(int i=0;i<n;i++)
			tree.put(i,new HashSet<Integer>());
		for(int i=0;i<n-1;i++){
			int a=sc.nextInt()-1,b=sc.nextInt()-1;
			tree.get(a).add(b);
			tree.get(b).add(a);
		}
		sc.close();
		getDDown(0,-1);
		getDUp(0,-1);
		int ct=0;
		for(int i:dist)
			if(i<=d)
				ct++;
		System.out.println(ct);
	}
	private static void insert(int ind,int val,int a){
		if(val>=dist[a]){
			distSec[a]=dist[a];
			dist[a]=val;
			maxChild[a]=ind;
		}else if(val>=distSec[a])
			distSec[a]=val;
	}
	private static void getDUp(int a,int p){
		if(p>=0&&dist[p]>=0){
			if(maxChild[p]==a)
				insert(p,distSec[p]+1,a);
			else
				insert(p,dist[p]+1,a);
		}
		for(int i:tree.get(a))
			if(i!=p)
				getDUp(i,a);
	}
	private static int getDDown(int a,int p){
		dist[a]=evil[a]?0:Integer.MIN_VALUE;
		distSec[a]=Integer.MIN_VALUE;
		for(int i:tree.get(a))
			if(i!=p&&getDDown(i,a)>=0)
				insert(i,dist[i]+1,a);
		return dist[a];
	}
}