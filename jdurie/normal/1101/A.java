import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int q=sc.nextInt();
		for(int i=0;i<q;i++){
			double l=sc.nextInt(),r=sc.nextInt(),d=sc.nextInt();
			System.out.println(d<l?(int)d:(int)((int)(r/d+1)*d));
		}
		sc.close();
	}
}