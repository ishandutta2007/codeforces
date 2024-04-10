import java.util.*;
public class Ideone{
	public static void main (String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[]a=new int[n];
		int min=Integer.MAX_VALUE;
		for(int i=0;i<n;i++){
			a[i]=sc.nextInt();
			min=Math.min(min,a[i]);
		}
		System.out.println(2+(min^a[2]));
	}
}