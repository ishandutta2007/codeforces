import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		long n=sc.nextLong(),s=sc.nextLong();
		long sum=0,min=Long.MAX_VALUE;
		for(long i=0;i<n;i++){
			long vi=sc.nextLong();
			sum+=vi;
			if(vi<min)
				min=vi;
		}
		sc.close();
		System.out.println(s>sum?-1:Math.min(min,(sum-s)/n));
	}
}