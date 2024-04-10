import java.util.*;
public class VasyaAndRobot {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),l=sc.nextInt(),r=sc.nextInt(),Ql=sc.nextInt(),Qr=sc.nextInt();
		int[]psum=new int[n];
		psum[0]=sc.nextInt();
		for(int i=1;i<n;i++)
			psum[i]=psum[i-1]+sc.nextInt();
		sc.close();
		int min=psum[n-1]*r+(n-1)*Qr;
		for(int i=0;i<n;i++){
			int cost=psum[i]*l+(psum[n-1]-psum[i])*r+Math.max(0,Math.abs(n-2*(i+1))-1)*(i+1<n/2?Qr:Ql);
			if(cost<min)
				min=cost;
		}
		System.out.println(min);
	}
}