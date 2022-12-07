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
        long prime[]=new long[3401],g=5,h=7;
        int k=2;
        prime[0]=2;
        prime[1]=3;
        prime[2]=5;
        while(k<3401)
        {
            if(isp(g,prime,k))
                prime[k++]=g;
            if(k<3401&&isp(h,prime,k))
                prime[k++]=h;
            g+=6;
            h+=6;
        }
        int i,j;
      //  for(int m=0;m<3401;m++)
         //   System.out.print(prime[m]+" ");
        Scanner sc=new Scanner(System.in);
        long n=sc.nextLong();
        k=sc.nextInt();
        ArrayList<Long> fact=new ArrayList<Long>();
        int num=k;
        int x=0,y=0;
        while(k!=1&&x<3401)
        {
            if(k%prime[x]==0)
            {
                //System.out.println(prime[x]);
                fact.add(y,prime[x]);
                //System.out.println(y+" "+prime[x]+"y");
                y++;
            }
                while(k%prime[x]==0)
                {
                k/=prime[x];
                //System.out.println(k+" "+prime[x]);
                }
            x++;
        }
       // System.out.println(k);
        if(k!=1)
        {
            fact.add(y,(long)k);
            y++;
        }
        long count[]=new long[y];
        for(i=0;i<y;i++)
            count[(int)i]=0;
        
        x=0;
        
        while(x<y)
        {
            while(num%fact.get(x)==0)
            {
                count[x]++;
                num/=fact.get(x);
            }
            x++;
        }
      //  for(int m=0;m<y;m++)
       // {
           // System.out.println(fact.get(m)+" "+count[m]);
       // }
        long a[]=new long[(int)n];
        
        for(i=0;i<n;i++)
            a[(int)i]=sc.nextLong();
       // long count1[][]=new long[(int)n][(int)y]; 
        
        
        
        long cnt[][]=new long[(int)n+1][y];
        
        for(i=0;i<y;i++)
            cnt[0][(int)i]=0;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<y;j++)
            {
                cnt[i][j]=cnt[i-1][j];
                while(a[(int)i-1]%fact.get((int)j)==0)
                {
                    cnt[i][j]++;
                    a[i-1]/=fact.get(j);
                }
            }
        }
        int l=0,r=0;
        long ans=0;
        while(l<n&&r<n)
        {
            while(r<n&&check(l,r+1,y,(int)n,cnt,count))
                r++;
            if(r==n)
                break;
            ans+=((long)n-(long)r);
            //System.out.println(l+" "+r+" "+ans);
            if(l==r)
                r++;
            l++;
        }
        System.out.print(ans);
    }
}