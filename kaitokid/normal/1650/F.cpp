#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100009];
ll dp[100009][209];
ll t[100009],p[100009];
vector<ll>v[100009];
vector<ll>res;
ll go(int x)
{
    int m=v[x].size();
    if(m==0)return INT_MAX;
    for(int i=1;i<=200;i++)dp[0][i]=INT_MAX;
    dp[0][0]=0;
    for(int i=1;i<=m;i++)
        for(int j=0;j<=200;j++)
    {
        dp[i][j]=dp[i-1][j];
        if(j>=p[v[x][i-1]])dp[i][j]=min(dp[i][j],dp[i-1][j-p[v[x][i-1]]]+t[v[x][i-1]]);
    }
    ll r=-1,tmp=INT_MAX;
    for(int i=100;i<=200;i++)
    if(dp[m][i]<tmp){tmp=dp[m][i];r=i;}
    if(r==-1)return tmp;
    int u=m;
    while(r>0)
    {
        if(dp[u][r]==dp[u-1][r]){u--;continue;}
        res.push_back(v[x][u-1]);
        r-=p[v[x][u-1]];
        u--;
    }
    return tmp;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)v[i].clear();
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=m;i++)
        {
            int x;
            cin>>x>>t[i]>>p[i];
            v[x].push_back(i);
        }
        ll tot=0;
        bool ans=true;
        res.clear();
        for(int i=1;i<=n;i++)
        {
            tot+=go(i);
            if(tot>a[i]){ans=false;break;}
        }
        if(!ans)cout<<-1<<endl;
        else{
            cout<<res.size()<<endl;
            for(int i=0;i<res.size();i++)cout<<res[i]<<" ";
            cout<<endl;
        }

    }
    return 0;
}