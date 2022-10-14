import java.util.*;
public class SerejaAndSuffixes {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt();
		int[]nums=new int[n+1];
		HashSet<Integer>set=new HashSet<Integer>();
		int[]distinctTo=new int[n+1];
		for(int i=1;i<=n;i++)
			nums[i]=sc.nextInt();
		for(int i=n;i>0;i--){
			set.add(nums[i]);
			distinctTo[i]=set.size();
		}
		for(int i=0;i<m;i++)
			System.out.println(distinctTo[sc.nextInt()]);
		sc.close();
	}
}