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
const int mxN = 1e5+1, oo = 1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    vector<ll> aa(n); for(auto& i : aa) cin >> i;
    vi bb(n); for(auto& i : bb) cin >> i;
    auto good = [&](ll x) {
        vector<vector<pair<ll,ll>>> pq(k+1);
        auto add = [&](int t,ll a, ll b) {
            auto dif = (a+b)/b;
            auto startofbad = t+dif;
            if(startofbad<k) {
                pq[startofbad].push_back({a-dif*b,b});
            }
        };
        for(int i=0;i<n;++i) add(0,aa[i],bb[i]);
        int ptr = 0;
        for(int t=0;t<k;++t) {
            if(!pq[t].empty()) return false;
            // find first bad
            while(ptr<k) {
                if(!pq[ptr].empty()) {
                    auto [a,b] = pq[ptr].back();
                    pq[ptr].pop_back();
                    add(ptr,a+x,b);
                    break;
                }
                ptr++;
            }
            if(ptr==k) return true;
        }

        return true;
    };
    ll lo=0,hi = 1e18;
    while(lo<hi) {
        auto x = (lo+hi)/2;
        if(good(x)) {
            hi = x;
        } else {
            lo = x+1;
        }
    }
    if(lo== ll(1e18)) cout << "-1\n";
    else cout << lo << '\n';
}