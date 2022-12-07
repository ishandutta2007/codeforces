import java.io.*;
import java.util.*;
import java.lang.*;

public class Solution {
    static int max(int a,int b)
    {
        if(a>b)
            return a;
        else
            return b;
    }
    static int min(int a,int b)
    {
        if(a<b)
            return a;
        else
            return b;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        
        String s[]=new String[n];
        int boundl[]=new int[n];
        int boundr[]=new int[n];
        int max_floor=-1;
        for(int i=n-1;i>=0;i--)
        {
            s[i]=sc.next();
            int count=0;
            for(int j=0;j<m+2;j++)
            {
                if(s[i].charAt(j)=='1'&&max_floor==-1)
                    max_floor=i;
                if(s[i].charAt(j)=='1')
                    count=1;
            }
            if(max_floor!=-1)
            {
                if(count==1)
                {
                    for(int j=0;j<m+2;j++)
                    {
                        if(s[i].charAt(j)=='1')
                        {
                            boundr[i]=j;
                            break;
                        }
                    }
                    for(int j=m+1;j>=0;j--)
                    {
                        if(s[i].charAt(j)=='1')
                        {
                            boundl[i]=j;
                            break;
                        }
                    }
                }
                else
                {
                    boundl[i]=0;
                    boundr[i]=m+1;
                }
            }
            else
            {
                boundl[i]=0;
                boundr[i]=m+1;
            }
        }
        if(max_floor==-1)
        {
            System.out.print("0");
            return;
        }
        int dp[][]=new int[max_floor+1][2];     
        boundr[0]=boundl[0];
        dp[0][0]=boundl[0];
        dp[0][1]=boundl[0];
        for(int i=1;i<=max_floor;i++)
        {
            dp[i][0]=min(dp[i-1][0]+boundl[i-1]+boundl[i]+1,dp[i-1][1]+boundr[i-1]+boundl[i]+1);
            dp[i][1]=min(dp[i-1][0]+2*m+3-boundr[i]-boundl[i-1],dp[i-1][1]+2*m+3-boundr[i]-boundr[i-1]);
        }
        //for(int i=0;i<=max_floor;i++)
            //System.out.println(dp[i][0]+" "+dp[i][1]);
        System.out.print(min(dp[max_floor][0],dp[max_floor][1]));
    }
}