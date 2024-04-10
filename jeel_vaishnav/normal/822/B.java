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
        int m=sc.nextInt();
        int n=sc.nextInt();
        
        String a=sc.next();
        String b=sc.next();
        int min=1001;
        for(int i=0;i<=n-m;i++)
        {
            int count=0;
            for(int j=i;j<i+m;j++)
            {
                if(b.charAt(j)!=a.charAt(j-i))
                    count++;
            }
            if(count<min)
                min=count;
        }
        System.out.println(min);
        for(int i=0;i<=n-m;i++)
        {
            int count=0;
            for(int j=i;j<i+m;j++)
            {
                if(b.charAt(j)!=a.charAt(j-i))
                    count++;
            }
            
            if(count==min)
             {
                for(int j=i;j<i+m;j++)
                    {
                if(b.charAt(j)!=a.charAt(j-i))
                    System.out.print((j-i+1)+" ");
                    }   
                break;
            }
        }
    }
}