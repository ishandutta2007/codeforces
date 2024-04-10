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
    int n; ll m,t;
    cin >> n >> m >> t;
    t*=4,m*=4;
    t--;
    // do everything times 4?

    vector<pair<ll,ll>> a(n);
    vector<ll> res;
    for(auto& [x,v] : a) {
        char c; cin >> x >> c;
        x=(x-1)*4;
        v = c=='R'?1:-1;
        res.push_back( ((x+v*t)%m + m)%m);
    }
    sort(all(res));
    assert(unique(all(res))==res.end());
    ll shift=0;
    vi ord(n); iota(all(ord),0);
    sort(all(ord),[&](int i, int j) {return a[i].first<a[j].first;});
    auto [x0,v0] = a[ord[0]];
    for(auto& [x,v] : a) {
        if(v!=v0) {
            // x0-x = (v-v0)*y;
            // y = (x0-x)/(v-v0);
            auto firstCollission = ( ((x0-x)/(v-v0))%(m/2) + m/2)%(m/2);
            assert(firstCollission>0 and firstCollission%2==0);
            if(firstCollission<t) shift+=(t-firstCollission)/(m/2) + 1;
            shift%=n;
        }
    }
    if(v0<0) shift = n-shift;
    auto j = lower_bound(all(res) , ((x0+v0*t)%m + m)%m)-res.begin();
    int dif = (j-shift+n)%n;
    rotate(res.begin(),res.begin()+dif,res.end());
    vector<ll> ans(n);
    for(int i=0;i<n;++i) {
        ans[ord[i]] = llround(0.25L*res[i])%(m/4) + 1;
    }
    
    cout << ans << '\n';

}