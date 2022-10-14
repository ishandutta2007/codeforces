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
const int mxN = 1.1e5+1, oo = 1e9;

map<int,int> dps[mxN];
void add(int i, int w, int k) {
    auto& dp = dps[i];
    auto it = dp.upper_bound(w);
    if(it!=dp.begin()) {
        auto it2 = prev(it);
        if(it2->second>=k) return;
    }
    while(it!=dp.end() and it->second<=k) {
        it = dp.erase(it);
    }
    dp[w]= k;

}
int main() {
    int n,m; cin >> n >> m;
    int ans=0;
    while(m--) {
        int a,b,w; cin >> a >> b >> w;
        auto it = dps[a].lower_bound(w);
        int k=0;
        if(it!=dps[a].begin()) {
            k = prev(it)->second;
        }
        add(b,w,k+1);
        ans=max(ans,k+1);
    }
    cout << ans << '\n';
}