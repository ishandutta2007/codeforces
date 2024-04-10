import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		long n=sc.nextLong();
		long x=sc.nextLong();
		long y=sc.nextLong();
		sc.close();
		System.out.println(x+y<=n+1?"White":"Black");
	}
}