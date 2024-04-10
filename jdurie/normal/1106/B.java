import java.util.*;
public class B {
	private static long[]a;
	private static long[]c;
	private static TreeMap<Long,Integer>minCost=new TreeMap<Long,Integer>();
	private static int n,m;
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		m=sc.nextInt();
		a=new long[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextLong();
		c=new long[n];
		for(int i=0;i<n;i++){
			c[i]=sc.nextLong();
			minCost.put(c[i]*n+i,i);
		}
		for(int i=0;i<m;i++){
			int t=sc.nextInt()-1;
			long d=sc.nextLong();
			System.out.println(costFor(t,d));
		}
		sc.close();
	}
	private static long costFor(int i,long d){
		if(minCost.isEmpty())
			return 0;
		long t=Math.min(d, a[i]);
		long cost=t*c[i];
		d-=t;
		a[i]-=t;
		if(a[i]==0)
			minCost.remove(c[i]*n+i);
		if(d>0){
			long cFor=minCost.isEmpty()?0:costFor(minCost.firstEntry().getValue(),d);
			cost=cFor==0?0:cost+cFor;
		}
		return cost;
	}
}