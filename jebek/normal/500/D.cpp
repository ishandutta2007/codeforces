#include <iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

const int MAXN=200000;
bool mark[MAXN];
int n;
long long c[MAXN][5],w[MAXN],x,y,t[MAXN],q,ans[MAXN];
long double ans1,ans2;
vector<int>G[MAXN],W[MAXN],ind[MAXN];

void dfs(int v)
{
    mark[v]=true;
    t[v]=1;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u])
        {
            dfs(u);
            ans[ind[v][i]]=c[t[u]][2]*c[n-t[u]][1]+c[t[u]][1]*c[n-t[u]][2];
            ans1+=ans[ind[v][i]]*W[v][i];
            t[v]+=t[u];
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        c[i][0]=c[i][i]=1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<min(i,4);j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    for(int i=1;i<n;i++)
    {
        int l,r;
        cin>>l>>r>>w[i];
        G[l].push_back(r);
        G[r].push_back(l);
        W[l].push_back(w[i]);
        W[r].push_back(w[i]);
        ind[l].push_back(i);
        ind[r].push_back(i);
    }
    cin>>q;
    dfs(1);
    for(int i=0;i<q;i++)
    {
        cin>>x>>y;
        ans1-=ans[x]*(w[x]-y);
        w[x]=y;
        ans2=c[n][3];
        ans2=ans1/ans2*2;
        cout<<fixed<<setprecision(7)<<ans2<<endl;
    }
}