#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[200009],p[200009];
vector<int>v[200009];
int ans,n,m;
int pr(int u)
{
    if(p[u]==u)return u;
    return p[u]=pr(p[u]);
}
void go(int x,int y)
{
    if(x==y)return;
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i];
        if(u!=0&&pr(a[u-1])==y)ans--;
        if((u!=(n-1))&&pr(a[u+1])==y)ans--;
    }
    for(int i=0;i<v[x].size();i++)v[y].push_back(v[x][i]);
    v[x].clear();
    p[x]=y;

}
int main()
{
    ios::sync_with_stdio(0);
    int x,y;
    cin>>n>>m;
    cin>>a[0];
    ans=1;
    v[a[0]].push_back(0);
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        v[a[i]].push_back(i);
        if(a[i]!=a[i-1])ans++;
    }
    for(int i=1;i<=m;i++)p[i]=i;
    cout<<ans-1<<endl;
    for(int i=0;i<m-1;i++)
    {
        cin>>x>>y;
        x=pr(x);
        y=pr(y);
        if(v[x].size()>v[y].size())swap(x,y);
   go(x,y);
   cout<<ans-1<<endl;
    }
        return 0;
}