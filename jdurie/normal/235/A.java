import java.util.*;
public class LCMChallenge {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		long n=sc.nextLong();
		sc.close();
		if(n<3)
			System.out.println(n);
		else if(n%2==0)
			System.out.println((n-1)*(n-3)*(n%3==0?n-2:n));
		else
			System.out.println(n*(n-1)*(n-2));
	}
}