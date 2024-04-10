import java.io.*;
import java.util.*;

public class Solution {
    static int min(int a,int b)
    {
        if(a<b)
            return a;
        else 
            return b;
    }
    static int max(int a,int b)
    {
        if(a>b)
            return a;
        else
            return b;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int d=sc.nextInt();
        int n=sc.nextInt();
        int m=sc.nextInt();
        int left[]=new int[n+1],right[]=new int[n+2],top[]=new int[m+1],bottom[]=new int[m+2];
        for(int i=0;i<n+1;i++)
        {
            left[i]=0;
            right[i]=0;
        }
        for(int i=0;i<m+1;i++)
        {
            top[i]=0;
            bottom[i]=0;
        }
        right[n+1]=0;
        bottom[m+1]=0;
        
        int x1[]=new int[d];
        int x2[]=new int[d];
        int y1[]=new int[d];
        int y2[]=new int[d];
        
        for(int i=0;i<d;i++)
        {
            x1[i]=sc.nextInt();
            y1[i]=sc.nextInt();
            x2[i]=sc.nextInt();
            y2[i]=sc.nextInt();
            
            left[min(x1[i],x2[i])]++;
            right[max(x1[i],x2[i])]++;
            top[min(y1[i],y2[i])]++;
            bottom[max(y1[i],y2[i])]++;
        }
        
        for(int i=1;i<n+1;i++)
            left[i]=left[i-1]+left[i];
        for(int i=n;i>=1;i--)
            right[i]=right[i+1]+right[i];
        
        for(int i=1;i<m+1;i++)
            top[i]=top[i-1]+top[i];
        for(int i=m;i>=1;i--)
            bottom[i]=bottom[i+1]+bottom[i];
        
        int cnt_l=sc.nextInt();
        int cnt_r=sc.nextInt();
        int cnt_t=sc.nextInt();
        int cnt_b=sc.nextInt();
        int ans=0;
        
        for(int i=0;i<d;i++)
        {
            int cl,cr,ct,cb;
            
            cl=left[max(x1[i],x2[i])-1];
            cr=right[min(x1[i],x2[i])+1];
            ct=top[max(y1[i],y2[i])-1];
            cb=bottom[min(y1[i],y2[i])+1];
            if(x1[i]!=x2[i])
            {
                cl--;
                cr--;
            }
            if(y1[i]!=y2[i])
            {
                ct--;
                cb--;
            }
            //System.out.println(cl+" "+cr+" "+ct+" "+cb);
            if(cnt_l==cl&&cnt_b==cb&&cnt_t==ct&&cnt_r==cr)
                ans=i+1;
        }
        if(ans==0)
            System.out.print("-1");
        else
            System.out.print(ans);
    }
}