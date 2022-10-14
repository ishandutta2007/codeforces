import java.util.*;
public class YoungPhysicist {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),xSum=0,ySum=0,zSum=0;
		for(int i=0;i<n;i++){
			xSum+=sc.nextInt();
			ySum+=sc.nextInt();
			zSum+=sc.nextInt();
		}
		sc.close();
		System.out.println((xSum==0&&ySum==0&&zSum==0)?"YES":"NO");
	}
}