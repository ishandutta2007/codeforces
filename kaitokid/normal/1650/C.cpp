#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[200009],w[200009],id[200009];
bool cmp1(int x,int y)
{
    return w[x]<w[y];
}
bool cmp2(int u,int v)
{
    return x[u]<x[v];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++){cin>>x[i]>>w[i];id[i]=i;}
        sort(id+1,id+m+1,cmp1);
        sort(id+1,id+2*n+1,cmp2);
        ll ans=0;
        for(int i=1;i<=2*n;i++)ans+=w[id[i]];
        cout<<ans<<endl;
        for(int i=1;i<=n;i++)
            cout<<id[i]<<" "<<id[2*n-i+1]<<endl;
    }
    return 0;
}