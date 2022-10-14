import java.util.*;
public class CountingKangaroos {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		Integer[]k=new Integer[n];
		for(int i=0;i<n;i++)
			k[i]=sc.nextInt();
		sc.close();
		Arrays.sort(k);
		int ind2=n>1?bSearch(2*k[0],k,1,n-1):1,ind=0;
		while(ind2+ind<n){
			ind++;
			ind2=Math.max(Math.max(ind+1,ind2),bSearch(2*k[ind],k,ind+1,n-1)-ind);
		}
		System.out.println(n-ind);
	}
	public static int bSearch(int target,Integer[]k,int start,int end){
		if(end-start<2)
			return k[start]>=target?start:(k[end]>=target?end:100000000);
		int mid=(start+end)/2;
		if(k[mid]<target)
			return bSearch(target,k,mid+1,end);
		return bSearch(target,k,start,mid);
	}
}