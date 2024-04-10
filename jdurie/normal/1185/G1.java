//package cf568d2;
import java.util.*;
public class G {
    static int n,t;
    static int[]a;
    static int[]g;
    static long[][][]dp;
    static final long MOD=1000000007;
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        t=sc.nextInt();
        a=new int[n];
        g=new int[n];
        for(int i=0;i<n;i++) {
            a[i] = sc.nextInt();
            g[i] = sc.nextInt();
        }
        dp=new long[4][1<<(n-1)+1][t+1];
        for(int i=0;i<4;i++)
            for(int j=0;j<1<<(n-1)+1;j++)
                for(int k=0;k<=t;k++)
                    dp[i][j][k]=-1;
        System.out.println(dp(0,0,t));
    }
    private static long dp(int genre,int mask,int time){
        if(time<0)
            return 0;
        if(dp[genre][mask][time]!=-1)
            return dp[genre][mask][time];
        if(time==0)
            return 1;
        dp[genre][mask][time]=0;
        for(int i=0;i<n;i++) {
            if (g[i] != genre && ((1 << i) & mask) == 0)
                dp[genre][mask][time] = (dp[genre][mask][time]+dp(g[i], mask | (1 << i), time - a[i]))%MOD;
        }
        return dp[genre][mask][time];
    }
}