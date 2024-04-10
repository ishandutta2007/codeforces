import java.util.*;
public class C {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int q=sc.nextInt();
		for(int t=0;t<q;t++){
			int a=sc.nextInt();
			if(isP2(a+1))
			    System.out.println(factorbs(a));
			else
				System.out.println((int)Math.pow(2,log2ACeil(a))-1);
		}
		sc.close();
	}
	private static int factorbs(int a){
		int maxFactor=1,i=2;
		while(++i<=Math.sqrt(a)&&maxFactor==1)
			if(a%i==0)
				maxFactor=a/i;
		return maxFactor;
	}
	private static boolean isP2(int a){
		long p=Math.round(Math.log(a)/Math.log(2));
		return (int)Math.pow(2,p)==a;
	}
	private static int log2ACeil(int a){
		if(isP2(a))
			a++;
		return (int)Math.ceil(Math.log(a)/Math.log(2));	
	}
}