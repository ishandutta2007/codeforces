#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)

#define MAXN 2000
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

int n;
//head
struct tree
{
    int N;
    int l[MAXN+5],r[MAXN+5];
    int val[MAXN+5][MAXN+5];
    VI e[MAXN+5];
    int dfs(int now)
    {
        int sz=now==1?0:1;
        for(auto v: e[now])
        {
            sz+=dfs(v);
            l[now]=min(l[now],l[v]);
            r[now]=max(r[now],r[v]);
        }
        val[l[now]][r[now]]=max(val[l[now]][r[now]],sz);
        return sz;
    }
    void init(int A)
    {
        N=A;
        rep(i,1,N) l[i]=infty;
        rep(i,1,N) r[i]=0;
        rep(i,2,N)
        {
            int x; scanf("%d",&x);
            e[x].pb(i);
        }
        rep(i,1,n)
        {
            int x; scanf("%d",&x);
            l[x]=r[x]=i;
        }
        dfs(1);
    }
}ta,tb;

int dp[MAXN+5];

int main()
{
	int a,b; scanf("%d",&n);
	scanf("%d",&a);
	ta.init(a);
    scanf("%d",&b);
    tb.init(b);
    rep(i,1,n) rep(j,1,i)
    {
        dp[i]=max(dp[i],dp[j-1]+ta.val[j][i]);
        dp[i]=max(dp[i],dp[j-1]+tb.val[j][i]);
    }
    printf("%d\n",dp[n]);
	return 0;
}