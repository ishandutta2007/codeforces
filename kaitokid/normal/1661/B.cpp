#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod=32768;
int ds[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=1;i<100000;i++)ds[i]=-1;
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        int v=(u+mod-1)%mod;
        if(ds[v]==-1){ds[v]=ds[u]+1;q.push(v);}
        v=u;
        if(v%2)continue;
        v/=2;
        if(ds[v]==-1){ds[v]=ds[u]+1;q.push(v);}
        v=((u+mod)/2)%mod;
        if(ds[v]==-1){ds[v]=ds[u]+1;q.push(v);}

    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==0){cout<<0<<" ";continue;}
        int ans=1+min(ds[(n+1)%mod],ds[(2*n)%mod]);
        cout<<ans<<" ";
    }


    return 0;
}