import java.util.*;
public class C {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		double n=sc.nextDouble(),r=sc.nextDouble();
		System.out.println(r/(1/Math.sin(Math.PI/n)-1));
		sc.close();
	}
}