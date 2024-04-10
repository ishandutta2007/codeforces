#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> v[100009];
int pr[21][100009],dist[100009];
void dfs(int x,int p,int ds)
{
    pr[0][x]=p;
    dist[x]=ds;
    for(int i=0;i<v[x].size();i++)
    if(v[x][i]!=p)dfs(v[x][i],x,ds+1);
}
int lca(int a,int b)
{
    if(dist[a]<dist[b])swap(a,b);
    int d=dist[a]-dist[b];
    while(d>0)
    {

        int u=log2(d);
        a=pr[u][a];
        d-=(1<<u);
    }

    if(a==b)return a;
    for(int i=20;i>=0;i--)if(pr[i][a]!=pr[i][b]){a=pr[i][a];b=pr[i][b];}
    return pr[0][a];
}
int dis(int a,int b)
{
    return dist[a]+dist[b]-2*dist[lca(a,b)];
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    int x,y;
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0,0);
    for(int i=1;(1<<i)<=n;i++)
        for(int j=1;j<=n;j++)
        pr[i][j]=pr[i-1][pr[i-1][j]];
int m,a,b,k;
cin>>m;
for(int i=0;i<m;i++)
{
    cin>>x>>y>>a>>b>>k;
int d=dis(a,b);
if(d%2==k%2&&k>=d){cout<<"YES\n";continue;}
d=dis(a,x)+dis(b,y)+1;

if((d%2)==(k%2)&&k>=d){cout<<"YES\n";continue;}
d=dis(a,y)+dis(b,x)+1;

if(d%2==k%2&&k>=d){cout<<"YES\n";continue;}
cout<<"NO\n";
}
    return 0;
}