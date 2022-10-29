#include <bits/stdc++.h>
#define pb push_back
#define pll pair < int , int >
#define vll vector < pll >
#define ml unordered_map < int , int >
#define mll map < pll , int >
#define x first
#define y second
#define vl vector < int >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
map < vl , int > grundy;
int g(vl v)
{
    int i,j;
    sort(v.begin(),v.end());
    if(grundy.find(v)!=grundy.end()) return grundy[v];
    set < int > s;
    if(v.size())
    for(i=1;i<=v.back();++i)
    {
        vl vv;
        for(j=0;j<v.size();++j)
        if(v[j]>i)
        vv.pb(v[j]-i);
        else if(v[j] && v[j]!=i) vv.pb(v[j]);
        s.insert(g(vv));
    }
    i=0;
    while(s.find(i)!=s.end())
    i++;
    return grundy[v]=i;
}
int main()
{
    io
    ml f[101],mp;
    ml ::iterator it;
    int n,a[101],i,ans=0,j,c=0;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=0;i<n;++i)
    {
        for(j=2;j*j<=a[i];++j)
        if(a[i]%j==0)
        {
            c=0;
            while(a[i]%j==0)
            {
                a[i]/=j;
                c++;
            }
            f[i][j]=c;
            mp[j]=1;
        }
        if(a[i]!=1)
        f[i][a[i]]=1,mp[a[i]]=1;
    }
    for(it=mp.begin();it!=mp.end();it++)
    {
        vl v;
        for(i=0;i<n;++i)
        v.pb(f[i][it->x]);
        ans^=g(v);
    }
    if(ans) cout<<"Mojtaba";
    else cout<<"Arpa";
    return 0;
}