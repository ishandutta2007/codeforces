import java.util.*;
public class D {
	private static final long MOD=998244353;
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		sc.close();
		long total=n-1;
		long r=n;
		while(r>=2)
			total=(total*r--+MOD)%MOD;
		long x=0;
		long term=1;
		while(n-x>=3){
			term=(term*(n-x++)+MOD)%MOD;
			total=(total-term+MOD)%MOD;
		}
		while(total<0)
			total+=MOD;
		System.out.println(n==1?1:total);
	}
}