import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int a=0;
		boolean b=true;
		a+=2*sc.nextInt();
		sc.nextInt();
		if(sc.nextInt()>0&&a==0)
			b=false;
		a-=2*sc.nextInt();
		if(a!=0)
			b=false;
		System.out.println(b?1:0);
		sc.close();
	}
}