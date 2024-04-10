#include <bits/stdc++.h>
#define pb push_back
#define pll pair < int , int >
#define vll vector < pll >
#define ml map < int , int >
#define mll map < pll , int >
#define x first
#define y second
#define vl vector < int >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
ml mp;
set < int >::iterator it;
set < int > f;
set < int > g[200005];
int n,i,a[200005],b[200005],l;
int main()
{
    io
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a[i];
        g[a[i]].insert(i);
        mp[a[i]]++;
    }
    cout<<n-mp.size()<<endl;
    for(i=1;i<=n;++i)
    if(g[i].size()>1)
    {
        for(it=g[i].begin();it!=g[i].end();++it)
        f.insert(*it);
    }
    for(i=1;i<=n;++i)
    if(mp[i]==0)
    {
        l=*f.begin();
        b[l]=i;
        f.erase(l);
        g[a[l]].erase(l);
        if(g[a[l]].size()==1 && a[l]>i)
        f.erase(*g[a[l]].begin());
    }
    else
    {
        l=*g[i].begin();
        b[l]=i;
        g[i].erase(l);
        if(g[i].size()>=1)
        f.erase(l);
    }
    for(i=1;i<=n;++i)
    cout<<b[i]<<" ";
    return 0;
}