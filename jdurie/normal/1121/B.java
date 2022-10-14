import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[]a=new int[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		sc.close();
		int[]counts=new int[200001];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				counts[a[i]+a[j]]++;
		int max=0;
		for(int i:counts)
			max=Math.max(max,i/2);
		System.out.println(max);
	}
}