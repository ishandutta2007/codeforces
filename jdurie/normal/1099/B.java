import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		sc.close();
		double s=Math.ceil(Math.sqrt(n));
		System.out.println((int)Math.round(s+Math.ceil(n/s)));
	}
}