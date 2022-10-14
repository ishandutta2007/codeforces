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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi h(n); 
        for(auto& i : h) cin >> i;
        auto check = [&](int mx) {
            ll lo=0,hi = 1e18;
            ll needo=0, neede=0;
            for(auto& i : h) {
                int j = mx-i;
                needo+=(j%2), neede+=j/2;
            }
            while(lo<hi) {
                auto good = [&](ll days) {
                    ll odds = (days+1)/2;
                    if(odds<needo) return false;
                    ll fr = odds-needo;
                    ll evens = days/2;
                    return (evens+fr/2) >=neede;
                };
                ll mid = (lo+hi)/2;
                if(good(mid)) {
                    hi = mid;
                } else lo = mid+1;
            }
            return lo;
        };
        int mx = *max_element(all(h));
        cout << min(check(mx), check(mx+1)) << '\n';
    }
}