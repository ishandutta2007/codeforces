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
    vector<pi> ivs(n);
    for(auto& [l,r] : ivs) cin >> l >> r;
    int ans[31] = {};
    for(int i=0;i<30;++i) {
        vector<pi> es;
        int cover=0;
        for(auto& [l,r] : ivs) {
            if(r-l+1>=(1<<i)) cover++;
            else {
                auto a = l%(1<<i);
                auto b = (r+1)%(1<<i);
                if(a>b) {
                    cover++;
                    es.push_back({b,-1});
                    es.push_back({a,1});
                } else {
                    es.push_back({a,1});
                    es.push_back({b,-1});
                }
            }
        }
        ans[i]=cover;
        sort(all(es));
        for(auto& [x,sgn] : es) {
            cover+=sgn;
            ans[i] = max(ans[i],cover);
        }
    }
    int q; cin >> q;
    while(q--) {
        int w; cin >> w;
        int i=0;
        while(!(1<<i & w)) ++i;
        cout << ans[i] << '\n';
    }
}