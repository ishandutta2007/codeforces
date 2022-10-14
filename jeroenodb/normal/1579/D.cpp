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
    int n; cin >> n;
    priority_queue<pi> pq;
    for(int i=1;i<=n;++i) {
        int a; cin >> a;
        if(a!=0) pq.push({a,i});
    }
    vector<pi> ans;
    while(pq.size()>=2) {
        auto a = pq.top(); pq.pop();
        auto b = pq.top();pq.pop();
        ans.push_back({a.second,b.second});
        if(a.first-1) pq.push({a.first-1,a.second});
        if(b.first-1) pq.push({b.first-1,b.second});
    }
    cout << ans.size() << '\n';
    for(auto [a,b]: ans) {
        cout << a << ' ' << b << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}