import java.util.*;
public class RomanAndNumbers {
	private static long[][]dp;
	private static char[]s;
	private static int m;
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		s=(""+sc.nextLong()).toCharArray();
		m=sc.nextInt();
		sc.close();
		dp=new long[(int)Math.pow(2,s.length)][m];
		for(long[]a:dp)
			for(int i=0;i<a.length;i++)
				a[i]=-1;
		System.out.println(getDP(0,0));
	}
	private static long getDP(int mask,int mod){
		if(dp[mask][mod]>=0)
			return dp[mask][mod];
		if(mask==dp.length-1){
			dp[mask][mod]=mod==0?1:0;
			return dp[mask][mod];
		}
		dp[mask][mod]=0;
		boolean[]used=new boolean[10];
		for(int i=0;i<s.length;i++)
			if(!used[s[i]-'0']&&(mask|1<<i)!=mask&&(mask>0||s[i]!='0')){
				dp[mask][mod]+=getDP(mask|1<<i,(10*mod+(s[i]-'0'))%m);
				used[s[i]-'0']=true;
			}
		return dp[mask][mod];
	}
}