import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        
        String a[]=new String[n];
        char s[][]=new char[n][m];
        for(int i=0;i<n;i++)
        {
            a[i]=sc.next();
            s[i]=a[i].toCharArray();
        }
        
        int dp[][][][]=new int[n][m][n][m];
        int check=0,max=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int x=0;x<n-i;x++)
                {
                    for(int y=0;y<m-j;y++)
                    {
                        if(i==0&&j==0)
                        {
                            if(s[x][y]=='0')
                                dp[x][y][x][y]=0;
                            else
                                dp[x][y][x][y]=1;
                        }
                        else if(i==0)
                        {
                            if(dp[x][y][x][y+j-1]==0&&s[x][y+j]=='0')
                                dp[x][y][x][y+j]=0;
                            else
                                dp[x][y][x][y+j]=1;
                        }
                        else if(j==0)
                        {
                            if(dp[x][y][x+i-1][y]==0&&s[x+i][y]=='0')
                                dp[x][y][x+i][y]=0;
                            else
                                dp[x][y][x+i][y]=1;
                        }
                        else
                        {
                          //  System.out.println(s[x+i][y+j]);
                            if(dp[x][y][x+i-1][y+j]==0&&dp[x][y][x+i][y+j-1]==0&&s[x+i][y+j]=='0')
                                dp[x][y][x+i][y+j]=0;
                            else
                                dp[x][y][x+i][y+j]=1;
                        }
                       // System.out.println(x+" "+y+" "+i+" "+j+" "+dp[x][y][x+i][y+j]);
                        if(dp[x][y][x+i][y+j]==0)
                        {
                           // System.out.println(i+" "+j);
                            check=2*(i+j+2);
                            if(check>max)
                                max=check;
                        }
                    }
                }
            }
        }
        System.out.print(max);
    }
}