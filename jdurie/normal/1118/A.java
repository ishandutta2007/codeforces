import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int q=sc.nextInt();
		for(int t=0;t<q;t++){
			long n=sc.nextLong(),a=sc.nextLong(),b=sc.nextLong();
			if(2*a<b)
				System.out.println(a*n);
			else
				System.out.println(b*(n/2)+a*(n%2));
		}
		sc.close();
	}
}