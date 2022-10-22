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
bool mark[maxn+5];
int cnt[2],C;

void dfs(int now,int fa,int dep)
{
    if(deg[now]==1) cnt[dep&1]++;
    for(auto v: e[now]) if(v!=fa)
    {
        dfs(v,now,dep+1); C++;
        if(deg[v]==1)
        {
            if(mark[now]) C--;
            else mark[now]=1;
        }
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
        deg[x]++;
        deg[y]++;
    }
    int r=-1;
    rep(i,1,n) if(deg[i]!=1) {r=i; break;}
    assert(r!=-1);
    dfs(r,0,0);
    int mn=-1;
    if(cnt[0]==0 || cnt[1]==0) mn=1;
    else mn=3;
    printf("%d %d\n",mn,C);
    return 0;
}