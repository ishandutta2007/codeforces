import java.util.*;

public class B {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		for(int i=0;i<n;i++){
			long k=sc.nextLong(),x=sc.nextLong();
			System.out.println(9*(k-1)+x);
		}
		sc.close();
	}
}