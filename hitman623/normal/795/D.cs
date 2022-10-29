using System;
using System.Linq;
class Program
{
    static void Main()
    {
        var f=1;
        var i=0;
        var nn = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var l = nn[1];
        var n = nn[0];
        var r = nn[2];
        var a = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        var b = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        for(i=0;i<l-1;++i)
        {
        if(a[i]!=b[i]) f=0;
        a[i]=0;b[i]=0;
        }
        for(i=r;i<n;++i)
        {
        if(a[i]!=b[i]) f=0;
        a[i]=0;b[i]=0;
        }
        Array.Sort(a);
        Array.Sort(b);
        for(i=0;i<n;++i)
        {if(a[i]!=b[i]) f=0;}
        if(f==0) Console.WriteLine("LIE");
        else Console.WriteLine("TRUTH");
    }
}