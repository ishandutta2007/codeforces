import java.io.*;
import java.util.*;

public class Main {
    static int max(int a,int b)
    {
        if(a>b)
            return a;
        else 
            return b;
    }
    static boolean isp(long num,long prime[],long k)
    {
        boolean flag=true;
        for(int i=0;i<k;i++)
        {
            if(num%prime[i]==0)
            {
                flag=false;
                break;
            }
        }
        return flag;
    }
    static boolean check(int l,int r,int y,int n,long[][] cnt,long[] sum)
    {
        boolean check=false;
        for(int i=0;i<y;i++)
        {
            //System.out.println("O/p: "+cnt[r][i]+" "+cnt[l][i]+" "+sum[i]);
            if(cnt[r][i]-cnt[l][i]<sum[i])
            {
                //System.out.println(l+" "+(r-1)+" "+(cnt[r][i]-cnt[l][i]))
                check=true;
                break;
            }
        }
        //System.out.println(l+" "+(r-1)+" "+check);
        return check;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int poss[][]=new int[4][4];
    for(int i=0;i<4;i++)
        {
        for(int j=0;j<4;j++)
            poss[i][j]=sc.nextInt();
    }
    int flag=0;
    if(poss[0][3]==1)
        {
        if(poss[0][1]==1||poss[0][2]==1||poss[0][0]==1)
            flag=1;
        if(poss[1][0]==1)
            flag=1;
        if(poss[2][1]==1)
            flag=1;
        if(poss[3][2]==1)
            flag=1;
    }
    if(poss[1][3]==1)
        {
        if(poss[1][1]==1||poss[1][2]==1||poss[1][0]==1)
            flag=1;
        if(poss[2][0]==1)
            flag=1;
        if(poss[3][1]==1)
            flag=1;
        if(poss[0][2]==1)
            flag=1;
    }
    if(poss[2][3]==1)
        {
        if(poss[2][1]==1||poss[2][2]==1||poss[2][0]==1)
            flag=1;
        if(poss[3][0]==1)
            flag=1;
        if(poss[0][1]==1)
            flag=1;
        if(poss[1][2]==1)
            flag=1;
    }
    if(poss[3][3]==1)
        {
        if(poss[3][1]==1||poss[3][2]==1||poss[3][0]==1)
            flag=1;
        if(poss[0][0]==1)
            flag=1;
        if(poss[1][1]==1)
            flag=1;
        if(poss[2][2]==1)
            flag=1;
    }
    if(flag==1)
        System.out.print("YES");
    else System.out.print("NO");
    }
}