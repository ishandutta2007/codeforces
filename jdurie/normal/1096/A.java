import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++){
			int x=sc.nextInt();
			sc.nextInt();
			System.out.println(x+" "+2*x);
		}
		sc.close();
	}
}