import java.util.*;
public class C {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[]a=new int[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		sc.close();
		Arrays.sort(a);
		int midL=a[n-1];
		int midR=a[n-2];
		int i=n-3;
		String ans=midL+" "+midR;
		while(i>0){
			int d1=Math.max(Math.abs(midL-a[i]),Math.abs(midR-a[i-1]));
			int d2=Math.max(Math.abs(midL-a[i-1]),Math.abs(midR-a[i]));
			if(d1<d2){
				midL=a[i];
				midR=a[i-1];
			}else{
				midL=a[i-1];
				midR=a[i];
			}
			ans=midL+" "+ans+" "+midR;
			i-=2;
		}
		if(i==0){
			midL=a[0];
			ans=midL+" "+ans;
		}
		System.out.println(ans);
	}
}