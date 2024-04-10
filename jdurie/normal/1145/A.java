
import java.util.*;
public class Ideone{
	public static void main (String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[]a=new int[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		System.out.println(longestSortedLen(a,0,n));
	}
	private static int longestSortedLen(int[]a,int s,int e){
		if(s+1==e)
			return 1;
		int m=(s+e)/2;
		int h1=longestSortedLen(a,s,m), h2=longestSortedLen(a,m,e);
		if(h1==h2&&h1==(e-s)/2&&a[m-1]<=a[m])
			return e-s;
		return Math.max(h1,h2);
	}
}