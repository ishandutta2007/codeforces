import java.util.*;
public class C {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long[]b=new long[n/2];
		long[]b2=new long[n/2];
		for(int i=0;i<n/2;i++)
			b[i]=sc.nextLong();
		long r=Long.MAX_VALUE,p=0;
		for(int i=0;i<n/2;i++){
			b2[i]=Math.min(r,b[i]-p);
			b[i]-=b2[i];
			r=b2[i];
			p=b[i];
		}
		for(int i=0;i<n/2;i++)
			System.out.print(b[i]+" ");
		for(int i=n/2-1;i>=0;i--)
			System.out.print(b2[i]+" ");
		sc.close();
	}
}