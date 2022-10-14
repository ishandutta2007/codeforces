import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),max=Integer.MIN_VALUE,sMax=Integer.MIN_VALUE,min=Integer.MAX_VALUE,sMin=Integer.MAX_VALUE;
		for(int i=0;i<n;i++){
			int d=sc.nextInt();
			if(d>=max){
				sMax=max;
				max=d;
			}else if(d>sMax)
				sMax=d;
			if(d<=min){
				sMin=min;
				min=d;
			}else if(d<sMin)
				sMin=d;
		}
		sc.close();
		System.out.println(n==2?0:Math.min(max-sMin,sMax-min));
	}
}