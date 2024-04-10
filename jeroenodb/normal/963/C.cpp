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
    int n; cin >> n;
    map<ll,map<ll,ll>> mp;
    for(int i=0;i<n;++i) {
        ll w,h,c; cin >> w >> h >> c;
        mp[w][h]=c;
    }
    vector<pair<ll,ll>> need;
    ll gg=0;
    for(auto& [w, v] : mp) {
        ll g = 0;
        for(auto [h,cnt] : v) g=gcd(g,cnt);
        vector<pair<ll,ll>> vv(all(v));
        for(auto& [a,b] : vv) b/=g;
        gg=gcd(gg,g);
        if(need.empty()) need=vv;
        else if(need!=vv) {
            cout << "0\n";
            exit(0);
        }
    }
    ll ans=0;
    for(ll i=1;i*i<=gg;++i) {
        if(gg%i==0) {
            ans += 1 + (i*i!=gg);
        }
    }
    cout << ans;
}