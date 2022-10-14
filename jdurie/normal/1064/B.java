import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++){
			long a=sc.nextLong();
			long ones=0;
			for(int j=0;j<=30;j++){
				if(a%2==1)
					ones++;
				a/=2;
			}
			System.out.println((long)Math.pow(2,ones));
		}
		sc.close();
	}
}