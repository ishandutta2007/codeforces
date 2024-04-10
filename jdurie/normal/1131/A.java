import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int w1=sc.nextInt(),h1=sc.nextInt();
		int w2=sc.nextInt(),h2=sc.nextInt();
		System.out.println(4+w1+2*h1+w2+2*h2+Math.abs(w2-w1));
		sc.close();
	}
}