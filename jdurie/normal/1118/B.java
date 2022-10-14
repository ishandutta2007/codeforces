import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[]a=new int[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		sc.close();
		int[]pSumO=new int[n];
		int[]pSumE=new int[n];
		pSumO[0]=0;
		pSumE[0]=a[0];
		for(int i=1;i<n;i++){
			pSumO[i]=pSumO[i-1];
			pSumE[i]=pSumE[i-1];
			if(i%2==0)
				pSumE[i]+=a[i];
			else
				pSumO[i]+=a[i];
		}
		int[]sSumO=new int[n];
		int[]sSumE=new int[n];
		sSumO[n-1]=(n-1)%2==0?a[n-1]:0;
		sSumE[n-1]=(n-1)%2==0?0:a[n-1];
		for(int i=n-2;i>=0;i--){
			sSumO[i]=sSumO[i+1];
			sSumE[i]=sSumE[i+1];
			if(i%2==1)
				sSumE[i]+=a[i];
			else
				sSumO[i]+=a[i];
		}
		int ct=0;
		/*for(int i:pSumE)
			System.out.printf(" %4d",i);
		System.out.println();
		for(int i:pSumO)
			System.out.printf(" %4d",i);
		System.out.println();
		for(int i:sSumE)
			System.out.printf(" %4d",i);
		System.out.println();
		for(int i:sSumO)
			System.out.printf(" %4d",i);
		System.out.println();*/
		for(int i=0;i<n;i++){
			int even=(i>0?pSumE[i-1]:0)+(i<n-1?sSumE[i+1]:0);
			int odd=(i>0?pSumO[i-1]:0)+(i<n-1?sSumO[i+1]:0);
			if(even==odd)
				ct++;
		}
		System.out.println(ct);
	}
}