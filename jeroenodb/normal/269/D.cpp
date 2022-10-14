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
const int mxN = 1e5+1, oo = 1e9+1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t; cin >> n >> t;
    vi dp(n+2,0);
    dp[n+1]=2*oo;

    map<int,int> mp;
    mp[-oo-1]={n+1};
    mp[oo+1] = {n+1};
    vector<array<int,3>> ivs(n);
    for(auto& [h,l,r] : ivs) cin >> h >> l >> r;
    ivs.push_back({t,-oo,oo});
    ivs.push_back({0,-oo-1,oo+1});
    vi ord(n+1); iota(all(ord),0);
    sort(all(ord),[&](int i, int j) {return ivs[i][0]<ivs[j][0];});
    for(auto i : ord) {
        auto [h,l,r] = ivs[i];
        auto it = prev(mp.upper_bound(l));
        int last=-1;
        while(it->first<=r) {
            last = it->second;
            auto it2 = next(it);
            int j = it->second;
            if( (it->first<=l or it->first==ivs[j][1]) and (it2->first>=r or it2->first==ivs[j][2])) {
                dp[i] = max(dp[i], min(dp[j],min(it2->first,r)-max(it->first,l)));
            }
            if(it->first>l) mp.erase(it);
            it=it2;
       }
       mp[l] = i;
       mp[r]=last;
    }
    cout << dp[n] << '\n';

}