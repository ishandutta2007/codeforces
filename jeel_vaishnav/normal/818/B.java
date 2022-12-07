import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
           int n=sc.nextInt();
           int m=sc.nextInt();
        
           int l[]=new int[m];
           int freq[]=new int[n+1];
           int a[]=new int[n];
        
            for(int i=0;i<n;i++)
                a[i]=0;
        
           for(int i=1;i<=n;i++)
               freq[i]=0;
        
           for(int i=0;i<m;i++)
           {
                l[i]=sc.nextInt();
           }
        
            for(int i=1;i<m;i++)
            {
                int value=l[i]-l[i-1];
                if(value<=0)
                    value+=n;
                if(freq[value]==1&&a[l[i-1]-1]!=value)
                {
                    System.out.print("-1");
                    return;
                }
                if(a[l[i-1]-1]!=0&&a[l[i-1]-1]!=value)
                {
                    System.out.print("-1");
                    return;
                }
                a[l[i-1]-1]=value;
                freq[value]=1;
            }
            for(int i=0;i<n;i++)
            {
                if(a[i]==0)
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(freq[j]==0)
                        {
                            a[i]=j;
                            freq[j]=1;
                            break;
                        }
                    }
                }
            }
        for(int i=0;i<n;i++)
            System.out.print(a[i]+" ");
    }
}