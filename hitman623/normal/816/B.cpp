#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
long k,n,q,x,y,i,j,val[200005];
int main()
{
    io
    vll v;
    cin>>n>>k>>q;
    for(i=0;i<n;++i)
    {
        cin>>x>>y;
        v.pb({x,-1});
        v.pb({y,1});
    }
    sort(v.begin(),v.end());
    long cur=0;
    for(i=0;i<v.size();++i)
    {
        if(v[i].second==-1) cur++;
        else cur--;
        if(cur>=k)
        {
            j=v[i].first;
            if(i<v.size()-1)
            while(j<=v[i+1].first)
            val[j]=1,j++;
            else
            while(j<=200005)
            val[j]=1,j++;
        }
    }
    for(i=1;i<=200005;++i)
    val[i]+=val[i-1];
    while(q--)
    {
        cin>>x>>y;
        cout<<val[y]-(x?val[x-1]:0)<<endl;
    }
    return 0;
}