//package a2oj;
import java.util.*;

public class DimaAndHares {
	static int n;
	static int[][] a;
	static int[][] dp;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		a = new int[n][3];
		dp = new int[n][2];
		for(int j = 0; j < 3; j++)
			for(int i = 0; i < n; i++)
				a[i][j] = sc.nextInt();
		for(int i = 0; i < n; i++)
			for(int j = 0; j < 2; j++)
				dp[i][j] = -1;
		System.out.println(dp(0,0));
		sc.close();
	}
	static int dp(int i, int j){
		if(dp[i][j] != -1)
			return dp[i][j];
		if(i == n - 1)
			return dp[i][j] = a[i][j];
		return dp[i][j] = Math.max(a[i][j] + dp(i + 1, 1), 
				a[i][j + 1] + dp(i + 1, 0));
	}
}