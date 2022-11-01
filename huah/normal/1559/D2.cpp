#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define nep(i, r, l) for (int i = r; i >= l; i--)
void sc(int &x) { scanf("%d", &x); }
void sc(int &x, int &y) { scanf("%d%d", &x, &y); }
void sc(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void sc(ll &x) { scanf("%lld", &x); }
void sc(ll &x, ll &y) { scanf("%lld%lld", &x, &y); }
void sc(ll &x, ll &y, ll &z) { scanf("%lld%lld%lld", &x, &y, &z); }
void sc(char *x) { scanf("%s", x); }
void sc(char *x, char *y) { scanf("%s%s", x, y); }
void sc(char *x, char *y, char *z) { scanf("%s%s%s", x, y, z); }
void out(int x) { printf("%d\n", x); }
void out(ll x) { printf("%lld\n", x); }
void out(int x, int y) { printf("%d %d\n", x, y); }
void out(ll x, ll y) { printf("%lld %lld\n", x, y); }
void out(int x, int y, int z) { printf("%d %d %d\n", x, y, z); }
void out(ll x, ll y, ll z) { printf("%lld %lld %lld\n", x, y, z); }
void ast(ll x,ll l,ll r){assert(x>=l&&x<=r);}
using namespace std;
const int N=5e5+5,bs=318,mod=1e9+7;
int tot,g[N],f1[N],f2[N],s1[N],s2[N];
int getf(int x,int *f){return f[x]==x?x:f[x]=getf(f[x],f);}
vector<int>vc1[N],vc2[N];
bitset<100001>b[320];
int n,m1,m2;
struct node
{
    int u,s;
    bool operator<(const node&o)const
    {
        return s!=o.s?s>o.s:u>o.u;
    }
    bool operator==(const node&o)const
    {
        return u==o.u&&s==o.s;
    }
};
priority_queue<node>q,del;
void qt(){while(del.size()&&q.top()==del.top()) q.pop(),del.pop();}
void Merge1(int u,int v)
{
    del.push({u,s1[u]});
    del.push({v,s1[v]});
    // cout<<"Del: "<<u<<' '<<s1[u]<<endl;
    // cout<<"Del: "<<v<<' '<<s1[v]<<endl;
    if(s1[u]>s1[v]) swap(u,v);
    f1[u]=v;
    s1[v]+=s1[u];
    vc1[v].insert(vc1[v].end(),vc1[u].begin(),vc1[u].end());
    vc1[u].clear();
    q.push({v,s1[v]});
}
void Merge2(int u,int v)
{
    if(s2[u]>s2[v]) swap(u,v);
    f2[u]=v;
    s2[v]+=s2[u];
    if(g[u]&&g[v]) 
        b[g[v]]|=b[g[u]];
    else if(g[v])
    {
        for(int &x:vc2[u]) b[g[v]][x]=1;
    }
    else
    {
        vc2[v].insert(vc2[v].begin(),vc2[u].begin(),vc2[u].end());
        vc2[u].clear();
        if(vc2[v].size()>=bs)
        {
            g[v]=++tot;
            for(int &x:vc2[v])
                b[g[v]][x]=1; 
        }
    }
}
int vis[N];
int main() 
{
    sc(n,m1,m2);
    rep(i,1,n) f1[i]=f2[i]=i,s1[i]=s2[i]=1,q.push({i,1}),vc1[i].push_back(i),vc2[i].push_back(i);
    if(m1>=m2)
    {
        while(m1--)
        {
            int u,v;sc(u,v);
            u=getf(u,f1);
            v=getf(v,f1);
            if(u!=v) Merge1(u,v);
        }
        while(m2--)
        {
            int u,v;sc(u,v);
            u=getf(u,f2);
            v=getf(v,f2);
            if(u!=v) Merge2(u,v);
        }
    }
    else
    {
        while(m1--)
        {
            int u,v;sc(u,v);
            u=getf(u,f2);
            v=getf(v,f2);
            if(u!=v) Merge2(u,v);
        }
        while(m2--)
        {
            int u,v;sc(u,v);
            u=getf(u,f1);
            v=getf(v,f1);
            if(u!=v) Merge1(u,v);
        }
    }
    vector<pair<int,int>>ans;
    while(true)
    {
        qt();
        int u=q.top().u;
        assert(f1[u]==u);
        // cout<<"U: "<<u<<' '<<s1[u]<<' '<<vc1[u].size()<<endl;
        if(s1[u]==n) break;
        for(int &x:vc1[u])
            vis[getf(x,f2)]++;
        int t=-1;
        // cout<<vc1[u].size()<<endl;
        for(int &x:vc1[u])
            if(s2[getf(x,f2)]!=n-s1[u]+vis[getf(x,f2)])
            {
                t=x;
                break;
            }
        assert(t!=-1);
        for(int &x:vc1[u])
            vis[getf(x,f2)]--;
        int tt=getf(t,f2);
        if(g[tt])
        {
            b[0]=b[g[tt]];
            for(int &x:vc1[u]) b[0][x]=1;
            b[0]=~b[0];
            b[0][0]=0;
            int v=b[0]._Find_first();
            ans.push_back({t,v});
            Merge1(getf(t,f1),getf(v,f1));
            Merge2(getf(t,f2),getf(v,f2));
        }
        else
        {
            b[0].reset();
            for(int &x:vc1[u]) b[0][x]=1;
            for(int &x:vc2[tt]) b[0][x]=1;
            b[0]=~b[0];
            b[0][0]=0;
            int v=b[0]._Find_first();
            ans.push_back({t,v});
            Merge1(getf(t,f1),getf(v,f1));
            Merge2(getf(t,f2),getf(v,f2));
        }
    }
    printf("%d\n",int(ans.size()));
    for(pair<int,int>&x:ans)
        printf("%d %d\n",x.first,x.second);
}
/*
befor submit code check:
freopen
size of N
mod
debug output
*/