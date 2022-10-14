import java.util.*;
public class Archer {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		double x=sc.nextDouble()/sc.nextDouble(),y=sc.nextDouble()/sc.nextDouble();
		sc.close();
		System.out.println(x/(1-(1-x)*(1-y)));
	}
}