#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int mn=2e5+10;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=1e9+7;

int r[mn][2];
vi g[mn];
ll dp[mn][2];
void dfs(int x,int p){
    dp[x][0]=dp[x][1]=0;
    for(int y:g[x])if(y!=p){
        dfs(y,x);
        for(int i=0;i<2;i++){
            dp[x][i]+=max({dp[y][0]+abs(r[x][i]-r[y][0]),dp[y][1]+abs(r[x][i]-r[y][1])});
        }
    }
    //cerr<<x<<" "<<dp[x][0]<<" "<<dp[x][1]<<endl;
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        g[i].clear();
    for(int i=1;i<=n;i++)scanf("%d%d",&r[i][0],&r[i][1]);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //cerr<<r[2][0]<<endl;
    dfs(1,1);
    printf("%lld\n",max(dp[1][0],dp[1][1]));
}

int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        solve();
    }
}