#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cerr <<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"
const int mod = 1e9+7;
const int N = 1e6+10;
int dp[N][21], factor[N];
void pre(){
    dp[0][0] = 1;
    for(int i = 1;i<=20;i++) dp[0][i] = 2;
    for(int i = 1;i<N;i++){
        rep(j,0,21){
            dp[i][j] = 0;
            rep(k,0,j+1){
                dp[i][j] = dp[i][j]+dp[i-1][k];
                if(dp[i][j]>=mod) dp[i][j] -= mod;
            }
        }
    }
    for(int i = 2;i*i<N;i++) if(!factor[i]) for(int j = i*i;j<N;j+=i) factor[j] = i;
    for(int i = 2;i<N;i++) if(!factor[i]) factor[i] = i;    
}
int main(){
    int t=1,n,r;
    pre();
    sd(t);
    while(t--){
        sd(r);sd(n);
        ll ans = 1;
        while(n > 1){
            int p = factor[n],k=0;
            while(n%p==0){
                n/=p;k++;
            }
            ans = (ans*dp[r][k])%mod;
        }
        plld(ans);
    }
}