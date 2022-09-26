using System;
using System.Collections.Generic;
using System.Linq; using System.Text;
namespace HelloWorld
{
    class Program 
    {
        static void Main(string[] args)
        {
          int n = Int32.Parse(Console.ReadLine());
          String s = System.Console.ReadLine(); 
          int q;
          int t=5*n;
          for (q=2*n-4; q>=0; q=q-2)
          if (s[q]!=s[q+2])
            t=q;
        if (t==5*n)
        System.Console.Write("YES");
        else
        {
        int ans=1;
        for (int i=0; i<=2*n-4; i=i+2)
        if (s[i]!=s[i+2])
            if ((i+2)%(t+2)!=0)
            ans=0;
        for (int i=t; i<=2*n-4; i+=(t+2))
         if (s[i]==s[i+2])
         ans=0;
         if (((2*n)%(t+2))!=0)
         ans=0;
         
        
        if (ans==1)
          System.Console.Write("YES");
          else
          System.Console.Write("NO");
        } 
         }
         } 
         }