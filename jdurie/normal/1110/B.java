import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt(),k=sc.nextInt();
		int[]b=new int[n];
		Integer[]diff=new Integer[n-1];
		for(int i=0;i<n;i++)
			b[i]=sc.nextInt();
		for(int i=0;i<n-1;i++)
			diff[i]=b[i+1]-1-b[i];
		Arrays.sort(diff);
		int len=b[n-1]-b[0]+1;
		for(int i=diff.length-1;i>diff.length-k;i--)
			len-=diff[i];
		System.out.println(len);
		sc.close();
	}
}