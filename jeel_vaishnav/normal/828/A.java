import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int a=sc.nextInt();
        int b=sc.nextInt();
        int ca=0,cb=0,cb1=0,count=0;
        for(int i=0;i<n;i++)
        {
            int t=sc.nextInt();
            if(t==1)
            {
                ca++;
                if(ca>a)
                {
                    ca--;
                    cb1++;
                    if(cb+cb1>b)
                    {
                        cb1--;
                        if(cb1>0)
                        {
                            cb1--;
                            cb++;
                        }
                        else
                            count++;
                    }
                }
            }
            if(t==2)
            {
                cb++;
                if(cb+cb1>b)
                {
                    cb--;
                    count+=2;
                }
            }
            //System.out.println(count+" "+ca+" "+cb+" "+cb1);
        }
        System.out.print(count);
    }
}