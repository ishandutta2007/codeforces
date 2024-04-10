import java.util.*;
public class Matrix {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		sc.nextLine();
		String s=sc.nextLine();
		sc.close();
		int[]pSum=new int[s.length()+1];
		for(int i=1;i<pSum.length;i++)
			pSum[i]=Integer.parseInt(""+s.charAt(i-1))+pSum[i-1];
		HashMap<Long,Long>factors=new HashMap<Long,Long>();
		for(int st=1;st<pSum.length;st++)
			for(int en=st;en<pSum.length;en++){
				long sum=pSum[en]-pSum[st-1];
				if(a==0||(sum>0&&a%sum==0))
					factors.put(sum,factors.containsKey(sum)?factors.get(sum)+1:1);
			}
		long ways=0;
		if(a==0&&factors.containsKey(0L)){
			for(long i:factors.keySet())
				if(i!=0)
					ways+=2*factors.get(0L)*factors.get(i);
			ways+=factors.get(0L)*factors.get(0L);
		}else if(a>0){
			for(long i:factors.keySet())
				if(factors.containsKey(a/i))
					ways+=factors.get(i)*factors.get(a/i);
		}
		System.out.println(ways);
	}
}