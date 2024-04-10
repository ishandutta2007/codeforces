#include <bits/stdc++.h>
#define pb insert
using namespace std;
long n,m,a[200005],b[200005],p[200005],i,c,d;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    set < long > v[4];
    cin>>n;
    for(i=0;i<n;++i)
    cin>>p[i];
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=0;i<n;++i)
    cin>>b[i];
    for(i=0;i<n;++i)
    {
        v[a[i]].pb(p[i]);
        v[b[i]].pb(p[i]);
    }
    cin>>m;
    for(i=0;i<m;++i)
    {
        cin>>c;
        if(v[c].empty()) cout<<-1<<" ";
        else
        {
            d=*v[c].begin();
            cout<<d<<" ";
            if(v[1].find(d)!=v[1].end())
            v[1].erase(v[1].find(d));
            if(v[2].find(d)!=v[2].end())
            v[2].erase(v[2].find(d));
            if(v[3].find(d)!=v[3].end())
            v[3].erase(v[3].find(d));
        }
    }
    return 0;
}