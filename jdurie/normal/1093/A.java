import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++)
			System.out.println((int)Math.ceil(sc.nextDouble()/7.0));
		sc.close();
	}
}