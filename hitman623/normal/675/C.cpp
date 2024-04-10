#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,p[100005],x,i,c=1000000000;
    map < long long , long long > mp;
    map < long long , long long > :: iterator it;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>x;
        if(i>0)
        p[i]=x+p[i-1];
        else p[i]=x;
        mp[p[i]]++;
    }
    for(it=mp.begin();it!=mp.end();it++)
    c=min(c,n-it->second);
    cout<<c;
    return 0;
}