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
void solve() {
    int n,m; cin >> n >> m;
    map<int,int> cnt;
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        cnt[a]++;
    }
    // cnt -> max two
    map<int,vi> revm;
    for(auto [i,c] : cnt) {
        revm[c].push_back(i);
    }
    for(auto& [c, v] : revm) {
        sort(all(v));
        reverse(all(v));
    }
    set<pi> bad;
    while(m--) {
        int u,v; cin >> u >> v;
        bad.insert({u,v});
    }
    auto isbad = [&](int x, int y) {
        if(x>y) swap(x,y);
        if(x==y) return true;
        return bad.count({x,y})!=0;
    };
    ll ans=0;
    for(auto [c,v] : revm) {
        for(auto& [c2,v2] : revm) {
            ll factor = ll(c+c2);
            struct el {
                ll a;
                vi:: iterator i,j;
                bool operator<(const el& o) const {
                    return a<o.a;
                }
            };
            auto construct = [&](vi::iterator i ,vi::iterator j) {
                return el{factor*(*i + *j), i,j};
            };
            priority_queue<el> pq;
            pq.push(construct(v.begin(),v2.begin()));
            while(!pq.empty()) {
                auto at = pq.top(); pq.pop();
                if(isbad(*at.i,*at.j)) {
                    if(at.i+1!=v.end() and at.j==v2.begin()) {
                        pq.push(construct(at.i+1,at.j));
                    }
                    if(at.j+1!=v2.end()) {
                        pq.push(construct(at.i,at.j+1));
                    }
                } else {
                    ans = max(ans,at.a);
                    break;
                }
            }

        }
    }
    
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}