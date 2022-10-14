import java.util.*;
public class LuckyTree {
	private static HashMap<Integer,HashSet<Integer>>unlucky=new HashMap<Integer,HashSet<Integer>>();
	private static boolean[]used;
	private static long n;
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		used=new boolean[(int)n];
		for(int i=0;i<n-1;i++){
			int u=sc.nextInt()-1,v=sc.nextInt()-1,w=sc.nextInt();
			if(unlucky(w)){
				if(!unlucky.containsKey(u))
					unlucky.put(u,new HashSet<Integer>());
				unlucky.get(u).add(v);
				if(!unlucky.containsKey(v))
					unlucky.put(v,new HashSet<Integer>());
				unlucky.get(v).add(u);
			}
		}
		sc.close();
		long ans=n*(n-1)*(n-2);
		for(int i:unlucky.keySet())
			if(!used[i])
				ans-=bs(size(i,-1));
		System.out.println(ans);
	}
	private static long bs(long x){
		return 2*x*(x-1)*(n-x)+x*(x-1)*(x-2);
	}
	private static int size(int i,int p){
		int size=1;
		used[i]=true;
		for(int j:unlucky.get(i))
			if(j!=p)
				size+=size(j,i);
		return size;
	}
	private static boolean unlucky(int w){
		while(w>0){
			if(w%10!=4&&w%10!=7)
				return true;
			w/=10;
		}
		return false;
	}
}