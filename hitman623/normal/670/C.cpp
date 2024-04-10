#include <iostream>
#include <bits/stdc++.h>
using namespace std;

map <long,long> q,v;
map <long,long> ::iterator it;
long n,a[200005],m,b[200005][2],i,j,au=0,su=0,in=0;
int main()
{
    cin>>n;
    for(i=0;i<n;++i)
    {cin>>a[i];
    q[a[i]]++;}
    cin>>m;
    for(i=0;i<m;++i)
    {cin>>b[i][0];
    v[b[i][0]]=1;}
    for(i=0;i<m;++i)
    cin>>b[i][1];
    for(it=q.begin();it!=q.end();++it)
        if(v[it->first]==1)
        au=max(au,it->second);
    for(i=0;i<m;++i)
    {
        if(q[b[i][0]]==au)
        {
            if(q[b[i][1]]>=su)
            {
                su=q[b[i][1]];
                in=i+1;
            }
        }
    }
    cout<<in;
        return 0;
}