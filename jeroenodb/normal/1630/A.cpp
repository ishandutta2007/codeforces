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
    int n,k; cin >> n >> k;
    // otherwise do construction
    vector<array<int,2>> ans;
    ans.reserve(n/2);
    int msk = n-1;
    for(int i=0;i<n/2;++i) {
        ans.push_back({i, msk^i});
    }
    if(n==4 and k== n-1) {
        // only this can be wrong!
        cout << "-1\n";
        return;
    }
    if(k==n-1) {
        // do something smart
        swap(ans[1][0], ans[msk^ (n/2)][0]);
        swap(ans[0][1], ans[msk^(n/2+1)][0]);
    } else {
        if(k>=n/2) {
            int id = k^msk;
            swap(ans[id][0], ans[0][1]);
        } else swap(ans[k][1], ans[0][1]);
    }
    int res=0;
    for(auto& [a,b] : ans) res+=a&b;
    assert(res==k);
    for(auto i : ans) cout << i << '\n';

}
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}