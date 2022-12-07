import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        String s[]=new String[n];
        for(int i=0;i<n;i++)
        {
            s[i]=sc.next();
        }
        int flag1=1,flag2=1;
        if(n%3==0)
        {
            flag1=0;
            int term=n/3;
            char first=s[term-1].charAt(0),second=s[2*term-1].charAt(0),third=s[3*term-1].charAt(0);
            if(first==second||second==third||third==first)
                flag1=1;
            for(int i=0;i<term&&flag1!=1;i++)
            {
                for(int j=0;j<m&&flag1!=1;j++)
                {
                    if(s[i].charAt(j)!=first)
                    {
                        flag1=1;
                    }
                }
            }
            for(int i=term;i<2*term&&flag1!=1;i++)
            {
                for(int j=0;j<m&&flag1!=1;j++)
                {
                    if(s[i].charAt(j)!=second)
                    {
                        flag1=1;
                    }
                }
            }
            for(int i=2*term;i<3*term&&flag1!=1;i++)
            {
                for(int j=0;j<m&&flag1!=1;j++)
                {
                    if(s[i].charAt(j)!=third)
                    {
                        flag1=1;
                    }
                }
            }
        }
        if(m%3==0)
        {
            flag2=0;
            int term=m/3;
            char first=s[0].charAt(term-1),second=s[0].charAt(2*term-1),third=s[0].charAt(3*term-1);
            if(first==second||second==third||third==first)
                flag2=1;
            for(int j=0;j<term&&flag2!=1;j++)
            {
                for(int i=0;i<n&&flag2!=1;i++)
                {
                    if(s[i].charAt(j)!=first)
                    {
                        flag2=1;
                    }
                }
            }
            for(int j=term;j<2*term&&flag2!=1;j++)
            {
                for(int i=0;i<n&&flag2!=1;i++)
                {
                    if(s[i].charAt(j)!=second)
                    {
                        flag2=1;
                    }
                }
            }
            for(int j=2*term;j<3*term&&flag2!=1;j++)
            {
                for(int i=0;i<n&&flag2!=1;i++)
                {
                    if(s[i].charAt(j)!=third)
                    {
                        flag2=1;
                    }
                }
            }
        }
        if(flag1==0||flag2==0)
            System.out.print("YES");
        else
            System.out.print("NO");
    }
}