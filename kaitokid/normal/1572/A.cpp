#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int>a[200009];
int dp[200009];
int vis[200009];
bool nt;
int go(int x)
{
    if(vis[x]==1){nt=true;return 0;}
    if(vis[x]==2)return dp[x];
    vis[x]=1;
    dp[x]=1;
    for(int i=0;i<a[x].size();i++)
    {
        if(nt)return 0;
    dp[x]=max(dp[x],go(a[x][i])+(a[x][i]>x));
    }
    vis[x]=2;
    return dp[x];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++){a[i].clear();
        vis[i]=0;
        int k;
        cin>>k;
        while(k--){int x;cin>>x;a[i].push_back(x);}
        }
        nt=false;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,go(i));
            if(nt)break;

        }
        if(nt){cout<<-1<<endl;continue;}
        cout<<ans<<endl;
    }
    return 0;
}