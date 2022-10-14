import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int lastT=-1;
		int ct=0;
		for(int i=0;i<n;i++){
			int a=sc.nextInt(),b=sc.nextInt();
			ct+=Math.max(0,Math.min(a, b)-lastT);
			lastT=a==b?a:Math.max(a,b)-1;
			//System.out.println(a+" "+b+" "+lastT+" "+ct);
		}
		System.out.println(ct);
		sc.close();
	}
}