#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 100, oo = 1e9;
bool take[mxN][mxN];
void solve() {
    int n,k; cin >> n >> k;

    vector<array<int,3>> minions(n);
    {
        int num=0;
    for(auto& [b,a,id] : minions) {
        cin >> a >> b;
        id=++num;
    }
    }
    sort(all(minions));
    pair<ll,vi> best = {-oo,{}};
    for(int last=0;last<n;++last) {
        vector<ll> dp(k,-ll(oo)*oo);
        dp[0]=0;
        for(int i=0;i<n;++i) if(i!=last) {
            auto [b,a,id] = minions[i];
            for(int j=k-1;j>0;--j) {
                ll nwscore = a+b*(j-1)+dp[j-1];
                ll nothing = dp[j]+(k-1)*b;
                if(nwscore>nothing) {
                    take[i][j]=true;
                    dp[j]=nwscore;
                } else {
                    take[i][j]=false;
                    dp[j]=nothing;
                }
            }
            dp[0]+=(k-1)*b;
            take[i][0]=false;
        }
        int at = k-1;
        vi res;
        vi after;
        for(int i=n-1;i>=0;--i) if(last!=i) {
            if(take[i][at]) {
                at--;
                res.push_back(minions[i][2]);
            } else after.push_back(minions[i][2]);
        }
        reverse(all(res));
        for(auto& i : after) {
            res.push_back(i), res.push_back(-i);
        }
        auto [lb,la,lid] = minions[last];
        res.push_back(lid);
        ll ans = dp[k-1]+(k-1)*lb + la;
        best = max(best, {ans,res});
    }
    auto res = best.second;
    cout << res.size() << '\n' << res << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}