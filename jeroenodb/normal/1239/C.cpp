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
    int n,p; cin >> n >> p;
    struct el {
        int at;
        ll t;
        bool done=false;
        bool operator<(const el& o) const {
            return make_tuple(t,done,at)>make_tuple(o.t,o.done,o.at);
        }
    };
    priority_queue<el> pq;
    set<int> available = {n+1},unseated = {n};
    for(int i=0;i<n;++i) {
        int t; cin >> t;
        pq.push({i,t});
    }
    ll lastdoneQ=0;
    vector<ll> ans(n);
    while(!pq.empty()) {
        auto e = pq.top(); pq.pop();
        if(e.done) {
            ans[e.at] = e.t;
            unseated.erase(e.at);
        } else {
            available.insert(e.at);
        }

        if(*available.begin()<= *unseated.begin()) {
            ll timefinish = max(lastdoneQ,e.t)+p;
            lastdoneQ = timefinish;
            int at = *available.begin();
            available.erase(available.begin());
            unseated.insert(at);
            pq.push({at,timefinish,true});
        }
    }
    cout << ans << '\n';

}