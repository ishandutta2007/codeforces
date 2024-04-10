import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[]a=new int[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		sc.close();
		int max=0,len=0,cLen=0;
		for(int i:a){
			if(i>max){
				max=i;
				cLen=1;
				len=1;
			}
			else if(i==max)
				cLen++;
			len=Math.max(len, cLen);
			if(i<max)
				cLen=0;
		}
		System.out.println(len);
	}
}