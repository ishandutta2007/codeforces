import java.util.*;
public class F {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long[]nums=new long[n];
		for(int i=0;i<n;i++)
			nums[i]=sc.nextInt();
		for(int i=n-1;i>0;i--)
			nums[i]-=nums[i-1];
		sc.close();
		ArrayList<Integer>ks=new ArrayList<Integer>();
		for(int k=1;k<=n;k++){
			boolean possible=true;
			for(int i=0;i<n-k;i++)
				if(nums[i]!=nums[i+k])
					possible=false;
			if(possible)
				ks.add(k);
		}
		System.out.println(ks.size());
		for(int i:ks)
			System.out.print(i+" ");
	}
}