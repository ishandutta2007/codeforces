import java.io.*;
import java.util.*;

public class Solution {
    static int max(int a,int b)
    {
        if(a>b)
            return a;
        else return b;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        String check[]=new String[n];
        for(int i=0;i<n;i++)
        {
            check[i]=sc.next();
        }
        int minx=101,miny=101,maxx=-1,maxy=-1,count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(check[i].charAt(j)=='B')
                {
                    if(i<minx)
                        minx=i;
                    if(j<miny)
                        miny=j;
                    if(j>maxy)
                        maxy=j;
                    if(i>maxx)
                        maxx=i;
                    count++;
                }
            }
        }
        if(count==0)
        {
            System.out.print("1");
            return;
        }
        else
        {
            int sizei=maxx-minx+1,sizej=maxy-miny+1;
            if(sizei>m||sizej>n)
                System.out.print("-1");
            else
                System.out.print(max(sizei,sizej)*max(sizei,sizej)-count);
        }
    }
}