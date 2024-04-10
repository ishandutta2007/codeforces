#include <iostream>
#include<bits/stdc++.h>
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
 return last+1;
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
 return beg+1;
}
int main()
{
   long long n,x,a[100000],i,c=0,d,p=0;
   cin>>n>>x;
   for(i=0;i<n;++i)
    cin>>a[i];
    sort(a,a+n);
   if(x!=0)
    for(i=0;i<n;++i)
    {  d=(a[i])^(x);
       if(bs1(a,d,n)>i+1)
            c+=bs1(a,d,n)-bs2(a,d,n)+1;
    }
   else for(i=1;i<n;i++)
    {
      if(a[i]==a[i-1]) p++;
      else {c+=(p*(p+1))/2;p=0;}
    }
    c+=(p*(p+1))/2;
    cout<<c;
   return 0;
}