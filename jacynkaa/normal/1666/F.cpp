#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(X) (int)((X).size())
#define st first
#define nd second
#define pii pair<int,int>
#define all(X) (X).begin(), (X).end()

#ifdef LOC
auto& operator<<(auto& out, pair<auto,auto> a) {return out<<"("<<a.st<<", "<<a.nd<<")";}
auto& operator<<(auto& out, auto a) {
   out << "{";
   for(auto b:a) out<<b<<", ";
   return out<<"}";
}

void dump(auto... x) {((cerr<<x<<", "),...) <<"\n";}
#define debug(...) cerr<< "[" #__VA_ARGS__ "]: ",dump(__VA_ARGS__)
#else
#define debug(...) 0
#endif

typedef long long ll;
const ll MOD = 998244353;

ll fme(ll a, ll b) {
    if(b == 0) return 1;
    if(b&1) return fme(a,b-1)*a%MOD;
    a = fme(a,b/2);
    return a*a%MOD;
}

vector<ll> fact;

ll nck(ll n, ll k) {
    if(k < 0 || k > n) return 0;
    return fact[n]*fme(fact[k],MOD-2)%MOD*fme(fact[n-k],MOD-2)%MOD;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fact.push_back(1);
    while(fact.size() <= 1e5)
        fact.push_back(fact.back()*fact.size()%MOD);
    debug(nck(4,2));
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> tab(n), cntle(n+1), cnt(n+1);
        rep(i,n)
            cin >> tab[i];
        sort(all(tab));
        for(auto a:tab) {
            cnt[a]++;
            for(int j=a;j<=n;j++)
                cntle[j]++;
        }
        
        vector<ll> dp(n+1), sdp(n+1), dpo(n+1), sdpo(n+1);

        for(int j=0;j<=n;j++) {
            dp[j] = dpo[j] = cntle[j-1]*cnt[j]%MOD;
        }

        sdpo[0] = 0;
        for(int j=1;j<=n;j++) {
            sdpo[j] = (sdpo[j-1] + dpo[j]* (max(0, cntle[j-1] - 1)))%MOD;
        }
        
     
        debug(1,dpo);
        for(int i=2;i<=n/2;i++) {
            dp[0] = 0;
            for(int j=1;j<=n;j++)
                dp[j] = (sdpo[j-1]*cnt[j])%MOD;
            sdp[0] = 0;
            for(int j=1;j<=n;j++) {
                sdp[j] = (sdp[j-1] + dp[j]* (max(0,cntle[j-1] - (2*i-1))))%MOD;
            }
            debug(i,dp);
            dpo = dp;
            sdpo = sdp;
        }
        ll res = (dp[tab.back()]%MOD+MOD)%MOD;

        ll d = 1;

        for(int i=0;i<=n;i++) {
            d = d*fact[cnt[i]]%MOD;
        }
        debug(res,d);
        cout<<res*fme(d,MOD-2)%MOD<<"\n";
    }
}