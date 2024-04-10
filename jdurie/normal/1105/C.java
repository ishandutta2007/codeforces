import java.util.*;
public class C {
	private static final long MOD=1000000007;
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), l = sc.nextInt(), r = sc.nextInt();
		sc.close();
		long[][]dp=new long[n][3];
		int m=l+(3-l%3)%3,q=r-r%3;
		for(int i=l;i<m;i++)
			dp[0][i%3]++;
		for(int i=q;i<=r;i++)
			dp[0][i%3]++;
		for(int i=0;i<3;i++)
			dp[0][i]+=(q-m)/3;
		for(int i=1;i<n;i++) {
			dp[i][0]=fill(dp,i,0);
			dp[i][1]=fill(dp,i,1);
			dp[i][2]=fill(dp,i,2);
		}
		System.out.println(dp[n-1][0]);
	}
	public static long fill(long[][]dp,int i,int k){
		long total=0;
		for(int j=0;j<3;j++)
			total=(total+dp[0][j]*dp[i-1][(3+k-j)%3])%MOD;
		return total;
	}
}