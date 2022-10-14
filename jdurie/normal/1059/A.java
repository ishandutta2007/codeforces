import java.util.*;
public class Cashier {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int L=sc.nextInt();
		int a=sc.nextInt();
		int lastTime=0;
		int breaks=0;
		for(int i=0;i<n;i++){
			int time=sc.nextInt();
			breaks+=(time-lastTime)/a;
			lastTime=time+sc.nextInt();
		}
		sc.close();
		breaks+=(L-lastTime)/a;
		System.out.println(breaks);
	}
}