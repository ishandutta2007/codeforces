import java.util.*;
public class C {
	private static int A;
	private static int B;
	private static HashMap<Integer,Integer>a;
	private static Integer[]ar;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n=sc.nextLong(), k = sc.nextLong();
		A = sc.nextInt();
		B = sc.nextInt();
		a=new HashMap<Integer,Integer>();
		ar=new Integer[(int)k];
		for(int i=0;i<k;i++){
			int j=sc.nextInt()-1;
			ar[i]=j;
			if(a.containsKey(j))
				a.put(j,a.get(j)+1);
			else
				a.put(j,1);
		}
		Arrays.sort(ar);
		sc.close();
		System.out.println(powToDestroy(0,(long)Math.pow(2,n))[0]);
	}
	public static boolean search(int min,int max,int start,int end){
		if(start==end||start+1==end)
			return (ar[start]>=min&&ar[start]<=max)||(ar[end]>=min&&ar[end]<=max);
		int mid=(start+end)/2;
		if(ar[mid]>=min&&ar[mid]<=max)
			return true;
		else if(ar[mid]>=min)
			return search(min,max,start,mid);
		return search(min,max,mid,end);
	}
	public static long[] powToDestroy(long start,long end){
		if(end==start+1){
			long c=a.containsKey((int)start)?a.get((int)start):-1;
			//System.out.println(start+": "+c);
			return c==-1?new long[]{A,0}:new long[]{B*c,c};
		}
		if(!search((int)start,(int)end-1,0,ar.length-1))
			return new long[]{A,0};
		long[] c1 = powToDestroy(start,(start+end)/2);
		long[] c2 = powToDestroy((start+end)/2,end);
		//System.out.println(start+" "+end+"->"+c1[0]+" "+c2[0]+" "+c1[1]+" "+c2[1]);
		if(c1[1]==-1&&c2[1]==-1)
			return new long[]{Math.min(c1[0]+c2[0], A),c1[1]+c2[1]};
		return new long[]{Math.min(c1[0]+c2[0],B*(c1[1]+c2[1])*(end-start)),c1[1]+c2[1]};
	}
}