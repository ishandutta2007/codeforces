#include <iostream>
#include<algorithm>
#include<vector>
#define MP make_pair
#define X first
#define Y second

using namespace std;

typedef pair<int,int> pii;
int n,m,ans,dp[400000];
vector<pair<int,pii> >e;
vector<pii> v1;

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v,u,w;
        cin>>v>>u>>w;
        e.push_back(MP(w,pii(v,u)));
    }
    sort(e.begin(),e.end());
    for(int i=0;i<e.size();i++)
    {
        int u=e[i].Y.X,v=e[i].Y.Y;
        if(i>0 && e[i].X!=e[i-1].X)
        {
            for(int j=0;j<v1.size();j++)
                dp[v1[j].X]=max(dp[v1[j].X],v1[j].Y);
            v1.clear();
        }
    //    cout<<v<<" "<<u<<" "<<dp[v]<<" "<<dp[u]<<endl;
        if(dp[u]+1>dp[v])
            v1.push_back(pii(v,dp[u]+1));
    }
     for(int j=0;j<v1.size();j++)
            dp[v1[j].X]=max(dp[v1[j].X],v1[j].Y);
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i]);
    cout<<ans<<endl;
}