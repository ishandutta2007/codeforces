import java.util.*;
public class SquareDifference {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		for(int i=0;i<n;i++){
			long a=sc.nextLong();
			long b=sc.nextLong();
			if(Math.abs(a-b)==1&&prime(a+b))
				System.out.println("YES");
			else
				System.out.println("NO");
		}
		sc.close();
	}
	public static boolean prime(long x){
		for(int i=2;i<=Math.sqrt(x);i++)
			if(x%i==0)
				return false;
		return true;
	}
}