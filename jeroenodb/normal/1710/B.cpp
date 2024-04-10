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
    struct event {
        int x,sgn,id=-1;
        bool operator<(const event& o) {
            return x<o.x;
        }
    };
    vector<event> es;
    vector<pi> rain(n);
    vector<bool> ans(n,1);
    {
    int id=0;
        for(auto& [x,p] : rain) {
             cin >> x >> p;
            es.push_back({x-p,1});
            es.push_back({x,-2,id++});
            es.push_back({x+p,1});
        }
    }
    sort(all(es));
    for(int rep=0;rep<2;++rep) {
        ll last=-1e10;
        ll slope=0,cur=0, bad=-1e18;
        for(auto& e : es) {
            cur+=slope*(e.x-last);
            slope+=e.sgn;
            last=e.x;
            if(cur>m) 
                bad = max(cur-e.x-m,bad);
            if(e.id!=-1) {
                auto& p = rain[e.id].second;
                if(p-e.x<bad) {
                    ans[e.id]=0;
                }
            }
        }
        reverse(all(es));
        for(auto& e : es) {
            e.x = -e.x;
        }
    }
    for(auto i : ans) {
        cout << int(i);
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}