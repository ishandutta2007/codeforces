import java.io.*;
import java.util.*;
import java.lang.*;

public class Solution {
    static int max1(int a,int b)
    {
        if(a>b)
            return a;
        else
            return b;
    }
    static int max(int a,int b,int c)
    {
        return max1(a,max1(b,c));
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long mod=1000000007;
        long sieve[]=new long[5000001];
        for(int i=0;i<=5000000;i++)
            sieve[i]=0;
        long store[]=new long[5000001];
        for(int i=2;i<=5000000;i++)
        {
            if(sieve[i]==0)
            {
                for(int j=i;j<=5000000;j+=i)
                {
                    if(sieve[j]==0)
                    sieve[j]=i;
                }
            }
        }
        
        store[1]=0;
        for(long i=2;i<=5000000;i++)
        {
            if(sieve[(int)i]==i)
                store[(int)i]=((i*(i-1))/2)%mod;
            else
            {
                long check=i/sieve[(int)i];
                store[(int)i]=(((((sieve[(int)i]*(sieve[(int)i]-1)/2)%mod)*check)%mod)+store[(int)check])%mod;
            }
        }
      //  for(int i=4900000;i<=5000000;i++)
       // {
        //    System.out.println(store[i]);
       // }
        long t=sc.nextLong();
        long l=sc.nextLong();
        long r=sc.nextLong();
        long value=1,sum=0;
        for(int i=(int)l;i<=(int)r;i++)
        { 
            sum=(sum+(value*store[(int)i])%mod)%mod;
            value=(value*t)%mod;
        }
        System.out.print(sum%mod);
    }
}