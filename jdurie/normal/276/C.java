import java.util.*;
public class LittleGirlMaxSum{
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt();
		Integer[]a=new Integer[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		Arrays.sort(a);
		Integer[]queries=new Integer[n+1];
		for(int i=0;i<=n;i++)
			queries[i]=0;
		for(int i=0;i<m;i++){
			queries[sc.nextInt()-1]++;
			queries[sc.nextInt()]--;
		}
		sc.close();
		for(int i=1;i<=n;i++)
			queries[i]+=queries[i-1];
		Arrays.sort(queries);
		long total=0;
		for(int i=0;i<n;i++)
			total+=(long)queries[i+1]*a[i];
		System.out.println(total);
	}
}