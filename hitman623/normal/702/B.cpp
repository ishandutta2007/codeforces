#include <bits/stdc++.h>

using namespace std;
long long bs1(long long a[],long long b,long long n)
{  long long beg=0,last=n-1,mid=(beg+last)/2;
 while(last>=beg)
 { if(b<a[mid])
   {
   last=mid-1;
   mid=(beg+last)/2;
      }
   else if(b>=a[mid])
   {
   beg=mid+1;
   mid=(beg+last)/2;
      }
  }
 return last;
}
long long bs2(long long a[],long long b,long long n)
{  long long beg=0,last=n-1,mid=(beg+last)/2;
 while(last>=beg)
 { if(b<=a[mid])
   {
   last=mid-1;
   mid=(beg+last)/2;
      }
   else if(b>a[mid])
   {
   beg=mid+1;
   mid=(beg+last)/2;
      }
  }
 return last+1;
}
int main()
{
     long long  n,a[100000],i,l=1,m=0,b=0,c=0,j,bss,d,bss1;
     cin>>n;
        for(i=0;i<n;++i)
            cin>>a[i];
        sort(a,a+n);
      for(i=1;i<32;++i)
      {
        b=pow(2,i);
        for(j=0;j<n && a[j]<b;++j)
        {
         bss=bs1(a,b-a[j],n);
         bss1=bs2(a,b-a[j],n);
         if(bss1<=j && a[bss1]!=a[j]) break;
         if(bss1<=j) bss1=j+1;
         if(bss!=j && bss!=-1) {d=bss-bss1+1;if(d>0)c+=d;}
        }
      }
      cout<<c;
    return 0;
}