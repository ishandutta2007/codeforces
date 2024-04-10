import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		long n=sc.nextInt(),m=sc.nextInt(),k=sc.nextInt();
		long max=0, sMax=0;
		for(long i=0;i<n;i++){
			long a=sc.nextInt();
			if(a>max){
				sMax=max;
				max=a;
			}else if(a>sMax)
				sMax=a;
		}
		long second=m/(k+1);
		System.out.println((second*sMax+(m-second)*max));
		sc.close();
	}
}