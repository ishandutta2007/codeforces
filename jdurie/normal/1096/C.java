import java.util.*;
public class C {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++){
			double ang=sc.nextDouble(),n=2;
			boolean b=false;
			while(!b){
				n++;
				double a=180*(n-2)/n;
				b=ang*(n-2)%a==0&&ang<=a;
			}
			System.out.println((int)n);
		}
		sc.close();
	}
}