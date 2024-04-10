import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[]a=new int[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		sc.close();
		int min=Integer.MAX_VALUE;
		for(int x=0;x<n;x++){
			int val=0;
			for(int i=0;i<n;i++)
				val+=a[i]*(Math.abs(x-i)+i+x);
			if(val<min)
				min=val;
		}
		System.out.println(2*min);
	}
}