#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>ed[300009],v[300009];
bool vis[300009];
int p[300009][27];
int lv[300009],a[300009];
void go(int x,int pr,int lvl)
{
    vis[x]=true;
    p[x][0]=pr;
    lv[x]=lvl;
    for(int i=0;i<ed[x].size();i++)
    {
        int u=ed[x][i];
        if(vis[u])continue;
        v[x].push_back(u);
        go(u,x,lvl+1);
    }
}

int res;
int cal(int x)
{
    int u=0;
    for(int i=0;i<v[x].size();i++)u+=cal(v[x][i]);
    res+=u/2;
    u%=2;
    if((a[x]%2)==0){res+=u;return 0;}
    if(u==0)u++;
    return u;
}
vector<int>pth[300009];
int lca(int x,int y)
{
    if(lv[x]<lv[y])swap(x,y);
    int r=lv[x]-lv[y];
    for(int i=22;i>=0;i--)
        if(r&(1<<i))x=p[x][i];
    if(x==y)return x;
    for(int i=22;i>=0;i--)
    {
        if(p[x][i]!=p[y][i]){x=p[x][i];y=p[y][i];}
    }
    return p[x][0];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    go(1,0,0);
    for(int i=1;i<22;i++)
        for(int j=1;j<=n;j++)
        p[j][i]=p[p[j][i-1]][i-1];

        int q;
        cin>>q;
        for(int w=0;w<q;w++)
        {
            int x,y;

        cin>>x>>y;

        int u=lca(x,y);
        while(x!=u)
        {
            a[x]++;
            pth[w].push_back(x);
            x=p[x][0];
        }
        pth[w].push_back(x);
        vector<int>rr;
        while(y!=u)
        {
            a[y]++;
            rr.push_back(y);
            y=p[y][0];
        }
        reverse(rr.begin(),rr.end());
        for(int i=0;i<rr.size();i++)pth[w].push_back(rr[i]);

        }
        bool ans=true;
        for(int i=1;i<=n;i++)if(a[i]%2)ans=false;
        if(ans)cout<<"YES"<<endl;
        else
        {cout<<"NO"<<endl;
        res=0;
        cal(1);
        cout<<res<<endl;
        return 0;}
        for(int w=0;w<q;w++)
        {
            cout<<pth[w].size()<<endl;
            for(int i=0;i<pth[w].size();i++)cout<<pth[w][i]<<" ";
            cout<<endl;
        }

    return 0;
}