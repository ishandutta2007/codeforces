import java.util.*;
public class A {
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int[]a=new int[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		int min=Integer.MAX_VALUE;
		int minT=-1;
		for(int t=1;t<=100;t++) {
			int sum=0;
			for(int i=0;i<n;i++)
				if(a[i]>t)
					sum+=Math.abs(a[i]-t-1);
				else if(a[i]<t)
					sum+=Math.abs(t-1-a[i]);
			if(sum<min){
				minT=t;
				min=sum;
			}
		}
		System.out.println(minT+" "+min);
		sc.close();
	}
}