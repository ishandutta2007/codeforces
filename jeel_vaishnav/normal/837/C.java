import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int a=sc.nextInt();
        int b=sc.nextInt();
        int x[]=new int[n];
        int y[]=new int[n];
        for(int i=0;i<n;i++)
        {
            x[i]=sc.nextInt();
            y[i]=sc.nextInt();
        }
        int max=0;
        for(int i=0;i<n;i++)
        {
            int t1=x[i],t2=y[i];
            for(int j=i+1;j<n;j++)
            {
                int s1=x[j],s2=y[j];
                if((t1+s1<=a||t2+s2<=b)&&t1<=a&&t2<=b&&s1<=a&&s2<=b)
                {
                    int area=t1*t2+s1*s2;
                    if(area>max)
                        max=area;
                }
                s1=y[j];
                s2=x[j];
                if((t1+s1<=a||t2+s2<=b)&&t1<=a&&t2<=b&&s1<=a&&s2<=b)
                {
                    int area=t1*t2+s1*s2;
                    if(area>max)
                        max=area;
                }
            }
            t1=y[i];
            t2=x[i];
            for(int j=i+1;j<n;j++)
            {
                int s1=x[j],s2=y[j];
                if((t1+s1<=a||t2+s2<=b)&&t1<=a&&t2<=b&&s1<=a&&s2<=b)
                {
                    int area=t1*t2+s1*s2;
                    if(area>max)
                        max=area;
                }
                s1=y[j];
                s2=x[j];
                if((t1+s1<=a||t2+s2<=b)&&t1<=a&&t2<=b&&s1<=a&&s2<=b)
                {
                    int area=t1*t2+s1*s2;
                    if(area>max)
                        max=area;
                }
            }
        }
        System.out.print(max);
    }
}