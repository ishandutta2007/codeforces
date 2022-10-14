import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		long n=sc.nextLong();
		int m=sc.nextInt();
		sc.close();
		long[]cts=new long[m];
		for(int i=1;i<=m;i++){
			int mod=(i*i)%m;
			cts[mod]+=n/m;
			if(i<=n%m)
				cts[mod]++;
		}
		long sum=0;
		for(int i=0;i<=m-1;i++)
			sum+=cts[i]*cts[(m-i)%m];
		System.out.println(sum);
	}
}