import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		System.out.println(Math.min(Math.min(3*sc.nextInt()+3,3*sc.nextInt()),3*sc.nextInt()-3));
		sc.close();
	}
}