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
const int N=3005;
struct node
{
    int x,y,d;
    node(int x=0,int y=0,int d=0):x(x),y(y),d(d){}
    bool operator<(const node&o)const 
    {
        return d>o.d;
    }
};
int n,a[N];
int dis[N][N];
priority_queue<node>q;
bool vis[N][N];
pair<int,int>pre[N][N];
int op[N][N];
void sol(int cas)
{
    sc(n);
    rep(i,1,n) sc(a[i]);
    vector<int>ans;
    for(int i=n;i>1;i-=2)
    {
        int x,y;
        for(int j=1;j<=i;j++)
        {
            if(a[j]==i) x=j;
            if(a[j]==i-1) y=j;
        }
        if(x==i&&y==i-1) continue;
        if(dis[x][y]==inf)
        {
            out(-1);return;
        }
        while(!(x==1&&y==2))
        {
            int t=op[x][y];
            pair<int,int>nx=pre[x][y];
            x=nx.first;y=nx.second;
            reverse(a+1,a+1+t);
            ans.push_back(t);
        }
        reverse(a+1,a+1+i);
        ans.push_back(i);
        assert(a[i]==i);
        assert(a[i-1]==i-1);
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf(i==ans.size()-1?"%d\n":"%d ",ans[i]);
}
int main()
{
    // freopen("1.in","r",stdin);
    memset(dis,inf,sizeof(dis));
    dis[1][2]=0;
    q.push(node(1,2,0));
    // int sum=0,mx=0;
    while(!q.empty())
    {
        int x=q.top().x,y=q.top().y;q.pop();
        if(vis[x][y]) continue;
        vis[x][y]=true;
        // mx=max(mx,dis[x][y]);
        // sum++;
        if(dis[x][y]<=3)
        for(int t=min(x,y)+(min(x,y)%2==0);t<=2021;t+=2)
        {
            int xx=x,yy=y;
            if(t>=x) xx=t-x+1;
            if(t>=y) yy=t-y+1;
            if(dis[xx][yy]>dis[x][y]+1)
            {
                dis[xx][yy]=dis[x][y]+1;
                q.push(node(xx,yy,dis[xx][yy]));
                pre[xx][yy]={x,y};
                op[xx][yy]=t;
            }
        }
    }
    // for(int i=1;i<=4;i+=2)
    //     for(int j=2;j<=4;j+=2)
    //     if(dis[i][j]==inf) cout<<i<<' '<<j<<endl;
    // cout<<sum<<endl;return 0;
    srand(time(0));
    int t=1,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        sol(++cas);
    }
}