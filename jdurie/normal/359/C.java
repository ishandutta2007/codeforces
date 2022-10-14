import java.util.*;
public class PrimeNumber {
	private static final long MOD=1000000007;
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		long n=sc.nextLong(),x=sc.nextLong(),sum=0;
		TreeMap<Integer,Integer>pows=new TreeMap<Integer,Integer>();
		for(int i=0;i<n;i++){
			int a=sc.nextInt();
			sum+=a;
			boolean b;
			do{
				b=false;
				if(!pows.containsKey(a))
					pows.put(a,1);
				else
					pows.put(a,pows.get(a)+1);
				if(pows.get(a)==x&&a>0){
					pows.remove(a--);
					b=true;
				}
			}while(b);
		}
		sc.close();
		System.out.println(power(x,(sum-pows.lastKey())%(MOD-1)));
	}
	public static long power(long base, long pow){
		if(pow==0)
			return 1;
		if(pow==1)
			return base;
		long p=power(base,pow/2);
		return ((p*p)%MOD)*(pow%2==1?base:1)%MOD;
	}
}