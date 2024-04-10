import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int a=sc.nextInt();
		int b=sc.nextInt();
		int c=sc.nextInt();
		sc.close();
		int max=Math.max(a,Math.max(b,c));
		int sumOfOthers=a+b+c-max;
		System.out.println(Math.max(0,max+1-sumOfOthers));
	}
}