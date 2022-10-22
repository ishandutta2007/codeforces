#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int>ed[200009];
ll v[200009],ans,sz[200009],sum;
int n;
void rem(int x,int y)
{
    sum-=sz[x];
    sz[x]-=sz[y];
    sum+=sz[x];
}
void add(int x,int y)
{

    sum-=sz[x];
    sz[x]+=sz[y];
    sum+=sz[x];
}
void fuck(int x,int p)
{
    ans=max(ans,sum);
    for(int i=0;i<ed[x].size();i++)
    {
        ll u=ed[x][i];
        if(u==p)continue;
        rem(x,u);
        add(u,x);
        fuck(u,x);
        rem(u,x);
        add(x,u);
    }
}

void go(int x,int p)
{
    sz[x]=1;
    sum++;
    for(int i=0;i<ed[x].size();i++)
        if(ed[x][i]!=p)
            {go(ed[x][i],x);
        add(x,ed[x][i]);}

}
int main()
{
    cin>>n;
    int x,y;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    go(1,0);
    fuck(1,0);
    cout<<ans;
    return 0;
}