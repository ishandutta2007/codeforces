#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,d[N],t[N<<2];
vector<int>v[N];
bool vis[N];
void build(int l,int r,int k)
{
    if(l==r) return;
    int m=l=r>>1;
    build(l,m,k<<1);build(m+1,r,k<<1|1);
    t[k]=t[k<<1]&t[k<<1|1];
}
queue<int>q;
void fix(int l,int r,int k,int x,int y)
{
    if(l>r||r<x||l>y||t[k]) return;
    if(l==r){t[k]=1;vis[l]=true;q.push(l);return;}
    int m=l+r>>1;
    fix(l,m,k<<1,x,y);fix(m+1,r,k<<1|1,x,y);
    t[k]=t[k<<1]&t[k<<1|1];
}
struct node
{
    int d,u;
    node(int d=0,int u=0):d(d),u(u){}
    bool operator<(const node&o)const
    {
        return d>o.d;
    }
};
priority_queue<node>qq;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
        d[x]++;d[y]++;
    }
    int ans=0,pos=1;
    for(int i=2;i<=n;i++)
        if(d[i]<d[pos]) pos=i;
    for(int i=1;i<=n;i++)
        if(i!=pos) qq.push(node(d[i],i));
    q.push(pos);
    while(!q.empty()||!qq.empty())
    {
        if(q.empty())
        {
            while(!qq.empty()&&vis[qq.top().u]) qq.pop();
            if(qq.empty()) break;
            q.push(qq.top().u);qq.pop();ans++;
        }
        int u=q.front();q.pop();
        if(v[u].empty()) break;
        sort(v[u].begin(),v[u].end());
        fix(1,n,1,1,v[u][0]-1);
        for(int i=1;i<v[u].size();i++)
            fix(1,n,1,v[u][i-1]+1,v[u][i]-1);
        fix(1,n,1,v[u][v[u].size()-1]+1,n);
    }
    printf("%d\n",ans);
}