import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int b=sc.nextInt(),k=sc.nextInt();
		boolean odd=false;
		for(int i=k-1;i>=0;i--){
			int a=sc.nextInt();
			if(!(a%2==0||(b%2==0&&i>0)))
				odd=!odd;
		}
		System.out.println(odd?"odd":"even");
		sc.close();
	}
}