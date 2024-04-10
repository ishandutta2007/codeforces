import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
            int n=sc.nextInt();
            long s=sc.nextInt();
           
            long a[]=new long[n];
            
            for(int i=0;i<n;i++)
                a[i]=sc.nextLong();
        
            long start=0,end=n,k=0,T=0;
            while(start<=end)
            {
                long mid=(start+end)/2;
                
                long b[]=new long[n];
                for(int i=0;i<n;i++)
                    b[i]=a[i]+((long)(i+1))*((long)mid);
                Arrays.sort(b);
                
                long cost=0,x=0;
                for(int i=0;i<mid;i++)
                    cost+=b[i];
                //System.out.println(mid+" "+cost);
                if(cost<=s)
                {
                    k=mid;
                    T=cost;
                    start=mid+1;
                }
                else
                    end=mid-1;
            }
        
            System.out.print(k+" "+T);
    }
}