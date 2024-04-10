import java.util.*;
public class BeautifulNumbers {
	private static final long MOD=1000000007;
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		long a=sc.nextInt(),b=sc.nextInt(),n=sc.nextInt();
		sc.close();
		long ans=0,num=1,denom=1;
		for(long i=0;i<=n;i++){
			if(good(a,b,i*a+(n-i)*b))
				ans=(ans+num*pow(denom,MOD-2)+MOD)%MOD;
			num=(num*(n-i))%MOD;
			denom=(denom*(i+1))%MOD;
		}
		System.out.println(ans);
	}
	public static long choose(long n,long r){
		long num=1;
		for(long i=n;i>n-r;i--)
			num=(num*i)%MOD;
		long denom=1;
		for(long i=2;i<=r;i++)
			denom=(denom*i)%MOD;
		return (num*pow(denom,MOD-2)%MOD);
	}
	public static long pow(long a,long p){
		if(p==1)
			return a;
		long s=pow(a,p/2);
		return (((s*s)%MOD)*(p%2==1?a:1))%MOD;
	}
	public static boolean good(long a,long b,long n){
		long temp=n;
		while(temp>0){
			if(temp%10!=a&&temp%10!=b)
				return false;
			temp/=10;
		}
		return true;
	}
}