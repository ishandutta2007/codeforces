#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a,b;
    long n,p[200005],pp[200005],i,j,l,h,m,nn;
    cin>>a>>b;
    n=a.length();
    nn=b.length();
    for(i=0;i<n;i++)
    {cin>>p[i];
    pp[p[i]-1]=i;}
    l=0;h=n;
    while(h-l>1)
    {
        m=(h+l)/2;
        j=0;
        for(i=0;i<n;++i)
            if(a[i]==b[j] && pp[i]>=m)
                j++;
        if(j==nn) l=m;
        else h=m;
    }
    cout<<l;
    return 0;
}