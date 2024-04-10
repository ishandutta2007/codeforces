import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),k=sc.nextInt();
		int[]mod=new int[k];
		for(int i=0;i<n;i++)
			mod[sc.nextInt()%k]++;
		sc.close();
		int ans=2*(mod[0]/2);
		for(int i=1;i<k/2.0;i++)
			ans+=2*Math.min(mod[i],mod[k-i]);
		if(k%2==0)
			ans+=2*(mod[k/2]/2);
		System.out.println(ans);
	}
}