#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  long t,n,n1,n2,i,a[100001];long double s=0,b=0,m1=0,m2=0;
   cin>>n>>n1>>n2;
   for(i=0;i<n;++i)
    cin>>a[i];
   sort(a,a+n);
   for(i=0;i<n/2;++i)
   {
       t=a[i];
       a[i]=a[n-1-i];
       a[n-1-i]=t;
   }
   for(i=0;i<n1+n2;++i)
    if(i<n1)s+=a[i];
    else b+=a[i];
    m1=(s/n1+b/n2);
    s=0;b=0;
   for( i=0;i<n1+n2;++i)
    if(i<n2)s+=a[i];
    else b+=a[i];
     m2=(b/n1+s/n2);
    if(m1>m2)cout<<setprecision(8)<<m1;
    else cout<<setprecision(8)<<m2;
    return 0;
}