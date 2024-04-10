import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		int k=sc.nextInt();
		sc.close();
		int spaces=2*(n+m)-4;
		int sum=0;
		for(int i=0;i<k;i++){
			sum+=spaces;
			spaces-=16;
		}
		System.out.println(sum);
	}
}