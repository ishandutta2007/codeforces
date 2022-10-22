#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)

#define infty 0x3f3f3f3f

#define pb push_back
#define mp make_pair
#define xx first
#define yy second

using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;

//head
const int maxn = 100000;

VI e[maxn+5];
int deg[maxn+5];
int up[maxn+5][2];
int down[maxn+5][2];
int ans;

void upd(int &x,int y) {if(y>x) x=y;}

void dfs(int now,int fa)
{
    up[now][0]=0+deg[now]-(fa!=0);
    up[now][1]=1;
    down[now][0]=0+deg[now]-(fa!=0);
    down[now][1]=1;
    int U[2][3]={},uf[2][3]={-1,-1,-1,-2,-2,-2};
    int D[2][3]={},df[2][3]={-1,-1,-1,-2,-2,-2};
    for(auto v: e[now]) if(v!=fa)
    {
        dfs(v,now);
        upd(up[now][0],max(up[v][1],up[v][0])+deg[now]-1-(fa!=0));
        upd(down[now][0],max(down[v][1],down[v][0])+deg[now]-1-(fa!=0));
        upd(up[now][1],up[v][0]+1);
        upd(down[now][1],down[v][0]+1);
        U[0][2]=up[v][0]; uf[0][2]=v;
        U[1][2]=max(up[v][0],up[v][1]); uf[1][2]=v;
        D[0][2]=down[v][0]; df[0][2]=v;
        D[1][2]=max(down[v][1],down[v][0]); df[1][2]=v;
        rep(c,0,1) per(i,0,1) if(U[c][i]<U[c][i+1]) swap(U[c][i],U[c][i+1]),swap(uf[c][i],uf[c][i+1]);
        rep(c,0,1) per(i,0,1) if(D[c][i]<D[c][i+1]) swap(D[c][i],D[c][i+1]),swap(df[c][i],df[c][i+1]);
    }
    if(uf[0][0]!=df[0][0]) upd(ans,U[0][0]+D[0][0]+1);
    else 
    {
        upd(ans,U[0][1]+D[0][0]+1);
        upd(ans,U[0][0]+D[0][1]+1);
    }
    if(uf[1][0]!=df[1][0]) upd(ans,U[1][0]+D[1][0]+deg[now]-(uf[1][0]>=0)-(df[1][0]>=0));
    else
    {
        upd(ans,U[1][0]+D[1][1]+deg[now]-(uf[1][0]>=0)-(df[1][1]>=0));
        upd(ans,U[1][1]+D[1][0]+deg[now]-(uf[1][1]>=0)-(df[1][0]>=0));
    }
    
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
        deg[x]++; deg[y]++;
    }
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}