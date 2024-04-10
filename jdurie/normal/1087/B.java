import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),k=sc.nextInt();
		sc.close();
		int mod=0;
		for(int i=1;i<k;i++)
			if(n%i==0)
				mod=i;
		int div=n/mod;
		System.out.println(div*k+mod);
	}
}