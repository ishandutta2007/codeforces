import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int sum=0,max=0;
		for(int i=0;i<n;i++){
			int num=sc.nextInt();
			sum+=num;
			if(num>max){
				max=num;
			}
		}
		sc.close();
		System.out.println(Math.max(max,(2*sum/n)+1));
	}
}