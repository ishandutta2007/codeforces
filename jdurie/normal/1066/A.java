import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++){
			int Li=sc.nextInt();
			int v=sc.nextInt();
			int l=sc.nextInt();
			int r=sc.nextInt();
			Li-=Li%v;
			System.out.println((l-1)/v+(int)Math.ceil((Li-r)/(double)v));
		}
		sc.close();
	}
}