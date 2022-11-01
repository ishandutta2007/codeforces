#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
int n,m,k,a[N],b[N],c[N],d[N];
vector<int>v[N];
bool vis[N];
int vv[N];
struct node
{
    int x,id;
    node(int x=0,int id=0):x(x),id(id){}
    bool operator<(const node&o)const
    {
        return x>o.x;
    }
};
priority_queue<node>q;
pair<int,int>p[N];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        v[x].push_back(y);
        vv[y]++;
    }
    for(int i=1;i<=n;i++) vv[i]++;
    d[n]=a[n];
    for(int i=n-1;i>=1;i--)
        d[i]=max(a[i],d[i+1]-b[i]);
    if(k<d[1]){cout<<-1<<endl;return 0;}
    int now=k;
    for(int i=1;i<=n;i++)
    {
        vv[i]--;
        now=now+b[i];
        int tot=0;
        for(int j=0;j<v[i].size();j++)
        {
            vv[v[i][j]]--;
            if(!vv[v[i][j]])
                p[tot++]={c[v[i][j]],v[i][j]};
        }
        if(!vv[i])
            p[tot++]={c[i],i};
        sort(p,p+tot);
        for(int j=tot-1;j>=0;j--)
            if(!vis[p[j].second])
            {
                if(now>d[i+1])
                {
                    now--;
                    q.push(node(p[j].first,p[j].second));
                    vis[p[j].second]=true;
                }
                else if(!q.empty())
                {
                    if(q.top().x<p[j].first)
                    {
                        vis[q.top().id]=false;
                        q.pop();
                        q.push(node(p[j].first,p[j].second));
                        vis[p[j].second]=true;
                    }
                }
            }
    }
    ll ans=0;
    while(!q.empty())
        ans+=q.top().x,q.pop();
    printf("%lld\n",ans);
}