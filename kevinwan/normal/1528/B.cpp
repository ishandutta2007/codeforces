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
const int mn=1e6+10;
mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
auto begin_time=std::chrono::high_resolution_clock::now();
const ll mod=998244353;

ll dp[mn],sum[mn];
void solve(){
    
}
int fac[mn];
int main(){
    int n;
    scanf("%d",&n);
    dp[0]=sum[0]=1;
    for(int i=1;i<=n;i++)for(int j=i;j<=n;j+=i)++fac[j];
    for(int i=1;i<=n;i++){
        dp[i]=sum[i-1];
        dp[i]+=fac[i]-1;
        if(dp[i]>=mod)dp[i]-=mod;
        sum[i]=(sum[i-1]+dp[i]);
        if(sum[i]>=mod)sum[i]-=mod;
    }
    printf("%lld\n",dp[n]);
}