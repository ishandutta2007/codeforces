import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
           int n=sc.nextInt();
           int a=sc.nextInt();
        
           int freq[]=new int[1000001];
            
           for(int i=0;i<1000001;i++)
               freq[i]=0;
              
           int flag=0;
        
           for(int i=0;i<n;i++)
           {
               int b;
               b=sc.nextInt();
               if(b!=a&&freq[b]>=freq[a])
               {
                   freq[b]++;
               }
               if(b==a)
                   freq[b]++;
           }
            int ans=0;
           for(int i=0;i<=1000000;i++)
           {
                if(i!=a&&freq[i]>=freq[a])
                {
                    flag=1;
                    ans=i;
                }
           }
           if(flag==0)
               System.out.print("-1");
        else
            System.out.print(ans);
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}