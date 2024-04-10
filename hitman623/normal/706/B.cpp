#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,x[100000],q,m[100000],i,d,las,beg,mid,j;
    cin>>n;
    for(i=0;i<n;++i)
        cin>>x[i];
    cin>>q;
    for(i=0;i<q;++i)
        cin>>m[i];
    sort(x,x+n);
    for(i=0;i<q;++i)
    {  las=n-1;beg=0;mid=(n-1)/2;
       while(las>=beg)
     {
        if(m[i]<x[mid])
        {
          las=mid-1;
          mid=(las+beg)/2;
        }
        else if(m[i]>=x[mid])
        {
            beg=mid+1;
            mid=(las+beg)/2;
        }
        d=las;
     }
     cout<<d+1<<endl;
    }
    return 0;
}