#include <iostream>
#include<algorithm>
#include<vector>
#define MP make_pair
using namespace std;

typedef pair<int,int> pii;

vector<int>G[2000];
vector<pair<int,pii> >e;
long long n,m,k,w,MIN,f,ans1,m1[2000],m2,t;
char c[2000][20][20];
bool mark[2000];

void dfs(int v,int v1)
{
    mark[v]=true;
    cout<<v<<" "<<v1<<endl;
    for(int i=0;i<G[v].size();i++)
        if(!mark[G[v][i]])
            dfs(G[v][i],v);
    //cout<<v<<" "<<ans[v]<<endl;
}

int main()
{
    cin>>n>>m>>k>>w;
    for(int u=1;u<=k;u++)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>c[u][i][j];
    }
    for(int u=1;u<=k;u++)
    {
        m1[u]=u;
        for(int v=1;v<=k;v++)
        {
            if(v==u)
                continue;
            f=0;
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    if(c[u][i][j]!=c[v][i][j])
                        f++;
            e.push_back(MP(f,pii(v,u)));
        }
    }
    sort(e.begin(),e.end());
    for(int i=0;i<e.size();i++)
    {
        int f=e[i].first,v=e[i].second.first,u=e[i].second.second;
        if(t==k-1 || f*w>=n*m)
            break;
        if(m1[v]==m1[u])
            continue;
        t++;
        m2=m1[u];
        for(int i=1;i<=k;i++)
            if(m1[i]==m2)
                m1[i]=m1[v];
        ans1+=f*w;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    ans1+=n*m*(k-t);
    cout<<ans1<<endl;
    for(int i=1;i<=k;i++)
        if(!mark[i])
            dfs(i,0);
}