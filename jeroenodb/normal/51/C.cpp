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
    int n; cin >> n;
    vector<ll> x(n);
    for(auto& i : x) cin >> i,i*=2;
    sort(all(x));
    auto good = [&](ll d) {
        vector<ll> res = {x[0]+d};
        auto prev = x[0];
        for(auto i : x) {
            if(i-prev>2*d) {
                res.push_back(i+d);
                prev = i;
            }
        }
        return res;
    };
    ll lo=0,hi = 5e9;
    while(lo<hi) {
        auto mid = (lo+hi)/2;
        if(good(mid).size()<=3) {
            hi = mid;
        } else lo = mid+1;
    }
    auto res = good(lo);
    while(res.size()<3) res.push_back(res.back());
    cout << setprecision(10) << lo*0.5 << '\n' << res[0]*0.5 << ' ' << res[1]*0.5 << ' ' << res[2]*0.5 << '\n';


}