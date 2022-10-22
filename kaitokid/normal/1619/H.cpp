#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int pr[100009];
int go[100009];
int pv[100009];
int sq=330;
int cal(int x)
{
    for(int i=0;i<sq;i++)x=pr[x];
    return x;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>pr[i];
        pv[pr[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        int u=i;
        for(int j=0;j<sq;j++)u=pr[u];
        go[i]=u;
    }
    while(q--)
    {
        int t,x,y;
        cin>>t>>x>>y;
        if(t==2)
        {
            while(y>=sq){x=go[x];y-=sq;}
            while(y){x=pr[x];y--;}
            cout<<x<<endl;
            continue;
        }
    swap(pr[x],pr[y]);
    pv[pr[x]]=x;
    pv[pr[y]]=y;
    go[x]=cal(x);
    go[y]=cal(y);
    for(int j=0;j<=sq+10;j++)
    {
        go[pv[x]]=pv[go[x]];
        x=pv[x];
    }
    for(int j=0;j<=sq+10;j++)
    {
        go[pv[y]]=pv[go[y]];
        y=pv[y];
    }
    }
    return 0;
}