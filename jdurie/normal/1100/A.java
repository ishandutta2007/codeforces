import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),k=sc.nextInt();
		int[]a=new int[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		sc.close();
		int max=0;
		for(int b=0;b<n;b++){
			int diff=0;
			for(int i=0;i<n;i++)
				if(((int)Math.abs(i-b))%k>0){
					diff+=a[i];
				}
			max=Math.max(Math.abs(diff),max);
		}
		System.out.println(max);
	}
}